
// MFC_lesson4Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "MFC_lesson4.h"
#include "MFC_lesson4Dlg.h"
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


// CMFC_lesson4Dlg dialog



CMFC_lesson4Dlg::CMFC_lesson4Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMFC_lesson4Dlg::IDD, pParent)
	, m_output(_T(""))
	, m_input(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFC_lesson4Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIToutput, m_output);//由于生成了关于EDIT控件的两个变量，从而生成了这两个函数
	DDX_Text(pDX, IDC_EDITinput, m_input);
	DDX_Control(pDX, IDC_EDIToutput, m_output_control);
}

BEGIN_MESSAGE_MAP(CMFC_lesson4Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_OK, &CMFC_lesson4Dlg::OnBnClickedOk)
//	ON_EN_CHANGE(IDC_EDITinput, &CMFC_lesson4Dlg::OnEnChangeEditinput)
ON_EN_CHANGE(IDC_EDITinput, &CMFC_lesson4Dlg::OnChangeEditinput)
//ON_WM_SIZE()
ON_WM_SIZE()
END_MESSAGE_MAP()


// CMFC_lesson4Dlg message handlers

BOOL CMFC_lesson4Dlg::OnInitDialog()
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

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMFC_lesson4Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMFC_lesson4Dlg::OnPaint()
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
HCURSOR CMFC_lesson4Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFC_lesson4Dlg::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	MessageBox(L"MFC test", L"Title");
}


//void CMFC_lesson4Dlg::OnEnChangeEditinput()
//{
//	// TODO:  If this is a RICHEDIT control, the control will not
//	// send this notification unless you override the CDialogEx::OnInitDialog()
//	// function and call CRichEditCtrl().SetEventMask()
//	// with the ENM_CHANGE flag ORed into the mask.
//
//	// TODO:  Add your control notification handler code here
//}


void CMFC_lesson4Dlg::OnChangeEditinput()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here

	UpdateData(TRUE);//更新成员变量里面的数据
	m_output = m_input;
	UpdateData(FALSE);//更新成员变量的值到窗口中
}


//void CMFC_lesson4Dlg::OnSize(UINT nType, int cx, int cy)
//{
//	CDialogEx::OnSize(nType, cx, cy);
//
//	// TODO: Add your message handler code here
//}


void CMFC_lesson4Dlg::OnSize(UINT nType, int cx, int cy)
{
	CDialogEx::OnSize(nType, cx, cy);

	// TODO: Add your message handler code here
	MessageBox(L"hello", L"MFC_TEST");
}
