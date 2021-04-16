#pragma once
class C_Object;
class CShop
{
public:
	CShop();
	~CShop();

public:
	void SetPlayer(C_Object* pPlayer) { m_pPlayer = pPlayer; }
	void ShopUpdate();

public:
	void ItemSetting(vector<C_Object*>& vector, int iItemLevel);
	void BuyItem();
	void DeletevecInt(vector<C_Object*>& vecItems);
	void ExtendInven();

public:
	const vector<C_Object*>&  GetvecItems();
	vector<C_Object*>& SetvecItems();

private:
	C_Object* m_pPlayer;
	vector<C_Object*> vecItems;
};

