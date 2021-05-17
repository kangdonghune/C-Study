#include "stdafx.h"
#include "Wall.h"
#include "BitmapManeger.h"

CWall::CWall()
{
}


CWall::~CWall()
{
}

CMapObject * CWall::Create(POINT& MousePos)
{
	CMapObject* pInstance = new CWall();
	if (!pInstance->Ready_MapObject())
	{
		Delete_Dynamic(pInstance);
		return pInstance;
	}
	dynamic_cast<CWall*>(pInstance)->CWall::SetPOS(MousePos);
	return pInstance;

}

void CWall::SetPOS(POINT & MousePos)
{
	float startPOSX = Wall_SideCX/2;
	float startPOSY = Wall_SideCY/2;
	int Wall_X = MousePos.x / Wall_SideCX;
	int Wall_Y = MousePos.y / Wall_SideCY;
	m_tMapInfo.fX = startPOSX + Wall_SideCX*Wall_X;
	m_tMapInfo.fY = startPOSY + Wall_SideCY*Wall_Y;
}

int CWall::Ready_MapObject()
{
	m_tMapInfo.ObjType = MAPOBJECT::WALL;
	m_tMapInfo.iCX = Wall_SideCX;
	m_tMapInfo.iCY = Wall_SideCY;
	m_tMapInfo.Objfeature = MAPOBJECTTYPE::DONEPASS;
	return Function_Pass;
}

int CWall::Render_MapObject(HDC hdc)
{
	HDC m_hmapDC = CBitmapManeger::Get_BitmapManeger()->Get_BitmapDC(L"desert_wall");
	if (m_hmapDC == nullptr)
		return Function_Fail;
	GdiTransparentBlt(hdc, m_Rc.left, m_Rc.top, Wall_SideCX, Wall_SideCY, m_hmapDC, (m_tMapInfo.iWallNum) *Wall_SideCX, 0, Wall_SideImgCX, Wall_SideImgCY, bmi_BackGround);
	return Function_Pass;
}

int CWall::Update_MapObject()
{
	Update_Rect();
	return Function_Pass;
}

int CWall::LateUpdate_MapObject()
{
	return Function_Pass;
}

int CWall::Release_MapObject()
{
	return Function_Pass;
}
