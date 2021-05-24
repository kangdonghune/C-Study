#pragma once
#include "GameObject.h"
class CGrenade : public CGameObject
{
private:
	CGrenade();
public:
	~CGrenade();
public:
	static CGameObject* Create(CGameObject* pObject, POINT tMouse);
public:

public:


	// CGameObject을(를) 통해 상속됨
	virtual int Ready_GameObject() override;

	virtual int Render_GameObject(HDC hdc) override;

	virtual int Update_GameObject() override;

	virtual int LateUpdate_GameObject() override;

	virtual int Release_GameObject() override;

private:
	CGameObject* m_pTarger;
	POINT m_tPoint;
	float m_fTimer;
	float m_fMaxPower;
	GRAVITY m_tGravity;
	float MaxDist;
	float m_iDist;
	float sin;
	float cos;
	DWORD Timer;
	bool m_bIsBoom;
};

