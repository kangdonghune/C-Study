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
		cout << "1. �ʺ��� ����. 2. �߱��� ����. 3. ����� ����. 4. �κ��丮 Ȯ�� 5. ���ư���" << endl;
		int iShopSelect;
		cin >> iShopSelect;
		switch (iShopSelect)
		{
		case 1:
			ItemSetting(vecItems, iShopSelect);
			for (int i = 0; i < vecItems.size(); i++)
			{	
				cout << i + 1 << "�� ��ǰ." << endl;
				vecItems[i]->ShowStatus();
			}
			BuyItem();
			break;
		case 2:
			ItemSetting(vecItems, iShopSelect);
			for (int i = 0; i < vecItems.size(); i++)
			{
				cout << i + 1 << "�� ��ǰ." << endl;
				vecItems[i]->ShowStatus();
			}
			BuyItem();
			break;
			case 3:
			ItemSetting(vecItems, iShopSelect);
			for (int i = 0; i < vecItems.size(); i++)
			{
				cout << i + 1 << "�� ��ǰ." << endl;
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
		dynamic_cast<CItem*>(vector[0])->SettingItem("����� ��", 1, 1, 1, 10);
		dynamic_cast<CItem*>(vector[1])->SettingItem("����� ����", 1, 1, 1, 10);
		dynamic_cast<CItem*>(vector[2])->SettingItem("����� ����", 1, 1, 1, 10);
		break;
	case expert:
		dynamic_cast<CItem*>(vector[0])->SettingItem("ưư�� ��", 10, 50, 10, 100);
		dynamic_cast<CItem*>(vector[1])->SettingItem("ưư�� ����", 50, 10, 10, 100);
		dynamic_cast<CItem*>(vector[2])->SettingItem("ưư�� ����", 10, 10, 50, 100);
		break;
	case master:
		dynamic_cast<CItem*>(vector[0])->SettingItem("�ܴ��� ��", 100, 500, 100, 1000);
		dynamic_cast<CItem*>(vector[1])->SettingItem("�ܴ��� ����", 500, 100, 100, 1000);
		dynamic_cast<CItem*>(vector[2])->SettingItem("�ܴ��� ����", 100, 100, 500, 1000);
		break;
	default:
		cout << "���� �ҷ����� �����Դϴ�." << endl;
		break;
	}
}

void CShop::BuyItem()
{
	cout << "1. �����Ѵ�. 2. ���ư���." << endl;
	while (true)
	{
		int iBuySelect;
		cin >> iBuySelect;
		switch (iBuySelect)
		{
		case 1:
			if (m_pPlayer->GetStatus().iInvenMaxSize <= dynamic_cast<CPlayer*>(m_pPlayer)->GetInventory().size())
			{
				cout << "�κ��丮�� ���� á���ϴ�.Ȯ���� �ϼ���." << endl;
				system("pause");
				return;
			}
			cout << "������ ������ ��ȣ�� �Է��ϼ���." << endl;
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
				cout << "�ܾ��� �����մϴ�." << endl;
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
	cout << "���� �κ��丮:" << m_pPlayer->GetStatus().iInvenMaxSize << "ĭ" << endl;
	cout << ">>�κ��丮 2ĭ Ȯ��(���:200���)" << endl;
	cout << "1. Ȯ��.  2. ���ư���." << endl;
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
				cout << "Ȯ��Ǿ����ϴ�. ���� �κ��丮:" << m_pPlayer->GetStatus().iInvenMaxSize << "ĭ" << endl;
				system("pause");
			}
			else
			{
				cout << "���� �����մϴ�." << endl;
				system("pause");
			}
			return;
		case 2:
			return;
		default:
			cout << "��ȣ�� Ȯ���ϼ���." << endl;
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

