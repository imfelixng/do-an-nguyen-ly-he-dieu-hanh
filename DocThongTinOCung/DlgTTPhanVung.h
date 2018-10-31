#pragma once
#include "afxwin.h"
#include "DiskInfo.h"
#include <iostream>

// DlgTTPhanVung dialog

class DlgTTPhanVung : public CDialogEx
{
	DECLARE_DYNAMIC(DlgTTPhanVung)

public:
	DlgTTPhanVung(CWnd* pParent = NULL);   // standard constructor
	virtual ~DlgTTPhanVung();

// Dialog Data
	enum { IDD = IDD_DLG_TT_PHANVUNG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
	CEdit edt_tenphanvung_;
	CEdit edt_thumucgoc_;
	CEdit edt_dinhdang_;
	CEdit edt_loai_;
	CEdit edt_sosectortrencluster;
	CEdit edt_tongsocluster_;
	CEdit edt_dungluongdadung_;
	CEdit edt_dungluongconlai_;
	CEdit edt_tongdungluong_;
	CComboBox cb_phanvung_;


public:
	void HienThi();
	void HienThiLenForm(ListLogicalPartitionInfo , int);
	afx_msg void OnCbnSelchangeCbPhanvung();
};
