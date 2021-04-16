#pragma once
#ifndef Player_h
#define Player_h
#include "Character.h"
class CPlayer : public CCharacter
{
public:
	CPlayer();
	~CPlayer();

public:
	void Init();
	void ShowInfo();
	void LeverUp();
private:

};
#endif // !Player_h



