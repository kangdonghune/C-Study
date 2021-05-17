#include "stdafx.h"
#include "Editor.h"
#include "Scene.h"
#include "ScrollManeger.h"
#include "MapObjectManeger.h"
#include "Tile.h"
#include "Celling.h"
#include "Wall.h"

CEditor::CEditor() 
{
}

CScene * CEditor::Create()
{
	CScene* pInstance = new CEditor;
	if (0 > pInstance->Ready_Scene())
	{
		Delete_Dynamic(pInstance);
		return nullptr;
	}
	return pInstance;
}



CEditor::~CEditor()
{
}

int CEditor::Ready_Scene()
{
	return 0;
}

void CEditor::Update_Scene()
{

	POINT pt = {};
	GetCursorPos(&pt);
	ScreenToClient(g_HWND, &pt);
	pt.x -= CScrollManeger::Get_ScrollX();
	pt.y -= CScrollManeger::Get_ScrollY();

	if (GetAsyncKeyState('0') & 0001)
	{
		POINT Mouse = {};
		GetCursorPos(&Mouse);
		ScreenToClient(g_HWND, &Mouse);
		CMapObjectManeger::Get_MapManeger()->Insert_MapObject(MAPOBJECT::CELLING, CCelling::Create(Mouse));
		CMapObjectManeger::Get_MapManeger()->SetList(MAPOBJECT::CELLING).back()->SetMINFO()->iCellingNum = 0;
	}
	if (GetAsyncKeyState('1') & 0001)
	{
		POINT Mouse = {};
		GetCursorPos(&Mouse);
		ScreenToClient(g_HWND, &Mouse);
		CMapObjectManeger::Get_MapManeger()->Insert_MapObject(MAPOBJECT::CELLING, CCelling::Create(Mouse));
		CMapObjectManeger::Get_MapManeger()->SetList(MAPOBJECT::CELLING).back()->SetMINFO()->iCellingNum = 1;
	}
	if (GetAsyncKeyState('2') & 0001)
	{
		POINT Mouse = {};
		GetCursorPos(&Mouse);
		ScreenToClient(g_HWND, &Mouse);
		CMapObjectManeger::Get_MapManeger()->Insert_MapObject(MAPOBJECT::CELLING, CCelling::Create(Mouse));
		CMapObjectManeger::Get_MapManeger()->SetList(MAPOBJECT::CELLING).back()->SetMINFO()->iCellingNum = 2;
	}
	if (GetAsyncKeyState('3') & 0001)
	{
		POINT Mouse = {};
		GetCursorPos(&Mouse);
		ScreenToClient(g_HWND, &Mouse);
		CMapObjectManeger::Get_MapManeger()->Insert_MapObject(MAPOBJECT::CELLING, CCelling::Create(Mouse));
		CMapObjectManeger::Get_MapManeger()->SetList(MAPOBJECT::CELLING).back()->SetMINFO()->iCellingNum = 3;
	}
	if (GetAsyncKeyState('4') & 0001)
	{
		POINT Mouse = {};
		GetCursorPos(&Mouse);
		ScreenToClient(g_HWND, &Mouse);
		CMapObjectManeger::Get_MapManeger()->Insert_MapObject(MAPOBJECT::CELLING, CCelling::Create(Mouse));
		CMapObjectManeger::Get_MapManeger()->SetList(MAPOBJECT::CELLING).back()->SetMINFO()->iCellingNum = 4;
	}
	if (GetAsyncKeyState('5') & 0001)
	{
		POINT Mouse = {};
		GetCursorPos(&Mouse);
		ScreenToClient(g_HWND, &Mouse);
		CMapObjectManeger::Get_MapManeger()->Insert_MapObject(MAPOBJECT::CELLING, CCelling::Create(Mouse));
		CMapObjectManeger::Get_MapManeger()->SetList(MAPOBJECT::CELLING).back()->SetMINFO()->iCellingNum = 5;
	}
	if (GetAsyncKeyState('6') & 0001)
	{
		POINT Mouse = {};
		GetCursorPos(&Mouse);
		ScreenToClient(g_HWND, &Mouse);
		CMapObjectManeger::Get_MapManeger()->Insert_MapObject(MAPOBJECT::CELLING, CCelling::Create(Mouse));
		CMapObjectManeger::Get_MapManeger()->SetList(MAPOBJECT::CELLING).back()->SetMINFO()->iCellingNum = 6;
	}
	if (GetAsyncKeyState('7') & 0001)
	{
		POINT Mouse = {};
		GetCursorPos(&Mouse);
		ScreenToClient(g_HWND, &Mouse);
		CMapObjectManeger::Get_MapManeger()->Insert_MapObject(MAPOBJECT::CELLING, CCelling::Create(Mouse));
		CMapObjectManeger::Get_MapManeger()->SetList(MAPOBJECT::CELLING).back()->SetMINFO()->iCellingNum = 7;
	}
	if (GetAsyncKeyState('8') & 0001)
	{
		POINT Mouse = {};
		GetCursorPos(&Mouse);
		ScreenToClient(g_HWND, &Mouse);
		CMapObjectManeger::Get_MapManeger()->Insert_MapObject(MAPOBJECT::CELLING, CCelling::Create(Mouse));
		CMapObjectManeger::Get_MapManeger()->SetList(MAPOBJECT::CELLING).back()->SetMINFO()->iCellingNum = 8;
	}
	if (GetAsyncKeyState('W') & 0001)
	{
		static int WallCount = 0;
		if (5 < WallCount)
			WallCount = 0;
		POINT Mouse = {};
		GetCursorPos(&Mouse);
		ScreenToClient(g_HWND, &Mouse);
		CMapObjectManeger::Get_MapManeger()->Insert_MapObject(MAPOBJECT::WALL, CWall::Create(Mouse));
		CMapObjectManeger::Get_MapManeger()->SetList(MAPOBJECT::WALL).back()->SetMINFO()->iWallNum = WallCount;
	}
	if (GetAsyncKeyState('T') & 0001)
	{
		POINT Mouse = {};
		GetCursorPos(&Mouse);
		ScreenToClient(g_HWND, &Mouse);
		CMapObjectManeger::Get_MapManeger()->Insert_MapObject(MAPOBJECT::TILE, CTile::Create(Mouse));
	}

	if (GetAsyncKeyState('S') & 0001)
		CMapObjectManeger::Get_MapManeger()->Save_MapObjectManager();
	if (GetAsyncKeyState('L') & 0001)
		CMapObjectManeger::Get_MapManeger()->Load_MapObjectManager();
	CMapObjectManeger::Get_MapManeger()->Update_MapObjectManerger();
}

void CEditor::Render_Scene(HDC hdc)
{
	CMapObjectManeger::Get_MapManeger()->Render_MapObjectManeger(hdc);
}

void CEditor::Release_Scene()
{
}
