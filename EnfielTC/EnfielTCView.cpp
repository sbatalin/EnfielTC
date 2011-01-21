
// EnfielTCView.cpp : implementation of the CEnfielTCView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "EnfielTC.h"
#endif

#include "EnfielTCDoc.h"
#include "EnfielTCView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CEnfielTCView

IMPLEMENT_DYNCREATE(CEnfielTCView, CView)

BEGIN_MESSAGE_MAP(CEnfielTCView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CEnfielTCView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CEnfielTCView construction/destruction

CEnfielTCView::CEnfielTCView()
{
	// TODO: add construction code here

}

CEnfielTCView::~CEnfielTCView()
{
}

BOOL CEnfielTCView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CEnfielTCView drawing

void CEnfielTCView::OnDraw(CDC* /*pDC*/)
{
	CEnfielTCDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CEnfielTCView printing


void CEnfielTCView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CEnfielTCView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CEnfielTCView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CEnfielTCView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CEnfielTCView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CEnfielTCView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CEnfielTCView diagnostics

#ifdef _DEBUG
void CEnfielTCView::AssertValid() const
{
	CView::AssertValid();
}

void CEnfielTCView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CEnfielTCDoc* CEnfielTCView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CEnfielTCDoc)));
	return (CEnfielTCDoc*)m_pDocument;
}
#endif //_DEBUG


// CEnfielTCView message handlers
