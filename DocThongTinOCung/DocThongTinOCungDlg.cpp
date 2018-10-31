
// DocThongTinOCungDlg.cpp : implementation file
//

#include "stdafx.h"
#include "DocThongTinOCung.h"
#include "DocThongTinOCungDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CDocThongTinOCungDlg dialog



CDocThongTinOCungDlg::CDocThongTinOCungDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDocThongTinOCungDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CDocThongTinOCungDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BTN_ABOUT, btn_about_);
	DDX_Control(pDX, IDC_TAB_THONGTIN, tab_thongtin_);
}

BEGIN_MESSAGE_MAP(CDocThongTinOCungDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB_THONGTIN, CDocThongTinOCungDlg::OnSelChangeTab)
END_MESSAGE_MAP()


// CDocThongTinOCungDlg message handlers

BOOL CDocThongTinOCungDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	tab_thongtin_.InsertItem(0, _T("Thông Tin Phân Vùng"));
	tab_thongtin_.InsertItem(1, _T("Thông Tin Ổ Đĩa"));

	dlg_tt_phanvung_.Create(IDD_DLG_TT_PHANVUNG, this);
	dlg_tt_odia_.Create(IDD_DLG_TT_ODIA, this);

	dlg_tt_phanvung_.ShowWindow(SW_SHOW);
	dlg_tt_odia_.ShowWindow(SW_HIDE);

	dlg_tt_phanvung_.HienThi();
	dlg_tt_odia_.HienThi();

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CDocThongTinOCungDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CDocThongTinOCungDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CDocThongTinOCungDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CDocThongTinOCungDlg::OnSelChangeTab(NMHDR* pNMHDR, LRESULT* pResult) {
	int idx = tab_thongtin_.GetCurSel();

	if (idx == 0) {
		dlg_tt_phanvung_.ShowWindow(SW_SHOW);
		dlg_tt_odia_.ShowWindow(SW_HIDE);
	}
	else {
		dlg_tt_phanvung_.ShowWindow(SW_HIDE);
		dlg_tt_odia_.ShowWindow(SW_SHOW);
	}
}


