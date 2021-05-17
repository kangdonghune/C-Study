#pragma once
#include "MapObject.h"
class CCelling : public CMapObject
{
private:
	CCelling();
public:
	~CCelling();
public:
	static CMapObject* Create(POINT& TilePos);
	void SetPOS(POINT& TilePos);
public:
	// CMapObject을(를) 통해 상속됨
	virtual int Ready_MapObject() override;
	virtual int Render_MapObject(HDC hdc) override;
	virtual int Update_MapObject() override;
	virtual int LateUpdate_MapObject() override;
	virtual int Release_MapObject() override;

};

