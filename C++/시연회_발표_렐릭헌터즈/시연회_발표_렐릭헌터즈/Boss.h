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
	void Move();// �����Ÿ� �̻� ����.  ���� �� ����Ʈ���̽� ��� �÷��̾�� �����ϸ� ���� �ƴϸ� �̵��ε�
				//�̵� 1. ����Ʈ���̽� true�� Ÿ�ٹ������� �̵�.
	void Attack();
	void UpdateHitBox();

public:


	// CMonster��(��) ���� ��ӵ�
	virtual int Ready_GameObject() override;
	virtual int Render_GameObject(HDC hdc) override;
	virtual int Update_GameObject() override;
	virtual int LateUpdate_GameObject() override;
	virtual int Release_GameObject() override;

private:
	bool m_bEggCrash;
};

