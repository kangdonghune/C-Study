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

Item-int iPrice ���
Equipment-����ü (ü��, ���ݷ�, ����) ���. ShowInfo(����ü, price) ��� ���
Posion-int iRecovery ���
*/

