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


BEGIN_MESSAGE_MAP(DlgTTPhanVung, CDialogEx)
END_MESSAGE_MAP()


// DlgTTPhanVung message handlers

