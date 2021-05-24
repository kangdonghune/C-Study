#pragma once
#include "GameObject.h"
class CMonster : public CGameObject
{
protected:
	explicit CMonster();
public:
	virtual ~CMonster();

public:
	bool RayTracying();// ���Ϳ� �÷��̾� ���̿� ������ �ʴ� ������ ���� �������� ��� �÷��̾� �̿��� ��ü�� �浹�ϸ� �̵��ϵ���

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

