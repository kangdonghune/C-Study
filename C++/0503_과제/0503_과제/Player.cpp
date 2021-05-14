#include "stdafx.h"
#include "Player.h"


CPlayer::CPlayer()
{
}

CGameObject * CPlayer::Create(HDC hdc)
{
	CPlayer* pInstance = new CPlayer;
	if (!pInstance->Ready_GameObject())
	{
		delete pInstance;
		pInstance = nullptr;
		return pInstance;
	}
	pInstance->m_hdc = hdc;

	return pInstance;
}


int CPlayer::SetAngle()
{
	if (300 <= m_tInfo.fX && 500 >= m_tInfo.fX)
	{
		m_tInfo.fAngle = atan2f((RPoint.y - LPoint.y), (RPoint.x - LPoint.x));
	}
	return 0;
}

CPlayer::~CPlayer()
{
	Release_GameObject();
}

int CPlayer::Ready_GameObject()
{
	m_tInfo.fX = 100.f;
	m_tInfo.fY = 400.f;
	m_tInfo.iCX = 20;
	m_tInfo.iCY = 20;
	m_tInfo.fSpeed = 10.f;	
	m_fJumpY = 30.f;
	m_fJumpSpeed = 0;

	return Function_Pass;
}

int CPlayer::Render_GameObject()
{
	Update_Rect();
	Rectangle(m_hdc, m_rc.left, m_rc.top, m_rc.right, m_rc.bottom);
	return Function_Pass;
}

int CPlayer::Update_GameObject()
{
	SetAngle();
	if (GetAsyncKeyState('A') & 0x8000)
	{
		
		if (LPoint.x <= m_tInfo.fX && RPoint.x >= m_tInfo.fX)
		{
			m_tInfo.fX += cosf(m_tInfo.fAngle) * -m_tInfo.fSpeed;
			m_tInfo.fY += sinf(m_tInfo.fAngle) * -m_tInfo.fSpeed;
		}
		else 
		{
			m_tInfo.fX -=   5.f;
		}

	} 	
	if (GetAsyncKeyState('D') & 0x8000)
	{
		if (LPoint.x <= m_tInfo.fX && RPoint.x >= m_tInfo.fX)
		{
			m_tInfo.fX += cosf(m_tInfo.fAngle) * +m_tInfo.fSpeed;
			m_tInfo.fY += sinf(m_tInfo.fAngle) * +m_tInfo.fSpeed;
		}
		else
		{
			m_tInfo.fX +=  5.f;
		}
	}

	if (GetAsyncKeyState('W') & 0x8000)
	{	
		m_tInfo.fY = m_fJumpSpeed*cosf(20)/g_iFrameCount;
	}
	return Function_Pass;
}

int CPlayer::LateUpdate_GameObject()
{
	return Function_Pass;
}

int CPlayer::Release_GameObject()
{
	return Function_Pass;
}
