#pragma once
#ifndef Item_h
#define Item_h
class CItem abstract
{
public:
	CItem();
	virtual ~CItem();

public:
	virtual void ShowInfo() = 0;
	const int GetPrice();
	void SetPrice(int iSettingPrice);
private:
	int m_iPrice;
};
#endif // !Item_h



/*
Item > Equipment > Weapon > Sword 
							Axe
							Bow
				 > Armor  > ChainMail
						  > PlateArmor

	 > Expendables > Posion > GreenPosion, BluePosion , RedPosion 

Item-int iPrice 상속
Equipment-구조체 (체력, 공격력, 방어력) 상속. ShowInfo(구조체, price) 출력 상속
Posion-int iRecovery 상속
*/

