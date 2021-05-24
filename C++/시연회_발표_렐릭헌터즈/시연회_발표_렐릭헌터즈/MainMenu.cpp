#include "stdafx.h"
#include "MainMenu.h"
#include "BitmapManeger.h"
#include "SceneManeger.h"
#include "Logo.h"
CMainMenu::CMainMenu()
{
}


CMainMenu::~CMainMenu()
{
	Release_Scene();
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
	m_pLogo = CLogo::Create();
	return Function_Pass;
}

void CMainMenu::Update_Scene()
{
	m_pLogo->Update_Logo();

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
	m_pLogo->Render_Logo(hdc);
	HDC hMemDCArrow = CBitmapManeger::Get_BitmapManeger()->Get_BitmapDC(L"Check_Arrow");
	HDC hMemDCEnter = CBitmapManeger::Get_BitmapManeger()->Get_BitmapDC(L"PressEnter");
	GdiTransparentBlt(hdc, 60, 360, MainArrow, MainArrow, hMemDCArrow, 0, 0, MainArrow, MainArrow, bmi_BackGround);
	GdiTransparentBlt(hdc, 100, 360, Enterbar_CX -10, Enterbar_CY - 10, hMemDCEnter, 0, 0, Enterbar_CX, Enterbar_CY, bmi_BackGround);

}

void CMainMenu::Release_Scene()
{
	if (nullptr != m_pLogo)
	{
		delete m_pLogo;
		m_pLogo = nullptr;
	}
}
