#pragma once
#include "GameObj.h"
class CBullet : public CGameObj
{
private:
	CBullet();
public:
	~CBullet();

	// CGameObj��(��) ���� ��ӵ�
	virtual int Ready_GameObj() override;
	virtual void Render_GameObj(HDC hdc) override;
	virtual void Update_GameObj() override;
	virtual void Release_GameObj() override;
	

	static CGameObj* Create(XY tXY);

private:

};

