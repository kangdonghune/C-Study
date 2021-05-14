#pragma once
#include "GameObject.h"
class CPlayer :	public CGameObject
{
private:
	CPlayer();

public:
	static CGameObject* Create(HDC hdc);

public:
	int SetAngle();
public:
	~CPlayer();

	// CGameObject을(를) 통해 상속됨
	virtual int Ready_GameObject() override;

	virtual int Render_GameObject() override;

	virtual int Update_GameObject() override;

	virtual int LateUpdate_GameObject() override;

	virtual int Release_GameObject() override;

private:
	float m_fJumpY;
	float m_fJumpSpeed;

};

