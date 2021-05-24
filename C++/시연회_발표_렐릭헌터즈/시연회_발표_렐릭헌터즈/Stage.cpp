#include "stdafx.h"
#include "Stage.h"
#include "GameObject.h"
#include "Player.h"
#include "GameObjectManeger.h"
#include "MapObjectManeger.h"
#include "SceneManeger.h"
#include "Monster.h"
#include "MonsterManeger.h"
#include "Portal.h"
#include "BossGun.h"
#include "StageLogo.h"
#include "PlayerHP.h"
#include "Item.h"

CStage::CStage()
{
}


CStage::~CStage()
{
}

CScene * CStage::Create()
{
	CScene* pInstance = new CStage;
	if (0 > pInstance->Ready_Scene())
	{
		Delete_Dynamic(pInstance);
		return pInstance;
	}
	return pInstance;
}

int CStage::Ready_Scene()
{
	m_pEffect = CStageLogo::Create(1);
	CMapObjectManeger::Get_MapManeger()->Load_MapObjectManager(L"../Data/Stage1.dat");
	CGameObject* pObject = CPlayer::Create();
	CGameObjectManeger::Get_GameObjectManeger()->Add_GameObject(GAMEOBJECT::PLAYER, pObject);
	CGameObjectManeger::Get_GameObjectManeger()->Add_GameObject(GAMEOBJECT::UI, CPlayerHP::Create(pObject));
	CGameObjectManeger::Get_GameObjectManeger()->Add_GameObject(GAMEOBJECT::ITEM, CItem::Create(pObject, ITEM::PISTOL, 600, 400));
	CGameObjectManeger::Get_GameObjectManeger()->Add_GameObject(GAMEOBJECT::ITEM, CItem::Create(pObject, ITEM::MACHINGUN, 300, 2200));
	CGameObjectManeger::Get_GameObjectManeger()->Add_GameObject(GAMEOBJECT::ITEM, CItem::Create(pObject, ITEM::SHOTGUN, 200, 2200));
	CGameObjectManeger::Get_GameObjectManeger()->Add_GameObject(GAMEOBJECT::ITEM, CItem::Create(pObject, ITEM::GRENADE, 700, 2200));

	CMonsterManeger::Get_MonsterManeger()->Insert_Monster(MONSTER::TURTLE, 1800, 400, pObject);
	CMonsterManeger::Get_MonsterManeger()->Insert_Monster(MONSTER::TURTLE, 2000, 600, pObject);
	CMonsterManeger::Get_MonsterManeger()->Insert_Monster(MONSTER::TURTLE, 2100, 600, pObject);
	CMonsterManeger::Get_MonsterManeger()->Insert_Monster(MONSTER::TURTLE, 1900, 700, pObject);
	CMonsterManeger::Get_MonsterManeger()->Insert_Monster(MONSTER::TURTLE, 1700, 800, pObject);
	CMonsterManeger::Get_MonsterManeger()->Insert_Monster(MONSTER::TURTLE, 400, 1300, pObject);
	CMonsterManeger::Get_MonsterManeger()->Insert_Monster(MONSTER::TURTLE, 500, 1400, pObject);
	CMonsterManeger::Get_MonsterManeger()->Insert_Monster(MONSTER::TURTLE, 500, 1500, pObject);
	CMonsterManeger::Get_MonsterManeger()->Insert_Monster(MONSTER::TURTLE, 600, 1500, pObject);
	CMonsterManeger::Get_MonsterManeger()->Insert_Monster(MONSTER::TURTLE, 300, 1700, pObject);
	CMonsterManeger::Get_MonsterManeger()->Insert_Monster(MONSTER::TURTLE, 1800, 1800, pObject);
	CMonsterManeger::Get_MonsterManeger()->Insert_Monster(MONSTER::TURTLE, 1800, 2000, pObject);
	CMapObjectManeger::Get_MapManeger()->Insert_MapObject(MAPOBJECT::WALL, CPortal::Create(2000, 2100));

	m_bStageChange = false;
	return Function_Pass;
}	

void CStage::Update_Scene()
{
	m_pEffect->Update_Logo();
	if (m_pEffect->Get_State() == DEAD)
	{
		delete m_pEffect;
		m_pEffect = nullptr;
	}
	CMapObjectManeger::Get_MapManeger()->Update_MapObjectManerger();
	CGameObjectManeger::Get_GameObjectManeger()->Update_GameObjectManeger();
	CMapObjectManeger::Get_MapManeger()->LateUpdate_MapObjectManeger();
	CGameObjectManeger::Get_GameObjectManeger()->LateUpdate_GameObjectManeger();

	if(m_bStageChange == true)
		CSceneManeger::Get_SceneManeger()->Change_SceneManager(CSceneManeger::ID::SCENE_BOSS);
	if (GetAsyncKeyState('V'))
	{
		CSceneManeger::Get_SceneManeger()->Change_SceneManager(CSceneManeger::ID::SCENE_BOSS);
		m_bStageChange = true;
	}
		


}

void CStage::Render_Scene(HDC hdc)
{
	
	CMapObjectManeger::Get_MapManeger()->Render_MapObjectManeger(hdc);
	CGameObjectManeger::Get_GameObjectManeger()->Render_GameObjectManeger(hdc);
	m_pEffect->Render_Logo(hdc);

}

void CStage::Release_Scene()
{
	if (m_pEffect != nullptr)
	{
		delete m_pEffect;
		m_pEffect = nullptr;
	}
}
