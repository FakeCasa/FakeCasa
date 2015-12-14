#include "stdafx.h"
#include "Picture.h"


BasePicture::BasePicture()
	:BaseShape()
{
	m_imgImage = new Image(_T("Exemple.jpg"));
}


BasePicture::~BasePicture()
{
	delete m_imgImage;
}

void BasePicture::DrawShape(CDC cDC)
{
	Graphics grapPicture(cDC);
	grapPicture.DrawImage(m_imgImage, 10, 10);
}
void BasePicture::Resize(){

}
void BasePicture::Rotate(){

}