#pragma once
#include "Monster.h"
class CBoss :
	public CMonster
{
private:
	CBoss();
public:
	~CBoss();
	static CGameObject* Create(MONSTER::Name MonsterName, float X, float Y, CGameObject* pTarget);

public:
	void ReadyDead();
	void CheckState(int State);
	void Move();// 일정거리 이상 접근.  접근 후 레이트레이싱 결과 플레이어와 마주하면 공격 아니면 이동인데
				//이동 1. 레이트레이싱 true면 타겟방향으로 이동.
	void Attack();
	void UpdateHitBox();

public:


	// CMonster을(를) 통해 상속됨
	virtual int Ready_GameObject() override;
	virtual int Render_GameObject(HDC hdc) override;
	virtual int Update_GameObject() override;
	virtual int LateUpdate_GameObject() override;
	virtual int Release_GameObject() override;

private:
	bool m_bEggCrash;
};

