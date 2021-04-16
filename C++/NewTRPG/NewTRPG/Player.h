#pragma once
#include "C_Object.h"

class CPlayer : public C_Object
{
public:
	CPlayer();
	~CPlayer();

public:
	void LevelUp();
	void ReSetHP();

public:
	const vector<STATUS>& GetInventory();
	vector<STATUS>& SetInventory();

private:
	// C_Object��(��) ���� ��ӵ�
	virtual void ShowStatus() override;


private:
	vector<STATUS> m_vecInventory;

};

