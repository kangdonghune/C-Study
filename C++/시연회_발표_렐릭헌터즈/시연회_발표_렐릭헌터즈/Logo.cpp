#include "stdafx.h"
#include "Logo.h"
#include "BitmapManeger.h"

CLogo::CLogo()
{
}


CLogo::~CLogo()
{
}

CLogo * CLogo::Create()
{
	CLogo* pInstance = new CLogo();
	if (!pInstance->Ready_Logo())
	{
		Delete_Dynamic(pInstance);
		return pInstance;
	}
	return pInstance;
}

void CLogo::UpdateRect()
{
	m_rc.left = m_tInfo.fX - m_tInfo.iCX / 2;
	m_rc.top  = m_tInfo.fY - m_tInfo.iCY / 2;
	m_rc.right = m_tInfo.fX + m_tInfo.iCX / 2;
	m_rc.bottom = m_tInfo.fY + m_tInfo.iCY / 2;

}

int CLogo::Ready_Logo()
{
	m_tInfo.fX = 400;
	m_tInfo.fY = 150;
	m_tInfo.iCX = MainLogo_CX;
	m_tInfo.iCY = MainLogo_CY;
	m_tInfo.dwTime = GetTickCount();
	m_tInfo.Limit = 80;
	m_tInfo.iRenderStart = 0;
	m_tInfo.iRenderEnd = 24;
	return Function_Pass;
}

int CLogo::Update_Logo()
{
	UpdateRect();
	return Function_Pass;
}

int CLogo::Render_Logo(HDC hdc)
{
	HDC m_hMemDC = CBitmapManeger::Get_BitmapManeger()->Get_BitmapDC(L"Main_Logo");
	if (m_tInfo.iRenderStart >= m_tInfo.iRenderEnd)
		m_tInfo.iRenderStart = m_tInfo.iRenderEnd;
	GdiTransparentBlt(hdc, m_rc.left, m_rc.top , MainLogo_CX+30, MainLogo_CY + 30, m_hMemDC, m_tInfo.iRenderStart * MainLogo_CX, 0, MainLogo_CX, MainLogo_CY, bmi_BackGround);
	if (m_tInfo.dwTime + m_tInfo.Limit < GetTickCount())
	{
		m_tInfo.iRenderStart++;
		m_tInfo.dwTime = GetTickCount();
	}
	return Function_Pass;
}

int CLogo::Release_Logo()
{
	return Function_Pass;
}
