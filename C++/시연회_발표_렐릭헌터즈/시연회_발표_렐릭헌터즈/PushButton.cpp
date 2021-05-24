#include "stdafx.h"
#include "PushButton.h"
#include "ScrollManeger.h"
#include "BitmapManeger.h"

CPushButton::CPushButton()
{
}


CPushButton::~CPushButton()
{
}

CMapObject * CPushButton::Create(float PosX, float PosY)
{
	CMapObject* pInstance = new CPushButton();
	if (!pInstance->Ready_MapObject())
	{
		Delete_Dynamic(pInstance);
		return pInstance;
	}
	POINT pt{ PosX, PosY };
	dynamic_cast<CPushButton*>(pInstance)->SetPOS(pt);
	pInstance->Update_Rect();
	return pInstance;
}

void CPushButton::SetPOS(POINT & TilePos)
{
	m_tMapInfo.fX = TilePos.x;
	m_tMapInfo.fY = TilePos.y;
}

int CPushButton::Ready_MapObject()
{
	m_tMapInfo.iCX = PushButton_CX;
	m_tMapInfo.iCY = PushButton_CY;
	m_tMapInfo.Objfeature = MAPOBJECTTYPE::PASS;
	m_tAni.iStart = 0;
	m_tAni.iEnd = 7;
	m_dwTime = GetTickCount();
	m_dwLimit = 80;

	return Function_Pass;
}

int CPushButton::Render_MapObject(HDC hdc)
{
	HDC m_hmapDC = CBitmapManeger::Get_BitmapManeger()->Get_BitmapDC(L"PushButton");
	if (m_hmapDC == nullptr)
		return Function_Fail;
	if (m_tAni.iStart >= m_tAni.iEnd)
		m_tAni.iStart = 0;
	GdiTransparentBlt(hdc, m_Rc.left + CScrollManeger::Get_ScrollX(), m_Rc.top + CScrollManeger::Get_ScrollY(), PushButton_CX, PushButton_CY, m_hmapDC, m_tAni.iStart*PushButton_CX, 0, PushButton_CX, PushButton_CY, bmi_BackGround);
	if (m_dwTime + m_dwLimit < GetTickCount())
	{
		m_tAni.iStart++;
		m_dwTime = GetTickCount();
	}
	return Function_Pass;
}

int CPushButton::Update_MapObject()
{
	return Function_Pass;
}

int CPushButton::LateUpdate_MapObject()
{
	return Function_Pass;
}

int CPushButton::Release_MapObject()
{
	return Function_Pass;
}
