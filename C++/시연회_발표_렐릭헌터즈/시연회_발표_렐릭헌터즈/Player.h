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
	
	void SetGrenadeOn(bool boolvalue) { m_bGrenadeOn = boolvalue; }

	void SetMyGun(CGameObject* pGun) { m_pMyGun = pGun; }
	vector<CGameObject*>& SetGunVector() { return m_vecGuns; }


	void IsOffset();
	void Idle();
	void Walk();
	void Run();
	void Melee();
	void ReadyDead();
	
	void CheckState(int State);
	int CheckPlayerDir();
	void UpdateHitBox();
	

public:
	// CGameObject을(를) 통해 상속됨
	virtual int Ready_GameObject() override;
	virtual int Render_GameObject(HDC hdc) override;
	virtual int Update_GameObject() override;
	virtual int LateUpdate_GameObject() override;
	virtual int Release_GameObject() override;
private:
	HDC m_ObjectDc;

	vector<CGameObject*> m_vecGuns;
	bool m_bGrenadeOn;
	int m_iGunNum;

};

