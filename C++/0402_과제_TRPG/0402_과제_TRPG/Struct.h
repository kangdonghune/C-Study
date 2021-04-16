#pragma once
#ifndef Struct_h
#define Str_h

typedef struct
{
	const char* pItemName = "";
	int m_iE_HP;
	int m_iE_ATK;
	int m_iE_DEF;

}EQUIPMENT_STATUS;

typedef struct
{
	char m_szName[32];
	int m_iLV;
	char m_szClassName[20];
	int m_iHP;
	int m_iATK;
	int m_iDEF;
	int m_iEXP;
	int m_iMaxExp;
	int m_iGold;
	vector<EQUIPMENT_STATUS> m_vecInventory; //기본 사이즈는 3 제한. 추가 결제 시 5로 증가.
	int m_iMaxInvenSize = 3;
}STATUS;

typedef struct
{
	const char* szSlime = "슬라임";
	const char* szSkelleton = "해골병사";
	const char* szOrc = "오크";
}MONSTERBROOD;



typedef struct
{
	const char* pItemName = "BegginerSword";
	int iHP = 1;
	int iATK = 1;
	int iDEF = 1;
	int iPrice =  1;
}BEGGINERSWORD;

typedef struct
{
	const char* pItemName = "NormalSword";
	int iHP = 10;
	int iATK = 10;
	int iDEF = 10;
	int iPrice = 50;
}NORMALSWORD;

typedef struct
{
	const char* pItemName = "MasterSword";
	int iHP = 90;
	int iATK = 90;
	int iDEF = 90;
	int iPrice = 900;
}MASTERSWORD;

typedef struct
{
	const char* pName ="Green-Posion";
	int iHealing = 10;
	int iPrice = 5;
}GREENPOSION;

typedef struct
{
	const char* pName = "Blue-Posion";
	int iHealing = 50;
	int iPrice = 30;
}BLUEPOSION;

typedef struct
{
	const char* pName = "Red-Posion";
	int iHealing = 100;
	int iPrice = 70;
}REDPOSION;
#endif // !Status_h