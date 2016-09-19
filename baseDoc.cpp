// baseDoc.cpp : implementation of the CBaseDoc class
//

#include "stdafx.h"
#include "base.h"

#include "baseDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CBaseDoc

IMPLEMENT_DYNCREATE(CBaseDoc, CDocument)

BEGIN_MESSAGE_MAP(CBaseDoc, CDocument)
	//{{AFX_MSG_MAP(CBaseDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBaseDoc construction/destruction

CBaseDoc::CBaseDoc()
{
	// TODO: add one-time construction code here

}

CBaseDoc::~CBaseDoc()
{
}

BOOL CBaseDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CBaseDoc serialization

void CBaseDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CBaseDoc diagnostics

#ifdef _DEBUG
void CBaseDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CBaseDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CBaseDoc commands
