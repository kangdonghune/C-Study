#include "stdafx.h"
#include "Player.h"
#include "GameObject.h"
#include "BitmapManeger.h"
#include "Gun.h"
#include "GameObjectManeger.h"
#include "Player_Bullet.h"
#include "ScrollManeger.h"
#include "MapObjectManeger.h"
#include "Grenade.h"
#include "SceneManeger.h"
#include "Pistol.h"

CPlayer::CPlayer()
	:m_bGrenadeOn(false)
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
		MessageBox(nullptr,L"Ready 오류", L"CPlayer::Create()", 0);
		return pInstance;
	}
	return pInstance;
}

void CPlayer::IsOffset()
{
	float RunSpeed = 1.f;
	float fScrollX = CScrollManeger::Get_ScrollX();
	float fScrollY = CScrollManeger::Get_ScrollY();
	float X = m_tInfo.fX + fScrollX;
	float Y = m_tInfo.fY + fScrollY;
	if (GetState() == RUN)
	{
		RunSpeed = 1.25f;
	}
	// x 200~600 y 200~400 사이에 플레이어는 고정하고 그 범위 벗어난 만큼 스크롤값 부여
	if ((WINCX / 2 + 30) < X)
		CScrollManeger::Set_ScrollX(-1*m_tInfo.fSpeed*RunSpeed);
	if ((WINCX / 2 - 30) > X)
	{
		if ((WINCX / 2 - 30) > m_tInfo.fX)
		{
			CScrollManeger::Set_ScrollX(0);
		}
		else
			CScrollManeger::Set_ScrollX(m_tInfo.fSpeed*RunSpeed);
	}
	if ((WINCY / 2 + 30) < Y)
		CScrollManeger::Set_ScrollY(-1 * m_tInfo.fSpeed*RunSpeed);
	if ((WINCY / 2 - 30) > Y)
	{
		if ((WINCY / 2 - 30) > m_tInfo.fY)
		{
			CScrollManeger::Set_ScrollY(0);
		}
		else
			CScrollManeger::Set_ScrollY(m_tInfo.fSpeed*RunSpeed);
	}
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
		m_tInfo.fX -= m_tInfo.fSpeed * 1.25;
		bIsChange = true;
	}

	if (GetAsyncKeyState('D') & 0x8000)
	{
		m_tInfo.fX += m_tInfo.fSpeed * 1.25;
		bIsChange = true;
	}
	if (GetAsyncKeyState('S') & 0x8000)
	{
		m_tInfo.fY += m_tInfo.fSpeed * 1.25;
		bIsChange = true;
	}
	if (GetAsyncKeyState('W') & 0x8000)
	{
		m_tInfo.fY -= m_tInfo.fSpeed * 1.25;
		bIsChange = true;
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

		m_iState = m_iOldState;
		m_tAni.iStart = 0;
		return;
	}

}

