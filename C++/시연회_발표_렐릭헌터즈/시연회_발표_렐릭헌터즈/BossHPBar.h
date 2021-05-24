#pragma once
#include "GameObject.h"
class CBossHPBar :public CGameObject
{
private:
	CBossHPBar();
public:
	~CBossHPBar();
public:
	static CGameObject* Create(CGameObject* pTarget);
public:
	// CGameObject을(를) 통해 상속됨
	virtual int Ready_GameObject() override;

	virtual int Render_GameObject(HDC hdc) override;

	virtual int Update_GameObject() override;

	virtual int LateUpdate_GameObject() override;

	virtual int Release_GameObject() override;

private:
	CGameObject* m_pTarget;
	float m_fRemainHP;

};

