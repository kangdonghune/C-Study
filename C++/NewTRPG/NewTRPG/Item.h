#pragma once
#include "C_Object.h"
class CItem : public C_Object
{
public:
	CItem();
	~CItem();

public:
	void SettingItem(const char* pItemName, int iHP, int iATK, int iDEF, int iGold);

	// C_Object을(를) 통해 상속됨
	virtual void ShowStatus() override;
};

