// DlgTTODia.cpp : implementation file
//

#include "stdafx.h"
#include "DocThongTinOCung.h"
#include "DlgTTODia.h"
#include "afxdialogex.h"


// DlgTTODia dialog

IMPLEMENT_DYNAMIC(DlgTTODia, CDialogEx)

DlgTTODia::DlgTTODia(CWnd* pParent /*=NULL*/)
	: CDialogEx(DlgTTODia::IDD, pParent)
{

}

DlgTTODia::~DlgTTODia()
{
}

void DlgTTODia::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_CB_ODIA, cb_odia_);
	DDX_Control(pDX, IDC_EDT_TENNHASANXUAT, edt_tennhasanxuat_);
	DDX_Control(pDX, IDC_EDT_MASANPHAM, edt_masanpham_);
	DDX_Control(pDX, IDC_EDT_SOSERIAL, edt_soserial_);
	DDX_Control(pDX, IDC_EDT_LOAIDIA, edt_loaidia_);
	DDX_Control(pDX, IDC_EDT_SOPHANVUNG, edt_sophanvung_);
	DDX_Control(pDX, IDC_EDT_SOBYTETRENSECTOR, edt_sobytetrensector_);
	DDX_Control(pDX, IDC_EDT_SOSECTORTRENTRACK, edt_sosectortrentrack_);
	DDX_Control(pDX, IDC_EDT_SOTRACKTRENCYLINDER, edt_sotracktrencylinder_);
	DDX_Control(pDX, IDC_EDT_TONGSOCYLINDER, edt_tongsocylinder_);
	DDX_Control(pDX, IDC_EDT_KICHTHUOC, edt_kichthuoc_);
}


BEGIN_MESSAGE_MAP(DlgTTODia, CDialogEx)
	ON_CBN_SELCHANGE(IDC_CB_ODIA, &DlgTTODia::OnCbnSelchangeCbOdia)
END_MESSAGE_MAP()


// DlgTTODia message handlers

std::wstring ConvertStringToLPCWSTR_ODIA(string s) {
	return std::wstring(s.begin(), s.end());
}

void DlgTTODia::HienThiLenForm(ListHardDiskInfo listHardDiskInfo, int i) {
	HardDiskInfo* hardDisk = listHardDiskInfo[i];

	string tennhasanxuat = hardDisk->getVendorId();
	edt_tennhasanxuat_.SetWindowTextW(ConvertStringToLPCWSTR_ODIA(tennhasanxuat).c_str());

	string masanpham = hardDisk->getProductId();
	edt_masanpham_.SetWindowTextW(ConvertStringToLPCWSTR_ODIA(masanpham).c_str());

	string soserial = hardDisk -> getSerialNumber();
	edt_soserial_.SetWindowTextW(ConvertStringToLPCWSTR_ODIA(soserial).c_str());

	unsigned long loaidia = hardDisk->getDriverType();
	edt_loaidia_.SetWindowTextW(ConvertStringToLPCWSTR_ODIA(std::to_string(loaidia)).c_str());

	unsigned long edt_sophanvung_;


	unsigned long sobytetrensector = hardDisk->getBytePerSector();
	edt_sobytetrensector_.SetWindowTextW(ConvertStringToLPCWSTR_ODIA(std::to_string(sobytetrensector) + " Byte").c_str());

	unsigned long sosectortrentrack = hardDisk->getSectorsPerTrack();
	edt_sosectortrentrack_.SetWindowTextW(ConvertStringToLPCWSTR_ODIA(std::to_string(sosectortrentrack)).c_str());

	unsigned long sotracktrencylinder = hardDisk->getTracksPerCylinder();
	edt_sotracktrencylinder_.SetWindowTextW(ConvertStringToLPCWSTR_ODIA(std::to_string(sotracktrencylinder)).c_str());

	unsigned long tongsocylinder = hardDisk->getCylinders();
	edt_tongsocylinder_.SetWindowTextW(ConvertStringToLPCWSTR_ODIA(std::to_string(tongsocylinder)).c_str());

	unsigned long long disksize = hardDisk->getDiskSize();
	unsigned long long kichthuoc = (disksize / 1024) / 1024 / 1024;
	edt_kichthuoc_.SetWindowTextW(ConvertStringToLPCWSTR_ODIA(std::to_string(kichthuoc) + " GB").c_str());
}

void DlgTTODia::HienThi() {
	DiskInfo diskInfo;
	vector<HardDiskInfo *> listHardDiskInfo = diskInfo.getHDisks();
	int length = listHardDiskInfo.size();
	for (int i = 0; i < length; i++) {
		string harddisk_name = listHardDiskInfo[i]->getProductId();
		cb_odia_.AddString(ConvertStringToLPCWSTR_ODIA(harddisk_name).c_str());
	}

	cb_odia_.SetCurSel(0);

	HienThiLenForm(listHardDiskInfo, 0);
}


void DlgTTODia::OnCbnSelchangeCbOdia()
{
	UpdateData(TRUE);

	DiskInfo diskInfo;
	vector<HardDiskInfo *> listHardDiskInfo = diskInfo.getHDisks();

	int idx = cb_odia_.GetCurSel();

	int length = listHardDiskInfo.size();
	for (int i = 0; i < length; i++) {
		if (i == idx) {
			HienThiLenForm(listHardDiskInfo, idx);
		}

	}

	UpdateData(FALSE);
}
