#include "stdafx.h"
#include "PlayerHP.h"
#include "ScrollManeger.h"
#include "BitmapManeger.h"

CPlayerHP::CPlayerHP()
{
}


CPlayerHP::~CPlayerHP()
{
}

CGameObject * CPlayerHP::Create(CGameObject * pTarget)
{
	CPlayerHP* pInstance = new CPlayerHP();
	pInstance->m_pTarget = pTarget;
	if (!pInstance->Ready_GameObject())
	{
		Delete_Dynamic(pInstance);
		return pInstance;
	}
	return pInstance;
}

int CPlayerHP::Ready_GameObject()
{
	m_tInfo.fX = 100;
	m_tInfo.fY = 70;
	m_tInfo.iCX = PLAYER_HPBARRENDX + PLAYER_HPFACERENDX;
	m_tInfo.iCY = PLAYER_HPBARRENDY + PLAYER_HPFACERENDY;
	m_fRemainHP = 100.f;
	m_tAni.iStart = 0;
	m_tAni.iEnd = 2;
	return Function_Pass;
}

int CPlayerHP::Render_GameObject(HDC hdc)
{
	HDC m_FaceDc = CBitmapManeger::Get_BitmapManeger()->Get_BitmapDC(L"Player_HpFace");
	HDC m_BarDc = CBitmapManeger::Get_BitmapManeger()->Get_BitmapDC(L"Player_HpBar");
	GdiTransparentBlt(hdc, m_Rc.left, m_Rc.top , PLAYER_HPFACERENDX, PLAYER_HPFACERENDY, m_FaceDc, PLAYER_HPFACECX  * m_tAni.iStart, 0, PLAYER_HPFACECX, PLAYER_HPFACECY, bmi_BackGround);
	GdiTransparentBlt(hdc, m_Rc.left + PLAYER_HPFACERENDX, m_Rc.top+ PLAYER_HPBARCY/2, PLAYER_HPBARRENDX*m_fRemainHP, PLAYER_HPBARCY, m_BarDc, 0, 0, PLAYER_HPBARCX, PLAYER_HPBARCY, bmi_BackGround);
	return Function_Pass;
}

int CPlayerHP::Update_GameObject()
{
	if (m_pTarget->GetState() == DEAD)
		SetDead();
	UpdateRect();
	if (m_pTarget->GetInfo()->iMaxHp * 2 / 3.f >= m_pTarget->GetInfo()->iHP)
		m_tAni.iStart = 1;
	if (m_pTarget->GetInfo()->iMaxHp * 1 / 3.f >= m_pTarget->GetInfo()->iHP)
		m_tAni.iStart = 2;
	m_fRemainHP = m_pTarget->GetInfo()->iHP / (m_pTarget->GetInfo()->iMaxHp*1.f);
	return Function_Pass;
}

int CPlayerHP::LateUpdate_GameObject()
{
	return Function_Pass;
}

int CPlayerHP::Release_GameObject()
{
	return Function_Pass;
}
