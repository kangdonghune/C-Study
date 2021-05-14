#include "stdafx.h"
#include "GuideBullet.h"


CGuideBullet::CGuideBullet()
{
}


CGuideBullet::~CGuideBullet()
{
	Release_GameObject();
}

int CGuideBullet::Ready_GameObject(HDC hdc)
{
	m_Gamehdc = hdc;
	m_tInfo.fX = m_tStartPos.fX;
	m_tInfo.fY = m_tStartPos.fY;
	m_tInfo.fSpeed = 30.f;
	m_tInfo.iWide = 10;
	m_Brush = (HBRUSH)CreateSolidBrush(RGB(75, 125, 125));
	return READY_PASS;
}

void CGuideBullet::Render_GameObject(HDC hdc)
{
	UpdateRect();
	m_oldBrush = (HBRUSH)SelectObject(hdc, m_Brush);
	Ellipse(hdc, m_Rect.left, m_Rect.top, m_Rect.right, m_Rect.bottom);
	SelectObject(hdc, m_oldBrush);
}

int CGuideBullet::Update_GameObject()
{
	IsIdle();
	if (m_bIsDead)
		return IDLE;
	SetAngle();
	m_tInfo.fX += cosf(m_fAngle)*m_tInfo.fSpeed;
	m_tInfo.fY += sinf(m_fAngle)*m_tInfo.fSpeed; //atna2 자체가 라디온 값을 반환하는데 추가적으로 음수도 반환하기에 별도의 수정 없이 추가해주면 y좌표계에도 적용된다.

	return NONIDLE;
}

int CGuideBullet::LateUpdate_GameObject()
{
	return 0;
}

void CGuideBullet::Release_GameObject()
{
	DeleteObject(m_Brush);
}

CGameObject * CGuideBullet::Create(HDC hdc, void* shotter)
{
	CGuideBullet* pInstance = new CGuideBullet;
	pInstance->SetStart((CGameObject*)shotter);
	if (!pInstance->Ready_GameObject(hdc))
	{
		delete pInstance;
		pInstance = nullptr;
		return pInstance;
	}

	return pInstance;
}

void CGuideBullet::IsIdle()
{
	if (100 >= m_tInfo.fX || INNERCX <= m_tInfo.fX || 100 >= m_tInfo.fY || INNERCY <= m_tInfo.fY)
		m_bIsDead = DEAD;
}