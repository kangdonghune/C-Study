#include "stdafx.h"
#include "GameObjectManeger.h"
#include "GameObject.h"

CGameObjectManeger* CGameObjectManeger::m_pInstance = nullptr;
CGameObjectManeger::CGameObjectManeger()
{
}


CGameObjectManeger::~CGameObjectManeger()
{
}

CGameObjectManeger * CGameObjectManeger::Get_Maneger()
{
	if (nullptr == m_pInstance)
	{
		m_pInstance = new CGameObjectManeger;
	}
	
	return m_pInstance;
}

int CGameObjectManeger::Add_GameObject(OBJECT::Objects Num, CGameObject * pObject)
{
	if (Num >= OBJECT::END || nullptr == pObject)
		return Function_Fail;

	m_listObject[Num].emplace_back(pObject);
	return Function_Pass;
}

int CGameObjectManeger::Ready_GameObjectManeger()
{
	return  Function_Pass;
}

int CGameObjectManeger::Render_GameObjectManeger()
{
	for (int i = 0; i < OBJECT::END; i++)
	{
		for (auto& pObject : m_listObject[i])
		{
			pObject->Render_GameObject();
		}
	}
	return  Function_Pass;
}

int CGameObjectManeger::Update_GameObjectManeger()
{
	for (int i = 0; i < OBJECT::END; i++)
	{
		for (auto& iter = m_listObject[i].begin(); iter != m_listObject[i].end(); )
		{
			if (DEAD != (*iter)->Update_GameObject())
			{
				Dynamic_delete(*iter);
				iter = m_listObject[i].erase(iter);
			}
			else 
			{
				if(iter != m_listObject[i].end())
				iter++;
			}
		}
	}
	return  Function_Pass;
}

int CGameObjectManeger::LateUpdate_GameObjectManeger()
{
	for (int i = 0; i < OBJECT::END; i++)
	{
		for (auto& pObject : m_listObject[i])
		{
			pObject->LateUpdate_GameObject();
		}
	}
	return  Function_Pass;
}

int CGameObjectManeger::Release_GameObjectManeger()
{
	for (int i = 0; i < OBJECT::END; i++)
	{
		for (auto& pObject : m_listObject[i])
		{
			Dynamic_delete(pObject);
		}
		m_listObject[i].clear();
	}
	return Function_Pass;
}
