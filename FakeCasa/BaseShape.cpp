#include "stdafx.h"
#include "BaseShape.h"


BaseShape::BaseShape()
{
	m_pntBegin = m_pntEnd = { 0, 0 };
	m_nAngle = 0;
}


BaseShape::~BaseShape()
{
}

void BaseShape::DrawShape(CDC cDC){

}
void BaseShape::Resize(){

}
void BaseShape::Rotate(){

}