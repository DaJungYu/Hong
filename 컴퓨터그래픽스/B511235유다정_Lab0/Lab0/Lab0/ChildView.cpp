//B511235 유다정
// ChildView.cpp: CChildView 클래스의 구현
//

#include "stdafx.h" //항상 있어야 함
#include "Lab0.h"
#include "ChildView.h"
#include "CMyDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CChildView

CChildView::CChildView()
{
	m_count = 0; //생성자에서 초기화
	m_number = 100;
}

CChildView::~CChildView()
{
}


BEGIN_MESSAGE_MAP(CChildView, CWnd)  
	ON_WM_PAINT()     //WM_PAINT: 화면에 그려라 하는 메세지
	ON_COMMAND(ID_MFC_DIALOGBOX, &CChildView::OnMfcDialogbox)
	ON_COMMAND(ID_MFC_WRITE, &CChildView::OnMfcWrite)
END_MESSAGE_MAP()



// CChildView 메시지 처리기

BOOL CChildView::PreCreateWindow(CREATESTRUCT& cs) 
{
	if (!CWnd::PreCreateWindow(cs))
		return FALSE;

	cs.dwExStyle |= WS_EX_CLIENTEDGE;
	cs.style &= ~WS_BORDER;
	cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW|CS_VREDRAW|CS_DBLCLKS, 
		::LoadCursor(nullptr, IDC_ARROW), reinterpret_cast<HBRUSH>(COLOR_WINDOW+1), nullptr);

	return TRUE;
}

void CChildView::OnPaint()   //여기서 OpenGL 사용 
{
	CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.
	
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	
	// 그리기 메시지에 대해서는 CWnd::OnPaint()를 호출하지 마십시오.
}



void CChildView::OnMfcDialogbox()
{
	CMyDialog dlg;
	dlg.m_number=m_number ; //초기에 값을 넘겨줌

	int res=dlg.DoModal();

	if (res == IDOK) {
		CString str;
		str.Format(_T("Input number : %d"), dlg.m_number);
		MessageBox(str);
	}
		
	else
		MessageBox(_T("Cancel"));
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
}


void CChildView::OnMfcWrite()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CString str;
	str.Format(_T("Write menu cliked! %d times\n"),++m_count);
	str += _T("next line\n");
	MessageBox(str);  //childview의 멤버함수
}
