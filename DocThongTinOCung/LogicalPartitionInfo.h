#pragma once
#include <string>
using std::string;

class LogicalPartitionInfo
{
private:
	string rootPathName, volumeName, fileSystemName;
	unsigned long sectorsPerCluster, numberOfFreeClusters, totalNumberOfClusters;
	unsigned long volumeSerialNumber;
	long long size;
	int type;

public:
	//get
	string getRootPathName();
	string getVolumeName();
	string getFileSystemName();
	unsigned long getSectorsPerCluster();
	unsigned long getNumberOfFreeClusters();
	unsigned long getTotalNumberOfClusters();
	unsigned long getVolumeSerialNumber();
	long long getSize();
	int getType();

	//set
	void setRootPathName(string);
	void setVolumeName(string);
	void setFileSystemName(string);
	void setSectorsPerCluster(unsigned long);
	void setNumberOfFreeClusters(unsigned long);
	void setTotalNumberOfClusters(unsigned long);
	void setVolumeSerialNumber(unsigned long);
	void setSize(long long);
	void setType(int);
	LogicalPartitionInfo();
	~LogicalPartitionInfo();
};

