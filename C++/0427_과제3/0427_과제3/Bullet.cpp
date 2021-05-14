#include "stdafx.h"
#include "Bullet.h"
#include "GameObject.h"

CBullet::CBullet()
{
}


CBullet::~CBullet()
{
	Release_GameObject();
}

int CBullet::Ready_GameObject(HDC hdc)
{
	m_Gamehdc = hdc;
	m_tInfo.iWide = 20;
	m_tInfo.fSpeed = 5.0f;
	m_Brush = (HBRUSH)CreateSolidBrush(RGB(75, 125, 125));
	return READY_PASS;
}

void CBullet::Render_GameObject(HDC hdc)
{
	UpdateRect();
	m_oldBrush = (HBRUSH)SelectObject(hdc, m_Brush);
	Ellipse(hdc, m_Rect.left, m_Rect.top, m_Rect.right, m_Rect.bottom);
	SelectObject(hdc, m_oldBrush);
}

int CBullet::Update_GameObject()
{
	IsIdle();
	if (m_bIsDead)
		return IDLE;
	m_tInfo.fX += cosf(m_fAngle)*m_tInfo.fSpeed;
	m_tInfo.fY += sinf(m_fAngle)*m_tInfo.fSpeed; //atna2 ��ü�� ���� ���� ��ȯ�ϴµ� �߰������� ������ ��ȯ�ϱ⿡ ������ ���� ���� �߰����ָ� y��ǥ�迡�� ����ȴ�.

	return NONIDLE;
}

int CBullet::LateUpdate_GameObject()
{
	return NONIDLE;
}

void CBullet::Release_GameObject()
{
	DeleteObject(m_Brush);
}

CGameObject * CBullet::Create(HDC hdc, const INFO tInfo, POINT* pMouse)
{
	CGameObject* pInstance = new CBullet;
	if (!pInstance->Ready_GameObject(hdc))
	{
		delete pInstance;
		pInstance = nullptr;	
	}
	CBullet* pBullet = dynamic_cast<CBullet*>(pInstance);
	if (pBullet)
	{
		pBullet->SetXY(tInfo);
		pBullet->SetAngle(pMouse);
	}
	pInstance = pBullet;
	
	return pInstance;
}

void CBullet::SetXY(const INFO tInfo)
{
	m_tInfo.fX = tInfo.fX;
	m_tInfo.fY = tInfo.fY;
}

void CBullet::IsIdle()
{
	if (100 >= m_tInfo.fX || INNERCX <= m_tInfo.fX || 100 >= m_tInfo.fY || INNERCY <= m_tInfo.fY)
		m_bIsDead = DEAD;
}

void CBullet::SetAngle(POINT* pMouse)
{
	//�Ϲݰ��� 60�������δ� 360�� x n + a ��. ȣ�������δ� 2*pi*n+ a��; 360���� 2���� ������ ����/ 180;
	m_fAngle = atan2f((pMouse->y - m_tInfo.fY), (pMouse->x - m_tInfo.fX)); 
}
