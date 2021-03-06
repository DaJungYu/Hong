// CMyDialog.cpp: 구현 파일
//

#include "stdafx.h"
#include "Lab0.h"
#include "CMyDialog.h"
#include "afxdialogex.h"


// CMyDialog 대화 상자

IMPLEMENT_DYNAMIC(CMyDialog, CDialogEx)

CMyDialog::CMyDialog(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG1, pParent)
	, m_number(0)
{

}

CMyDialog::~CMyDialog()
{
}

void CMyDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_Number, m_number);   //값 매칭
	DDV_MinMaxInt(pDX, m_number, 0, 255); //0~255
}


BEGIN_MESSAGE_MAP(CMyDialog, CDialogEx)
	ON_BN_CLICKED(IDOK, &CMyDialog::OnBnClickedOk)
END_MESSAGE_MAP()


// CMyDialog 메시지 처리기


void CMyDialog::OnBnClickedOk()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CDialogEx::OnOK();
}
