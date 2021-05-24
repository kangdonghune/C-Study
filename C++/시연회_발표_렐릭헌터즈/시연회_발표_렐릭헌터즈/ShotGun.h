#pragma once
#include "GameObject.h"
class CShotGun :public CGameObject
{
private:
	CShotGun();
public:
	~CShotGun();

public:
	static CGameObject* Create(CGameObject* pTarget);
	CGameObject* GetTarget() { return m_pTarget; }
public:

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

};

