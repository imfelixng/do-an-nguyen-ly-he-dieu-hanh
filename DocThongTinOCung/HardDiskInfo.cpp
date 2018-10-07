#include "stdafx.h"
#include "HardDiskInfo.h"


HardDiskInfo::HardDiskInfo()
{
}


HardDiskInfo::~HardDiskInfo()
{
}

//get
string HardDiskInfo::getVendorId() {
	return vendorId;
}
string HardDiskInfo::getProductId() {
	return productId;
}
string HardDiskInfo::getSerialNumber() {
	return serialNumber;
}
unsigned long HardDiskInfo::getBytePerSector() {
	return bytePerSector;
}
unsigned long HardDiskInfo::getSectorsPerTrack() {
	return sectorsPerTrack;
}
unsigned long HardDiskInfo::getTracksPerCylinder() {
	return tracksPerCylinder;
}
long long HardDiskInfo::getDiskSize() {
	return diskSize;
}
long long HardDiskInfo::getCylinders() {
	return cylinders;
}
int HardDiskInfo::getDriverType() {
	return driverType;
}
//set
void HardDiskInfo::setVendorId(string mvendorId) {
	vendorId = mvendorId;
}
void HardDiskInfo::setProductId(string mproductId) {
	productId = mproductId;
}
void HardDiskInfo::setSerialNumber(string mserialNumber) {
	serialNumber = mserialNumber;
}
void HardDiskInfo::setBytePerSector(unsigned long mbytePerSector) {
	bytePerSector = mbytePerSector;
}
void HardDiskInfo::setSectorsPerTrack(unsigned long msectorsPerTrack) {
	sectorsPerTrack = msectorsPerTrack;
}
void HardDiskInfo::setTracksPerCylinder(unsigned long mtracksPerCylinder) {
	tracksPerCylinder = mtracksPerCylinder;
}
void HardDiskInfo::setDiskSize(long long mdiskSize) {
	diskSize = mdiskSize;
}
void HardDiskInfo::setCylinders(long long mcylinders) {
	cylinders = mcylinders;
}
void HardDiskInfo::setDriverType(int mdriverType) {
	driverType = mdriverType;
}
