// baseDoc.h : interface of the CBaseDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_BASEDOC_H__4738508C_97AA_4F9B_A964_72FFAD21A2F3__INCLUDED_)
#define AFX_BASEDOC_H__4738508C_97AA_4F9B_A964_72FFAD21A2F3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CBaseDoc : public CDocument
{
protected: // create from serialization only
	CBaseDoc();
	DECLARE_DYNCREATE(CBaseDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBaseDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CBaseDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CBaseDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BASEDOC_H__4738508C_97AA_4F9B_A964_72FFAD21A2F3__INCLUDED_)
