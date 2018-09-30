#pragma once


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

	DECLARE_MESSAGE_MAP()
};
