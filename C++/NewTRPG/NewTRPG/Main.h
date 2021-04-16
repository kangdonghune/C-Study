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
	//새로하기 이어하기.
	//새로하기 시 캐릭터 생성
	//로비 호출

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
