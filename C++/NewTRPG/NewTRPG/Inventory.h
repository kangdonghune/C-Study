#pragma once
class C_Object;

class CInventory
{
public:
	CInventory();
	~CInventory();
	void SetPlayer(C_Object* pPlayer) { m_pPlayer = pPlayer; }
	void InventoryUpdate();
	void ShowInventory();
	void WearItem();
	void UnwornITem();
	void SellItem();
private:
	C_Object* m_pPlayer;
};

