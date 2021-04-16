#pragma once
#ifndef Equipment_h
#define Equipment_h
#include "Item.h"

class CEquipment abstract : public CItem
{
public:
	CEquipment();
	virtual ~CEquipment();
	void Init();

public:
	EQUIPMENT_STATUS*  GetEquipStat();
	EQUIPMENT_STATUS* SetEquipment(EQUIPMENT_STATUS*& rEquipStat);

protected:
	EQUIPMENT_STATUS* m_pEquipStat;
};


#endif // !Equipment_h



