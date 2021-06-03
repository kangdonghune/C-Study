#include "stdafx.h"
#include "Main.h"

#define S_OK 1
#define S_OK 0
#define PI 3.141592
#define RADIAN PI/180.f

CMain::CMain()
{
}


CMain::~CMain()
{
}

CMain * CMain::Create()
{
	CMain* pInstance = new CMain();
	if (0 > pInstance->Ready_Main())
	{
		delete pInstance;
		pInstance = nullptr;
		return pInstance;
	}
	return pInstance;
}

int CMain::Ready_Main()
{
	m_hDC	=	 GetDC(g_hwnd);
	m_Pos	=	{ 200.f, 200.f, 0.f };
	m_iC	=	100;
	m_fAngle=	45.f;
	
	m_D3vec[0] = { (float)-m_iC, (float)-m_iC, 0 };
	m_D3vec[1] = { (float)m_iC, (float)-m_iC, 0 };
	m_D3vec[2] = { (float)m_iC, (float)m_iC, 0 };
	m_D3vec[3] = { (float)-m_iC, (float)m_iC, 0 };

	return S_OK;
}

int CMain::Update_Main()
{
	for (int i = 0; i < 4; i++)
	{
		m_D3vec[i].x = m_D3vec[i].x*cosf(m_fAngle / (3.141592/180.f)) - m_D3vec[i].y * sinf(m_fAngle / (3.141592 / 180.f));
		m_D3vec[i].y = m_D3vec[i].x*sinf(m_fAngle / (3.141592 /180.f)) + m_D3vec[i].y * cosf(m_fAngle / (3.141592 / 180.f));

		m_D3vec[i] + m_Pos;
	}

	return S_OK;
}

int CMain::Render_Main()
{
	MoveToEx(m_hDC, m_D3vec[0].x, m_D3vec[0].y, nullptr);
	LineTo(m_hDC, m_D3vec[1].x, m_D3vec[1].y);
	LineTo(m_hDC, m_D3vec[2].x, m_D3vec[1].y);
	LineTo(m_hDC, m_D3vec[3].x, m_D3vec[3].y);
	LineTo(m_hDC, m_D3vec[0].x, m_D3vec[0].y);

	return S_OK;
}

int CMain::Release_Main()
{
	return 0;
}
