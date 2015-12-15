#include "stdafx.h"
#pragma once
class BaseShape
{
protected:
	POINT m_pntBegin;
	POINT m_pntEnd;
	INT m_nAngle;

public:
	BaseShape();
	~BaseShape();
public:
	virtual void DrawShape(CDC *cDC);
	virtual void Resize();
	virtual void Rotate();
	virtual void GetFullPathImg(CString csPathName);
};

