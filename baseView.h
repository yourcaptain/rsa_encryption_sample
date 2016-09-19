// baseView.h : interface of the CBaseView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_BASEVIEW_H__FE5B55F7_2799_4E08_8C74_660C333B4DB5__INCLUDED_)
#define AFX_BASEVIEW_H__FE5B55F7_2799_4E08_8C74_660C333B4DB5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <string>//Ôö¼Ó
//#include <qstring>//QString


class CBaseView : public CView
{
protected: // create from serialization only
	CBaseView();
	DECLARE_DYNCREATE(CBaseView)

// Attributes
public:
	CBaseDoc* GetDocument();

//	QString global_strPublicKey ;
//	static const char rnd_seed[] = "string to make the random number generator think it has entropy";



//	std::string base64_encode(unsigned char const* , unsigned int len);
//	std::string base64_encode(unsigned char const* bytes_to_encode, unsigned int in_len) 
//
//	std::string base64_decode(std::string const& s);
//	std::string base64_decode(std::string const& encoded_string) 

	std::string EncodeRSAKeyFile(std::string const& strPemFileName, std::string const& strData);
	std::string EncodeRSAKeyMemory(std::string const& strData);
	std::string DecodeRSAKeyFile(std::string const& strPemFileName, std::string const& strData);
	std::string DecodeRSAKeyMemory(std::string const& strData);
//	std::string EncodeRSAKeyFile( const std::string& strPemFileName, const std::string& strData );
//	std::string DecodeRSAKeyFile( const std::string& strPemFileName, const std::string& strData );
// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBaseView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CBaseView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CBaseView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in baseView.cpp
inline CBaseDoc* CBaseView::GetDocument()
   { return (CBaseDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BASEVIEW_H__FE5B55F7_2799_4E08_8C74_660C333B4DB5__INCLUDED_)
