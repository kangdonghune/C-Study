#pragma once
#include "GameObject.h"
class BossGun :	public CGameObject
{
private:
	BossGun();
public:
	~BossGun();

public:
	static CGameObject* Create(CGameObject* pTarget);
	CGameObject* GetTarget() { return m_pTarget; }

public:
	GUNINFO* Get_GunInfo() { return &m_tGunInfo; }
	ITEM::Name GetName() { return m_tGunInfo.Name; }

	void SetTarget(CGameObject* pTarget) { m_pTarget = pTarget; }
	void UpdateGunRect();
public:

	// CGameObject을(를) 통해 상속됨
	virtual int Ready_GameObject() override;
	virtual int Render_GameObject(HDC hdc) override;
	virtual int Update_GameObject() override;
	virtual int LateUpdate_GameObject() override;
	virtual int Release_GameObject() override;

protected:

	HDC m_hGunDC;
	POINT* m_pPoint;
	GUNINFO m_tGunInfo;
};

