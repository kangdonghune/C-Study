#pragma once
class C_Object;
class CField;
class CShop;
class CInventory;
class CMain
{
public:
	CMain();
	~CMain();
	//�����ϱ� �̾��ϱ�.
	//�����ϱ� �� ĳ���� ����
	//�κ� ȣ��

public:
	void ReadyMain();
	void UpdateMain();
	void SelectNeworLoad();
	void SelectClass();
	void Save();
	void Load(C_Object** ppPlayer);
private:
	C_Object* m_pPlayer;
	CField* m_pField;
	CShop* m_pShop;
	CInventory* m_pInventory;

};
