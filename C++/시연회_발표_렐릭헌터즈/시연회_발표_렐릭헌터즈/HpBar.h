#pragma once
#include "GameObject.h"
class CHpBar : public CGameObject
{
public:
	CHpBar();
	virtual ~CHpBar();

public: 

	// CGameObject��(��) ���� ��ӵ�
	virtual int Ready_GameObject() override;
	virtual int Render_GameObject(HDC hdc) override;
	virtual int Update_GameObject() override;
	virtual int LateUpdate_GameObject() override;
	virtual int Release_GameObject() override;
};

