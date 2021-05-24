#pragma once
#include "GameObject.h"
class CPlayer_Bullet : public CGameObject
{
private:
	CPlayer_Bullet();
public:
	~CPlayer_Bullet();

public:
	static CGameObject* Create(CGameObject* pTarget);
	void SetTarget(CGameObject* pTarget) { m_pTarget = pTarget; }
public:

	// CGameObject을(를) 통해 상속됨
	virtual int Ready_GameObject() override;

	virtual int Render_GameObject(HDC hdc) override;

	virtual int Update_GameObject() override;

	virtual int LateUpdate_GameObject() override;

	virtual int Release_GameObject() override;

private:
	int m_icount;
	float m_fStart;
	BULLETINFO m_tBulletInfo;
	RECT m_tOldRect;
	int randomDir;
	HDC m_hDC;
	ITEM::Name Name;
};

