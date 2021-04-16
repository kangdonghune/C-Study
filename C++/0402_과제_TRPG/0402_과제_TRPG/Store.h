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
	CEquipment* m_pEquipments; //���� �迭
	CPosion* m_pPosions; //���Ƿ� �迭
};
#endif // !Store_h



