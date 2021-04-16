#pragma once
#ifndef Store_h
#define Store_h
#include "Player.h"
class CEquipment;
class CSword;
class CPosion;

class CStore abstract
{
public:
	CStore();
	virtual ~CStore();

public:
	virtual void ShowEquipments(CPlayer* pPlayer) = 0;
	virtual void ShowPosions(CPlayer* pPlayer) = 0;
	virtual void BuyEquipments(CPlayer* pPlayer, int iGoodsNum) = 0;
	virtual void BuyPosions(CPlayer* pPlayer, int iGoodsNum) = 0;
protected:
	CEquipment* m_pEquipments; //장비류 배열
	CPosion* m_pPosions; //포션류 배열
};
#endif // !Store_h



