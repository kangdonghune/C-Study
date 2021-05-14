#include "stdafx.h"
#include "Shield.h"


CShield::CShield()
{
}


CShield::~CShield()
{
	Release_GameObject();
}

int CShield::Ready_GameObject(HDC hdc)
{

	m_fAngle = 0;
	m_tInfo.iWide = 20;
	m_Brush = (HBRUSH)CreateSolidBrush(RGB(25, 25, 25));
	m_tInfo.fSpeed = 20.f;
	return READY_PASS;
}

void CShield::Render_GameObject(HDC hdc)
{
	UpdateRect();
	m_oldBrush = (HBRUSH)SelectObject(hdc, m_Brush);
	Ellipse(hdc, m_Rect.left, m_Rect.top, m_Rect.right, m_Rect.bottom);
	SelectObject(hdc, m_oldBrush);
}

int CShield::Update_GameObject()
{
	if (m_bIsDead)
		return IDLE;
	m_fAngle += 5;
	m_tInfo.fX = m_tInfo.fX + cosf(m_fAngle/RADIAN)*60.f;
	m_tInfo.fY = m_tInfo.fY - sinf(m_fAngle / RADIAN)*60.f;
	

	return NONIDLE;
}

int CShield::LateUpdate_GameObject()
{
	return NONIDLE;
}

void CShield::Release_GameObject()
{
	DeleteObject(m_Brush);
}

CGameObject * CShield::Create(HDC hdc,INFO tInfo)
{
	CGameObject* pInstance = new CShield;
	dynamic_cast<CShield*>(pInstance)->SetXY(tInfo);
	if (!pInstance->Ready_GameObject(hdc))
	{
		delete pInstance;
		pInstance = nullptr;
	}
	return pInstance;
}

void CShield::SetXY(const INFO tInfo)
{
	m_tInfo.fX = tInfo.fX;
	m_tInfo.fY = tInfo.fY;
}
