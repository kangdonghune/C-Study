#include "stdafx.h"
#include "Celling.h"
#include "BitmapManeger.h"

CCelling::CCelling()
{
}


CCelling::~CCelling()
{
}

CMapObject * CCelling::Create(POINT & TilePos)
{
	CMapObject* pInstance = new CCelling();
	if (!pInstance->Ready_MapObject())
	{
		Delete_Dynamic(pInstance);
		return pInstance;
	}
	dynamic_cast<CCelling*>(pInstance)->SetPOS(TilePos);
	return pInstance;
}

void CCelling::SetPOS(POINT & TilePos)
{

	float startPOSX = Celling_CX/2;
	float startPOSY = Celling_CY/2;
	int Celling_X = TilePos.x / Celling_CX;
	int Celling_Y = TilePos.y / Celling_CY;
	m_tMapInfo.fX = startPOSX + Celling_CX*Celling_X;
	m_tMapInfo.fY = startPOSY + Celling_CY*Celling_Y;
}

int CCelling::Ready_MapObject()
{
	m_tMapInfo.ObjType = MAPOBJECT::CELLING;
	m_tMapInfo.iCX = Celling_CX;
	m_tMapInfo.iCY = Celling_CY;
	m_tMapInfo.Objfeature = MAPOBJECTTYPE::DONEPASS;
	m_tMapInfo.iCellingNum = 0;
	return Function_Pass;
}

int CCelling::Render_MapObject(HDC hdc)
{
	HDC m_hmapDC = CBitmapManeger::Get_BitmapManeger()->Get_BitmapDC(L"Ceiling_desert");
	HDC hTempDC = CBitmapManeger::Get_BitmapManeger()->Get_BitmapDC(L"Celling_back");
	BitBlt(hTempDC, 0, 0, 2*m_tMapInfo.iCX, 2*m_tMapInfo.iCY, m_hmapDC,(m_tMapInfo.iCellingNum%3)* 2 * m_tMapInfo.iCX,(m_tMapInfo.iCellingNum/3)* 2 * m_tMapInfo.iCY, SRCCOPY);
	GdiTransparentBlt(hdc, m_Rc.left, m_Rc.top, m_tMapInfo.iCX, m_tMapInfo.iCY, hTempDC, 0, 0, 2 * m_tMapInfo.iCX, 2 * m_tMapInfo.iCY, bmi_BackGround);
	return Function_Pass;
}

int CCelling::Update_MapObject()
{
	Update_Rect();
	return Function_Pass;
}

int CCelling::LateUpdate_MapObject()
{
	return Function_Pass;
}

int CCelling::Release_MapObject()
{
	return Function_Pass;
}
