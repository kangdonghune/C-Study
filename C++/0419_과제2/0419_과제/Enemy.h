#pragma once
#include "GameObj.h"
class CEnemy : public CGameObj
{
private:
	CEnemy();
public:
	
	~CEnemy();

	// CGameObj��(��) ���� ��ӵ�
	virtual int Ready_GameObj() override;
	virtual void Render_GameObj(HDC hdc) override;
	virtual void Update_GameObj() override;
	virtual void Release_GameObj() override;

public:

	static CGameObj* Create(HDC hdc);


};

