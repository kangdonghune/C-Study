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
	void SetPos(POINT& MousePOS); // ���콺 ��ǥ ����Ͽ� Ư�� ���� ���̶��  ���� ���콺 ��ǥ�� �ƴ϶� Ʋ�� �´� ��ġ�� �����ǵ��� ��ǥ ����.
public:
	// CMapObject��(��) ���� ��ӵ�
	virtual int Ready_MapObject() override;
	virtual int Render_MapObject(HDC hdc) override;
	virtual int Update_MapObject() override;
	virtual int LateUpdate_MapObject() override;
	virtual int Release_MapObject() override;
};

