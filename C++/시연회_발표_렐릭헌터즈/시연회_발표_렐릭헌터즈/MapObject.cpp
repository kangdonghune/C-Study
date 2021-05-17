#include "stdafx.h"
#include "MapObject.h"


CMapObject::CMapObject()
	:m_iState(IDLE)
{
}


CMapObject::~CMapObject()
{
}

void CMapObject::Update_Rect()
{
	m_Rc.left	= (long)(m_tMapInfo.fX - m_tMapInfo.iCX/2);
	m_Rc.top	= (long)(m_tMapInfo.fY - m_tMapInfo.iCY/2);
	m_Rc.right	= (long)(m_tMapInfo.fX + m_tMapInfo.iCX/2);
	m_Rc.bottom	= (long)(m_tMapInfo.fY + m_tMapInfo.iCY/2);
}
