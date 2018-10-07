#pragma once
#include <vector>
#include <string>
#include "LogicalPartitionInfo.h"
#include "HardDiskInfo.h"
using std::vector;
using std::string;
typedef vector<LogicalPartitionInfo *> ListLogicalPartitionInfo;
typedef vector<HardDiskInfo *> ListHardDiskInfo;

class DiskInfo
{
private:
	ListLogicalPartitionInfo listLogicalPartitionInfo;
	ListHardDiskInfo listHardDiskInfo;
	char* getString(const char * , int , char * );
	void DestroyListLogicalPartitions();
	void DestroyListHardDisks();
public:
	int ReadHardDisksInfo();
	int ReadLogicalPartitionsInfo();
	void DestroyAll();
	ListHardDiskInfo getHDisks();
	ListLogicalPartitionInfo getPartitions();
	DiskInfo();
	virtual ~DiskInfo();
};


