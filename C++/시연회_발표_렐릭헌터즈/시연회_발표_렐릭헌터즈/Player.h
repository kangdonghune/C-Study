#pragma once
#include "GameObject.h"
class CPlayer :
	public CGameObject
{
private:
	CPlayer();
public:
	~CPlayer();

public:
	static CGameObject* Create();

public:
	void IsOffset();
	void Idle();
	void Walk();
	void Run();
	void Melee();

	void CheckState(int State);
	int CheckPlayerDir();


public:
	// CGameObject��(��) ���� ��ӵ�
	virtual int Ready_GameObject() override;
	virtual int Render_GameObject(HDC hdc) override;
	virtual int Update_GameObject() override;
	virtual int LateUpdate_GameObject() override;
	virtual int Release_GameObject() override;
private:
	HDC m_ObjectDc;
};

