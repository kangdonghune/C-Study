#pragma once
#include "GameObject.h"

class CMapObject;
class CItem :
	public CGameObject
{
private:
	CItem();
public:
	~CItem();
public:
	static CGameObject* Create(CGameObject* pTarget, ITEM::Name Name , float POSX, float POSY);

public:
	void PushButton();

public:
	// CGameObject을(를) 통해 상속됨
	virtual int Ready_GameObject() override;
	virtual int Render_GameObject(HDC hdc) override;
	virtual int Update_GameObject() override;
	virtual int LateUpdate_GameObject() override;
	virtual int Release_GameObject() override;

private:
	CGameObject* m_pTarget;
	ITEM::Name Name;
	HDC m_hDC;
	bool m_bisTouch;
	bool m_bButtonRender;
	CMapObject* m_pButton;
};

