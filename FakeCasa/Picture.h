#include "BaseShape.h"

#pragma once
class BasePicture: public BaseShape
{
private:
	Image *m_imgImage;
	CString m_csFullPath;
public:
	BasePicture();
	~BasePicture();
public:
	void DrawShape(CDC *cDC);
	void Resize();
	void Rotate();
private:
	void GetFullPathImg(CString csPathName);
};

