#pragma once
#ifndef BeginnerStore_h
#define BeginnerStore_h
#include "Store.h"
#include "Player.h"
class CBeginnerStore : public CStore
{
public:
	CBeginnerStore();
	~CBeginnerStore();
	void Init(CPlayer* pPlayer);

public:
	// CStore을(를) 통해 상속됨
	virtual void ShowEquipments(CPlayer* pPlayer) override;
	virtual void ShowPosions(CPlayer* pPlayer) override;
	virtual void BuyEquipments(CPlayer* pPlayerint,int iGoodsNum) override;
	virtual void BuyPosions(CPlayer* pPlayer, int iGoodsNum) override;

private:
};

#endif


