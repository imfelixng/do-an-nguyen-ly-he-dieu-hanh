#pragma once


// ThongTinDoAn dialog

class ThongTinDoAn : public CDialogEx
{
	DECLARE_DYNAMIC(ThongTinDoAn)

public:
	ThongTinDoAn(CWnd* pParent = NULL);   // standard constructor
	virtual ~ThongTinDoAn();

// Dialog Data
	enum { IDD = IDD_DLG_ABOUT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
	int dlg_tt_doan_;
};