void CPlayer::ReadyDead()
{
	if (m_tAni.iStart > m_tAni.iEnd)
	{
		m_iState = DEAD;
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
	case READYDEAD:
		m_tAni.iEnd = 10;
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
	return m_tInfo.fX - (m_tMouse.x - CScrollManeger::Get_ScrollX());
}

void CPlayer::UpdateHitBox()
{
	m_rcHitBox.left = m_tInfo.fX - PLAYER_HITBOXCX/2;
	m_rcHitBox.top	= (m_tInfo.fY - PLAYER_HITBOXCY/2);
	m_rcHitBox.right = m_tInfo.fX + PLAYER_HITBOXCX/2;
	m_rcHitBox.bottom = m_tInfo.fY + PLAYER_HITBOXCY/2 ;
}


int CPlayer::Ready_GameObject()
{
	m_tInfo.fX = 400.f;
	m_tInfo.fY = 400.f;
	m_tInfo.iCX = PLAYER_ICX;
	m_tInfo.iCY = PLAYER_ICY;
	m_tInfo.fSpeed = PLAYER_SPEED;
	m_tInfo.fAngle = 0;
	m_tInfo.iMaxHp = 6000;
	m_tInfo.iHP = m_tInfo.iMaxHp;
	m_tInfo.dwTime = GetTickCount();
	m_tInfo.LimitTime = 180;
	m_idir = 1;
	UpdateHitBox();
	m_tGunAni.iStart = 0;
	m_iGunNum = 0;
	//m_pMyGun = CPistol::Create(this);
	//if (!(CGameObjectManeger::Get_GameObjectManeger()->Add_GameObject(GAMEOBJECT::GUN, m_pMyGun)))
	//	return Function_Fail;

	
	return Function_Pass;
}

int CPlayer::Render_GameObject(HDC hdc)
{


	CheckState(m_iState);
	if (m_iState == DEAD)
		return  Function_Pass;
	if (m_tAni.iStart > m_tAni.iEnd) 
		m_tAni.iStart = 0;
	GdiTransparentBlt(hdc, m_Rc.left + CScrollManeger::Get_ScrollX(), m_Rc.top + CScrollManeger::Get_ScrollY(), PLAYER_ICX, PLAYER_ICY, m_ObjectDc, PLAYER_ICX  * m_tAni.iStart, 0, PLAYER_ICX, PLAYER_ICY, bmi_BackGround);
	if(m_tInfo.dwTime +80 < GetTickCount())
	{
		m_tAni.iStart++;
		m_tInfo.dwTime = GetTickCount();
	}

	return Function_Pass;
}

int CPlayer::Update_GameObject()
{

	if (0 >= m_tInfo.iHP)
	{
		if (m_iState != READYDEAD)
		{
			m_iState = READYDEAD;
			m_tAni.iStart = 0;
			for (auto& pGuns : m_vecGuns)
				pGuns->SetDead();
			m_vecGuns.clear();
		}	
	}
		
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

	case READYDEAD:
		m_ObjectDc = CBitmapManeger::Get_BitmapManeger()->Get_BitmapDC(L"Player_Dead(R)");
		ReadyDead();
		if(m_idir > 0)
			m_ObjectDc = CBitmapManeger::Get_BitmapManeger()->Get_BitmapDC(L"Player_Dead(L)");
		break;
	case DEAD:
		break;
	default:
		break;
	}
	IsOffset();
	UpdateRect();
	UpdateHitBox();
	CheckMouseDir();
	m_tInfo.fAngle = (m_tInfo.fAngle * RADIAN);
	if (m_tInfo.fAngle < 0)
		m_tInfo.fAngle = 180 + (180-fabs(m_tInfo.fAngle));
	m_tGunAni.iStart = m_tInfo.fAngle / 10;

	if (GetAsyncKeyState(VK_LBUTTON) & 0x8000)
	{
		if (m_pMyGun == nullptr)
			return Function_Pass;

		if (dynamic_cast<CGameObject*>(m_pMyGun)->Get_GunInfo()->fBulletTime + dynamic_cast<CGameObject*>(m_pMyGun)->Get_GunInfo()->fBulletCoolTime < GetTickCount())
		{
			CGameObjectManeger::Get_GameObjectManeger()->Add_GameObject(GAMEOBJECT::PLAYER_BULLET, CPlayer_Bullet::Create(this));
			dynamic_cast<CGameObject*>(m_pMyGun)->Get_GunInfo()->fBulletTime = GetTickCount();
			CSceneManeger::Get_SceneManeger()->SetWaveGunRebounde(true);
		}
	}

	if (GetAsyncKeyState('Q') & 0x0001 && m_bGrenadeOn)
	{
		GetCursorPos(&m_tMouse);
		ScreenToClient(g_HWND, &m_tMouse);
		CGameObjectManeger::Get_GameObjectManeger()->Add_GameObject(GAMEOBJECT::GRENADE, CGrenade::Create(this, m_tMouse));
	}

	if (GetAsyncKeyState('R') & 0x0001)
	{
		int GunsSize = m_vecGuns.size(); //한개라도 있으면 1;
		if (!m_vecGuns.empty())
		{
			m_pMyGun = m_vecGuns[m_iGunNum];
			if (m_iGunNum < GunsSize-1)
				m_iGunNum++;
			else
				m_iGunNum = 0;
		}
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
