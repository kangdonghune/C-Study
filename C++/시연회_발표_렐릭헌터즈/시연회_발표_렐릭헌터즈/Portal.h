#pragma once
#include "MapObject.h"
class CGameObject;
class CPortal :public CMapObject
{
private:
	CPortal();
public:
	~CPortal();
public:
	static CMapObject* Create(float PosX, float PosY);

public:
	void NextMap();
	void SetPOS(POINT& TilePos);
public:
	// CMapObject을(를) 통해 상속됨
	virtual int Ready_MapObject() override;
	virtual int Render_MapObject(HDC hdc) override;
	virtual int Update_MapObject() override;
	virtual int LateUpdate_MapObject() override;
	virtual int Release_MapObject() override;

private:
	bool m_bButtonRender;
	CGameObject* m_pPlayer;
	CMapObject* m_pButton;
};

