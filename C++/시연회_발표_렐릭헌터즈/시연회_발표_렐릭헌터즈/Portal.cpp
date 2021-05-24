#include "stdafx.h"
#include "Portal.h"
#include "BitmapManeger.h"
#include "ScrollManeger.h"
#include "GameObject.h"
#include "GameObjectManeger.h"
#include "SceneManeger.h"
#include "PushButton.h"
#include "MapObjectManeger.h"
#include "Stage.h"

CPortal::CPortal()
	:m_pButton(nullptr)
{
}


CPortal::~CPortal()
{
}

CMapObject * CPortal::Create(float PosX, float PosY)
{
	CMapObject* pInstance = new CPortal();
	if (!pInstance->Ready_MapObject())
	{
		Delete_Dynamic(pInstance);
		return pInstance;
	}
	POINT pt{ PosX, PosY };
	dynamic_cast<CPortal*>(pInstance)->SetPOS(pt);
	pInstance->Update_Rect();
	return pInstance;
}

void CPortal::NextMap()
{
	RECT rc{};
	if (IntersectRect(&rc, &m_pPlayer->GetRect(), &(this->m_Rc)))
	{
		//MessageBox(nullptr, L"Æ÷Å»", L"portal", MB_OK);
		if (GetAsyncKeyState('E'))
		{
			m_iState = DEAD;
			*(dynamic_cast<CStage*>(CSceneManeger::Get_SceneManeger()->GetScene())->GetStageChange()) = true;
			
		}

	}
}

void CPortal::SetPOS(POINT & TilePos)
{
	m_tMapInfo.fX = TilePos.x;
	m_tMapInfo.fY = TilePos.y;
}

int CPortal::Ready_MapObject()
{
	m_tMapInfo.iCX = Portal_CX;
	m_tMapInfo.iCY = Portal_CY;
	m_tMapInfo.Objfeature = MAPOBJECTTYPE::PASS;
	m_pPlayer = CGameObjectManeger::Get_GameObjectManeger()->GetList(GAMEOBJECT::PLAYER).back();
	m_bButtonRender = false;
	return Function_Pass;
}

int CPortal::Render_MapObject(HDC hdc)
{
	HDC m_hmapDC = CBitmapManeger::Get_BitmapManeger()->Get_BitmapDC(L"Portal");
	if (m_hmapDC == nullptr)
		return Function_Fail;
	GdiTransparentBlt(hdc, m_Rc.left + CScrollManeger::Get_ScrollX(), m_Rc.top + CScrollManeger::Get_ScrollY(), Portal_CX, Portal_CY, m_hmapDC, 0, 0, Portal_CX, Portal_CY, bmi_BackGround);
	return Function_Pass;
}

int CPortal::Update_MapObject()
{
	if (150 >= fabs(m_pPlayer->GetInfo()->fX - m_tMapInfo.fX) && 150 >= fabs(m_pPlayer->GetInfo()->fY - m_tMapInfo.fY))
	{
		if (m_bButtonRender == false)
		{
			m_pButton = CPushButton::Create(m_tMapInfo.fX, m_tMapInfo.fY - 50);
			CMapObjectManeger::Get_MapManeger()->Insert_MapObject(MAPOBJECT::BUTTON, m_pButton);
			m_bButtonRender = true;
		}
	NextMap();
	}
	else
	{
		m_bButtonRender = false;
		if(m_pButton != nullptr)
			m_pButton->SetDead();
	}
	return Function_Pass;
}

int CPortal::LateUpdate_MapObject()
{

	return Function_Pass;
}

int CPortal::Release_MapObject()
{
	return Function_Pass;
}
