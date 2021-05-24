#include "stdafx.h"
#include "BossStage.h"
#include "MapObjectManeger.h"
#include "GameObjectManeger.h"
#include "Player.h"
#include "ScrollManeger.h"
#include "MonsterManeger.h"
#include "StageLogo.h"
#include "Boss.h"
#include "BossHPBar.h"

CBossStage::CBossStage()
{
}


CBossStage::~CBossStage()
{
}

CScene * CBossStage::Create()
{
	CScene* pInstance = new CBossStage();
	if (0 > pInstance->Ready_Scene())
	{
		Delete_Dynamic(pInstance);
		return pInstance;
	}
	return pInstance;
}

int CBossStage::Ready_Scene()
{
	CSoundMgr::Get_Instance()->PlayBGM(L"bgm_stage2.wav");
	CSoundMgr::Get_Instance()->PlaySound(L"sfx_teleport.wav", CSoundMgr::PLAYER);
	m_pEffect = CStageLogo::Create(2);
	for (auto& pMonster : CGameObjectManeger::Get_GameObjectManeger()->SetList(GAMEOBJECT::MONSTER))
		pMonster->SetDead();
	
	CMapObjectManeger::Get_MapManeger()->Load_MapObjectManager(L"../Data/Stage_Boss.dat");
	CGameObjectManeger::Get_GameObjectManeger()->GetList(GAMEOBJECT::PLAYER).back()->SetInfo()->fX = 400;
	CGameObjectManeger::Get_GameObjectManeger()->GetList(GAMEOBJECT::PLAYER).back()->SetInfo()->fY = 400;
	CScrollManeger::Set_ScrollX(0);
	CScrollManeger::Set_ScrollX(0);
	CMonsterManeger::Get_MonsterManeger()->Insert_Monster(MONSTER::BOSS, 1600, 600, CGameObjectManeger::Get_GameObjectManeger()->GetList(GAMEOBJECT::PLAYER).back());
	CGameObjectManeger::Get_GameObjectManeger()->Add_GameObject(GAMEOBJECT::UI, CBossHPBar::Create(CGameObjectManeger::Get_GameObjectManeger()->GetList(GAMEOBJECT::BOSS).back()));
	return Function_Pass;
}

void CBossStage::Update_Scene()
{
	m_pEffect->Update_Logo();
	CMapObjectManeger::Get_MapManeger()->Update_MapObjectManerger();
	CGameObjectManeger::Get_GameObjectManeger()->Update_GameObjectManeger();
	CMapObjectManeger::Get_MapManeger()->LateUpdate_MapObjectManeger();
	CGameObjectManeger::Get_GameObjectManeger()->LateUpdate_GameObjectManeger();
}

void CBossStage::Render_Scene(HDC hdc)
{
	CMapObjectManeger::Get_MapManeger()->Render_MapObjectManeger(hdc);
	CGameObjectManeger::Get_GameObjectManeger()->Render_GameObjectManeger(hdc);
	m_pEffect->Render_Logo(hdc);
}

void CBossStage::Release_Scene()
{
}
