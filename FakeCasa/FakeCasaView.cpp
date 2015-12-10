
// FakeCasaView.cpp : implementation of the CFakeCasaView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "FakeCasa.h"
#endif

#include "FakeCasaDoc.h"
#include "FakeCasaView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CFakeCasaView

IMPLEMENT_DYNCREATE(CFakeCasaView, CView)

BEGIN_MESSAGE_MAP(CFakeCasaView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CFakeCasaView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CFakeCasaView construction/destruction

CFakeCasaView::CFakeCasaView()
{
	// TODO: add construction code here

}

CFakeCasaView::~CFakeCasaView()
{
}

BOOL CFakeCasaView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CFakeCasaView drawing

void CFakeCasaView::OnDraw(CDC* /*pDC*/)
{
	CFakeCasaDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CFakeCasaView printing


void CFakeCasaView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CFakeCasaView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CFakeCasaView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CFakeCasaView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CFakeCasaView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CFakeCasaView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CFakeCasaView diagnostics

#ifdef _DEBUG
void CFakeCasaView::AssertValid() const
{
	CView::AssertValid();
}

void CFakeCasaView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CFakeCasaDoc* CFakeCasaView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CFakeCasaDoc)));
	return (CFakeCasaDoc*)m_pDocument;
}
#endif //_DEBUG


// CFakeCasaView message handlers
