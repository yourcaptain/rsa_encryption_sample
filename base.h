// base.h : main header file for the BASE application
//

#if !defined(AFX_BASE_H__23BF5326_30E2_47BE_906C_4F4138B259E5__INCLUDED_)
#define AFX_BASE_H__23BF5326_30E2_47BE_906C_4F4138B259E5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CBaseApp:
// See base.cpp for the implementation of this class
//

class CBaseApp : public CWinApp
{
public:
	CBaseApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBaseApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CBaseApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BASE_H__23BF5326_30E2_47BE_906C_4F4138B259E5__INCLUDED_)
