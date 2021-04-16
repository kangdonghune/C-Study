#include "stdafx.h"
#include "Shop.h"
#include "C_Object.h"
#include "Item.h"
#include "Player.h"


CShop::CShop()
	:m_pPlayer(nullptr)
{
}


CShop::~CShop()
{
}

void CShop::ShopUpdate()
{
	while (true)
	{
		system("cls");
		cout << "1. 초보자 상점. 2. 중급자 상점. 3. 상급자 상점. 4. 인벤토리 확장 5. 돌아가기" << endl;
		int iShopSelect;
		cin >> iShopSelect;
		switch (iShopSelect)
		{
		case 1:
			ItemSetting(vecItems, iShopSelect);
			for (int i = 0; i < vecItems.size(); i++)
			{	
				cout << i + 1 << "번 상품." << endl;
				vecItems[i]->ShowStatus();
			}
			BuyItem();
			break;
		case 2:
			ItemSetting(vecItems, iShopSelect);
			for (int i = 0; i < vecItems.size(); i++)
			{
				cout << i + 1 << "번 상품." << endl;
				vecItems[i]->ShowStatus();
			}
			BuyItem();
			break;
			case 3:
			ItemSetting(vecItems, iShopSelect);
			for (int i = 0; i < vecItems.size(); i++)
			{
				cout << i + 1 << "번 상품." << endl;
				vecItems[i]->ShowStatus();
			}
			BuyItem();
			break;
		case 4:
			ExtendInven();
			break;
		case 5:
			DeletevecInt(vecItems);
			return;
		default:
			continue;
		}
	}
}

void CShop::ItemSetting(vector<C_Object*>& vector, int iItemLevel)
{
	if (!vector.empty())
	{
		vector.clear();
	}
	vector.push_back(new CItem);
	vector.push_back(new CItem);
	vector.push_back(new CItem);

	switch (iItemLevel)
	{
	case novice:
		dynamic_cast<CItem*>(vector[0])->SettingItem("평범한 검", 1, 1, 1, 10);
		dynamic_cast<CItem*>(vector[1])->SettingItem("평범한 갑옷", 1, 1, 1, 10);
		dynamic_cast<CItem*>(vector[2])->SettingItem("평범한 방패", 1, 1, 1, 10);
		break;
	case expert:
		dynamic_cast<CItem*>(vector[0])->SettingItem("튼튼한 검", 10, 50, 10, 100);
		dynamic_cast<CItem*>(vector[1])->SettingItem("튼튼한 갑옷", 50, 10, 10, 100);
		dynamic_cast<CItem*>(vector[2])->SettingItem("튼튼한 방패", 10, 10, 50, 100);
		break;
	case master:
		dynamic_cast<CItem*>(vector[0])->SettingItem("단단한 검", 100, 500, 100, 1000);
		dynamic_cast<CItem*>(vector[1])->SettingItem("단단한 갑옷", 500, 100, 100, 1000);
		dynamic_cast<CItem*>(vector[2])->SettingItem("단단한 방패", 100, 100, 500, 1000);
		break;
	default:
		cout << "상점 불러오기 에러입니다." << endl;
		break;
	}
}

void CShop::BuyItem()
{
	cout << "1. 구매한다. 2. 돌아간다." << endl;
	while (true)
	{
		int iBuySelect;
		cin >> iBuySelect;
		switch (iBuySelect)
		{
		case 1:
			if (m_pPlayer->GetStatus().iInvenMaxSize <= dynamic_cast<CPlayer*>(m_pPlayer)->GetInventory().size())
			{
				cout << "인벤토리가 가득 찼습니다.확장을 하세요." << endl;
				system("pause");
				return;
			}
			cout << "구매할 아이템 번호를 입력하세요." << endl;
			int iItemNum;
			cin >> iItemNum;
			if (0 >= iItemNum || 4 <= iItemNum)
				continue;
			if (m_pPlayer->GetStatus().iGold >= vecItems[iItemNum-1]->GetStatus().iGold)
			{
				dynamic_cast<CPlayer*>(m_pPlayer)->SetInventory().push_back(vecItems[iItemNum - 1]->GetStatus());
				m_pPlayer->SetStatus().iGold -= vecItems[iItemNum - 1]->GetStatus().iGold;
				m_pPlayer->SetStatus().iInvenSize = dynamic_cast<CPlayer*>(m_pPlayer)->GetInventory().size();
			}
			else
			{
				cout << "잔액이 부족합니다." << endl;
				system("pause");
			}
			return;
		case 2:
			return;
		default:
			continue;
		}
	}
	
}

void CShop::DeletevecInt(vector<C_Object*>& vecItems)
{
	if (!vecItems.empty())
	{
		for (int i = 0; i < vecItems.size(); i++)
		{
			delete vecItems[i];
		}
		vecItems.clear();
		vecItems.swap(vector<C_Object*>());
	}
}

void CShop::ExtendInven()
{
	system("cls");
	cout << "현재 인벤토리:" << m_pPlayer->GetStatus().iInvenMaxSize << "칸" << endl;
	cout << ">>인벤토리 2칸 확장(비용:200골드)" << endl;
	cout << "1. 확장.  2. 돌아가기." << endl;
	int iExtendSelect;
	while (true)
	{
		cin >> iExtendSelect;
		switch (iExtendSelect)
		{
		case 1:
			if (m_pPlayer->GetStatus().iGold >= 200)
			{
				m_pPlayer->SetStatus().iGold -= 200;
				m_pPlayer->SetStatus().iInvenMaxSize += 2;
				cout << "확장되었습니다. 현재 인벤토리:" << m_pPlayer->GetStatus().iInvenMaxSize << "칸" << endl;
				system("pause");
			}
			else
			{
				cout << "돈이 부족합니다." << endl;
				system("pause");
			}
			return;
		case 2:
			return;
		default:
			cout << "번호를 확인하세요." << endl;
			break;
		}
	}
}


const vector<C_Object*>& CShop::GetvecItems()
{
	return vecItems;
}

vector<C_Object*>& CShop::SetvecItems()
{
	return vecItems;
}

