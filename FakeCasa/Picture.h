#include "BaseShape.h"
#include <windows.h>
#include <objidl.h>
#include <gdiplus.h>
using namespace Gdiplus;
#pragma comment (lib,"Gdiplus.lib")

#pragma once
class BasePicture: BaseShape
{
private:
	Image *m_imgImage;
public:
	BasePicture();
	~BasePicture();
public:
	void DrawShape(CDC cDC);
	void Resize();
	void Rotate();
};

