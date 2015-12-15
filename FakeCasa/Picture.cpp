#include "stdafx.h"
#include "Picture.h"


BasePicture::BasePicture()
	:BaseShape()
{
	m_imgImage = NULL;
}


BasePicture::~BasePicture()
{
	delete m_imgImage;
}

void BasePicture::DrawShape(CDC *cDC)
{
	m_imgImage = new Image(m_csFullPath);
	Graphics grapPicture(*cDC);
	grapPicture.DrawImage(m_imgImage, 10, 10);
}
void BasePicture::Resize(){

}
void BasePicture::Rotate(){

}

void BasePicture::GetFullPathImg(CString csPathName)
{
	m_csFullPath = csPathName;
}
