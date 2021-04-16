#pragma once
#ifndef Monster_h
#define Monster_h
#include "Character.h"

class CMonster : public CCharacter
{
public:
	CMonster();
	~CMonster();

public:
	void Init();
	void ShowInfo();

private:
};

#endif // !Monster_h

