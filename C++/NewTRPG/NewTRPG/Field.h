#pragma once
#include "C_Object.h"
class CField
{
public:
	CField();
	~CField();

public:
	void SetPlayer(C_Object* pPlayer) { m_pPlayer = pPlayer; }
	void FieldUpdate();
	void Fight(C_Object* pPlayer, C_Object* pMonster);

private:
	C_Object* m_pPlayer;
};

