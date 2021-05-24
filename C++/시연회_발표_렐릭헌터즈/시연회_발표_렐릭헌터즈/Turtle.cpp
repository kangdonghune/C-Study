#include "stdafx.h"
#include "Monster.h"
#include "Turtle.h"
#include "GameObject.h"
#include "BitmapManeger.h"
#include "Gun.h"
#include "GameObjectManeger.h"
#include "Player_Bullet.h"
#include "ScrollManeger.h"
#include "MapObjectManeger.h"
#include "MapObject.h"
#include <iostream>
#include <random>
#include "Pistol.h"


CTultle::CTultle()
{
}


CTultle::~CTultle()
{
	Release_GameObject();
}

CGameObject * CTultle::Create (MONSTER::Name MonsterName, float X, float Y, CGameObject* pTarget)
{
	CTultle* pInstance = new CTultle();
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

void CTultle::ReadyDead()
{
	if (m_tAni.iStart > m_tAni.iEnd)
	{
		m_iState = DEAD;

	}
}

void CTultle::CheckState(int State)
{
	switch (State)
	{
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

void CTultle::Move()
{
	if (300.f >= fabs(m_pTarget->GetInfo()->fX - m_tInfo.fX) && 300.f >= fabs(m_pTarget->GetInfo()->fY - m_tInfo.fY))
	{
		Attack();
		return;
	}
	AngleToTarget(m_pTarget->GetInfo()->fX+m_irandomDirX*150, m_pTarget->GetInfo()->fY+ m_irandomDirY * 150);
	m_tInfo.fX += cosf(m_tInfo.fAngle) * m_tInfo.fSpeed;
	m_tInfo.fY += sinf(m_tInfo.fAngle) * m_tInfo.fSpeed;
	
}

void CTultle::Attack()
{
	if (m_iState == DEAD || m_iState == READYDEAD)
		return;
	if (dynamic_cast<CGameObject*>(m_pMyGun)->Get_GunInfo()->fBulletTime + dynamic_cast<CGameObject*>(m_pMyGun)->Get_GunInfo()->fBulletCoolTime < GetTickCount())
	{
		CGameObjectManeger::Get_GameObjectManeger()->Add_GameObject(GAMEOBJECT::MONSTER_BULLET, CPlayer_Bullet::Create(this));
		dynamic_cast<CGameObject*>(m_pMyGun)->Get_GunInfo()->fBulletTime = GetTickCount();
	}
}

void CTultle::UpdateHitBox()
{
	m_rcHitBox.left = m_tInfo.fX - M_TURTLE_CX / 2;
	m_rcHitBox.top = (m_tInfo.fY - M_TURTLE_CY / 2);
	m_rcHitBox.right = m_tInfo.fX + M_TURTLE_CX / 2;
	m_rcHitBox.bottom = m_tInfo.fY + M_TURTLE_CY / 2;
}



int CTultle::Ready_GameObject()
{
	m_tInfo.iMaxHp = 30;
	m_tInfo.iHP = m_tInfo.iMaxHp;
	m_tInfo.iCX = M_TURTLE_DEADCX;
	m_tInfo.iCY = M_TURTLE_DEADCY;
	m_tInfo.fSpeed = 8;
	m_tInfo.iDamege = 10;
	m_tAni.iStart = 0;
	m_tAni.iEnd = 9;
	m_tInfo.dwTime = GetTickCount();
	m_tInfo.LimitTime = 120;
	m_idir = 1;
	RayTime = GetTickCount();
	RayCool = 500;
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> dir(-1, 1);
	m_irandomDirX = dir(gen);
	m_irandomDirY = dir(gen);

	m_pMyGun = CPistol::Create(this);
	if(!CGameObjectManeger::Get_GameObjectManeger()->Add_GameObject(GAMEOBJECT::GUN, m_pMyGun))
		return Function_Fail;
	return Function_Pass;
}

int CTultle::Render_GameObject(HDC hdc)
{
	CheckState(m_iState);
	if (m_iState == DEAD)
		return Function_Pass;
	if (m_tAni.iStart > m_tAni.iEnd)
		m_tAni.iStart = 0;
	GdiTransparentBlt(hdc, m_Rc.left + CScrollManeger::Get_ScrollX(), m_Rc.top + CScrollManeger::Get_ScrollY(), M_TURTLE_DEADCX, M_TURTLE_DEADCY, m_hMemDC, m_tAni.iStart * M_TURTLE_DEADCX, 0, M_TURTLE_DEADCX, M_TURTLE_DEADCY, bmi_BackGround);
	if (m_tInfo.dwTime + m_tInfo.LimitTime < GetTickCount())
	{
		m_tAni.iStart++;
		m_tInfo.dwTime = GetTickCount();
	}
	return Function_Pass;
}

int CTultle::Update_GameObject()
{
	UpdateRect();
	UpdateHitBox();
	CheckTargetDir(m_pTarget);

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
	case IDLE:
		if(m_idir == -1)
			m_hMemDC = CBitmapManeger::Get_BitmapManeger()->Get_BitmapDC(L"Turtle_idle(R)");
		else
			m_hMemDC = CBitmapManeger::Get_BitmapManeger()->Get_BitmapDC(L"Turtle_idle(L)");
		break;
	case WALK:
		if (m_idir == -1)
			m_hMemDC = CBitmapManeger::Get_BitmapManeger()->Get_BitmapDC(L"Turtle_walk(R)");
		else
			m_hMemDC = CBitmapManeger::Get_BitmapManeger()->Get_BitmapDC(L"Turtle_walk(L)");
		break;
	case READYDEAD:
		if (m_idir == -1)
			m_hMemDC = CBitmapManeger::Get_BitmapManeger()->Get_BitmapDC(L"Turtle_Dead(R)");
		else
			m_hMemDC = CBitmapManeger::Get_BitmapManeger()->Get_BitmapDC(L"Turtle_Dead(L)");
		ReadyDead();
		break;
	default:
		break;
	}


	if (400.f >= fabs(m_pTarget->GetInfo()->fX - m_tInfo.fX) && 400.f >= fabs(m_pTarget->GetInfo()->fY - m_tInfo.fY) && m_iState != READYDEAD && m_iState != DEAD)
	{
		if (RayTime + RayCool < GetTickCount())
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
			RayTime = GetTickCount();
		}
		
		if(MoveOn)
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

int CTultle::LateUpdate_GameObject() // 플레이어와 몬스터의 거리가 300이하일 때만 호출
{

	return Function_Pass;
}

int CTultle::Release_GameObject()
{
	m_pMyGun->SetDead();
	return Function_Pass;
}
