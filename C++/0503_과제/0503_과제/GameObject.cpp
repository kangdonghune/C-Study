#include "stdafx.h"
#include "GameObject.h"


CGameObject::CGameObject()
	:m_bisDead(0)
{
}


CGameObject::~CGameObject()
{
}

int CGameObject::Update_Rect()
{
	m_rc.left = LONG(m_tInfo.fX - m_tInfo.iCX);
	m_rc.right = LONG(m_tInfo.fX + m_tInfo.iCX);
	m_rc.top = LONG(m_tInfo.fY - m_tInfo.iCY);
	m_rc.bottom = LONG(m_tInfo.fY + m_tInfo.iCY);
	return Function_Pass;
}
