#include "stdafx.h"
#include "Posion.h"


CPosion::CPosion()
	:m_pName(nullptr)
	,m_iHealing(0)
{
	Init();
}

CPosion::CPosion(GREENPOSION P)
	:m_pName(nullptr)
{
	m_pName = P.pName;
	m_iHealing = P.iHealing;
	SetPrice(P.iPrice);
}

CPosion::CPosion(BLUEPOSION P)
	:m_pName(nullptr)
{
	m_pName = P.pName;
	m_iHealing = P.iHealing;
	SetPrice(P.iPrice);
}

CPosion::CPosion(REDPOSION P)
	:m_pName(nullptr)
{
	m_pName = P.pName;
	m_iHealing = P.iHealing;
	SetPrice(P.iPrice);
}

CPosion::~CPosion()
{
}

void CPosion::Init()
{
	m_pName = "";
	m_iHealing = 0;
	SetPrice(0);
}

void CPosion::ShowInfo()
{
	cout << "-------------------------------------------------------" << endl;
	cout << m_pName << endl;
	cout << "회복량:\t" << m_iHealing << endl;
	cout << "가격:\t" << GetPrice() << endl;
	cout << "-------------------------------------------------------" << endl;

}
