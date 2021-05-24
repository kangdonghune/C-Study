#include "stdafx.h"
#include "GameObject.h"
#include "BitmapManeger.h"
#include "ScrollManeger.h"
CGameObject::CGameObject()
	:m_iState(IDLE)
	,m_tAni({})
{
}


CGameObject::~CGameObject()
{
}

float CGameObject::CheckTargetDir(CGameObject * pTarget)
{
	return m_tInfo.fAngle = atan2f(((pTarget->GetInfo()->fY) - m_tInfo.fY), ((pTarget->GetInfo()->fX) - m_tInfo.fX));
}

float CGameObject:: CheckMouseDir()
{
	GetCursorPos(&m_tMouse);
	ScreenToClient(g_HWND, &m_tMouse);
	return m_tInfo.fAngle = atan2f(((m_tMouse.y - CScrollManeger::Get_ScrollY()) - m_tInfo.fY),((m_tMouse.x - CScrollManeger::Get_ScrollX())- m_tInfo.fX));
}


void CGameObject::SetDir()
{
	m_tInfo.fDirX = cosf(m_tInfo.fAngle);
	m_tInfo.fDirY = sinf(m_tInfo.fAngle);
}

void CGameObject::UpdateRect()
{
	m_Rc.left	 = static_cast<LONG>(m_tInfo.fX - m_tInfo.iCX / 2)   ;
	m_Rc.top	 = static_cast<LONG>(m_tInfo.fY - m_tInfo.iCY / 2) ;
	m_Rc.right	 = static_cast<LONG>(m_tInfo.fX + m_tInfo.iCX / 2) ;
	m_Rc.bottom  = static_cast<LONG>(m_tInfo.fY + m_tInfo.iCY / 2) ;
}
