// baseView.cpp : implementation of the CBaseView class
//

#include "stdafx.h"
#include "base.h"

#include "baseDoc.h"
#include "baseView.h"



//#include "stdafx.h"
#include <string>
#include <iostream>
#include "base64.h"





#include <openssl/rsa.h>
#include <openssl/err.h>
#include <openssl/pem.h>
#include <iostream>
#include <string>
#include <cstring>
#include <cassert>
//#include <QString.h>//QString

using namespace std;


//	QString global_strPublicKey ;
//	static const char rnd_seed[] = "string to make the random number generator think it has entropy";




#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CBaseView

IMPLEMENT_DYNCREATE(CBaseView, CView)

BEGIN_MESSAGE_MAP(CBaseView, CView)
	//{{AFX_MSG_MAP(CBaseView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBaseView construction/destruction

CBaseView::CBaseView()
{
	// TODO: add construction code here

}

CBaseView::~CBaseView()
{
}

BOOL CBaseView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CBaseView drawing

void CBaseView::OnDraw(CDC* pDC)
{
	CBaseDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

		pDC->SetTextColor( RGB(0,0,0) ); 
	

		CPen pen(PS_SOLID,1,RGB(255,0,0));//RGB(152,251,152)
		CPen *pOldPen=NULL;
		CFont* pOldFont=NULL;

			pOldPen=pDC->SelectObject(&pen); 
		//
		int        nHeight,nWeight;
		CString    outputLine, str;
		CFont      font;
		TEXTMETRIC tm;


			font.CreateFont( 10,                        // nHeight 
			0,                        // nWidth 
			0,                        // nEscapement 
			0,                        // nOrientation 
			FW_NORMAL,                // nWeight 
			FALSE,                    // bItalic 
			FALSE,                    // bUnderline 
			0,                        // cStrikeOut 
			ANSI_CHARSET,              // nCharSet 
			OUT_DEFAULT_PRECIS,        // nOutPrecision 
			CLIP_DEFAULT_PRECIS,      // nClipPrecision 
			DEFAULT_QUALITY,          // nQuality 
			DEFAULT_PITCH | FF_SWISS, 
			"Arial"                    // nPitchAndFamily 
			);            

			pOldFont = pDC->SelectObject(&font);
			pDC->GetTextMetrics(&tm);
			nHeight = tm.tmHeight + tm.tmExternalLeading;
			nWeight=tm.tmWeight ;	


	pOldFont = pDC->SelectObject(&font);
	pDC->SetBkMode(TRANSPARENT);//͸��
								


	CString strMfc="ADP GmbH\nAnalyse Design & Programmierung\nGesellschaft mit beschr?nkter Haftung �й�����" ;
	std::string s;
	s=strMfc.GetBuffer(0);

//	const std::string s = "ADP GmbH\nAnalyse Design & Programmierung\nGesellschaft mit beschr?nkter Haftung �й�����" ;

	base64 b64;

	//base64
	std::string encoded = b64.base64_encode(reinterpret_cast<const unsigned char*>(s.c_str()), s.length());
	//��base64����ԭ��
	std::string decoded = b64.base64_decode(encoded);


	CString tempstr_encoded;
	tempstr_encoded=encoded.c_str();

	CString tempstr_decoded;
	tempstr_decoded=decoded.c_str();

	//base64
	pDC->SetTextAlign(TA_LEFT+TA_BOTTOM);//
	pDC->TextOut ( 300,100 , "base64:"+tempstr_encoded );

	//��base64����ԭ��
	pDC->SetTextAlign(TA_LEFT+TA_BOTTOM);//
	pDC->TextOut ( 300,150 , "��base64����ԭ��:"+tempstr_decoded );
  
    //���ģ����������ݣ�  
	//�Ի�õ�base64����RSA����
    //string two = EncodeRSAKeyFile("pubkey.pem", encoded);  
	//Ԭ�����Ϊ�����·���
	string two = EncodeRSAKeyMemory(encoded);  

	CString tempstr_two;
	tempstr_two=two.c_str();

	//RSA���ܺ��base64
	pDC->SetTextAlign(TA_LEFT+TA_BOTTOM);//
	pDC->TextOut ( 300,200 , "RSA���ܺ��base64:"+tempstr_two );

    //˳���Ļ������ܺ�����ֺ�ԭ����һ�µ�  
	//RSA���ܺ��base64
    //string three = DecodeRSAKeyFile("prikey.pem", two); 
	//Ԭ�����Ϊ�����·���
	string three = DecodeRSAKeyMemory(two);
 	CString tempstr_three;
	tempstr_three=three.c_str();

	//RSA���ܺ��base64
	pDC->SetTextAlign(TA_LEFT+TA_BOTTOM);//
	pDC->TextOut ( 300,250 , "RSA���ܺ��base64:"+tempstr_three );


	//��base64����ԭ��
	std::string decoded_three = b64.base64_decode(three);

	CString tempstr_encoded_three;
	tempstr_encoded_three = decoded_three.c_str();

	pDC->SetTextAlign(TA_LEFT+TA_BOTTOM);//
	pDC->TextOut ( 300,300 , "��base64����ԭ��:" + tempstr_encoded_three );
	pDC->SelectObject(pOldFont);


	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CBaseView printing

BOOL CBaseView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CBaseView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CBaseView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}





