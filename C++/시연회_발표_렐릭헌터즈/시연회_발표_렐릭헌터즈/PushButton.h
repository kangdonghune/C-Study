#pragma once
#include "MapObject.h"
class CPushButton :	public CMapObject
{
private:
	CPushButton();
public:
	~CPushButton();

public:
	static CMapObject* Create(float PosX, float PosY);
	void SetPOS(POINT& TilePos);
public:
	// CMapObject을(를) 통해 상속됨
	virtual int Ready_MapObject() override;
	virtual int Render_MapObject(HDC hdc) override;
	virtual int Update_MapObject() override;
	virtual int LateUpdate_MapObject() override;
	virtual int Release_MapObject() override;

private:
	ANIINFO m_tAni;
	DWORD m_dwTime;
	DWORD m_dwLimit;
};

