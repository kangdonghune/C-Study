#include "stdafx.h"
#include "BossGun.h"
#include "BitmapManeger.h"
#include "ScrollManeger.h"
#include "GameObjectManeger.h"

BossGun::BossGun()
{
}


BossGun::~BossGun()
{
}

CGameObject * BossGun::Create(CGameObject * pTarget)
{
	BossGun* pInstance = new BossGun();
	pInstance->SetTarget(pTarget);
	if (!pInstance->Ready_GameObject())
	{
		Delete_Dynamic(pInstance);
		return pInstance;
	}

	return pInstance;
}

void BossGun::UpdateGunRect()
{
	float fPushx = 10;
	if (m_idir < 1)
		fPushx = 10;
	else
		fPushx = -10;

	m_Rc.left = m_pTarget->GetInfo()->fX - Boss_GunCX / 2 + fPushx;
	m_Rc.top = m_pTarget->GetInfo()->fY - (Boss_GunCY / 5.f) + 30;
	m_Rc.right = m_pTarget->GetInfo()->fX + Boss_GunCX / 2 + fPushx;
	m_Rc.bottom = m_pTarget->GetInfo()->fY + (Boss_GunCY / 5.f) * 4 +30;

	m_tInfo.fX = m_pTarget->GetInfo()->fX;
	m_tInfo.fY = m_pTarget->GetInfo()->fY;
}

int BossGun::Ready_GameObject()
{
	m_tGunInfo.Name = ITEM::BOSSGUN;
	m_idir = m_pTarget->GetDir();
	m_tGunInfo.fBulletCoolTime = 200;
	m_tGunInfo.fBulletDist = 400;
	m_tGunInfo.fBulletTime = GetTickCount();
	if (0 > m_pTarget->GetDir())
	{
		m_idir = m_pTarget->GetDir();
		m_hGunDC = CBitmapManeger::Get_BitmapManeger()->Get_BitmapDC(L"Boss_gun");
	}
	else
	{
		m_idir = m_pTarget->GetDir();
		m_hGunDC = CBitmapManeger::Get_BitmapManeger()->Get_BitmapDC(L"Boss_gun");
	}
	return Function_Pass;
}

int BossGun::Render_GameObject(HDC hdc)
{
	if (m_pTarget->Get_GunAni().iStart % 36 == 0)
		m_pTarget->Set_GunAni()->iStart = 0;

	GdiTransparentBlt(hdc, m_Rc.left + CScrollManeger::Get_ScrollX(), m_Rc.top + CScrollManeger::Get_ScrollY(), Boss_GunCX, Boss_GunCY, m_hGunDC, m_pTarget->Set_GunAni()->iStart*Boss_GunCX, 0, Boss_GunCX, Boss_GunCY, bmi_BackGround);
	return Function_Pass;
}

int BossGun::Update_GameObject()
{
	if (0 > m_pTarget->GetDir())
	{
		m_idir = m_pTarget->GetDir();
		m_hGunDC = CBitmapManeger::Get_BitmapManeger()->Get_BitmapDC(L"Boss_gun");
	}
	else
	{
		m_idir = m_pTarget->GetDir();
		m_hGunDC = CBitmapManeger::Get_BitmapManeger()->Get_BitmapDC(L"Boss_gun");
	}
	UpdateGunRect();
	m_tInfo.fAngle = m_pTarget->GetInfo()->fAngle;
	return Function_Pass;
}

int BossGun::LateUpdate_GameObject()
{
	return Function_Pass;
}

int BossGun::Release_GameObject()
{
	return Function_Pass;
}
