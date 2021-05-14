#include "stdafx.h"
#include "Main.h"
#include "GameObject.h"
#include "Player.h"
#include "Bullet.h"
#include "Enemy.h"

CMain::CMain()
{
}


CMain::~CMain()
{
}

int CMain::Ready_Main()
{
	m_Mainhdc = GetDC(g_hwnd);
	m_dwEnemySpawnTime = GetTickCount();
	CGameObject* pPlayer = CPlayer::Create(m_Mainhdc, m_pGameObjList);
	m_pGameObjList[GameObjectList::PLAYER].push_back(pPlayer);

	return READY_PASS;
}

void CMain::Render_Main()
{
	Rectangle(m_Mainhdc, 0, 0, WINCX, WINCY);
	Rectangle(m_Mainhdc, 100, 100, INNERCX, INNERCY);
	for (int i = 0; i < GameObjectList::SIZE; i++)
	{
		for (auto& iter = m_pGameObjList[i].begin(); iter != m_pGameObjList[i].end(); iter++)
		{
			(*iter)->Render_GameObject(m_Mainhdc);
		}
	}
}

void CMain::Update_Main()
{
	if (m_dwEnemySpawnTime + 500 < GetTickCount())
	{
		CGameObject* pEnemy = CEnemy::Create(m_Mainhdc, *m_pGameObjList[GameObjectList::PLAYER].back()->GetInfo());
		m_pGameObjList[GameObjectList::ENEMY].push_back(pEnemy);
		m_dwEnemySpawnTime = GetTickCount();
	}

	for (int i = 0; i < GameObjectList::SIZE; i++)
	{
		for (auto& iter = m_pGameObjList[i].begin(); iter != m_pGameObjList[i].end();)
		{
			if (i == GameObjectList::ENEMY)
			{
				dynamic_cast<CEnemy*>(*iter)->SetAngle(*m_pGameObjList[GameObjectList::PLAYER].back()->GetInfo());
			}
			if (IDLE == (*iter)->Update_GameObject())
			{
				iter = m_pGameObjList[i].erase(iter);
			}
			if (iter != m_pGameObjList[i].end())
				iter++;
		}
	}
}

void CMain::LateUpdate_Main()
{
	for (int i = 0; i < GameObjectList::SIZE; i++)
	{
		for (auto& iter = m_pGameObjList[i].begin(); iter != m_pGameObjList[i].end(); )
		{
			if (IDLE == (*iter)->LateUpdate_GameObject())
			{
				iter = m_pGameObjList[i].erase(iter);	
			}
			if (iter != m_pGameObjList[i].end())
				iter++;
		}
	}
	RECT rc = {};
	for (auto& iterEnemy = m_pGameObjList[GameObjectList::ENEMY].begin(); iterEnemy != m_pGameObjList[GameObjectList::ENEMY].end();)
	{
		for (auto& iterBullet = m_pGameObjList[GameObjectList::BULLET].begin(); iterBullet != m_pGameObjList[GameObjectList::BULLET].end();)
		{
			if (IntersectRect(&rc, (*iterEnemy)->GetRect(), (*iterBullet)->GetRect()))
			{
				(*iterEnemy)->Dead();
				(*iterBullet)->Dead();
			}
			if (iterBullet != m_pGameObjList[GameObjectList::BULLET].end())
				iterBullet++;
		}
		if (iterEnemy != m_pGameObjList[GameObjectList::ENEMY].end())
			iterEnemy++;
	}

	for (auto& iterEnemy = m_pGameObjList[GameObjectList::ENEMY].begin(); iterEnemy != m_pGameObjList[GameObjectList::ENEMY].end();)
	{
		for (auto& iterShield = m_pGameObjList[GameObjectList::SHIELD].begin(); iterShield != m_pGameObjList[GameObjectList::SHIELD].end();)
		{
			if (IntersectRect(&rc, (*iterEnemy)->GetRect(), (*iterShield)->GetRect()))
			{
				(*iterEnemy)->Dead();
				(*iterShield)->Dead();
			}
			if (iterShield != m_pGameObjList[GameObjectList::SHIELD].end())
				iterShield++;
		}
		if (iterEnemy != m_pGameObjList[GameObjectList::ENEMY].end())
			iterEnemy++;
	}

	for (auto& iterGuide = m_pGameObjList[GameObjectList::GUIDEBULLET].begin(); iterGuide != m_pGameObjList[GameObjectList::GUIDEBULLET].end();)
	{
		for (auto& iterEnemy = m_pGameObjList[GameObjectList::ENEMY].begin(); iterEnemy != m_pGameObjList[GameObjectList::ENEMY].end();)
		{
			if (IntersectRect(&rc, (*iterGuide)->GetRect(), (*iterEnemy)->GetRect()))
			{
				(*iterEnemy)->Dead();
			}
			if (iterEnemy != m_pGameObjList[GameObjectList::ENEMY].end())
				iterEnemy++;
		}
		if (iterGuide != m_pGameObjList[GameObjectList::GUIDEBULLET].end())
			iterGuide++;
	}


}

void CMain::Release_Main()
{
	DeleteDC(m_Mainhdc);
	for (int i = 0; i < GameObjectList::SIZE; i++)
	{
		for (auto& iter = m_pGameObjList[i].begin(); iter != m_pGameObjList[i].end();)
		{
			iter = m_pGameObjList[i].erase(iter);
		}
	}
}

CMain * CMain::Create()
{	
	CMain* pInstance = new CMain;
	if (!pInstance->Ready_Main())
	{
		delete pInstance;
		pInstance = nullptr;
	}
	return pInstance;
}
