#pragma once
class C_Object abstract
{
public:
	C_Object();
	~C_Object();

public:
	void Init();
	const STATUS& GetStatus();
	STATUS& SetStatus();
	void SetDamege(C_Object* DEF);

public:
	virtual void ShowStatus() = 0;
	virtual void ReadyGameObj(const char* pClassName, int iHP, int iATK, int iDEF, int iLV = 1, int iMAXEXP = 100, int iGold = 10);

private:
	STATUS m_tSTATUS;
	
};

