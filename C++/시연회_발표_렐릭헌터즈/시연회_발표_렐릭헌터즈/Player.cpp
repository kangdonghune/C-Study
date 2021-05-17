#include "stdafx.h"
#include "Player.h"
#include "GameObject.h"
#include "BitmapManeger.h"
#include "Gun.h"
#include "GameObjectManeger.h"
#include "Player_Bullet.h"
#include "ScrollManeger.h"
CPlayer::CPlayer()
{
}


CPlayer::~CPlayer()
{
}

CGameObject * CPlayer::Create()
{
	CPlayer* pInstance = new CPlayer();
	if (!pInstance->Ready_GameObject())
	{
		Delete_Dynamic(pInstance);
		MessageBox(nullptr,L"Ready ¿À·ù", L"CPlayer::Create()", 0);
		return pInstance;
	}
	return pInstance;
}

void CPlayer::IsOffset()
{
	float fScrollY = CScrollManeger::Get_ScrollY();
	float fScrollX = CScrollManeger::Get_ScrollX();
	float X = m_tInfo.fX + fScrollX;
	float Y = m_tInfo.fY + fScrollY;
	if ((WINCX >> 1) + 200 < X)
		CScrollManeger::Set_ScrollX(-m_tInfo.fSpeed);
	if ((WINCX >> 1) - 200 > X)
		CScrollManeger::Set_ScrollX(m_tInfo.fSpeed);
	if ((WINCY >> 1) + 100 < Y)
		CScrollManeger::Set_ScrollY(-m_tInfo.fSpeed);
	if ((WINCY >> 1) - 100 > Y)
		CScrollManeger::Set_ScrollY(m_tInfo.fSpeed);

	int i = 0;
	int j = 0;
}

void CPlayer::Idle()
{
	if (GetAsyncKeyState('A') & 0x8000)
	{
		
		m_iState = WALK;
		m_tAni.iStart = 0;
	}

	if (GetAsyncKeyState('D') & 0x8000)
	{
		m_iState = WALK;
		m_tAni.iStart = 0;
	}
	if (GetAsyncKeyState('S') & 0x8000)
	{
		m_iState = WALK;
		m_tAni.iStart = 0;
	}
	if (GetAsyncKeyState('W') & 0x8000)
	{
		m_iState = WALK;
		m_tAni.iStart = 0;
	}
	if (GetAsyncKeyState(VK_SHIFT) & 0x8000)
	{
		m_iState = RUN;
		m_tAni.iStart = 0;
	}
	if (GetAsyncKeyState(VK_LBUTTON) & 0x8000)
	{
		CGameObjectManeger::Get_GameObjectManeger()->Add_GameObject(GAMEOBJECT::PLAYER_BULLET, CPlayer_Bullet::Create(this));
		m_iOldState = m_iState;
		m_iState = MELEE;
		m_tAni.iStart = 0;
	}
}

void CPlayer::Walk()
{
	bool bIsChange = false;
	if (GetAsyncKeyState('A') & 0x8000)
	{
		m_tInfo.fX -= m_tInfo.fSpeed;
		bIsChange = true;
	}

	if (GetAsyncKeyState('D') & 0x8000)
	{
		m_tInfo.fX += m_tInfo.fSpeed;
		bIsChange = true;
	}
	if (GetAsyncKeyState('S') & 0x8000)
	{
		m_tInfo.fY += m_tInfo.fSpeed;
		bIsChange = true;
	}
	if (GetAsyncKeyState('W') & 0x8000)
	{
		m_tInfo.fY -= m_tInfo.fSpeed;
		bIsChange = true;
	}

	if (GetAsyncKeyState(VK_SHIFT) & 0x8000)
	{
		m_iState = RUN;
		m_tAni.iStart = 0;
		return;
	}
	if (GetAsyncKeyState(VK_LBUTTON) & 0x8000)
	{
		CGameObjectManeger::Get_GameObjectManeger()->Add_GameObject(GAMEOBJECT::PLAYER_BULLET, CPlayer_Bullet::Create(this));
		m_iOldState = m_iState;
		m_iState = MELEE;
		m_tAni.iStart = 0;
		return;
	}

	if (bIsChange == false)
	{
		m_iState = IDLE;
		m_tAni.iStart = 0;
	}
}

void CPlayer::Run()
{
	bool bIsChange = false;

	if (!(GetAsyncKeyState(VK_SHIFT) & 0x8000))
	{
		m_iState = WALK;
		m_tAni.iStart = 0;
		return;
	}

	if (GetAsyncKeyState('A') & 0x8000)
	{
		m_tInfo.fX -= m_tInfo.fSpeed * 1.5;
		bIsChange = true;
	}

	if (GetAsyncKeyState('D') & 0x8000)
	{
		m_tInfo.fX += m_tInfo.fSpeed * 1.5;
		bIsChange = true;
	}
	if (GetAsyncKeyState('S') & 0x8000)
	{
		m_tInfo.fY += m_tInfo.fSpeed * 1.5;
		bIsChange = true;
	}
	if (GetAsyncKeyState('W') & 0x8000)
	{
		m_tInfo.fY -= m_tInfo.fSpeed * 1.5;
		bIsChange = true;
	}

	if (GetAsyncKeyState(VK_LBUTTON) & 0x8000)
	{
		CGameObjectManeger::Get_GameObjectManeger()->Add_GameObject(GAMEOBJECT::PLAYER_BULLET, CPlayer_Bullet::Create(this));

		return;
	}

	if (bIsChange == false)
	{
		m_iState = IDLE;
		m_tAni.iStart = 0;
	}


}

