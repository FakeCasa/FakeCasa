
// FakeCasaDoc.cpp : implementation of the CFakeCasaDoc class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "FakeCasa.h"
#endif

#include "FakeCasaDoc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CFakeCasaDoc

IMPLEMENT_DYNCREATE(CFakeCasaDoc, CDocument)

BEGIN_MESSAGE_MAP(CFakeCasaDoc, CDocument)
	ON_COMMAND(ID_FILE_OPEN, &CFakeCasaDoc::OnFileOpen)
END_MESSAGE_MAP()


// CFakeCasaDoc construction/destruction

CFakeCasaDoc::CFakeCasaDoc()
{
	// TODO: add one-time construction code here
	m_csFullPathName = _T("");
}

CFakeCasaDoc::~CFakeCasaDoc()
{
}

BOOL CFakeCasaDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)
	m_arrBaseShape.RemoveAll();
	return TRUE;
}




// CFakeCasaDoc serialization

void CFakeCasaDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

#ifdef SHARED_HANDLERS

// Support for thumbnails
void CFakeCasaDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// Modify this code to draw the document's data
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// Support for Search Handlers
void CFakeCasaDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// Set search contents from document's data. 
	// The content parts should be separated by ";"

	// For example:  strSearchContent = _T("point;rectangle;circle;ole object;");
	SetSearchContent(strSearchContent);
}

void CFakeCasaDoc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = NULL;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != NULL)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CFakeCasaDoc diagnostics

#ifdef _DEBUG
void CFakeCasaDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CFakeCasaDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CFakeCasaDoc commands
void CFakeCasaDoc::OnFileOpen()
{
	LPCTSTR pszFilter =
		_T("Bitmap files (*.bmp;*.dib;*.rle)|*.bmp;*.dib;*.rle|")
		_T("JPEG files (*.jpg;*.jpeg;*.jpe;*.jfif)|*.jpg;*.jpeg;*.jpe;*.jfif||");

	CFileDialog dlgFile(TRUE, NULL, NULL,
		OFN_HIDEREADONLY,
		pszFilter,
		AfxGetMainWnd());

	if (IDOK == dlgFile.DoModal())
	{
		m_csFullPathName = dlgFile.GetPathName();

		AfxGetApp()->OpenDocumentFile(m_csFullPathName);
	}
}
