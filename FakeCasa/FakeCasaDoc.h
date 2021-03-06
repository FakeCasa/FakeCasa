
// FakeCasaDoc.h : interface of the CFakeCasaDoc class
//
#include "BaseShape.h"

#pragma once


class CFakeCasaDoc : public CDocument
{
protected: // create from serialization only
	CFakeCasaDoc();
	DECLARE_DYNCREATE(CFakeCasaDoc)

// Attributes
public:
	CArray<BaseShape*, BaseShape*> m_arrBaseShape;
	CString m_csFullPathName;
// Operations
public:

// Overrides
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// Implementation
public:
	virtual ~CFakeCasaDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	afx_msg void OnFileOpen();
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// Helper function that sets search content for a Search Handler
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
