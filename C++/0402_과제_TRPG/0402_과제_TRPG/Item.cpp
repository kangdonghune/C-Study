#include "stdafx.h"
#include "Item.h"


CItem::CItem()
	:m_iPrice(0)
{
}


CItem::~CItem()
{
}

const int CItem::GetPrice()
{
	return m_iPrice;
}

void CItem::SetPrice(int iSettingPrice)
{
	m_iPrice = iSettingPrice;
}
