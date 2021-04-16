#include "stdafx.h"
#include "Sword.h"

CSword::CSword()
{
	Init();
}

CSword::CSword(BEGGINERSWORD T)
{
	m_pEquipStat->pItemName = T.pItemName;
	m_pEquipStat->m_iE_HP = T.iHP;
	m_pEquipStat->m_iE_ATK = T.iATK;
	m_pEquipStat->m_iE_DEF = T.iDEF;
	SetPrice(T.iPrice);

}

CSword::CSword(NORMALSWORD T)
{
	m_pEquipStat->pItemName = T.pItemName;
	SetEquipment(m_pEquipStat)->m_iE_HP = T.iHP;
	SetEquipment(m_pEquipStat)->m_iE_ATK = T.iATK;
	SetEquipment(m_pEquipStat)->m_iE_DEF = T.iDEF;
	SetPrice(T.iPrice);
}

CSword::CSword(MASTERSWORD T)
{
	m_pEquipStat->pItemName = T.pItemName;
	SetEquipment(m_pEquipStat)->m_iE_HP = T.iHP;
	SetEquipment(m_pEquipStat)->m_iE_ATK = T.iATK;
	SetEquipment(m_pEquipStat)->m_iE_DEF = T.iDEF;
	SetPrice(T.iPrice);
}


CSword::~CSword()
{
}

void CSword::Init()
{
	m_pEquipStat->pItemName = "비어있음";
	m_pEquipStat->m_iE_HP = 0;
	m_pEquipStat->m_iE_ATK = 0;
	m_pEquipStat->m_iE_DEF = 0;
	SetPrice(0);
}

void CSword::ShowInfo()
{
	cout << "-------------------------------------------------------" << endl;
	cout << m_pEquipStat->pItemName << endl;
	cout << "체력:\t" << m_pEquipStat->m_iE_HP << endl;
	cout << "공격력:\t" << m_pEquipStat->m_iE_ATK << endl;
	cout << "방어력:\t" << m_pEquipStat->m_iE_DEF << endl;
	cout << "가격:\t" << GetPrice() << "냥" << endl;
	cout << "-------------------------------------------------------" << endl;
	
}
