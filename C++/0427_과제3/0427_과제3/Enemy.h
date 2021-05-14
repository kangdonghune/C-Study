#pragma once
#include "GameObject.h"
class CEnemy :	public CGameObject
{
private:
	CEnemy();
public:
	~CEnemy();

	// CGameObject을(를) 통해 상속됨
	virtual int Ready_GameObject(HDC hdc) override;
	virtual void Render_GameObject(HDC hdc) override;
	virtual int Update_GameObject() override;
	virtual int LateUpdate_GameObject() override;
	virtual void Release_GameObject() override;

public:
	static CGameObject* Create(HDC hdc,INFO tInfo);
	void SetAngle(INFO tInfo);

};

