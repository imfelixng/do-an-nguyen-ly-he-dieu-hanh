
// DocThongTinOCungDlg.h : header file
//

#pragma once
#include "afxwin.h"
#include "afxcmn.h"
#include "DlgTTPhanVung.h";
#include "DlgTTODia.h";
#include "ThongTinDoAn.h";
// CDocThongTinOCungDlg dialog
class CDocThongTinOCungDlg : public CDialogEx
{
// Construction
public:
	CDocThongTinOCungDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_DOCTHONGTINOCUNG_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support

	afx_msg void CDocThongTinOCungDlg::OnSelChangeTab(NMHDR* pNMHDR, LRESULT* pResult);

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
	CButton btn_about_;
public:

protected:
	CTabCtrl tab_thongtin_;
	DlgTTPhanVung dlg_tt_phanvung_;
	DlgTTODia dlg_tt_odia_;
	ThongTinDoAn dlg_tt_doan_;
public:
	afx_msg void OnBnClickedBtnAbout();
};
