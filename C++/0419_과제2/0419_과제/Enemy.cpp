#include "stdafx.h"
#include "Enemy.h"
#include "GameObj.h"

CEnemy::CEnemy()
{
}


CEnemy::~CEnemy()
{
}

int CEnemy::Ready_GameObj()
{
	m_tXY.fX = 200.f;
	m_tXY.fY = 200.f;
	m_tXY.iWide = 30;
	m_iSpeed = 10;
	rc = { m_tXY.fX - (m_tXY.iWide / 2), m_tXY.fY - (m_tXY.iWide / 2), m_tXY.fX + (m_tXY.iWide / 2),m_tXY.fY + (m_tXY.iWide / 2) };
	
	return Ready_Success;
}

void CEnemy::Render_GameObj(HDC hdc)
{
	myBrush = (HBRUSH)CreateSolidBrush(RGB(255, 0, 0));
	oldBrush = (HBRUSH)SelectObject(m_hdc, myBrush);
	
	Rectangle(hdc, rc.left, rc.top, rc.right, rc.bottom);

	SelectObject(hdc, oldBrush);
	DeleteObject(myBrush);
	
}

void CEnemy::Update_GameObj()
{
	if (200.f > m_tXY.fX)
	{
		m_iSpeed = -1 * m_iSpeed;
	}
	if (600.f < m_tXY.fX)
	{
		m_iSpeed = -1 * m_iSpeed;
	}
	m_tXY.fX += m_iSpeed;
}

void CEnemy::Release_GameObj()
{
	SelectObject(m_hdc, oldBrush);
	DeleteObject(myBrush);
}

CGameObj * CEnemy::Create(HDC hdc)
{
	CGameObj* pInstance = new CEnemy;
	dynamic_cast<CEnemy*>(pInstance)->m_hdc = hdc;
	if (0 > pInstance->Ready_GameObj())
	{
		delete pInstance;
		pInstance = nullptr;
	}
;
	return pInstance;
}
