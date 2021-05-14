#pragma once
#include "GameObject.h"
class CShield : public CGameObject
{
private:
	CShield();
public:
	~CShield();

	// CGameObject을(를) 통해 상속됨
	virtual int Ready_GameObject(HDC hdc) override;
	virtual void Render_GameObject(HDC hdc) override;
	virtual int Update_GameObject() override;
	virtual int LateUpdate_GameObject() override;
	virtual void Release_GameObject() override;

public:
	static CGameObject* Create(HDC hdc, INFO tInfo);
	void SetXY(const INFO tInfo);
};

