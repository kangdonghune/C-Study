#include "stdafx.h"
#include "GameObject.h"


CGameObject::CGameObject()
	:m_tInfo({})
	,m_bIsDead(0)
	,m_fAngle(0)
{
}


CGameObject::~CGameObject()
{
}

int CGameObject::Update_GameObject()
{
	m_Rect.left = static_cast<long>(m_tInfo.fX - (m_tInfo.iWide >> 1));
	m_Rect.top = static_cast<long>(m_tInfo.fY - (m_tInfo.iWide >> 1));
	m_Rect.right = static_cast<long>(m_tInfo.fX + (m_tInfo.iWide >> 1));
	m_Rect.bottom = static_cast<long>(m_tInfo.fY + (m_tInfo.iWide >> 1));
	return NONIDLE;
}

void CGameObject::UpdateRect()
{
	m_Rect.left = static_cast<long>(m_tInfo.fX - (m_tInfo.iWide >> 1));
	m_Rect.top = static_cast<long>(m_tInfo.fY - (m_tInfo.iWide >> 1));
	m_Rect.right = static_cast<long>(m_tInfo.fX + (m_tInfo.iWide >> 1));
	m_Rect.bottom = static_cast<long>(m_tInfo.fY + (m_tInfo.iWide >> 1));
}


