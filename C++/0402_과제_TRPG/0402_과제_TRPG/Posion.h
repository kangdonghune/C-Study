#pragma once
#ifndef Posion_h
#include "Item.h"
class CPosion : public CItem
{
public:
	CPosion();
	CPosion(GREENPOSION P);
	CPosion(BLUEPOSION P);
	CPosion(REDPOSION P);
	virtual ~CPosion();
	void Init();
private:
	const char* m_pName;
	int m_iHealing;

	// CItem을(를) 통해 상속됨
	virtual void ShowInfo() override;
};

#endif // !Posion_h


