#include "stdafx.h"
#include "GameObjectManeger.h"
#include "GameObject.h"

CGameObjectManeger* CGameObjectManeger::m_pInstance = nullptr;
CGameObjectManeger::CGameObjectManeger()
{
}


CGameObjectManeger::~CGameObjectManeger()
{
	Release_GameObjectManeger();
}

CGameObjectManeger * CGameObjectManeger::Get_GameObjectManeger()
{
	if (nullptr == m_pInstance)
	{
		m_pInstance = new CGameObjectManeger();
	}
	return m_pInstance;
}

void CGameObjectManeger::Destroy_GameObjectManeger()
{
	if (m_pInstance)
	{
		delete m_pInstance;
		m_pInstance = nullptr;
	}
}

int CGameObjectManeger::Add_GameObject(GAMEOBJECT::Object Num, CGameObject * pObject)
{
	if (nullptr == pObject || Num >= GAMEOBJECT::END)
		return Function_Fail;

	m_listGameObject[Num].emplace_back(pObject);
	return Function_Pass;
}



int CGameObjectManeger::Ready_GameObjectManeger()
{
	return Function_Pass;
}

int CGameObjectManeger::Render_GameObjectManeger(HDC hdc)
{
	for (int i = 0; i < GAMEOBJECT::END; ++i)
	{
		for (auto& iter = m_listGameObject[i].begin(); iter != m_listGameObject[i].end(); ++iter)
		{
			(*iter)->Render_GameObject(hdc);
		}
	}
	return Function_Pass;
}

int CGameObjectManeger::Update_GameObjectManeger()
{
	for (int i = 0; i < GAMEOBJECT::END; i++)
	{
		for (auto& iter = m_listGameObject[i].begin(); iter != m_listGameObject[i].end();)
		{

			if (DEAD == (*iter)->GetState())
			{
				Delete_Dynamic(*iter);
				iter = m_listGameObject[i].erase(iter);
			}
			else
			{
				(*iter)->Update_GameObject();
				++iter;
			}

		}
	}
	return Function_Pass;
}

int CGameObjectManeger::LateUpdate_GameObjectManeger()
{
	for (int i = 0; i < GAMEOBJECT::END; ++i)
	{
		for (auto& iter = m_listGameObject[i].begin(); iter != m_listGameObject[i].end(); ++iter)
		{
			(*iter)->LateUpdate_GameObject();
		}
	}
	return Function_Pass;
}

int CGameObjectManeger::Release_GameObjectManeger()
{
	for (int i = 0; i < GAMEOBJECT::END; i++)
	{
		for (auto& pObject : m_listGameObject[i])
		{
			Delete_Dynamic(pObject);
		}
		m_listGameObject[i].clear();
	}
	return Function_Pass;
}

CGameObject * CGameObjectManeger::Get_Target(GAMEOBJECT::Object Num)
{
	if (m_listGameObject[Num].empty() || Num >= GAMEOBJECT::END)
		return nullptr;

	CGameObject* pTarget = m_listGameObject[Num].front();

	return pTarget;
}
