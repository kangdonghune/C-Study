#pragma once
#include "C_Object.h"
class CMonster : public C_Object
{
public:
	CMonster();
	~CMonster();

private:


	// C_Object을(를) 통해 상속됨
	virtual void ShowStatus() override;

};

