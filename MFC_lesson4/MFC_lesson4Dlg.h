
// MFC_lesson4Dlg.h : header file
//

#pragma once
#include "afxwin.h"


// CMFC_lesson4Dlg dialog
class CMFC_lesson4Dlg : public CDialogEx
{
// Construction
public:
	CMFC_lesson4Dlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_MFC_LESSON4_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	CString m_output;
	CString m_input;//添加两个edit对应的值之后生成的CString
//	afx_msg void OnEnChangeEditinput();
	afx_msg void OnChangeEditinput();
	CEdit m_output_control;
//	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnSize(UINT nType, int cx, int cy);
};
