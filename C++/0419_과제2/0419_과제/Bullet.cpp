#include "stdafx.h"
#include "Bullet.h"


CBullet::CBullet()
{
}


CBullet::~CBullet()
{
	Release_GameObj();
}

int CBullet::Ready_GameObj()
{
	m_iSpeed = 5;
	rc = { m_tXY.fX - (m_tXY.iWide / 2), m_tXY.fY - (m_tXY.iWide / 2), m_tXY.fX + (m_tXY.iWide / 2), m_tXY.fY + (m_tXY.iWide / 2) };
	return Ready_Success;
}

void CBullet::Render_GameObj(HDC hdc)
{

	Ellipse(hdc, rc.left, rc.top, rc.right, rc.bottom);
}

void CBullet::Update_GameObj()
{
	switch (m_iBulletDir)
	{
	case A:
		m_tXY.fX -= m_iSpeed;
		break;
	case D:
		m_tXY.fX += m_iSpeed;
		break;
	case W:
		m_tXY.fY -= m_iSpeed;
		break;
	case S:
		m_tXY.fY += m_iSpeed;
		break;
	default:
		break;
	}
	

}

void CBullet::Release_GameObj()
{

}

CGameObj * CBullet::Create(XY tXY)
{
	CGameObj* pInstance = new CBullet;
	if (0 > pInstance->Ready_GameObj())
	{
		delete pInstance;
		pInstance = nullptr;
		return pInstance;
	}
	pInstance->SetXY(tXY);
	return pInstance;
}
