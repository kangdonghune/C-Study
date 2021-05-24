#include "stdafx.h"
#include "Item.h"
#include "BitmapManeger.h"
#include "ScrollManeger.h"
#include "PushButton.h"
#include "MapObjectManeger.h"
#include "GameObjectManeger.h"
#include "Player.h"
#include "Pistol.h"
#include "ShotGun.h"
#include "Gun.h"

CItem::CItem()
	:m_bisTouch(false)
	, m_bButtonRender(false)
{
}


CItem::~CItem()
{
	Release_GameObject();
}

CGameObject * CItem::Create(CGameObject* pTarget, ITEM::Name Name, float POSX, float POSY)
{
	CItem* pInstance = new CItem();
	pInstance->m_pTarget = pTarget;
	pInstance->Name = Name;
	pInstance->m_tInfo.fX = POSX;
	pInstance->m_tInfo.fY = POSY;
	if (!pInstance->Ready_GameObject())
	{
		Delete_Dynamic(pInstance);
		return pInstance;
	}

	return pInstance;
}

void CItem::PushButton()
{
	switch (Name)
	{
	case ITEM::PISTOL:
		/*m_pMyGun = CGun::Create(this);
		if (!(CGameObjectManeger::Get_GameObjectManeger()->Add_GameObject(GAMEOBJECT::GUN, m_pMyGun)))
		return Function_Fail;*/
		dynamic_cast<CPlayer*>(m_pTarget)->SetMyGun(CPistol::Create(m_pTarget));
		dynamic_cast<CPlayer*>(m_pTarget)->SetGunVector().emplace_back(dynamic_cast<CPlayer*>(m_pTarget)->Get_MyGun());
		m_pTarget->Get_MyGun()->SetHold();
		if (!(CGameObjectManeger::Get_GameObjectManeger()->Add_GameObject(GAMEOBJECT::GUN, dynamic_cast<CPlayer*>(m_pTarget)->Get_MyGun())))
			MessageBox(nullptr, L"ÀåÂø", L"error", MB_OK);
		SetDead();
		break;
	case ITEM::MACHINGUN:
		dynamic_cast<CPlayer*>(m_pTarget)->SetMyGun(CGun::Create(m_pTarget));
		dynamic_cast<CPlayer*>(m_pTarget)->SetGunVector().emplace_back(dynamic_cast<CPlayer*>(m_pTarget)->Get_MyGun());
		m_pTarget->Get_MyGun()->SetHold();
		if (!(CGameObjectManeger::Get_GameObjectManeger()->Add_GameObject(GAMEOBJECT::GUN, dynamic_cast<CPlayer*>(m_pTarget)->Get_MyGun())))
			MessageBox(nullptr, L"ÀåÂø", L"error", MB_OK);
		SetDead();
		break;
	case ITEM::SHOTGUN:
		dynamic_cast<CPlayer*>(m_pTarget)->SetMyGun(CShotGun::Create(m_pTarget));
		dynamic_cast<CPlayer*>(m_pTarget)->SetGunVector().emplace_back(dynamic_cast<CPlayer*>(m_pTarget)->Get_MyGun());
		m_pTarget->Get_MyGun()->SetHold();
		if (!(CGameObjectManeger::Get_GameObjectManeger()->Add_GameObject(GAMEOBJECT::GUN, dynamic_cast<CPlayer*>(m_pTarget)->Get_MyGun())))
			MessageBox(nullptr, L"ÀåÂø", L"error", MB_OK);
		SetDead();
		break;
	case ITEM::BOSSGUN:
		break;
	case ITEM::GRENADE:
		dynamic_cast<CPlayer*>(m_pTarget)->SetGrenadeOn(true);
		m_bisTouch = true;
		break;
	case ITEM::END:
		break;
	default:
		break;
	}
}

