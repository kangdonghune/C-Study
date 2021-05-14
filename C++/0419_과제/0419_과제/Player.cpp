#include "stdafx.h"
#include "Player.h"



CPlayer::CPlayer()
{
}


CPlayer::~CPlayer()
{
	Release_GameObj();
}

int CPlayer::Ready_GameObj()
{
	m_tXY.fX = 50.f;
	m_tXY.fY = 50.f;
	return Ready_Success;
}

void CPlayer::Render_GameObj(HDC hdc)
{
	m_hdc = hdc;
	MoveToEx(m_hdc, m_tXY.fX, m_tXY.fY, nullptr);
	LineTo(m_hdc, m_tXY.fX + 200, m_tXY.fY);
	LineTo(m_hdc, m_tXY.fX + 200, m_tXY.fY + 100);
	LineTo(m_hdc, m_tXY.fX, m_tXY.fY + 100);
	LineTo(m_hdc, m_tXY.fX , m_tXY.fY + 200);
	LineTo(m_hdc, m_tXY.fX + 200, m_tXY.fY + 200);

	


	Ellipse(m_hdc, 380, 40, 460, 120);
	Ellipse(m_hdc, 540, 40, 620, 120);

	Ellipse(m_hdc, 400, 60, 440, 100);
	Ellipse(m_hdc, 560, 60, 600, 100);

	Ellipse(m_hdc, 400, 50, 600, 250);
	Ellipse(m_hdc, 420, 70, 580, 230);

	Ellipse(m_hdc, 440, 120, 480, 160);
	Ellipse(m_hdc, 520, 120, 560, 160);

	Ellipse(m_hdc, 495, 190, 515, 210);

}

void CPlayer::Update_GameObj()
{
	Render_GameObj(m_hdc);
}

void CPlayer::Release_GameObj()
{
	
}

CPlayer* CPlayer::Create()
{
	CPlayer* pInstance = new CPlayer();
	if (0 > pInstance->Ready_GameObj()) // ready_Gameobj가 제대로 실행되면 1, 아니면 -1 반환.
	{
		delete pInstance;  // 제대로 초기화가 안되었으니 할당받은 거 해제하고 
		pInstance = nullptr; // nullptr로 초기화.
		return pInstance;
	}

	return pInstance;
}
