#include "stdafx.h"
#include "SceneManeger.h"
#include "Scene.h"
#include "Editor.h"
#include "Stage.h"
#include "MainMenu.h"
#include "GameObjectManeger.h"
#include "GameObject.h"
#include "MapObject.h"
#include "MapObjectManeger.h"
#include "ColliderManeger.h"
#include "BossStage.h"
#include "Wave.h"

CSceneManeger* CSceneManeger::m_pInstance = nullptr;
CSceneManeger::CSceneManeger()
	:WaveOn(false)
	,WaveGunRebounde(false)
{
}


CSceneManeger::~CSceneManeger()
{
	Release_SceneManager();
}

CSceneManeger * CSceneManeger::Get_SceneManeger()
{
	if (nullptr == m_pInstance)
	{
		m_pInstance = new CSceneManeger();
	}
	return m_pInstance;
}

	void CSceneManeger::Destroy_SceneManeger()
{
	if (nullptr != m_pInstance)
	{
		delete m_pInstance;
		m_pInstance == nullptr;
	}
}

void CSceneManeger::Change_SceneManager(ID eNextScene)
{
	m_eNextScene = eNextScene;
	if (m_eCurScene != m_eNextScene)
	{

		Delete_Dynamic(m_pScene);
		switch (m_eNextScene)
		{
		/*case CSceneManeger::SCENE_LOADING:
			m_pScene = CLoading::Create();
			break;*/
		case CSceneManeger::SCENE_MENU:
			m_pScene = CMainMenu::Create();
			break;
		case CSceneManeger::SCENE_STAGE1:
			m_pScene = CStage::Create();
			break;
		case CSceneManeger::SCENE_BOSS:
			m_pScene = CBossStage::Create();
			break;
		case CSceneManeger::SCENE_EDIT:
			m_pScene = CEditor::Create();
			break;
		case CSceneManeger::SCENE_END:
			break;
		default:
			break;
		}
		m_eCurScene = m_eNextScene;
	}
}


void CSceneManeger::Update_SceneManager()
{
	if (WaveOn)
		WaveOn = CWave::Wave();
	if (WaveGunRebounde)
		WaveGunRebounde = CWave::WaveGunRebound();

	for (int i = 0; i < MAPOBJECT::END; i++)
	{
		CColliderManeger::Get_ColliderManeger()->Collision_PlayerAndNonePassObj(&(CMapObjectManeger::Get_MapManeger()->Get_ObjectVector(i)), &CGameObjectManeger::Get_GameObjectManeger()->SetList(GAMEOBJECT::PLAYER));
	}
	for (int i = 0; i < MAPOBJECT::END; i++)
	{
		CColliderManeger::Get_ColliderManeger()->Collision_PlayerAndNonePassObj(&(CMapObjectManeger::Get_MapManeger()->Get_ObjectVector(i)), &CGameObjectManeger::Get_GameObjectManeger()->SetList(GAMEOBJECT::MONSTER));
	}
	for (int i = 0; i < MAPOBJECT::END; i++)
	{
		CColliderManeger::Get_ColliderManeger()->Collision_PlayerAndNonePassObj(&(CMapObjectManeger::Get_MapManeger()->Get_ObjectVector(i)), &CGameObjectManeger::Get_GameObjectManeger()->SetList(GAMEOBJECT::BOSS));
	}

	for (int i = 0; i < MAPOBJECT::END; i++)
	{
		CColliderManeger::Get_ColliderManeger()->Collision_BulletAndNonePassObj(&(CMapObjectManeger::Get_MapManeger()->Get_ObjectVector(i)), &CGameObjectManeger::Get_GameObjectManeger()->SetList(GAMEOBJECT::PLAYER_BULLET));
	}
	for (int i = 0; i < MAPOBJECT::END; i++)
	{
		CColliderManeger::Get_ColliderManeger()->Collision_BulletAndNonePassObj(&(CMapObjectManeger::Get_MapManeger()->Get_ObjectVector(i)), &CGameObjectManeger::Get_GameObjectManeger()->SetList(GAMEOBJECT::MONSTER_BULLET));
	}
	CColliderManeger::Get_ColliderManeger()->Collision_UnitAndBullet(&CGameObjectManeger::Get_GameObjectManeger()->SetList(GAMEOBJECT::MONSTER), &CGameObjectManeger::Get_GameObjectManeger()->SetList(GAMEOBJECT::PLAYER_BULLET));
	CColliderManeger::Get_ColliderManeger()->Collision_UnitAndBullet(&CGameObjectManeger::Get_GameObjectManeger()->SetList(GAMEOBJECT::BOSS), &CGameObjectManeger::Get_GameObjectManeger()->SetList(GAMEOBJECT::PLAYER_BULLET));
	CColliderManeger::Get_ColliderManeger()->Collision_UnitAndGrenadeToM(&CGameObjectManeger::Get_GameObjectManeger()->SetList(GAMEOBJECT::MONSTER), &CGameObjectManeger::Get_GameObjectManeger()->SetList(GAMEOBJECT::GRENADE));
	CColliderManeger::Get_ColliderManeger()->Collision_UnitAndGrenade(&CGameObjectManeger::Get_GameObjectManeger()->SetList(GAMEOBJECT::BOSS), &CGameObjectManeger::Get_GameObjectManeger()->SetList(GAMEOBJECT::GRENADE));
	CColliderManeger::Get_ColliderManeger()->Collision_UnitAndBullet(&CGameObjectManeger::Get_GameObjectManeger()->SetList(GAMEOBJECT::PLAYER), &CGameObjectManeger::Get_GameObjectManeger()->SetList(GAMEOBJECT::MONSTER_BULLET));
	


	m_pScene->Update_Scene();

}

void CSceneManeger::Render_SceneManager(HDC hDC)
{
	m_pScene->Render_Scene(hDC);
}

void CSceneManeger::Release_SceneManager()
{
	Delete_Dynamic(m_pScene);
}
