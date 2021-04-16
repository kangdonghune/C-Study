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
	m_pEquipStat->pItemName = "�������";
	m_pEquipStat->m_iE_HP = 0;
	m_pEquipStat->m_iE_ATK = 0;
	m_pEquipStat->m_iE_DEF = 0;
	SetPrice(0);
}

void CSword::ShowInfo()
{
	cout << "-------------------------------------------------------" << endl;
	cout << m_pEquipStat->pItemName << endl;
	cout << "ü��:\t" << m_pEquipStat->m_iE_HP << endl;
	cout << "���ݷ�:\t" << m_pEquipStat->m_iE_ATK << endl;
	cout << "����:\t" << m_pEquipStat->m_iE_DEF << endl;
	cout << "����:\t" << GetPrice() << "��" << endl;
	cout << "-------------------------------------------------------" << endl;
	
}
