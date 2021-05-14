#pragma once
#include "GameObject.h"
class CPlayer : public CGameObject
{
private:
	CPlayer();
public:
	~CPlayer();
public:


	// CGameObject을(를) 통해 상속됨
	virtual int Ready_GameObject(HDC hdc) override;

	virtual void Render_GameObject(HDC hdc) override;

	virtual int Update_GameObject() override;

	virtual int LateUpdate_GameObject() override;

	virtual void Release_GameObject() override;

public:
	static CGameObject* Create(HDC hdc, list<CGameObject*>* pBulletList);
	CGameObject* CreateBullet(POINT* pMouse);
	CGameObject* CreateShield();
	CGameObject* CreateGuideBullet();
	list<CGameObject*>* m_pGameObjList;
	list<CGameObject*>* m_pBulletList;
	list<CGameObject*>* m_pShieldList;
	DWORD m_dwBulletCoolTime;
	DWORD m_dwShieldCoolTime;
};

