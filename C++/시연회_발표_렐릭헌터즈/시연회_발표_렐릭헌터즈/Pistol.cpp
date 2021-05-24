#include "stdafx.h"
#include "Pistol.h"
#include "BitmapManeger.h"
#include "ScrollManeger.h"

CPistol::CPistol()
	:m_pPoint(nullptr)
{
}


CPistol::~CPistol()
{
}

CGameObject * CPistol::Create(CGameObject * pTarget)
{
	CPistol* pInstance = new CPistol();
	pInstance->SetTarget(pTarget);
	if (!pInstance->Ready_GameObject())
	{
		Delete_Dynamic(pInstance);
		return pInstance;
	}

	return pInstance;
}

void CPistol::UpdateGunRect()
{
	float fPushx = 10;
	if (m_idir < 1)
		fPushx = 10;
	else
		fPushx = -10;

	m_Rc.left = m_pTarget->GetInfo()->fX - PISTOL_C / 2 + fPushx;
	m_Rc.top = m_pTarget->GetInfo()->fY - PISTOL_C *(2/3.f) + 30;
	m_Rc.right = m_pTarget->GetInfo()->fX + PISTOL_C / 3 + fPushx;
	m_Rc.bottom = m_pTarget->GetInfo()->fY + (PISTOL_C / 5.f) * 4 + 30;

	m_tInfo.fX = m_pTarget->GetInfo()->fX;
	m_tInfo.fY = m_pTarget->GetInfo()->fY;
}

int CPistol::Ready_GameObject()
{
	m_tGunInfo.Name = ITEM::PISTOL;
	m_idir = m_pTarget->GetDir();
	m_tGunInfo.fBulletCoolTime = 200;
	m_tGunInfo.fBulletDist = 400;
	m_tGunInfo.fBulletTime = GetTickCount();
	if (0 > m_pTarget->GetDir())
	{
		m_idir = m_pTarget->GetDir();
		m_hGunDC = CBitmapManeger::Get_BitmapManeger()->Get_BitmapDC(L"pistol");
	}
	else
	{
		m_idir = m_pTarget->GetDir();
		m_hGunDC = CBitmapManeger::Get_BitmapManeger()->Get_BitmapDC(L"pistol");
	}
	return Function_Pass;
}

int CPistol::Render_GameObject(HDC hdc)
{
	if (m_pTarget->Get_GunAni().iStart % 36 == 0)
		m_pTarget->Set_GunAni()->iStart = 0;

	GdiTransparentBlt(hdc, m_Rc.left + CScrollManeger::Get_ScrollX(), m_Rc.top + CScrollManeger::Get_ScrollY(), PISTOL_C, PISTOL_C, m_hGunDC, m_pTarget->Set_GunAni()->iStart*PISTOL_C, 0, PISTOL_C, PISTOL_C, bmi_BackGround);
	return Function_Pass;
}

int CPistol::Update_GameObject()
{
	if (0 > m_pTarget->GetDir())
	{
		m_idir = m_pTarget->GetDir();
		m_hGunDC = CBitmapManeger::Get_BitmapManeger()->Get_BitmapDC(L"pistol");
	}
	else
	{
		m_idir = m_pTarget->GetDir();
		m_hGunDC = CBitmapManeger::Get_BitmapManeger()->Get_BitmapDC(L"pistol");
	}
	UpdateGunRect();
	m_tInfo.fAngle = m_pTarget->GetInfo()->fAngle;
	return Function_Pass;
}

int CPistol::LateUpdate_GameObject()
{
	return Function_Pass;
}

int CPistol::Release_GameObject()
{
	return Function_Pass;
}
