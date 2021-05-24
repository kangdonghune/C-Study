#include "stdafx.h"
#include "Main.h"
#include "GameObjectManeger.h"
#include "BitmapManeger.h"
#include "Player.h"
#include "MapObjectManeger.h"
#include "Tile.h"
#include "Celling.h"
#include "ScrollManeger.h"
#include "SceneManeger.h"
POINT g_Mouse = {};
CMain::CMain()
{

}


CMain::~CMain()
{
}

CMain * CMain::Create()
{
	CMain* pInstance = new CMain();
	if (!pInstance->Ready_Main())
	{
		Delete_Dynamic(pInstance);
		return pInstance;
	}
	return pInstance;
}

int CMain::Ready_Main()
{
	m_hdc = GetDC(g_HWND);

	//if (!CGameObjectManeger::Get_GameObjectManeger()->Add_GameObject(GAMEOBJECT::PLAYER, CPlayer::Create()))
	//	return Function_Fail; //플레이어 추가 실패한다면 

	CSceneManeger::Get_SceneManeger()->Change_SceneManager(CSceneManeger::SCENE_MENU);
	CSoundMgr::Get_Instance()->Initialize();
	CSoundMgr::Get_Instance()->PlayBGM(L"bgm_menu.wav");
	return Function_Pass;
}

int CMain::Render_Main()
{
	HDC hDoubleBuffer = CBitmapManeger::Get_BitmapManeger()->Get_BitmapDC(L"DoubleBuff");
	if (nullptr == hDoubleBuffer)
		return Function_Fail;

	HDC BitmapDC = CBitmapManeger::Get_BitmapManeger()->Get_BitmapDC(L"BackBuffer");
	if (nullptr == BitmapDC)
		return Function_Fail;

	BitBlt(hDoubleBuffer, 0, 0, WINCX, WINCY, BitmapDC, 0, 0, SRCCOPY);
	/*CMapObjectManeger::Get_MapManeger()->Render_MapObjectManeger(hDoubleBuffer);
	CGameObjectManeger::Get_GameObjectManeger()->Render_GameObjectManeger(hDoubleBuffer);*/
	CSceneManeger::Get_SceneManeger()->Render_SceneManager(hDoubleBuffer);
	BitBlt(m_hdc, 0, 0, WINCX, WINCY, hDoubleBuffer, 0, 0, SRCCOPY);
	return Function_Pass;
}

int CMain::Update_Main()
{
	CSceneManeger::Get_SceneManeger()->Update_SceneManager();
	//CMapObjectManeger::Get_MapManeger()->Update_MapObjectManerger();
	//CGameObjectManeger::Get_GameObjectManeger()->Update_GameObjectManeger();

	CScrollManeger::ScrollLcok();
	return Function_Pass;
}

int CMain::LateUpdate_Main()
{
	return Function_Pass;
}

int CMain::Release_Main()
{
	DeleteDC(m_hdc);
	CBitmapManeger::Destroy_BitmapManeger();
	CGameObjectManeger::Destroy_GameObjectManeger();
	return Function_Pass;
}
