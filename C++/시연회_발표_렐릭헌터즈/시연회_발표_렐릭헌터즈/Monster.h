#pragma once
#include "GameObject.h"
class CMonster : public CGameObject
{
protected:
	explicit CMonster();
public:
	virtual ~CMonster();

public:
	bool RayTracying();// 몬스터와 플레이어 사이에 보이지 않는 일직선 상의 레이저를 쏘아 플레이어 이외의 물체와 충돌하면 이동하도록

public:

	void SetName(MONSTER::Name MonsterName) { m_tName = MonsterName; }
	void SetTarget(CGameObject* pTarget) { m_pTarget = pTarget; }



protected:
	MONSTER::Name m_tName;
	CGameObject* m_pTarget;
	LaserPoint m_tLaser;
	HDC m_hMemDC;
	bool MoveOn;
	DWORD RayTime;
	DWORD RayCool;
	int m_irandomDirX;
	int m_irandomDirY;
};