//����  ��Կ
std::string CBaseView::EncodeRSAKeyFile( const std::string& strPemFileName, const std::string& strData )  
{  
 
    if (strPemFileName.empty() || strData.empty())  
    {  
        assert(false);  
        return "";  
    }  
    FILE* hPubKeyFile = fopen(strPemFileName.c_str(), "rb");  
    if( hPubKeyFile == NULL )  
    {  
        //assert(false);  
        //return "";   
    }  
    std::string strRet;  
    RSA* pRSAPublicKey = RSA_new();  


    if(PEM_read_RSA_PUBKEY(hPubKeyFile, &pRSAPublicKey, 0, 0) == NULL)  
    {  
        assert(false);  
        return "";  
    }  



    int nLen = RSA_size(pRSAPublicKey); 
	
    char* pEncode = new char[nLen + 1];  
    int ret = RSA_public_encrypt(strData.length(), (const unsigned char*)strData.c_str(), (unsigned char*)pEncode, pRSAPublicKey, RSA_PKCS1_PADDING);  
    if (ret >= 0)  
    {  
        strRet = std::string(pEncode, ret);  
    }  
    delete[] pEncode;  
    RSA_free(pRSAPublicKey);  
    fclose(hPubKeyFile);  
    CRYPTO_cleanup_all_ex_data();   
    return strRet;  


	

    return strRet;  
}  
  
//����  
std::string CBaseView::DecodeRSAKeyFile( const std::string& strPemFileName, const std::string& strData )  
{  
    if (strPemFileName.empty() || strData.empty())  
    {  
        assert(false);  
        return "";  
    }  
    FILE* hPriKeyFile = fopen(strPemFileName.c_str(),"rb");  
    if( hPriKeyFile == NULL )  
    {  
        assert(false);  
        return "";  
    }  
    std::string strRet;  
    RSA* pRSAPriKey = RSA_new();  
    if(PEM_read_RSAPrivateKey(hPriKeyFile, &pRSAPriKey, 0, 0) == NULL)  
    {  
        assert(false);  
        return "";  
    }  
    int nLen = RSA_size(pRSAPriKey);  
    char* pDecode = new char[nLen+1];  
  
    int ret = RSA_private_decrypt(strData.length(), (const unsigned char*)strData.c_str(), (unsigned char*)pDecode, pRSAPriKey, RSA_PKCS1_PADDING);  
    if(ret >= 0)  
    {  
        strRet = std::string((char*)pDecode, ret);  
    }  
    delete [] pDecode;  
    RSA_free(pRSAPriKey);  
    fclose(hPriKeyFile);  
    CRYPTO_cleanup_all_ex_data();   

    return strRet;  
}  


//Ԭ���������˷�����EncodeRSAKeyMemory
//����  ��Կ ���ڴ��ȡ
std::string CBaseView::EncodeRSAKeyMemory(const std::string& strData )  
{  
	//Ԭ�������Ӳ��� ��ʼ
	char pem_key_buffer[] = "-----BEGIN PUBLIC KEY-----\nMIGfMA0GCSqGSIb3DQEBAQUAA4GNADCBiQKBgQCnsx4diMfrmTbos85nk+64HnSs\n8Osp5mjxara/I7tOSe9HhW3gxtPENMBoi36Eh1dGE12lm1g0fbwDgdxFIDnjWoZ4\n6MFKT3fTu+A+jmvkFo/ouq00U8p83Y8wLFo6bjqkRaSMRfuqCS067cgaXiIeqeUW\n2MBILIlCYTZt4PowgwIDAQAB\n-----END PUBLIC KEY-----\n";
	BIO *bufio;
	RSA *pRSAPublicKey;

	bufio = BIO_new_mem_buf(pem_key_buffer, -1);
	if (bufio == NULL)
		assert(false);
	pRSAPublicKey = PEM_read_bio_RSA_PUBKEY(bufio, NULL, NULL, NULL);
	if (!pRSAPublicKey)
		assert(false);

	//Ԭ�������Ӳ��� ���� 

	std::string strRet;  
    int nLen = RSA_size(pRSAPublicKey); 
	
    char* pEncode = new char[nLen + 1];  
    int ret = RSA_public_encrypt(strData.length(), (const unsigned char*)strData.c_str(), (unsigned char*)pEncode, pRSAPublicKey, RSA_PKCS1_PADDING);  
    if (ret >= 0)  
    {  
        strRet = std::string(pEncode, ret);  
    }  
    delete[] pEncode;  
    RSA_free(pRSAPublicKey);  
    //fclose(hPubKeyFile);  
    CRYPTO_cleanup_all_ex_data();   
    return strRet;  


	

    return strRet;  
}  



