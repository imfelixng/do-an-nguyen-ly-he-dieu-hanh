// DlgTTPhanVung.cpp : implementation file
//

#include "stdafx.h"
#include "DocThongTinOCung.h"
#include "DlgTTPhanVung.h"
#include "afxdialogex.h"

// DlgTTPhanVung dialog

IMPLEMENT_DYNAMIC(DlgTTPhanVung, CDialogEx)

DlgTTPhanVung::DlgTTPhanVung(CWnd* pParent /*=NULL*/)
	: CDialogEx(DlgTTPhanVung::IDD, pParent)
{

}

DlgTTPhanVung::~DlgTTPhanVung()
{
}

void DlgTTPhanVung::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDT_TENPHANVUNG, edt_tenphanvung_);
	DDX_Control(pDX, IDC_EDT_THUMUCGOC, edt_thumucgoc_);
	DDX_Control(pDX, IDC_EDT_DINHDANG, edt_dinhdang_);
	DDX_Control(pDX, IDC_EDT_LOAI, edt_loai_);
	DDX_Control(pDX, IDC_EDT_SOSECTORTRENCLUSTER, edt_sosectortrencluster);
	DDX_Control(pDX, IDC_EDT_TONGSOCLUSTER, edt_tongsocluster_);
	DDX_Control(pDX, IDC_EDT_DUNGLUONGDADUNG, edt_dungluongdadung_);
	DDX_Control(pDX, IDC_EDT_DUNGLUONGCONLAI, edt_dungluongconlai_);
	DDX_Control(pDX, IDC_EDT_TONGDUNGLUONG, edt_tongdungluong_);
	DDX_Control(pDX, IDC_CB_PHANVUNG, cb_phanvung_);
}

std::wstring ConvertStringToLPCWSTR(string s) {
	return std::wstring(s.begin(), s.end());
}

void DlgTTPhanVung::HienThiLenForm(ListLogicalPartitionInfo listLogicalPartitionInfo, int i) {
	LogicalPartitionInfo* partiton = listLogicalPartitionInfo[i];

	string tenphanvung = listLogicalPartitionInfo[i]->getVolumeName();
	edt_tenphanvung_.SetWindowTextW(ConvertStringToLPCWSTR(tenphanvung).c_str());

	string dinhdang = listLogicalPartitionInfo[0]->getFileSystemName();
	edt_dinhdang_.SetWindowTextW(ConvertStringToLPCWSTR(dinhdang).c_str());

	unsigned long loai = listLogicalPartitionInfo[i]->getType();
	edt_loai_.SetWindowTextW(ConvertStringToLPCWSTR(std::to_string(loai)).c_str());

	unsigned long sosectortrencluster = listLogicalPartitionInfo[i]->getSectorsPerCluster();
	edt_sosectortrencluster.SetWindowTextW(ConvertStringToLPCWSTR(std::to_string(sosectortrencluster)).c_str());

	unsigned long tongsocluster = listLogicalPartitionInfo[i]->getTotalNumberOfClusters();
	edt_tongsocluster_.SetWindowTextW(ConvertStringToLPCWSTR(std::to_string(tongsocluster)).c_str());


	unsigned long soclusterconlai = listLogicalPartitionInfo[i]->getNumberOfFreeClusters();
	unsigned long sobytetrensector = listLogicalPartitionInfo[i]->getBytesPerSector();
	unsigned long dungluongconlai = (soclusterconlai / 1024) * (sosectortrencluster * sobytetrensector / 1024) / 1024;
	edt_dungluongconlai_.SetWindowTextW(ConvertStringToLPCWSTR(std::to_string(dungluongconlai) + " GB").c_str());

	unsigned long tongdungluong = (tongsocluster / 1024) * (sosectortrencluster * sobytetrensector / 1024) / 1024;
	edt_tongdungluong_.SetWindowTextW(ConvertStringToLPCWSTR(std::to_string(tongdungluong) + " GB").c_str());

	unsigned long dungluongdadung = tongdungluong - dungluongconlai;
	edt_dungluongdadung_.SetWindowTextW(ConvertStringToLPCWSTR(std::to_string(dungluongdadung) + " GB").c_str());

}

void DlgTTPhanVung::HienThi() {
	DiskInfo diskInfo;
	vector<LogicalPartitionInfo *> listLogicalPartitionInfo = diskInfo.getPartitions();
	int length = listLogicalPartitionInfo.size();
	for (int i = 0; i < length; i++) {
		string partition_name = listLogicalPartitionInfo[i]->getRootPathName();

		cb_phanvung_.AddString(ConvertStringToLPCWSTR(partition_name).c_str());
		
	}

	cb_phanvung_.SetCurSel(0);

	int idx = cb_phanvung_.GetCurSel();
	CString thumucgoc_name_edt;

	cb_phanvung_.GetLBText(idx, thumucgoc_name_edt);
	edt_thumucgoc_.SetWindowTextW(thumucgoc_name_edt);

	HienThiLenForm(listLogicalPartitionInfo, 0);
	



}



BEGIN_MESSAGE_MAP(DlgTTPhanVung, CDialogEx)
	ON_CBN_SELCHANGE(IDC_CB_PHANVUNG, &DlgTTPhanVung::OnCbnSelchangeCbPhanvung)
END_MESSAGE_MAP()


// DlgTTPhanVung message handlers


void DlgTTPhanVung::OnCbnSelchangeCbPhanvung()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	
	DiskInfo diskInfo;
	vector<LogicalPartitionInfo *> listLogicalPartitionInfo = diskInfo.getPartitions();

	int idx = cb_phanvung_.GetCurSel();
	CString thumucgoc_name_edt;

	cb_phanvung_.GetLBText(idx, thumucgoc_name_edt);
	edt_thumucgoc_.SetWindowTextW(thumucgoc_name_edt);

	int length = listLogicalPartitionInfo.size();
	for (int i = 0; i < length; i++) {
		if (i == idx) {
			HienThiLenForm(listLogicalPartitionInfo, idx);
		}

	}

	UpdateData(FALSE);
}
