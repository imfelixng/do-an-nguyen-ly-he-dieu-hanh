#pragma once
#include <string>
using std::string;

class HardDiskInfo
{
private:
	string vendorId, productId, serialNumber;
	unsigned long bytePerSector, sectorsPerTrack, tracksPerCylinder;
	long long diskSize, cylinders;
	int driverType;

public:
	//get
	string getVendorId();
	string getProductId();
	string getSerialNumber();
	unsigned long getBytePerSector();
	unsigned long getSectorsPerTrack();
	unsigned long getTracksPerCylinder();
	long long getDiskSize();
	long long getCylinders();
	int getDriverType();
	//set
	void setVendorId(string);
	void setProductId(string);
	void setSerialNumber(string);
	void setBytePerSector(unsigned long);
	void setSectorsPerTrack(unsigned long);
	void setTracksPerCylinder(unsigned long);
	void setDiskSize(long long);
	void setCylinders(long long);
	void setDriverType(int);
	HardDiskInfo();
	~HardDiskInfo();
};

