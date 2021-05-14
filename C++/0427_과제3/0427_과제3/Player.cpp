#include "stdafx.h"
#include "Player.h"
#include "GameObject.h"
#include "Bullet.h"
#include "Shield.h"
#include "GuideBullet.h"
CPlayer::CPlayer()
{
}


CPlayer::~CPlayer()
{
	Release_GameObject();
}

int CPlayer::Ready_GameObject(HDC hdc)
{
	m_Gamehdc = hdc;
	m_tInfo.fX = 420.0f;
	m_tInfo.fY = 310.0f;
	m_tInfo.iWide = 70;
	m_tInfo.fSpeed = 10.0f;
	m_dwBulletCoolTime = GetTickCount();
	m_dwShieldCoolTime = GetTickCount();;
	m_Brush = (HBRUSH)CreateSolidBrush(RGB(0, 255, 0));
	

	return READY_PASS;
}

void CPlayer::Render_GameObject(HDC hdc)
{
	UpdateRect();
	m_oldBrush = (HBRUSH)SelectObject(hdc, m_Brush);
	Rectangle(hdc, m_Rect.left, m_Rect.top, m_Rect.right, m_Rect.bottom);
	SelectObject(hdc, m_oldBrush);
	
}

int CPlayer::Update_GameObject()
{
	if (GetAsyncKeyState('A') & 0x8000)
	{
		m_tInfo.fX -= m_tInfo.fSpeed;
	}
	if (GetAsyncKeyState('W') & 0x8000)
	{
		m_tInfo.fY -= m_tInfo.fSpeed;
	}
	if (GetAsyncKeyState('D') & 0x8000)
	{
		m_tInfo.fX += m_tInfo.fSpeed;
	}
	if (GetAsyncKeyState('S') & 0x8000)
	{
		m_tInfo.fY += m_tInfo.fSpeed;
	}
	if (GetAsyncKeyState(VK_LBUTTON) & 0x8000)
	{
		if (m_dwBulletCoolTime + 200 < GetTickCount())
		{
			GetCursorPos(&mouse);
			ScreenToClient(g_hwnd, &mouse);
			m_pBulletList->push_back(CreateBullet(&mouse));
			m_dwBulletCoolTime = GetTickCount();
		}
	}

	if (GetAsyncKeyState('Q') & 0x8000)
	{
		if (m_dwShieldCoolTime + 300 < GetTickCount())
		{
			m_pShieldList->push_back(CreateShield());
			m_dwShieldCoolTime = GetTickCount();
		}
	
	}
	if (GetAsyncKeyState('E') & 0x8000)
	{
		CGameObject* pInstance = CreateGuideBullet();
		dynamic_cast<CGuideBullet*>(pInstance)->SetTarget(m_pGameObjList[GameObjectList::ENEMY].back());
	
		m_pGameObjList[GameObjectList::GUIDEBULLET].push_back(pInstance);

	}

	for (auto& iter = m_pShieldList->begin(); iter != m_pShieldList->end(); iter++)
	{
		dynamic_cast<CShield*>(*iter)->SetXY(m_tInfo);
	}

	return NONIDLE;
}

int CPlayer::LateUpdate_GameObject()
{
	return NONIDLE;
}

void CPlayer::Release_GameObject()
{
	DeleteObject(m_Brush);
}

CGameObject * CPlayer::Create(HDC hdc, list<CGameObject*>* pGameObjectList)
{
	CGameObject* pInstance = new CPlayer();
	if (!pInstance->Ready_GameObject(hdc))
	{
		delete pInstance;
		pInstance = nullptr;
	}
	CPlayer* pPlayer = dynamic_cast<CPlayer*>(pInstance);
	if (pPlayer)
	{
		pPlayer->m_pGameObjList = pGameObjectList;
		pPlayer->m_pBulletList = &(pGameObjectList[GameObjectList::BULLET]);
		pPlayer->m_pShieldList = &(pGameObjectList[GameObjectList::SHIELD]);
	}
	pInstance = pPlayer;
	return pInstance;
}

CGameObject * CPlayer::CreateBullet(POINT* pMouse)
{
	CGameObject* pBullet = CBullet::Create(m_Gamehdc, m_tInfo, pMouse);

	return pBullet;
}

CGameObject * CPlayer::CreateShield()
{
	CGameObject* pShield = CShield::Create(m_Gamehdc, m_tInfo);

	return pShield;
}

CGameObject * CPlayer::CreateGuideBullet()
{
	CGameObject* pInstance = CGuideBullet::Create(m_Gamehdc, this);

	return pInstance;
}


