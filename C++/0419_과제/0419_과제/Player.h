#pragma once
#include "GameObj.h"
class CPlayer : public CGameObj
{
public:
	CPlayer();
	~CPlayer();


	// CGameObj��(��) ���� ��ӵ�
	virtual int Ready_GameObj() override;

	virtual void Render_GameObj(HDC hdc) override;

	virtual void Update_GameObj() override;

	virtual void Release_GameObj() override;

	static CPlayer* Create();

private:
	HDC m_hdc;
};

