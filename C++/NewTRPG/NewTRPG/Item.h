#pragma once
#include "C_Object.h"
class CItem : public C_Object
{
public:
	CItem();
	~CItem();

public:
	void SettingItem(const char* pItemName, int iHP, int iATK, int iDEF, int iGold);

	// C_Object��(��) ���� ��ӵ�
	virtual void ShowStatus() override;
};

