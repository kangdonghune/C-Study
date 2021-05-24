#include "stdafx.h"
#include "MonsterManeger.h"
#include "Turtle.h"
#include "Boss.h"
#include "GameObjectManeger.h"

CMonsterManeger* CMonsterManeger::m_pInstance = nullptr;

CMonsterManeger::CMonsterManeger()
{
}


CMonsterManeger::~CMonsterManeger()
{
}

CMonsterManeger * CMonsterManeger::Get_MonsterManeger()
{
	if (nullptr == m_pInstance)
		m_pInstance = new CMonsterManeger();
	return m_pInstance;
}

void CMonsterManeger::Insert_Monster(MONSTER::Name Name, float X, float Y, CGameObject * pTarget)
{
	switch (Name)
	{
	case MONSTER::TURTLE:
		CGameObjectManeger::Get_GameObjectManeger()->Add_GameObject(GAMEOBJECT::MONSTER,CTultle::Create(MONSTER::TURTLE, X, Y, pTarget));
		break;
	case MONSTER::BOSS:
		CGameObjectManeger::Get_GameObjectManeger()->Add_GameObject(GAMEOBJECT::BOSS, CBoss::Create(MONSTER::BOSS, X, Y, pTarget));
		break;
	case MONSTER::END:
		break;
	default:
		break;
	}
}
