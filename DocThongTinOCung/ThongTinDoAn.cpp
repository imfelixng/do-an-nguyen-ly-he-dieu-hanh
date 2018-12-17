// ThongTinDoAn.cpp : implementation file
//

#include "stdafx.h"
#include "DocThongTinOCung.h"
#include "ThongTinDoAn.h"
#include "afxdialogex.h"


// ThongTinDoAn dialog

IMPLEMENT_DYNAMIC(ThongTinDoAn, CDialogEx)

ThongTinDoAn::ThongTinDoAn(CWnd* pParent /*=NULL*/)
	: CDialogEx(ThongTinDoAn::IDD, pParent)
	, dlg_tt_doan_(0)
{

}

ThongTinDoAn::~ThongTinDoAn()
{
}

void ThongTinDoAn::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(ThongTinDoAn, CDialogEx)
END_MESSAGE_MAP()


// ThongTinDoAn message handlers
