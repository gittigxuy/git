
// MFC_lesson4.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CMFC_lesson4App:
// See MFC_lesson4.cpp for the implementation of this class
//

class CMFC_lesson4App : public CWinApp
{
public:
	CMFC_lesson4App();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CMFC_lesson4App theApp;