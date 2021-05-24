#include "stdafx.h"
#include "BossHPBar.h"
#include "BitmapManeger.h"

CBossHPBar::CBossHPBar()
{
}


CBossHPBar::~CBossHPBar()
{
}

CGameObject * CBossHPBar::Create(CGameObject * pTarget)
{
	CBossHPBar* pInstance = new CBossHPBar();
	pInstance->m_pTarget = pTarget;
	if (!pInstance->Ready_GameObject())
	{
		Delete_Dynamic(pInstance);
		return pInstance;
	}
	return pInstance;
}

int CBossHPBar::Ready_GameObject()
{
	m_tInfo.fX = 400;
	m_tInfo.fY = 500;
	m_tInfo.iCX = BOSS_HPBARRENDX + BOSS_HPFACECX;
	m_tInfo.iCY = BOSS_HPBARCY + BOSS_HPFACECY;
	m_fRemainHP = 100.f;
	m_tAni.iStart = 0;
	m_tAni.iEnd = 2;
	return Function_Pass;
}

int CBossHPBar::Render_GameObject(HDC hdc)
{
	HDC m_FaceDc = CBitmapManeger::Get_BitmapManeger()->Get_BitmapDC(L"Boss_HPFace");
	HDC m_BarDc = CBitmapManeger::Get_BitmapManeger()->Get_BitmapDC(L"Boss_HpBar");
	GdiTransparentBlt(hdc, m_Rc.left, m_Rc.top, BOSS_HPFACECX, BOSS_HPFACECY, m_FaceDc, BOSS_HPFACECX  * m_tAni.iStart, 0, BOSS_HPFACECX, BOSS_HPFACECY, bmi_BackGround);
	GdiTransparentBlt(hdc, m_Rc.left + BOSS_HPFACECX, m_Rc.top + BOSS_HPBARCY, BOSS_HPBARRENDX*m_fRemainHP, BOSS_HPBARCY, m_BarDc, 0, 0, BOSS_HPBARCX, BOSS_HPBARCY, bmi_BackGround);
	return Function_Pass;
}

int CBossHPBar::Update_GameObject()
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

int CBossHPBar::LateUpdate_GameObject()
{
	return Function_Pass;
}

int CBossHPBar::Release_GameObject()
{
	return Function_Pass;
}
