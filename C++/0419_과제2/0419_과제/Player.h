#pragma once
#include "GameObj.h"

class CBullet;
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

	void SetBulletList(list<CGameObj*>* BulletList) { m_pBulletList = BulletList; };

public:

	static CPlayer* Create();

private:
	CGameObj* m_pBullet;
	list<CGameObj*>* m_pBulletList;

};

