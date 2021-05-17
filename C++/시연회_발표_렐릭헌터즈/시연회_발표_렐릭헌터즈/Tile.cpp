#include "stdafx.h"
#include "Tile.h"
#include "MapObjectManeger.h"
#include "BitmapManeger.h"
CTile::CTile()
{
}

CMapObject * CTile::Create(POINT& TilePos)
{
	CMapObject* pInstance = new CTile();
	if (!pInstance->Ready_MapObject())
	{
		Delete_Dynamic(pInstance);
		return pInstance;
	}
	dynamic_cast<CTile*>(pInstance)->SetPos(TilePos);
	return pInstance;
}




CTile::~CTile()
{
	Release_MapObject();
}

void CTile::SetPos(POINT& MousePOS)
{

	float startPOSX = TILECX / 2;
	float startPOSY = TILECY / 2;
	int Tile_X = MousePOS.x / TILECX;
	int Tile_Y = MousePOS.y / TILECY;
	m_tMapInfo.fX = startPOSX + TILECX*Tile_X;
	m_tMapInfo.fY = startPOSY + TILECX*Tile_Y;
}

int CTile::Ready_MapObject()
{
	m_tMapInfo.ObjType = MAPOBJECT::TILE;
	m_tMapInfo.iCX = TILECX;
	m_tMapInfo.iCY = TILECY;
	m_tMapInfo.Objfeature= MAPOBJECTTYPE::NONE;
	return Function_Pass;
}

int CTile::Render_MapObject(HDC hdc)
{
	HDC m_hmapDC = CBitmapManeger::Get_BitmapManeger()->Get_BitmapDC(L"floor_desert");
	GdiTransparentBlt(hdc, m_Rc.left, m_Rc.top, m_tMapInfo.iCX, m_tMapInfo.iCY, m_hmapDC, 0, 0, m_tMapInfo.iCX, m_tMapInfo.iCY, bmi_BackGround);
	return Function_Pass;
}

int CTile::Update_MapObject()
{
	Update_Rect();
	return Function_Pass;
}

int CTile::LateUpdate_MapObject()
{
	return Function_Pass;
}

int CTile::Release_MapObject()
{
	return Function_Pass;
}
