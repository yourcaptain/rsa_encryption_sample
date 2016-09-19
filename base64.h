/*
#if !defined(AFX_BASE64_H__194C97EB_0019_4048_9AED_84118593BE53__INCLUDED_)
#define AFX_BASE64_H__194C97EB_0019_4048_9AED_84118593BE53__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// base64.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// base64 document

class base64 : public CDocument
{
protected:
	base64();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(base64)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(base64)
	public:
	virtual void Serialize(CArchive& ar);   // overridden for document i/o
	protected:
	virtual BOOL OnNewDocument();
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~base64();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
protected:
	//{{AFX_MSG(base64)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BASE64_H__194C97EB_0019_4048_9AED_84118593BE53__INCLUDED_)
*/
// base64.h: interface for the base64 class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_BASE64_H__753F7548_11A6_4376_A9FC_54EC087AC794__INCLUDED_)
#define AFX_BASE64_H__753F7548_11A6_4376_A9FC_54EC087AC794__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <string>

class base64  
{
public:
	base64();
	virtual ~base64();

	std::string base64_encode(unsigned char const* , unsigned int len);
	std::string base64_decode(std::string const& s);

};

#endif // !defined(AFX_BASE64_H__753F7548_11A6_4376_A9FC_54EC087AC794__INCLUDED_)
