#include "stdafx.h"
#include "Enemy.h"
#include <random>

CEnemy::CEnemy()
{
}


CEnemy::~CEnemy()
{
	Release_GameObject();
}


int CEnemy::Ready_GameObject(HDC hdc)
{
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> RandomX(100, INNERCX);
	uniform_int_distribution<int> RandomY(100, INNERCY);
	m_tInfo.fX = (float)RandomX(gen);
	m_tInfo.fY = (float)RandomY(gen);
	m_tInfo.fSpeed = 3.f;
	m_tInfo.iWide = 40;
	m_Brush = (HBRUSH)CreateSolidBrush(RGB(255, 0, 0));

	return READY_PASS;
}

void CEnemy::Render_GameObject(HDC hdc)
{
	UpdateRect();
	m_oldBrush = (HBRUSH)SelectObject(hdc, m_Brush);
	Rectangle(hdc, m_Rect.left, m_Rect.top, m_Rect.right, m_Rect.bottom);
	SelectObject(hdc, m_oldBrush);
}

int CEnemy::Update_GameObject()
{
	if (m_bIsDead)
		return IDLE;
	m_tInfo.fX += cos(m_fAngle)*m_tInfo.fSpeed;
	m_tInfo.fY += sin(m_fAngle)*m_tInfo.fSpeed;
	return NONIDLE;
}

int CEnemy::LateUpdate_GameObject()
{
	return NONIDLE;
}

void CEnemy::Release_GameObject()
{
	DeleteObject(m_Brush);
}

CGameObject * CEnemy::Create(HDC hdc, INFO tInfo)
{
	CGameObject* pInstance = new CEnemy();
	if (!pInstance->Ready_GameObject(hdc))
	{
		delete pInstance;
		pInstance = nullptr;
	}
	dynamic_cast<CEnemy*>(pInstance)->SetAngle(tInfo);
	return pInstance;
}

void CEnemy::SetAngle(INFO tInfo)
{
	m_fAngle = atan2f((tInfo.fY - m_tInfo.fY),(tInfo.fX - m_tInfo.fX));
}
