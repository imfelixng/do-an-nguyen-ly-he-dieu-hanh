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
	LogicalPartitionInfo();
	~LogicalPartitionInfo();
};

