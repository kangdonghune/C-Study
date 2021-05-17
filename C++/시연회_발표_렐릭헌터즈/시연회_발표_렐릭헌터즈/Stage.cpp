#include "stdafx.h"
#include "Stage.h"
#include "GameObject.h"
#include "Player.h"
#include "GameObjectManeger.h"
#include "MapObjectManeger.h"

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
	CGameObject* pObject = CPlayer::Create();
	CGameObjectManeger::Get_GameObjectManeger()->Add_GameObject(GAMEOBJECT::PLAYER, pObject);

	CMapObjectManeger::Get_MapManeger()->Load_MapObjectManager();
	return Function_Pass;
}

void CStage::Update_Scene()
{
	CMapObjectManeger::Get_MapManeger()->Update_MapObjectManerger();
	CGameObjectManeger::Get_GameObjectManeger()->Update_GameObjectManeger();
	CMapObjectManeger::Get_MapManeger()->LateUpdate_MapObjectManeger();
	CGameObjectManeger::Get_GameObjectManeger()->LateUpdate_GameObjectManeger();
}

void CStage::Render_Scene(HDC hdc)
{
	CMapObjectManeger::Get_MapManeger()->Render_MapObjectManeger(hdc);
	CGameObjectManeger::Get_GameObjectManeger()->Render_GameObjectManeger(hdc);
}

void CStage::Release_Scene()
{
}
