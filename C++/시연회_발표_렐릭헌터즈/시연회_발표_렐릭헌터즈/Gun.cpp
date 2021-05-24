#include "stdafx.h"
#include "Gun.h"
#include "C_Bitmap.h"
#include "BitmapManeger.h"
#include "GameObject.h"
#include "BitmapManeger.h"
#include "Player.h"
#include "ScrollManeger.h"
#include "Player_Bullet.h"
#include "GameObject.h"
#include "GameObjectManeger.h"

CGun::CGun()
	:m_pPoint(nullptr)
{
}

CGameObject * CGun::Create(CGameObject* pTarget)
{
	CGun* pInstance = new CGun();
	pInstance->SetTarget(pTarget);
	if (!pInstance->Ready_GameObject())
	{
		Delete_Dynamic(pInstance);
		return pInstance;
	}

	return pInstance;
}


void CGun::UpdateGunRect()
{		
	float fPushx = 10;
	if (m_idir < 1)
		fPushx = 10;
	else
		fPushx = -10;

	m_Rc.left	= m_pTarget->GetInfo()->fX - GUN_ICX / 2 + fPushx;
	m_Rc.top = m_pTarget->GetInfo()->fY - (GUN_ICY/5.f);
	m_Rc.right	= m_pTarget->GetInfo()->fX + GUN_ICX / 2 + fPushx;
	m_Rc.bottom = m_pTarget->GetInfo()->fY + (GUN_ICY/5.f)*4;

	m_tInfo.fX = m_pTarget->GetInfo()->fX;
	m_tInfo.fY = m_pTarget->GetInfo()->fY;
}

CGun::~CGun()
{
}

int CGun::Ready_GameObject()
{
	m_tGunInfo.Name = ITEM::MACHINGUN;
	m_idir = m_pTarget->GetDir();
	m_tGunInfo.fBulletCoolTime = 30;
	m_tGunInfo.fBulletDist = 400;
	m_tGunInfo.fBulletTime = GetTickCount();
	if (0 > m_pTarget->GetDir())
	{
		m_idir = m_pTarget->GetDir();
		m_hGunDC = CBitmapManeger::Get_BitmapManeger()->Get_BitmapDC(L"Player_machinegun");
	}
	else
	{
		m_idir = m_pTarget->GetDir();
		m_hGunDC = CBitmapManeger::Get_BitmapManeger()->Get_BitmapDC(L"Player_machinegun");
	}
	return Function_Pass;
}

int CGun::Render_GameObject(HDC hdc)
{
	if (m_pTarget->Get_GunAni().iStart % 36 == 0)
		m_pTarget->Set_GunAni()->iStart = 0;
	if (m_iState == DEAD)
		return Function_Fail;
	GdiTransparentBlt(hdc, m_Rc.left + CScrollManeger::Get_ScrollX(), m_Rc.top + CScrollManeger::Get_ScrollY(), GUN_ICX, GUN_ICY, m_hGunDC, m_pTarget->Set_GunAni()->iStart*GUN_ICX, 0, GUN_ICX, GUN_ICY, bmi_BackGround);
	return Function_Pass;
}

int CGun::Update_GameObject()
{
	if (0 > m_pTarget->GetDir())
	{
		m_idir = m_pTarget->GetDir();
		m_hGunDC = CBitmapManeger::Get_BitmapManeger()->Get_BitmapDC(L"Player_machinegun");
	}
	else
	{
		m_idir = m_pTarget->GetDir();
		m_hGunDC = CBitmapManeger::Get_BitmapManeger()->Get_BitmapDC(L"Player_machinegun");
	}
	UpdateGunRect();
	m_tInfo.fAngle = m_pTarget->GetInfo()->fAngle;
	return Function_Pass;
}

int CGun::LateUpdate_GameObject()
{
	return Function_Pass;
}

int CGun::Release_GameObject()
{
	Delete_Dynamic(m_pPoint);
	return Function_Pass;
}
