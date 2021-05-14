#include "stdafx.h"
#include "Main.h"
#include "GameObjectManeger.h"
#include "BitmapManeger.h"
#include "Player.h"
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

	if (!CGameObjectManeger::Get_GameObjectManeger()->Add_GameObject(OBJECT::PLAYER, CPlayer::Create()))
		return Function_Fail; //플레이어 추가 실패한다면 
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
	CGameObjectManeger::Get_GameObjectManeger()->Render_GameObjectManeger(hDoubleBuffer);
	BitBlt(m_hdc, 0, 0, WINCX, WINCY, hDoubleBuffer, 0, 0, SRCCOPY);
	return Function_Pass;
}

int CMain::Update_Main()
{
	CGameObjectManeger::Get_GameObjectManeger()->Update_GameObjectManeger();
	return Function_Pass;
}

int CMain::LateUpdate_Main()
{
	return Function_Pass;
}

int CMain::Release_Main()
{
	DeleteDC(m_hdc);
	return Function_Pass;
}