//����  
std::string CBaseView::DecodeRSAKeyMemory(const std::string& strData )  
{  
    
	//Ԭ�������Ӳ��� ��ʼ
	char pem_key_buffer[] = "-----BEGIN RSA PRIVATE KEY-----\nMIICXwIBAAKBgQCnsx4diMfrmTbos85nk+64HnSs8Osp5mjxara/I7tOSe9HhW3g\nxtPENMBoi36Eh1dGE12lm1g0fbwDgdxFIDnjWoZ46MFKT3fTu+A+jmvkFo/ouq00\nU8p83Y8wLFo6bjqkRaSMRfuqCS067cgaXiIeqeUW2MBILIlCYTZt4PowgwIDAQAB\nAoGBAIN79MjDTbxzTJH3KIYdfrXtax2NZ1Rayz09pjsHEPy5C1rQSu5J9g+ILLPL\na08NrmfLF0mZGvdM/fTiBIpOUhOiRIe60slEjdU4VvVfItQ5wSIYr0fYrh1nbI7y\ngrLTQgKTv5i+Zso3xaOcoTfF4NaJtTbK2Ay5aQdn0aaio3sBAkEA3wCQ6ryNFMsF\na+l4w1PQ7Ea8WVtjTPJpaN/k2LL8rEC/Q2Jx2DH6ssXbXSTYkdw3pQbYCAdlf1y7\nHEdl12R7kwJBAMCDqg7diiLYXEqP/lHZSKFPsNCsK01wxt0FHS1h8Y/P76loGq2P\nnEsLmy3tpc2V1UUjbylKKl8bESthWSoY7VECQQC31zOhEMgN+EED8XmJLbPy1W25\nDMoUSVP1DX8P1p7PMqF639GStcFDWDG73ABeXvnQpo+6Lr7R/JSUf5fJtiDZAkEA\nnuOMVdyPCBdehMO3eUJGaazmGDQhQTcVSpHP9QbjYniSK1WavyjKLD4WA6Aiuj0x\n2nBWbNOjiP9D+nPMLayJIQJBAMm2Z9UTcMapSaXEG9izxQSvDYkNBO0cWcFa0qn3\nYtFmPp0jUfigZ2bPVJ7Bjs3OsPkTbXW4QybM9kOCDUMw17M=\n-----END RSA PRIVATE KEY-----\n";
	BIO *bufio;
	RSA *pRSAPriKey;

	bufio = BIO_new_mem_buf(pem_key_buffer, -1);
	if (bufio == NULL)
		assert(false);
	pRSAPriKey = PEM_read_bio_RSAPrivateKey(bufio, NULL, NULL, NULL);
	if (!pRSAPriKey)
		assert(false);

	//Ԭ�������Ӳ��� ���� 



    std::string strRet;  
    //RSA* pRSAPriKey = RSA_new();  
    //if(PEM_read_RSAPrivateKey(hPriKeyFile, &pRSAPriKey, 0, 0) == NULL)  
    //{  
    //    assert(false);  
    //    return "";  
    //}  
    int nLen = RSA_size(pRSAPriKey);  
    char* pDecode = new char[nLen+1];  
  
    int ret = RSA_private_decrypt(strData.length(), (const unsigned char*)strData.c_str(), (unsigned char*)pDecode, pRSAPriKey, RSA_PKCS1_PADDING);  
    if(ret >= 0)  
    {  
        strRet = std::string((char*)pDecode, ret);  
    }  
    delete [] pDecode;  
    RSA_free(pRSAPriKey);  
    //fclose(hPriKeyFile);  
    CRYPTO_cleanup_all_ex_data();   

    return strRet;  
}  







/////////////////////////////////////////////////////////////////////////////
// CBaseView diagnostics

#ifdef _DEBUG
void CBaseView::AssertValid() const
{
	CView::AssertValid();
}

void CBaseView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CBaseDoc* CBaseView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CBaseDoc)));
	return (CBaseDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CBaseView message handlers