int CItem::Ready_GameObject()
{
	switch (Name)
	{
	case ITEM::PISTOL:
		m_tAni.iStart = 0;
		m_tAni.iEnd = 3;
		m_tInfo.iCX = Pistol_itemCX;
		m_tInfo.iCY = Pistol_itemCY;
		m_tInfo.dwTime = GetTickCount();
		m_tInfo.LimitTime = 100;
		m_hDC = CBitmapManeger::Get_BitmapManeger()->Get_BitmapDC(L"Pistol_Pop");
		m_bisTouch = true;
		break;
	case ITEM::MACHINGUN:
		m_tAni.iStart = 0;
		m_tAni.iEnd = 3;
		m_tInfo.iCX = MachinGun_itemCX;
		m_tInfo.iCY = MachinGun_itemCY;
		m_tInfo.dwTime = GetTickCount();
		m_tInfo.LimitTime = 100;
		m_hDC = CBitmapManeger::Get_BitmapManeger()->Get_BitmapDC(L"machinegun_Pop");
		m_bisTouch = true;
		break;
	case ITEM::SHOTGUN:
		m_tAni.iStart = 0;
		m_tAni.iEnd = 3;
		m_tInfo.iCX = ShotGun_itemCX;
		m_tInfo.iCY = ShotGun_itemCY;
		m_tInfo.dwTime = GetTickCount();
		m_tInfo.LimitTime = 100;
		m_hDC = CBitmapManeger::Get_BitmapManeger()->Get_BitmapDC(L"shotgun_PoP");
		m_bisTouch = true;
		break;
	case ITEM::BOSSGUN:
		break;
	case ITEM::GRENADE:
		m_tAni.iStart = 0;
		m_tAni.iEnd = 16;
		m_tInfo.iCX = GrenadeBox_CX;
		m_tInfo.iCY = GrenadeBox_CY;
		m_tInfo.dwTime = GetTickCount();
		m_tInfo.LimitTime = 100;
		m_hDC = CBitmapManeger::Get_BitmapManeger()->Get_BitmapDC(L"Grenade_Pop");
		break;
	case ITEM::END:
		break;
	default:
		break;
	}
	UpdateRect();
	return Function_Pass;
}

int CItem::Render_GameObject(HDC hdc)
{
	if (m_tAni.iStart >= m_tAni.iEnd)
		m_tAni.iStart = 0;

	GdiTransparentBlt(hdc, m_Rc.left + CScrollManeger::Get_ScrollX(), m_Rc.top + CScrollManeger::Get_ScrollY(), m_tInfo.iCX, m_tInfo.iCY, m_hDC, m_tAni.iStart *m_tInfo.iCX, 0, m_tInfo.iCX, m_tInfo.iCY, bmi_BackGround);
	if (m_bisTouch && m_tInfo.dwTime + m_tInfo.LimitTime < GetTickCount())
	{
		m_tAni.iStart++;
		m_tInfo.dwTime = GetTickCount();
		if (Name == ITEM::GRENADE && m_tAni.iStart >= m_tAni.iEnd)
			SetDead();
	}
	return Function_Pass;
}

int CItem::Update_GameObject()
{

	if (100 >= fabs(m_pTarget->GetInfo()->fX - m_tInfo.fX) && 100 >= fabs(m_pTarget->GetInfo()->fY - m_tInfo.fY))
	{
		if (m_bButtonRender == false)
		{
			m_pButton = CPushButton::Create(m_tInfo.fX, m_tInfo.fY - 50);
			CMapObjectManeger::Get_MapManeger()->Insert_MapObject(MAPOBJECT::BUTTON, m_pButton);
			m_bButtonRender = true;
		}
		if (GetAsyncKeyState('E') & 0X0001)
		{
			CSoundMgr::Get_Instance()->PlaySound(L"sfx_pickup_weapon.wav", CSoundMgr::EFFECT);
			PushButton();
		}
			
	}
	else
	{
		m_bButtonRender = false;
		if (m_pButton != nullptr)
			m_pButton->SetDead();
	}
	return Function_Pass;
}

int CItem::LateUpdate_GameObject()
{
	return Function_Pass;
}

int CItem::Release_GameObject()
{
	m_pButton->SetDead();
	return Function_Pass;
}
