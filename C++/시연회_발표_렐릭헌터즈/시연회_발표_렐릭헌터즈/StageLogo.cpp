#include "stdafx.h"
#include "StageLogo.h"
#include "BitmapManeger.h"

CStageLogo::CStageLogo()
{
}


CStageLogo::~CStageLogo()
{
}

CStageLogo * CStageLogo::Create(int Num)
{
	CStageLogo* pInstance = new CStageLogo();
	if (!pInstance->Ready_Logo())
	{
		Delete_Dynamic(pInstance);
		return pInstance;
	}
	pInstance->m_iEffectNum = Num;
	return pInstance;
}

int CStageLogo::Ready_Logo()
{
	m_tInfo.fX = 400;
	m_tInfo.fY = 300;
	m_tInfo.iCX = StageEffectRendX;
	m_tInfo.iCY = StageEffectRendY;
	m_tInfo.dwTime = GetTickCount();
	m_tInfo.Limit = 80;
	m_tInfo.iRenderStart = 0;
	m_tInfo.iRenderEnd = 12;
	return Function_Pass;
}

int CStageLogo::Update_Logo()
{
	UpdateRect();
	return Function_Pass;
}

int CStageLogo::Render_Logo(HDC hdc)
{
	HDC m_hMemDC1 = CBitmapManeger::Get_BitmapManeger()->Get_BitmapDC(L"Stage1_effect");
	HDC m_hMemDC2 = CBitmapManeger::Get_BitmapManeger()->Get_BitmapDC(L"StageBoss_effect");
	if (m_tInfo.iRenderStart >= m_tInfo.iRenderEnd)
		m_iState = m_tInfo.iRenderEnd;
	if (m_iEffectNum == 1)
		GdiTransparentBlt(hdc, m_rc.left, m_rc.top, StageEffectRendX, StageEffectRendY, m_hMemDC1, m_tInfo.iRenderStart * StageEffectCX, 0, StageEffectCX, StageEffectCY, bmi_BackGround);
	else
		GdiTransparentBlt(hdc, m_rc.left, m_rc.top, StageEffectRendX, StageEffectRendY, m_hMemDC2, m_tInfo.iRenderStart * StageEffectCX, 0, StageEffectCX, StageEffectCY, bmi_BackGround);
	if (m_tInfo.dwTime + m_tInfo.Limit < GetTickCount())
	{
		m_tInfo.iRenderStart++;
		m_tInfo.dwTime = GetTickCount();
	}
	return Function_Pass;
}

int CStageLogo::Release_Logo()
{
	return Function_Pass;
}
