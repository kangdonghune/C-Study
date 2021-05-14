#pragma once
#include "GameObject.h"
class CGun :
	public CGameObject
{
private:
	CGun();

public:
	static CGameObject* Create(CGameObject* pTarget);

public:
	void SetTarget(CGameObject* pTarget) { m_pTarget = pTarget; }
	void UpdateGunRect();
	void SetPoints(float Radian);
public:
	~CGun();

	// CGameObject을(를) 통해 상속됨
	virtual int Ready_GameObject() override;
	virtual int Render_GameObject(HDC hdc) override;
	virtual int Update_GameObject() override;
	virtual int LateUpdate_GameObject() override;
	virtual int Release_GameObject() override;
	
private:
	CGameObject* m_pTarget;
	HDC m_hGunDC;
	POINT* m_pPoint;

};

