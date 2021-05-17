#pragma once
#include "MapObject.h"
class CWall : public CMapObject
{
private:

	CWall();
	~CWall();

public:
	static CMapObject* Create(POINT& MousePos);
public:
	void SetPOS(POINT& MousePos);
public:
	// CMapObject��(��) ���� ��ӵ�
	virtual int Ready_MapObject() override;
	virtual int Render_MapObject(HDC hdc) override;
	virtual int Update_MapObject() override;
	virtual int LateUpdate_MapObject() override;
	virtual int Release_MapObject() override;
};

