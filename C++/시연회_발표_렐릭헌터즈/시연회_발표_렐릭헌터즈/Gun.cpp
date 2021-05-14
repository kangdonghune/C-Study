#include "stdafx.h"
#include "Gun.h"
#include "C_Bitmap.h"
#include "BitmapManeger.h"
#include "GameObject.h"
#include "BitmapManeger.h"
#include "Player.h"


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
	if (0 > m_idir)
	{
		m_Rc.left = m_pTarget->GetInfo()->fX;
		m_Rc.top = m_pTarget->GetInfo()->fY + GUN_ICY/2;
		m_Rc.right = m_pTarget->GetInfo()->fX + GUN_ICX;
		m_Rc.bottom = m_pTarget->GetInfo()->fY + GUN_ICY*3/2.f;
	}
	else
	{
		m_Rc.left = m_pTarget->GetInfo()->fX - GUN_ICX;
		m_Rc.top = m_pTarget->GetInfo()->fY + GUN_ICY / 2;;
		m_Rc.right = m_pTarget->GetInfo()->fX;
		m_Rc.bottom = m_pTarget->GetInfo()->fY + GUN_ICY * 3 / 2.f;
	}


	m_tInfo.fX = m_pTarget->GetInfo()->fX;
	m_tInfo.fY = m_pTarget->GetInfo()->fY;
}

void CGun::SetPoints(float Radian)
{
	POINT temp0, temp1, temp2;
	if (0 < m_idir)
	{
		temp0.x = GUN_ICX;
		temp0.y = 0;
		temp1.x = 0;
		temp1.y = 0;
		temp2.x = 0;
		temp2.y = GUN_ICY;

		m_pPoint[0].x = temp0.x*cosf(Radian) - temp0.y*sinf(Radian);
		m_pPoint[0].y = temp0.x*sinf(Radian) + temp0.y*cosf(Radian);
		m_pPoint[1].x = temp1.x*cosf(Radian) - temp1.y*sinf(Radian);
		m_pPoint[1].y = temp1.x*sinf(Radian) + temp1.y*cosf(Radian);
		m_pPoint[2].x = temp2.x*cosf(Radian) - temp2.y*sinf(Radian);
		m_pPoint[2].y = temp2.x*sinf(Radian) + temp2.y*cosf(Radian);
	}
	else
	{
		temp0.x = 0;
		temp0.y = 0;
		temp1.x = GUN_ICX;
		temp1.y = 0;
		temp2.x = 0;
		temp2.y = GUN_ICY;

		m_pPoint[0].x = temp0.x*cosf(Radian) - temp0.y*sinf(Radian);
		m_pPoint[0].y = temp0.x*sinf(Radian) + temp0.y*cosf(Radian);
		m_pPoint[1].x = temp1.x*cosf(Radian) - temp1.y*sinf(Radian);
		m_pPoint[1].y = temp1.x*sinf(Radian) + temp1.y*cosf(Radian);
		m_pPoint[2].x = temp2.x*cosf(Radian) - temp2.y*sinf(Radian);
		m_pPoint[2].y = temp2.x*sinf(Radian) + temp2.y*cosf(Radian);

		//temp0.x = GUN_ICX;
		//temp0.y = GUN_ICX;
		//temp1.x = 2 * GUN_ICX;
		//temp1.y = GUN_ICX;
		//temp2.x = GUN_ICX;
		//temp2.y = 2 * GUN_ICX;

		//m_pPoint[0].x = temp0.x*cosf(Radian) - temp0.y*sinf(Radian);
		//m_pPoint[0].y = temp0.x*sinf(Radian) + temp0.y*cosf(Radian);
		//m_pPoint[1].x = temp1.x*cosf(Radian) - temp1.y*sinf(Radian);
		//m_pPoint[1].y = temp1.x*sinf(Radian) + temp1.y*cosf(Radian);
		//m_pPoint[2].x = temp2.x*cosf(Radian) - temp2.y*sinf(Radian);
		//m_pPoint[2].y = temp2.x*sinf(Radian) + temp2.y*cosf(Radian);
	}

}



CGun::~CGun()
{
}

int CGun::Ready_GameObject()
{
	m_pPoint = new POINT[3];
	m_pPoint[0].x = 0;
	m_pPoint[0].y = 0;
	m_pPoint[1].x = 0;
	m_pPoint[1].y = 0;
	m_pPoint[2].x = 0;
	m_pPoint[2].y = 0;
	m_idir = m_pTarget->GetDir();
	if (0 > m_pTarget->GetDir())
	{
		m_idir = m_pTarget->GetDir();
		m_hGunDC = CBitmapManeger::Get_BitmapManeger()->Get_BitmapDC(L"MuchineGun(R)");
	}
	else
	{
		m_idir = m_pTarget->GetDir();
		m_hGunDC = CBitmapManeger::Get_BitmapManeger()->Get_BitmapDC(L"MuchineGun(L)");
	}
	return Function_Pass;
}

int CGun::Render_GameObject(HDC hdc)
{
	GdiTransparentBlt(hdc, m_Rc.left, m_Rc.top, GUN_ICX, GUN_ICY, m_hGunDC, 0, 0, GUN_ICX, GUN_ICY, bmi_BackGround);	
	return Function_Pass;
}

int CGun::Update_GameObject()
{
	if (0 > m_pTarget->GetDir())
	{
		m_idir = m_pTarget->GetDir();
		m_hGunDC = CBitmapManeger::Get_BitmapManeger()->Get_BitmapDC(L"MuchineGun(R)");
	}
	else
	{
		m_idir = m_pTarget->GetDir();
		m_hGunDC = CBitmapManeger::Get_BitmapManeger()->Get_BitmapDC(L"MuchineGun(L)");
	}
	CheckMouseDir();
	UpdateGunRect();
//	SetPoints(m_tInfo.fAngle);
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
