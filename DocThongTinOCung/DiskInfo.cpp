#include "stdafx.h"
#include "DiskInfo.h"
#include <Windows.h>
#include <WinIoCtl.h>
#include <iostream>
using namespace std;
#define  MAX_IDE_DRIVES  16
#define IOCTL_DISK_GET_DRIVE_GEOMETRY_EX CTL_CODE(IOCTL_DISK_BASE, 0x0028, METHOD_BUFFERED, FILE_ANY_ACCESS)

DiskInfo diskInfo;

DiskInfo::DiskInfo()
{
	this->ReadLogicalPartitionsInfo();
	this->ReadHardDisksInfo();
}

int DiskInfo::ReadHardDisksInfo() {
	this->DestroyListHardDisks();
	int drive = 0;
	HardDiskInfo *hardDiskInfo;
	for (drive; drive < MAX_IDE_DRIVES; drive++) {
		HANDLE hPhysicalDrive = 0;
		char driveName[256];
		sprintf_s(driveName, "\\\\.\\PhysicalDrive%d", drive);
		WCHAR name[256];
		MultiByteToWideChar(0, 0, driveName, 255, name, 256);
		
		hPhysicalDrive = CreateFile(name, 0, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, NULL);

		if (hPhysicalDrive != INVALID_HANDLE_VALUE) {
			
			STORAGE_PROPERTY_QUERY query;
			DWORD cbBytesReturned = 0;
			char buffer[10000];
			memset((void *)&query, 0, sizeof(query)); //gan tung ki tu = null
			query.PropertyId = StorageDeviceProperty;
			query.QueryType = PropertyStandardQuery;
			memset(buffer, 0, sizeof (buffer)); //gan tung ki tu = null

			if (DeviceIoControl(hPhysicalDrive, IOCTL_STORAGE_QUERY_PROPERTY, &query, sizeof(query), &buffer, sizeof(buffer), &cbBytesReturned, NULL)) {
				STORAGE_DEVICE_DESCRIPTOR* descrip = (STORAGE_DEVICE_DESCRIPTOR*) &buffer;
				char serialNumber[1000];
				char modelNumber[1000];
				char vendorId[1000];

				getString(buffer, descrip->VendorIdOffset, vendorId);
				getString(buffer, descrip->ProductIdOffset, modelNumber);
				getString(buffer, descrip->SerialNumberOffset, serialNumber);
				//Them mot doi tuong o cung vao danh sach voi cac thong tin mo ta
				hardDiskInfo = new HardDiskInfo;
				hardDiskInfo->setVendorId(string(vendorId));
				hardDiskInfo->setProductId(string(modelNumber));
				hardDiskInfo->setSerialNumber(string(serialNumber));
				hardDiskInfo->setBytePerSector(0);
				hardDiskInfo->setCylinders(0);
				hardDiskInfo->setDiskSize(0);
				hardDiskInfo->setTracksPerCylinder(0);
				hardDiskInfo->setSectorsPerTrack(0);
				hardDiskInfo->setDriverType(-1);
				listHardDiskInfo.push_back(hardDiskInfo);

				// Lay thong tin chi tiet cua o cung
				memset(buffer, 0, sizeof(buffer));
				if (DeviceIoControl(hPhysicalDrive,
					IOCTL_DISK_GET_DRIVE_GEOMETRY_EX,
					NULL,
					0,
					&buffer,
					sizeof(buffer),
					&cbBytesReturned,
					NULL))
				{
					//google xem struct DISK_GEOMETRY_EX
					DISK_GEOMETRY_EX* geom = (DISK_GEOMETRY_EX*)&buffer;
					int fixed = (geom->Geometry.MediaType == FixedMedia);
					__int64 size = geom->DiskSize.QuadPart;
					//Cap nhap thong tin chi tiet
					hardDiskInfo->setBytePerSector(geom->Geometry.BytesPerSector);
					hardDiskInfo->setDiskSize(geom->DiskSize.QuadPart);
					hardDiskInfo->setTracksPerCylinder(geom->Geometry.TracksPerCylinder);
					hardDiskInfo->setSectorsPerTrack(geom->Geometry.SectorsPerTrack);
					hardDiskInfo->setDriverType(geom->Geometry.MediaType);
					hardDiskInfo->setCylinders(geom->Geometry.Cylinders.QuadPart);
				}
			}
			CloseHandle(hPhysicalDrive);
		}
	}
	return drive;
}

