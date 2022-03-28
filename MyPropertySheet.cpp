// MyPropertySheet.cpp : implementation file
//

#include "stdafx.h"
#include "NewPropButton.h"
#include "MyPropertySheet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMyPropertySheet

IMPLEMENT_DYNAMIC(CMyPropertySheet, CPropertySheet)

CMyPropertySheet::CMyPropertySheet(UINT nIDCaption, CWnd* pParentWnd, UINT iSelectPage)
	:CPropertySheet(nIDCaption, pParentWnd, iSelectPage)
{
}

CMyPropertySheet::CMyPropertySheet(LPCTSTR pszCaption, CWnd* pParentWnd, UINT iSelectPage)
	:CPropertySheet(pszCaption, pParentWnd, iSelectPage)
{
}

CMyPropertySheet::~CMyPropertySheet()
{
}


BEGIN_MESSAGE_MAP(CMyPropertySheet, CPropertySheet)
	//{{AFX_MSG_MAP(CMyPropertySheet)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_BUTTON_COPY, OnButtonCopy)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyPropertySheet message handlers

BOOL CMyPropertySheet::OnInitDialog() 
{
	BOOL bResult = CPropertySheet::OnInitDialog();
	
	// TODO: Add your specialized code here
	CRect rect, tabrect;
	int width;

	//Get button sizes and positions
	GetDlgItem(IDOK)->GetWindowRect(rect);
	GetTabControl()->GetWindowRect(tabrect);
	ScreenToClient(rect); ScreenToClient(tabrect);
	
	//New button - width, height and Y-coordiate of IDOK
	//           - X-coordinate of tab control
	width = rect.Width();
	rect.left = tabrect.left; rect.right = tabrect.left + width;
	
	//Create new "Add" button and set standard font
	m_ButtonCopy.Create("Copy",
			BS_PUSHBUTTON|WS_CHILD|WS_VISIBLE|WS_TABSTOP,
			rect, this, IDC_BUTTON_COPY);
	m_ButtonCopy.SetFont(GetFont());
	
	return bResult;
}

void CMyPropertySheet::OnButtonCopy()
{
	MessageBox("COPY button pressed!!");
}
