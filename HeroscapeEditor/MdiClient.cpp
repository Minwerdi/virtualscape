#include "stdafx.h"
#include "MdiClient.h"

// The constructor
//
CMdiClient::CMdiClient()
{
	m_pBmp = NULL;
	m_nBackColor = CLR_INVALID;
}

// The destructor
//
CMdiClient::~CMdiClient()
{
	if (m_pBmp)
	{
		m_pBmp->DeleteObject();
		delete m_pBmp;
		m_pBmp = NULL;
	}
}

IMPLEMENT_DYNCREATE(CMdiClient, CWnd)

BEGIN_MESSAGE_MAP(CMdiClient, CWnd)
	//{{AFX_MSG_MAP(CMdiClient)
	ON_WM_ERASEBKGND()
	ON_WM_SIZE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

// Don't erase the background but draw the bitmap
//
BOOL CMdiClient::OnEraseBkgnd(CDC* pDC) 
{
	CRect rect;
	GetClientRect(&rect);

	if (m_nBackColor != CLR_INVALID)
		pDC->FillSolidRect(&rect, m_nBackColor);
	else
		if (m_pBmp != NULL)
		{
			BITMAP bm;
			CDC dcMem;
			VERIFY(m_pBmp->GetObject(sizeof(BITMAP), (LPVOID)&bm));
			dcMem.CreateCompatibleDC(NULL);
			CBitmap* pOldBitmap = dcMem.SelectObject(m_pBmp);

			for (register int nX = 0; nX < rect.Width(); nX += bm.bmWidth)
				for (register int nY = 0; nY < rect.Height(); nY += bm.bmHeight)
					pDC->BitBlt(nX, nY, bm.bmWidth, bm.bmHeight, &dcMem, 0, 0, SRCCOPY);

			dcMem.SelectObject(pOldBitmap);
		}
		else
			CWnd::OnEraseBkgnd(pDC);

	return TRUE;
}

// Set the back color
//
COLORREF CMdiClient::SetBackColor(COLORREF nBackColor)
{
	LockWindowUpdate();

	COLORREF cr = m_nBackColor;
	m_nBackColor = nBackColor;

	UnlockWindowUpdate();

	return cr;
}

// Set the bitmap
//
BOOL CMdiClient::SetBitmap(UINT nID)
{
	BOOL bResult = true;

	LockWindowUpdate();

	if (m_pBmp)
	{
		m_pBmp->DeleteObject();
		delete m_pBmp;
		m_pBmp = NULL;
	}

	m_pBmp = new CBitmap();
	bResult = m_pBmp->LoadBitmap(nID);

	UnlockWindowUpdate();

	return bResult;
}

// When the size change then redraw the bitmap
//
void CMdiClient::OnSize(UINT nType, int cx, int cy) 
{
	CWnd::OnSize(nType, cx, cy);
	
	if (m_pBmp != NULL)
		Invalidate();
}