void CPlayer::Melee()
{
	bool bIsChange = false;

	if (m_tAni.iStart == m_tAni.iEnd)
	{
		m_iState = IDLE;
		m_tAni.iStart = 0;
	}

	if (GetAsyncKeyState(VK_LBUTTON) & 0x0001)
	{
		CGameObjectManeger::Get_GameObjectManeger()->Add_GameObject(GAMEOBJECT::PLAYER_BULLET, CPlayer_Bullet::Create(this));
		m_iState = m_iOldState;
		m_tAni.iStart = 0;
		return;
	}

	if (GetAsyncKeyState('A') & 0x8000)
	{
		m_tInfo.fX -= m_tInfo.fSpeed * 0.7f;
		bIsChange = true;
	}

	if (GetAsyncKeyState('D') & 0x8000)
	{
		m_tInfo.fX += m_tInfo.fSpeed* 0.7f;
		bIsChange = true;
	}
	if (GetAsyncKeyState('S') & 0x8000)
	{
		m_tInfo.fY += m_tInfo.fSpeed* 0.7f;
		bIsChange = true;
	}
	if (GetAsyncKeyState('W') & 0x8000)
	{
		m_tInfo.fY -= m_tInfo.fSpeed* 0.7f;
		bIsChange = true;
	}

	if (GetAsyncKeyState(VK_SHIFT) & 0x8000)
	{
		m_iState = RUN;
		m_tAni.iStart = 0;
		return;
	}
}

void CPlayer::CheckState(int State)
{
	switch (State)
	{
	case IDLE:
		m_tAni.iEnd = 9;
		break;
	case WALK:
		m_tAni.iEnd = 5;
		break;
	case RUN:
		m_tAni.iEnd = 5;
		break;
	case MELEE:
		m_tAni.iEnd = 5;
		break;
	default:
		m_iState = DEAD;
		break;
	}
}

int CPlayer::CheckPlayerDir()
{
	GetCursorPos(&m_tMouse);
	ScreenToClient(g_HWND, &m_tMouse);
	return m_tInfo.fX - m_tMouse.x;
}


int CPlayer::Ready_GameObject()
{
	m_tInfo.fX = 200.f;
	m_tInfo.fY = 200.f;
	m_tInfo.iCX = PLAYER_ICX;
	m_tInfo.iCY = PLAYER_ICY;
	m_tInfo.fSpeed = PLAYER_SPEED;
	m_tInfo.fAngle = 0;
	m_idir = 1;
	if (!(CGameObjectManeger::Get_GameObjectManeger()->Add_GameObject(GAMEOBJECT::GUN, CGun::Create(this))))
	return Function_Fail;

	
	return Function_Pass;
}

int CPlayer::Render_GameObject(HDC hdc)
{
	UpdateRect();
	CheckState(m_iState);
	if (m_tAni.iStart > m_tAni.iEnd)
		m_tAni.iStart = 0;
	GdiTransparentBlt(hdc, m_Rc.left, m_Rc.top, PLAYER_ICX, PLAYER_ICY, m_ObjectDc, PLAYER_ICX  * m_tAni.iStart, 0,PLAYER_ICX, PLAYER_ICY, bmi_BackGround);
	m_tAni.iStart++;
	
	return Function_Pass;
}

int CPlayer::Update_GameObject()
{
	m_idir = CheckPlayerDir();
	switch (m_iState)
	{
	case IDLE:
		m_ObjectDc = CBitmapManeger::Get_BitmapManeger()->Get_BitmapDC(L"Player_idle(R)");
		Idle();
		if (m_idir > 0)
			m_ObjectDc = CBitmapManeger::Get_BitmapManeger()->Get_BitmapDC(L"Player_idle(L)");
		break;
	case WALK:
		m_ObjectDc = CBitmapManeger::Get_BitmapManeger()->Get_BitmapDC(L"Player_walk(R)");
		Walk();
		if (m_idir > 0)
			m_ObjectDc = CBitmapManeger::Get_BitmapManeger()->Get_BitmapDC(L"Player_walk(L)");
		break;
	case RUN:
		m_ObjectDc = CBitmapManeger::Get_BitmapManeger()->Get_BitmapDC(L"Player_run(R)");
		Run();
		if (m_idir > 0)
			m_ObjectDc = CBitmapManeger::Get_BitmapManeger()->Get_BitmapDC(L"Player_run(L)");
		break;
	case MELEE:
		m_ObjectDc = CBitmapManeger::Get_BitmapManeger()->Get_BitmapDC(L"Player_melee(R)");
		Melee();
		if (m_idir > 0)
			m_ObjectDc = CBitmapManeger::Get_BitmapManeger()->Get_BitmapDC(L"Player_melee(L)");
		break;
	default:
		break;
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
