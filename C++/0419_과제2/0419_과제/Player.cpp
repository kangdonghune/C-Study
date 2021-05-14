#include "stdafx.h"
#include "Player.h"
#include "Bullet.h"


CPlayer::CPlayer()
{
}


CPlayer::~CPlayer()
{
	Release_GameObj();
}

int CPlayer::Ready_GameObj()
{
	m_tXY.fX = 400.f;
	m_tXY.fY = 300.f;
	m_tXY.iWide = 70;
	return Ready_Success;
}

void CPlayer::Render_GameObj(HDC hdc)
{
	RECT rc = { m_tXY.fX - (m_tXY.iWide / 2), m_tXY.fY - (m_tXY.iWide / 2), m_tXY.fX + (m_tXY.iWide / 2), m_tXY.fY + (m_tXY.iWide / 2) };
	Rectangle(hdc, rc.left,rc.top, rc.right, rc.bottom);
	
}

void CPlayer::Update_GameObj()
{
	/*반환값 4개
	0x0000 현재 아무것도 안 누름
	0x0001 1 현재 안눌렸고 이전에 눌렸을 때  맨 뒤의 1은 이전에 눌렀다
	0x8000 - 8000은 signed이기 때문에 음수다. 현재 눌렸다는 의미.
	0x8001  현재도 눌리고 있고 이전에도 눌리고 있다.
	*/
	if (GetAsyncKeyState(VK_LEFT) & 0x8000) //이전 눌린 여부와 상관없이 현재 눌린지만 보고 싶을 때 사용 //코드라인이 실행되는 단계에서 키가 눌렸는지 판별
		m_tXY.fX -= 8.f;
	if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
		m_tXY.fX += 8.f;
	if (GetAsyncKeyState(VK_UP) & 0x8000)
		m_tXY.fY -= 8.f;
	if (GetAsyncKeyState(VK_DOWN) & 0x8000)
		m_tXY.fY += 8.f;

	if (GetAsyncKeyState(0x41))
	{
		m_pBulletList->push_back(CBullet::Create(m_tXY));
		m_pBulletList->back()->SetDir() = A;
	}
		
	if (GetAsyncKeyState(0x44))
	{
		m_pBulletList->push_back(CBullet::Create(m_tXY));
		m_pBulletList->back()->SetDir() = D;
	}
	if (GetAsyncKeyState(0x57))
	{
		m_pBulletList->push_back(CBullet::Create(m_tXY));
		m_pBulletList->back()->SetDir() = W;
	}
	if (GetAsyncKeyState(0x53))
	{
		m_pBulletList->push_back(CBullet::Create(m_tXY));
		m_pBulletList->back()->SetDir() = S;
	}
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


