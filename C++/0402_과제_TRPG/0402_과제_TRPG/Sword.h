#pragma once
#ifndef Sword_h
#define Sword_h
#include "Equipment.h"
class CSword : public CEquipment
{
public:
	CSword();
	CSword(BEGGINERSWORD T);
	CSword(NORMALSWORD T);
	CSword(MASTERSWORD T);
	virtual ~CSword();
	void Init();

public:
	virtual void ShowInfo();
private:
	
};
#endif


