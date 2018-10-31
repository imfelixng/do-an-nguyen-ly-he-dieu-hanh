#pragma once
#include "afxwin.h"
#include "DiskInfo.h"

// DlgTTODia dialog

class DlgTTODia : public CDialogEx
{
	DECLARE_DYNAMIC(DlgTTODia)

public:
	DlgTTODia(CWnd* pParent = NULL);   // standard constructor
	virtual ~DlgTTODia();

// Dialog Data
	enum { IDD = IDD_DLG_TT_ODIA };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	CComboBox cb_odia_;
	CEdit edt_tennhasanxuat_;
	CEdit edt_masanpham_;
	CEdit edt_soserial_;
	CEdit edt_loaidia_;
	CEdit edt_sophanvung_;
	CEdit edt_sobytetrensector_;
	CEdit edt_sosectortrentrack_;
	CEdit edt_sotracktrencylinder_;
	CEdit edt_tongsocylinder_;
	CEdit edt_kichthuoc_;

	DECLARE_MESSAGE_MAP()
public:
	void HienThi();
	void HienThiLenForm(ListHardDiskInfo, int);
	afx_msg void OnCbnSelchangeCbOdia();
};
