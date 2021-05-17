#include "stdafx.h"
#include "Player_Bullet.h"
#include "BitmapManeger.h"

CPlayer_Bullet::CPlayer_Bullet()
	:m_pTarget(nullptr)
	,m_icount(0)
{
}


CPlayer_Bullet::~CPlayer_Bullet()
{
}

CGameObject * CPlayer_Bullet::Create(CGameObject* pTarget)
{
	CPlayer_Bullet* pInstance = new CPlayer_Bullet();
	pInstance->SetTarget(pTarget);
	if (!pInstance->Ready_GameObject())
	{
		Delete_Dynamic(pInstance);
		return pInstance;
	}
	return pInstance;
}

int CPlayer_Bullet::Ready_GameObject()
{
	if (0 > m_pTarget->GetDir())
		m_idir = 1;
	else
		m_idir = -1;
	m_tInfo.fX = m_pTarget->GetInfo()->fX + (m_idir*GUN_ICX)*6/4.f;
	m_fStart = m_tInfo.fX;
	m_tInfo.fY = m_pTarget->GetInfo()->fY + GUN_ICY;
	m_tInfo.iCX = Bullet_ICX;
	m_tInfo.iCY = Bullet_ICY;
	m_tInfo.fSpeed = 50.f;
	m_tInfo.iDamege = 10;
	
	return Function_Pass;
}

int CPlayer_Bullet::Render_GameObject(HDC hdc)
{
	UpdateRect();
	HDC hMemDC = CBitmapManeger::Get_BitmapManeger()->Get_BitmapDC(L"Player_bullet");
	GdiTransparentBlt(hdc, m_Rc.left, m_Rc.top, Bullet_ICX/2, Bullet_ICY/2, hMemDC, 0, 0, Bullet_ICX, Bullet_ICY, bmi_BackGround);
	return Function_Pass;
}

int CPlayer_Bullet::Update_GameObject()
{

	if (0 > m_idir)
		m_tInfo.fX -= m_tInfo.fSpeed;
	else
		m_tInfo.fX += m_tInfo.fSpeed;

	if (400 < (fabsf(m_tInfo.fX - m_fStart)))
		m_iState = DEAD;
	return Function_Pass;
}

int CPlayer_Bullet::LateUpdate_GameObject()
{
	return Function_Pass;
}

int CPlayer_Bullet::Release_GameObject()
{
	return Function_Pass;
}
