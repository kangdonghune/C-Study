#pragma once
#include "C_Object.h"
class CMonster : public C_Object
{
public:
	CMonster();
	~CMonster();

private:


	// C_Object��(��) ���� ��ӵ�
	virtual void ShowStatus() override;

};

