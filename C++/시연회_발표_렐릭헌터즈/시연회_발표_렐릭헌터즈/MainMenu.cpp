#include "stdafx.h"
#include "MainMenu.h"
#include "BitmapManeger.h"
#include "SceneManeger.h"
CMainMenu::CMainMenu()
{
}


CMainMenu::~CMainMenu()
{
}

CScene * CMainMenu::Create()
{
	CMainMenu* pInstance = new CMainMenu();
	if (!pInstance->Ready_Scene())
	{
		delete pInstance;
		pInstance = nullptr;
		return pInstance;
	}

	return pInstance;
}

int CMainMenu::Ready_Scene()
{
	return Function_Pass;
}

void CMainMenu::Update_Scene()
{
	if (GetAsyncKeyState(VK_RETURN) & 0x0001)
		CSceneManeger::Get_SceneManeger()->Change_SceneManager(CSceneManeger::SCENE_STAGE1);
	if (GetAsyncKeyState('E') & 0x0001)
		CSceneManeger::Get_SceneManeger()->Change_SceneManager(CSceneManeger::SCENE_EDIT);
}

void CMainMenu::Render_Scene(HDC hdc)
{
	HDC hMemDC = CBitmapManeger::Get_BitmapManeger()->Get_BitmapDC(L"menu_main"); 
	if (hMemDC == nullptr)
		return;
	BitBlt(hdc, 0, 0, WINCX, WINCY, hMemDC, 0, 0, SRCCOPY);
}

void CMainMenu::Release_Scene()
{
}
