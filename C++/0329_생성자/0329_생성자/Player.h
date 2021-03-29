#pragma once
#include "stdafx.h"


class CMonster;
class CPlayer
{
public:
	CPlayer();
	~CPlayer();

	void Test();
private:
	CMonster* m_tMonster;
};

