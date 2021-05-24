#include "stdafx.h"
#include "Boss.h"
#include "stdafx.h"
#include "Monster.h"
#include "Turtle.h"
#include "GameObject.h"
#include "BitmapManeger.h"
#include "GameObjectManeger.h"
#include "Player_Bullet.h"
#include "ScrollManeger.h"
#include "MapObjectManeger.h"
#include "MapObject.h"
#include "BossGun.h"

CBoss::CBoss()
{
}


CBoss::~CBoss()
{
}

CGameObject * CBoss::Create(MONSTER::Name MonsterName, float X, float Y, CGameObject * pTarget)
{
	CBoss* pInstance = new CBoss();
	if (!pInstance->Ready_GameObject())
	{
		Delete_Dynamic(pInstance);
		return pInstance;
	}
	pInstance->SetName(MonsterName);
	pInstance->SetPos(X, Y);
	pInstance->SetTarget(pTarget);
	return pInstance;
}

void CBoss::ReadyDead()
{
	if (m_tAni.iStart > m_tAni.iEnd)
	{
		m_iState = DEAD;

	}
}

void CBoss::CheckState(int State)
{
	switch (State)
	{
	case EGG:
		m_tAni.iEnd = 9;
		break;
	case EGGCRACK:
		m_tAni.iEnd = 20;
		break;
	case IDLE:
		m_tAni.iEnd = 11;
		break;
	case WALK:
		m_tAni.iEnd = 5;
		break;
	case READYDEAD:
		m_tAni.iEnd = 12;
		break;
	default:
		m_iState = DEAD;
		break;
	}
}

void CBoss::Move()
{
	if (300.f >= fabs(m_pTarget->GetInfo()->fX - m_tInfo.fX) && 300.f >= fabs(m_pTarget->GetInfo()->fY - m_tInfo.fY))
	{
		Attack();
		return;
	}
	AngleToTarget(m_pTarget->GetInfo()->fX + m_irandomDirX * 150, m_pTarget->GetInfo()->fY + m_irandomDirY * 150);
	m_tInfo.fX += cosf(m_tInfo.fAngle) * m_tInfo.fSpeed;
	m_tInfo.fY += sinf(m_tInfo.fAngle) * m_tInfo.fSpeed;
}

void CBoss::Attack()
{
	if (m_iState == DEAD || m_iState == READYDEAD)
		return;
	if (dynamic_cast<BossGun*>(m_pMyGun)->Get_GunInfo()->fBulletTime + dynamic_cast<BossGun*>(m_pMyGun)->Get_GunInfo()->fBulletCoolTime < GetTickCount())
	{
		CGameObjectManeger::Get_GameObjectManeger()->Add_GameObject(GAMEOBJECT::MONSTER_BULLET, CPlayer_Bullet::Create(this));
		dynamic_cast<BossGun*>(m_pMyGun)->Get_GunInfo()->fBulletTime = GetTickCount();
	}
}

void CBoss::UpdateHitBox()
{
	m_rcHitBox.left = m_tInfo.fX - Boss_HitX / 2;
	m_rcHitBox.top = (m_tInfo.fY - Boss_HitY / 2);
	m_rcHitBox.right = m_tInfo.fX + Boss_HitX / 2;
	m_rcHitBox.bottom = m_tInfo.fY + Boss_HitY / 2;
}

int CBoss::Ready_GameObject()
{
	m_tInfo.iMaxHp = 300;
	m_tInfo.iHP = m_tInfo.iMaxHp;
	m_tInfo.iCX = Boss_CX;
	m_tInfo.iCY = Boss_CY;
	m_tInfo.fSpeed = 8;
	m_tInfo.iDamege = 10;
	m_tAni.iStart = 0;
	m_tAni.iEnd = 9;
	m_iState = EGG;
	m_bEggCrash = false;
	m_tInfo.dwTime = GetTickCount();
	m_tInfo.LimitTime = 120;
	m_idir = 1;

	return Function_Pass;
}

