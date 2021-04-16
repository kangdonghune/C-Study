#pragma once
#ifndef CCharacter_h
#define CCharacter_h

class CCharacter
{
//생성자
public:
	CCharacter();
	virtual ~CCharacter();
//상속 함수
public:
	//공격
	void Attck(CCharacter* Attacker, CCharacter* Attacked_side);
	STATUS* GetStatus();

//가상 함수
	virtual void Init() = 0;
	virtual void ShowInfo() = 0;
protected:
	STATUS* m_pStatus;
};
#endif // !CCharater_h

