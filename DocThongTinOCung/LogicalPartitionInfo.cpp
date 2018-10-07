#include "stdafx.h"
#include "LogicalPartitionInfo.h"


LogicalPartitionInfo::LogicalPartitionInfo()
{
	
}


LogicalPartitionInfo::~LogicalPartitionInfo()
{
}

string LogicalPartitionInfo::getRootPathName() {
	return rootPathName;
}
string LogicalPartitionInfo::getVolumeName() {
	return volumeName;
}
string LogicalPartitionInfo::getFileSystemName() {
	return fileSystemName;
}
unsigned long LogicalPartitionInfo::getSectorsPerCluster() {
	return sectorsPerCluster;
}
unsigned long LogicalPartitionInfo::getNumberOfFreeClusters() {
	return numberOfFreeClusters;
}
unsigned long LogicalPartitionInfo::getTotalNumberOfClusters() {
	return totalNumberOfClusters;
}
unsigned long LogicalPartitionInfo::getVolumeSerialNumber() {
	return volumeSerialNumber;
}
long long LogicalPartitionInfo::getSize() {
	return size;
}
int LogicalPartitionInfo::getType() {
	return type;
}

void LogicalPartitionInfo::setRootPathName(string mrootPathName) {
	rootPathName = mrootPathName;
}
void LogicalPartitionInfo::setVolumeName(string mvolumeName) {
	volumeName = mvolumeName;
}
void LogicalPartitionInfo::setFileSystemName(string mfileSystemName) {
	fileSystemName = mfileSystemName;
}
void LogicalPartitionInfo::setSectorsPerCluster(unsigned long msectorsPerCluster) {
	sectorsPerCluster = msectorsPerCluster;
}
void LogicalPartitionInfo::setNumberOfFreeClusters(unsigned long mnumberOfFreeClusters) {
	numberOfFreeClusters = mnumberOfFreeClusters;
}
void LogicalPartitionInfo::setTotalNumberOfClusters(unsigned long mtotalNumberOfClusters) {
	totalNumberOfClusters = mtotalNumberOfClusters;
}
void LogicalPartitionInfo::setVolumeSerialNumber(unsigned long mvolumeSerialNumber) {
	volumeSerialNumber = mvolumeSerialNumber;
}
void LogicalPartitionInfo::setSize(long long msize) {
	size = msize;
}
void LogicalPartitionInfo::setType(int mtype) {
	type = mtype;
}