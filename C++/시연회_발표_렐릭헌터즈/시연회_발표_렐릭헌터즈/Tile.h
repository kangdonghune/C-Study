#pragma once
#include "MapObject.h"
class CTile : public CMapObject
{
private:
	explicit CTile();

public:
	static CMapObject* Create(POINT& TilePos);
public:
	~CTile();
public:
	void SetPos(POINT& MousePOS); // 마우스 좌표 대비하여 특정 공간 사이라면  실제 마우스 좌표가 아니라 틀에 맞는 위치에 생성되도록 좌표 수정.
public:
	// CMapObject을(를) 통해 상속됨
	virtual int Ready_MapObject() override;
	virtual int Render_MapObject(HDC hdc) override;
	virtual int Update_MapObject() override;
	virtual int LateUpdate_MapObject() override;
	virtual int Release_MapObject() override;
};

