#pragma once
class CPlayer;
class CInventory
{
public:
	CInventory();
	~CInventory();
public:
	void ShowInventory(CPlayer* pPlayer);
private:
	EQUIPMENT_STATUS* Weapons;
};

