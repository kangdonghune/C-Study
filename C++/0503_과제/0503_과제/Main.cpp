#include "stdafx.h"
#include "Main.h"
#include "GameObjectManeger.h"
#include "GameObject.h"
#include "Player.h"

int g_iFrame = 0;
int g_iFrameCount = 0;
CMain::CMain()
{
}


CMain * CMain::Create()
{
	CMain* pMain = new CMain;
	if (!pMain->Ready_Main())
	{
		Dynamic_delete(pMain);
		return pMain;
	}
	return pMain;
}

CMain::~CMain()
{
	Release_Main();
}

int CMain::Ready_Main()
{
	m_hdc = GetDC(g_hwnd);
	CGameObjectManeger::Get_Maneger()->Add_GameObject(OBJECT::PLAYER,CPlayer::Create(m_hdc));
	return Function_Pass;
}

int CMain::Render_Main()
{
	Rectangle(m_hdc, 0, 0, WinCX, WinCY);
	Rectangle(m_hdc, 100, 100, InnerCX, InnerCY);
	MoveToEx(m_hdc, 100, 400, nullptr);
	LineTo(m_hdc, LPoint.x, LPoint.y);
	LineTo(m_hdc, RPoint.x, RPoint.y);
	LineTo(m_hdc, 700, 200);
	CGameObjectManeger::Get_Maneger()->Render_GameObjectManeger();
	return Function_Pass;
}

int CMain::Update_Main()
{
	CGameObjectManeger::Get_Maneger()->Update_GameObjectManeger();
	return Function_Pass;
}

int CMain::LateUpdate_Main()
{
	CGameObjectManeger::Get_Maneger()->LateUpdate_GameObjectManeger();
	return Function_Pass;
}

int CMain::Release_Main()
{
	DeleteDC(m_hdc);
	CGameObjectManeger::Get_Maneger()->Release_GameObjectManeger();
	return Function_Pass;
}