int CBoss::Render_GameObject(HDC hdc)
{
	CheckState(m_iState);
	if (m_iState == DEAD)
		return Function_Pass;
	if (m_tAni.iStart > m_tAni.iEnd)
		m_tAni.iStart = 0;
	GdiTransparentBlt(hdc, m_Rc.left + CScrollManeger::Get_ScrollX(), m_Rc.top + CScrollManeger::Get_ScrollY(), Boss_CX, Boss_CY, m_hMemDC, m_tAni.iStart * Boss_CX, 0, Boss_CX, Boss_CY, bmi_BackGround);
	if (m_tInfo.dwTime + m_tInfo.LimitTime < GetTickCount())
	{
		m_tAni.iStart++;
		m_tInfo.dwTime = GetTickCount();
	}
	return Function_Pass;
}

int CBoss::Update_GameObject()
{
	UpdateRect();
	UpdateHitBox();
	CheckTargetDir(m_pTarget);
	if (300 > m_tInfo.iHP && !m_bEggCrash)
	{
		m_bEggCrash = true;
		m_iState = EGGCRACK;
	}
		
	if (0 >= m_tInfo.iHP)
	{
		if (m_iState != READYDEAD)
		{
			m_iState = READYDEAD;
			m_tAni.iStart = 0;
			m_pMyGun->SetDead();
		}
	}

	m_tInfo.fAngle = (m_tInfo.fAngle * RADIAN);
	if (m_tInfo.fAngle < 0)
		m_tInfo.fAngle = 180 + (180 - fabs(m_tInfo.fAngle));
	m_tGunAni.iStart = m_tInfo.fAngle / 10;

	if (m_pTarget->GetInfo()->fX > m_tInfo.fX)
	{
		m_idir = -1;

	}

	else
	{
		m_idir = 1;

	}
	switch (m_iState)
	{
	case EGG:
			m_hMemDC = CBitmapManeger::Get_BitmapManeger()->Get_BitmapDC(L"Boss_Egg");
			return Function_Pass;
		break;
	case EGGCRACK:
			m_hMemDC = CBitmapManeger::Get_BitmapManeger()->Get_BitmapDC(L"Boss_egg_crack");
			if (m_tAni.iStart >= m_tAni.iEnd)
			{
				m_iState = IDLE;
				m_tAni.iStart = 0;
				m_pMyGun = BossGun::Create(this);
				if (!CGameObjectManeger::Get_GameObjectManeger()->Add_GameObject(GAMEOBJECT::GUN, m_pMyGun))
					return Function_Fail;
			}
			return Function_Pass;

	case IDLE:
		if (m_idir == -1)
			m_hMemDC = CBitmapManeger::Get_BitmapManeger()->Get_BitmapDC(L"Boss_idle(R)");
		else
			m_hMemDC = CBitmapManeger::Get_BitmapManeger()->Get_BitmapDC(L"Boss_idle(L)");
		break;
	case WALK:
		if (m_idir == -1)
			m_hMemDC = CBitmapManeger::Get_BitmapManeger()->Get_BitmapDC(L"Boss_walk(R)");
		else
			m_hMemDC = CBitmapManeger::Get_BitmapManeger()->Get_BitmapDC(L"Boss_walk(L)");
		break;
	case READYDEAD:
		if (m_idir == -1)
			m_hMemDC = CBitmapManeger::Get_BitmapManeger()->Get_BitmapDC(L"Boss_dead(R)");
		else
			m_hMemDC = CBitmapManeger::Get_BitmapManeger()->Get_BitmapDC(L"Boss_dead(L)");
		ReadyDead();
		break;
	default:
		break;
	}


	if (700.f >= fabs(m_pTarget->GetInfo()->fX - m_tInfo.fX) && 700.f >= fabs(m_pTarget->GetInfo()->fY - m_tInfo.fY) && m_iState != READYDEAD && m_iState != DEAD)
	{
		if (RayTracying())
		{
			m_iState = WALK;
			MoveOn = true;
		}
		else
		{
			MoveOn = false;
			if (m_iState == WALK)
			{
				m_iState = IDLE;
				m_tAni.iStart = 0;
			}
		}
		if (MoveOn)
			Move();
	}
	else
	{
		if (m_iState == WALK)
		{
			m_iState = IDLE;
			m_tAni.iStart = 0;
		}
	}


	return Function_Pass;
}

int CBoss::LateUpdate_GameObject()
{
	return Function_Pass;
}

int CBoss::Release_GameObject()
{
	return Function_Pass;
}
