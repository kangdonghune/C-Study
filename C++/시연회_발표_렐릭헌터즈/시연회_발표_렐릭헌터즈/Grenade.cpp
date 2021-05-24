#include "stdafx.h"
#include "Grenade.h"
#include "BitmapManeger.h"
#include "GameObjectManeger.h"
#include "ScrollManeger.h"
#include "SceneManeger.h"
CGrenade::CGrenade()
{
}


CGrenade::~CGrenade()
{
}

CGameObject * CGrenade::Create(CGameObject * pObject, POINT tMouse)
{
	CGrenade* pInstance = new CGrenade();
	pInstance->m_pTarger = pObject;
	pInstance->m_tPoint.x = tMouse.x - CScrollManeger::Get_ScrollX();
	pInstance->m_tPoint.y = tMouse.y - CScrollManeger::Get_ScrollY();
	if (!pInstance->Ready_GameObject())
	{
		Delete_Dynamic(pInstance);
		return pInstance;
	}
	return pInstance;
}

int CGrenade::Ready_GameObject()
{
	m_tInfo.fX = m_pTarger->GetInfo()->fX + 10;
	m_tInfo.fY = m_pTarger->GetInfo()->fY - 30;
	m_tInfo.iCX = Grenade_CX;
	m_tInfo.iCX = Grenade_CY;
	m_tInfo.dwTime = GetTickCount();
	m_tInfo.LimitTime = 50;
	m_tInfo.fSpeed = 8.0f;
	m_tInfo.fAngle = atan2f(m_tPoint.y - m_tInfo.fY, m_tPoint.x - m_tInfo.fX);
	m_fTimer = m_pTarger->GetInfo()->fY;
	m_fMaxPower = 10.f;
	m_tGravity.fPower = m_fMaxPower;
	m_tGravity.fAccel = 0;
	m_tGravity.Gravity = 9.8f;
	sin = sinf(m_tInfo.fAngle);
	cos = cosf(m_tInfo.fAngle);
	m_fTimer = m_pTarger->GetInfo()->fY;
	MaxDist = 300;
	m_iDist = MaxDist;
	m_bIsBoom = false;
	m_tInfo.dwTime = GetTickCount();
	m_tInfo.LimitTime = 50;
	m_tInfo.iDamege = 100;
	return Function_Pass;
}

int CGrenade::Render_GameObject(HDC hdc)
{
	HDC m_hmapDC = CBitmapManeger::Get_BitmapManeger()->Get_BitmapDC(L"Grenade");
	HDC m_hmapDC2 = CBitmapManeger::Get_BitmapManeger()->Get_BitmapDC(L"Grenade_boom");
	if (m_hmapDC == nullptr)
		return Function_Fail;
	if(m_bIsBoom)
		GdiTransparentBlt(hdc, m_Rc.left + CScrollManeger::Get_ScrollX(), m_Rc.top + CScrollManeger::Get_ScrollY(), Grenade_BoomCX*1.5, Grenade_BoomCY*1.5, m_hmapDC2,m_tAni.iStart* Grenade_BoomCX, 0, Grenade_BoomCX, Grenade_BoomCY, bmi_BackGround);
	else
		GdiTransparentBlt(hdc, m_Rc.left + CScrollManeger::Get_ScrollX(), m_Rc.top + CScrollManeger::Get_ScrollY(), Grenade_CX, Grenade_CY, m_hmapDC, 0, 0, Grenade_CX, Grenade_CY, bmi_BackGround);
	
	if (m_tInfo.dwTime + m_tInfo.LimitTime < GetTickCount())
	{
		m_tAni.iStart++;
		m_tInfo.dwTime = GetTickCount();
	}
	//if (m_tAni.iStart >= m_tAni.iEnd)
	//	SetDead();;
	return Function_Pass;
}

int CGrenade::Update_GameObject()
{
	if (!m_bIsBoom)
	{
		m_tGravity.fAccel += 0.035;
		m_tGravity.fPower -= m_tGravity.fAccel;
		m_tInfo.fX += cosf(m_tInfo.fAngle)*m_tInfo.fSpeed;
		m_tInfo.fY += sinf(m_tInfo.fAngle)*m_tInfo.fSpeed;
		m_fTimer += sinf(m_tInfo.fAngle)*m_tInfo.fSpeed;
		m_tInfo.fY -= m_tGravity.fPower;
		m_iDist -= m_tInfo.fSpeed;
		if (m_fTimer >= m_tInfo.fX)
		{
			m_tGravity.fPower = (m_iDist / MaxDist)*m_fMaxPower;
		}

	}
	

	if (0 >= m_iDist && !m_bIsBoom)
	{
		m_bIsBoom = true;
		m_tInfo.iCX = Grenade_BoomCX;
		m_tInfo.iCY = Grenade_BoomCY;
		m_tAni.iStart = 0;
		m_tAni.iEnd = 7;
		CSceneManeger::Get_SceneManeger()->SetWaveOn(true);
	}
	UpdateRect();
	return Function_Pass;
}

int CGrenade::LateUpdate_GameObject()
{
	return Function_Pass;
}

int CGrenade::Release_GameObject()
{
	return Function_Pass;
}