int DiskInfo::ReadLogicalPartitionsInfo() {
	this->DestroyListLogicalPartitions();
	const int lenght = 255;
	char buffer[lenght + 1];
	WCHAR names[256];
	//Lay danh sach cac o dia logical
	::GetLogicalDriveStrings(lenght, names);
	//Convert WCHAR* to char*
	for (int i = 0; i < 256; i++){
		buffer[i] = names[i];
	}
	char *s = buffer;
	//Khoi tao danh sach cac o dia logical
	while (*s)
	{
		LogicalPartitionInfo *volumeInfo = new LogicalPartitionInfo;
		volumeInfo->setRootPathName(s);
		listLogicalPartitionInfo.push_back(volumeInfo);
		s += strlen(s) + 1;
	}
	//Lay thong tin chi tiet cua moi o dia logical
	WCHAR VolumeNameBuffer[256], FileSystemBuffer[256];
	for (unsigned int i = 0; i < listLogicalPartitionInfo.size(); i++)
	{
		memset(VolumeNameBuffer, 0, 256 * sizeof(WCHAR));
		memset(FileSystemBuffer, 0, 256 * sizeof(WCHAR));
		unsigned long bytesPerSector = 0;
		unsigned long sectorsPerCluster = 0;
		unsigned long numberOfFreeClusters = 0;
		unsigned long totalNumberOfClusters = 0;
		unsigned long volumeSerialNumber = 0;
		unsigned long maximumComponentLength = 0;
		unsigned long fileSystemFlags = 0;
		int driverType;

		WCHAR rootPath[5];
		MultiByteToWideChar(0, 0, listLogicalPartitionInfo[i]->getRootPathName().data(), 5, rootPath, 5);

		driverType = ::GetDriveType((LPCWSTR)rootPath);
		//Google xem GetDiskFreeSpace
		::GetDiskFreeSpace(
			(LPCWSTR)rootPath,
			&sectorsPerCluster,
			&bytesPerSector,
			&numberOfFreeClusters,
			&totalNumberOfClusters
			);
		//Google xem VolumeInfomation
		::GetVolumeInformation(
			(LPCWSTR)rootPath,
			(LPWSTR)VolumeNameBuffer,
			256,
			&volumeSerialNumber,
			&maximumComponentLength,
			&fileSystemFlags,
			(LPWSTR)FileSystemBuffer,
			256
			);
		//Convert WCHAR * to char *
		char volumName[256], fileSystem[256];
		for (int i = 0; i < 256; i++){
			volumName[i] = VolumeNameBuffer[i];
			fileSystem[i] = FileSystemBuffer[i];
		}
		listLogicalPartitionInfo[i]->setType(driverType);
		listLogicalPartitionInfo[i]->setNumberOfFreeClusters(numberOfFreeClusters);
		listLogicalPartitionInfo[i]->setSectorsPerCluster(sectorsPerCluster);
		listLogicalPartitionInfo[i]->setTotalNumberOfClusters(totalNumberOfClusters);
		listLogicalPartitionInfo[i]->setVolumeSerialNumber(volumeSerialNumber);
		listLogicalPartitionInfo[i]->setVolumeName(string(volumName));
		listLogicalPartitionInfo[i]->setFileSystemName(string(fileSystem));
		listLogicalPartitionInfo[i]->setSize(bytesPerSector * sectorsPerCluster * (long long)totalNumberOfClusters);

	}
	return this->listLogicalPartitionInfo.size();

}

char* DiskInfo::getString(const char * str, int pos, char * buf) {
	buf[0] = 0;
	if (pos <= 0)
		return buf;

	int i = pos;
	int j = 1;
	int k = 0;
	//Tach xau
	while (j && str[i] != 0)
	{
		char c = str[i];
		if (!isprint(c))
		{
			j = 0;
			break;
		}
		buf[k] = c;
		++k;
		++i;
	}

	// Neu khong co ky tu nao in duoc
	if (!j)
		k = 0;

	buf[k] = 0;

	// Trim: Loai bo khoang trang dau va cuoi xau    
	while (isspace(buf[0]) && buf[0] != 0)
	{
		i = 0;
		while (buf[i] != 0)
		{
			buf[i] = buf[i + 1];
			i++;
		}
	}
	if (strlen((buf)) > 1)
	while (isspace(buf[strlen(buf) - 1]))
	{
		buf[strlen(buf) - 1] = 0;
	}

	return buf;

}

void DiskInfo::DestroyListLogicalPartitions()
{
	while (!listLogicalPartitionInfo.empty())
	{
		delete listLogicalPartitionInfo.back();
		listLogicalPartitionInfo.pop_back();
	}
}

void DiskInfo::DestroyListHardDisks()
{
	while (!listHardDiskInfo.empty())
	{
		delete listHardDiskInfo.back();
		listHardDiskInfo.pop_back();
	}
}

void DiskInfo::DestroyAll()
{
	this->DestroyListHardDisks();
	this->DestroyListLogicalPartitions();
}

DiskInfo::~DiskInfo()
{
	this->DestroyAll();
}

ListHardDiskInfo DiskInfo::getHDisks()
{
	return this->listHardDiskInfo;
}

ListLogicalPartitionInfo DiskInfo::getPartitions()
{
	return this->listLogicalPartitionInfo;
}
