#include "stdafx.h"
#include "Player_Bullet.h"
#include <random>
#include "GameObjectManeger.h"
#include "ScrollManeger.h"
#include "Player.h"
#include "BitmapManeger.h"
#include "SceneManeger.h"

CPlayer_Bullet::CPlayer_Bullet()
{

}


CPlayer_Bullet::~CPlayer_Bullet()
{
}

CGameObject * CPlayer_Bullet::Create(CGameObject * pTarget)
{
	CPlayer_Bullet* pInstance = new CPlayer_Bullet();
	pInstance->SetTarget(pTarget);
	if (!pInstance->Ready_GameObject())
	{
		Delete_Dynamic(pInstance);
		return pInstance;
	}
	return pInstance;
}

int CPlayer_Bullet::Ready_GameObject()
{

	if (m_pTarget->GetDir() < 0)
		m_idir = 1;
	if (!m_pTarget->GetDir() < 0)
		m_idir = -1;
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> dir(-1, 1);
	Name = (m_pTarget)->Get_MyGun()->Get_GunInfo()->Name;
	int RandomDir = dir(rd);
	m_tBulletInfo.fBulletDist = 500;
	switch (Name)
	{
	case ITEM::PISTOL:
		CSoundMgr::Get_Instance()->PlaySound(L"sfx_pistol.wav", CSoundMgr::EFFECT);
		m_hDC = CBitmapManeger::Get_BitmapManeger()->Get_BitmapDC(L"Pistol_Bullet");
		m_tInfo.fAngle = m_pTarget->GetInfo()->fAngle + RandomDir*5;
		m_tInfo.fX = m_pTarget->GetInfo()->fX + (cosf(m_tInfo.fAngle / RADIAN)*PISTOL_C);
		m_tInfo.fY = m_pTarget->GetInfo()->fY + sinf(m_tInfo.fAngle / RADIAN)*PISTOL_C /2 + 10;
		m_tInfo.fSpeed = 15.f;
		m_tInfo.iCX = Pistol_bC;
		m_tInfo.iCY = Pistol_bC;
		m_tInfo.iDamege = 15;
		break;
	case ITEM::MACHINGUN:
		CSoundMgr::Get_Instance()->PlaySound(L"sfx_rifle1.wav", CSoundMgr::UI);
		m_hDC = CBitmapManeger::Get_BitmapManeger()->Get_BitmapDC(L"Machgun_bullet");
		m_tInfo.fAngle = m_pTarget->GetInfo()->fAngle + RandomDir * 5;
		m_tInfo.fX = m_pTarget->GetInfo()->fX + (cosf(m_tInfo.fAngle / RADIAN)*GUN_ICX/2.f);
		m_tInfo.fY = m_pTarget->GetInfo()->fY + sinf(m_tInfo.fAngle / RADIAN)*GUN_ICY / 2 + 13;
		m_tInfo.fSpeed = 20.f;
		m_tInfo.iCX = Machgun_bC;
		m_tInfo.iCY = Machgun_bC;
		m_tInfo.iDamege = 10;
		CSceneManeger::Get_SceneManeger()->SetWaveGunRebounde(true);
		break;
	case ITEM::SHOTGUN:
		CSoundMgr::Get_Instance()->PlaySound(L"sfx_shotgun.wav", CSoundMgr::UI);
		m_hDC = CBitmapManeger::Get_BitmapManeger()->Get_BitmapDC(L"Player_bullet");
		m_tInfo.fAngle = m_pTarget->GetInfo()->fAngle;
		m_tInfo.fX = m_pTarget->GetInfo()->fX + (cosf(m_tInfo.fAngle / RADIAN)*SHOTGUN_C * 3 / 4.f);
		m_tInfo.fY = m_pTarget->GetInfo()->fY + sinf(m_tInfo.fAngle / RADIAN)*SHOTGUN_C / 2 + 13;
		m_tInfo.fSpeed = 22.f;
		m_tInfo.iCX = Bullet_ICX;
		m_tInfo.iCY = Bullet_ICY;
		m_tInfo.iDamege = 20;
		CSceneManeger::Get_SceneManeger()->SetWaveOn(true);
		break;
	case ITEM::BOSSGUN:
		//CSoundMgr::Get_Instance()->PlaySound(L"sfx_shield_destroy.wav", CSoundMgr::MONSTER);
		m_hDC = CBitmapManeger::Get_BitmapManeger()->Get_BitmapDC(L"Boss_Bullet");
		m_tInfo.fAngle = m_pTarget->GetInfo()->fAngle + RandomDir * 5;
		m_tInfo.fX = m_pTarget->GetInfo()->fX + (cosf(m_tInfo.fAngle / RADIAN)*Boss_GunCX * 3 / 4.f);
		m_tInfo.fY = m_pTarget->GetInfo()->fY + sinf(m_tInfo.fAngle / RADIAN)*Boss_GunCY;
		m_tInfo.fSpeed = 22.f;
		m_tInfo.iCX = Bossgun_bC;
		m_tInfo.iCY = Bossgun_bC;
		m_tInfo.iDamege = 20;
		break;
	default:
		break;
	}
	UpdateRect();


	return Function_Pass;
}

int CPlayer_Bullet::Render_GameObject(HDC hdc)
{
	if (m_pTarget->Get_GunAni().iStart < 18)
		m_tAni.iStart = m_pTarget->Get_GunAni().iStart;
	else
		m_tAni.iStart = m_pTarget->Get_GunAni().iStart - 18;
	if(Name == ITEM::PISTOL)
		GdiTransparentBlt(hdc, m_Rc.left + CScrollManeger::Get_ScrollX(), m_Rc.top + CScrollManeger::Get_ScrollY(), m_tInfo.iCX, m_tInfo.iCY, m_hDC, 0, 0, m_tInfo.iCX, m_tInfo.iCY, bmi_BackGround);
	else
	{
		GdiTransparentBlt(hdc, m_Rc.left + CScrollManeger::Get_ScrollX(), m_Rc.top + CScrollManeger::Get_ScrollY(), m_tInfo.iCX, m_tInfo.iCY, m_hDC, m_tAni.iStart*m_tInfo.iCX, 0, m_tInfo.iCX, m_tInfo.iCY, bmi_BackGround);
	}
	return Function_Pass;
}

int CPlayer_Bullet::Update_GameObject()
{
	m_tInfo.fX += cosf(m_tInfo.fAngle / RADIAN)*m_tInfo.fSpeed;
	m_tInfo.fY += sinf(m_tInfo.fAngle / RADIAN)*m_tInfo.fSpeed;
	m_tBulletInfo.fBulletDist -= m_tInfo.fSpeed;
	if (0 > m_tBulletInfo.fBulletDist)
		SetDead();
	UpdateRect();
	return Function_Pass;
}

int CPlayer_Bullet::LateUpdate_GameObject()
{
	return Function_Pass;
}

int CPlayer_Bullet::Release_GameObject()
{
	return Function_Pass;
}
