#pragma once
#ifndef CCharacter_h
#define CCharacter_h

class CCharacter
{
//������
public:
	CCharacter();
	virtual ~CCharacter();
//��� �Լ�
public:
	//����
	void Attck(CCharacter* Attacker, CCharacter* Attacked_side);
	STATUS* GetStatus();

//���� �Լ�
	virtual void Init() = 0;
	virtual void ShowInfo() = 0;
protected:
	STATUS* m_pStatus;
};
#endif // !CCharater_h

