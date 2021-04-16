#include "stdafx.h"
#include "Inventory.h"
#include "C_Object.h"
#include "Player.h"


CInventory::CInventory()
	:m_pPlayer(nullptr)
{
}


CInventory::~CInventory()
{
}

void CInventory::InventoryUpdate()
{
	while (true)
	{
		system("cls");
		ShowInventory();
		cout << "1. 착용하기. 2. 해제하기. 3. 판매하기. 4.돌아가기" << endl;
		int iInvenSelect;
		cin >> iInvenSelect;
		switch (iInvenSelect)
		{
		case 1:
			WearItem();
			break;
		case 2:
			UnwornITem();
			break;
		case 3:
			SellItem();
			break;
		case 4:
			dynamic_cast<CPlayer*>(m_pPlayer)->ReSetHP();
			return;
		default:
			cout << "번호를 확인하세요." << endl;
			system("pause");
			continue;
		}
	}


}

void CInventory::ShowInventory()
{
	for (int i = 0; i < dynamic_cast<CPlayer*>(m_pPlayer)->GetInventory().size(); i++)
	{
		cout << i + 1 << "번" << endl;
		cout << "-------------아이템-------------" << endl;
		cout << "이름:\t" << dynamic_cast<CPlayer*>(m_pPlayer)->GetInventory().at(i).szName << endl;
		cout << "체력:\t" << dynamic_cast<CPlayer*>(m_pPlayer)->GetInventory().at(i).iHP << endl;
		cout << "공격력:\t" << dynamic_cast<CPlayer*>(m_pPlayer)->GetInventory().at(i).iATK << endl;
		cout << "방어력:\t" << dynamic_cast<CPlayer*>(m_pPlayer)->GetInventory().at(i).iDEF << endl;
		if (dynamic_cast<CPlayer*>(m_pPlayer)->GetInventory().at(i).bIsUsed)
		{
			cout << "착용 중" << endl;
		}
		else
		{
			cout << "미착용 중" << endl;
		}
		cout << "--------------------------------" << endl;
	}
}

void CInventory::WearItem()
{
	if (dynamic_cast<CPlayer*>(m_pPlayer)->GetInventory().empty())
	{
		cout << "인벤토리가 비었습니다." << endl;
		system("pause");
		return;
	}

	cout << "착용할 아이템 번호를 입력하세요." << endl;
	int iWearNum;
	
	while (true)
	{
		cin >> iWearNum;
	
		if (iWearNum <= 0 || iWearNum > m_pPlayer->GetStatus().iInvenMaxSize)
		{
			cout << "해당하는 번호의 아이템이 없습니다. 번호를 확인하세요." << endl;
			system("pause");
			return;
		}
		if (dynamic_cast<CPlayer*>(m_pPlayer)->GetInventory()[iWearNum - 1].bIsUsed)
		{
			cout << "착용 중인 상품은 착용할 수 없습니다." << endl;
			system("pause");
			return;
		}
		
		dynamic_cast<CPlayer*>(m_pPlayer)->SetInventory().at(iWearNum-1).bIsUsed = true;
		m_pPlayer->SetStatus().iMAXHP += dynamic_cast<CPlayer*>(m_pPlayer)->GetInventory().at(iWearNum - 1).iHP;
		m_pPlayer->SetStatus().iATK += dynamic_cast<CPlayer*>(m_pPlayer)->GetInventory().at(iWearNum - 1).iATK;
		m_pPlayer->SetStatus().iDEF += dynamic_cast<CPlayer*>(m_pPlayer)->GetInventory().at(iWearNum - 1).iDEF;
		break;
	}
}

void CInventory::UnwornITem()
{
	if (dynamic_cast<CPlayer*>(m_pPlayer)->GetInventory().empty())
	{
		cout << "인벤토리가 비었습니다." << endl;
		system("pause");
		return;
	}

	cout << "해제할 아이템 번호를 입력하세요." << endl;
	int iUnwearNum;
	while (true)
	{
		cin >> iUnwearNum;

		if (iUnwearNum <= 0 || iUnwearNum > m_pPlayer->GetStatus().iInvenMaxSize)
		{
			cout << "해당하는 번호의 아이템이 없습니다. 번호를 확인하세요." << endl;
			system("pause");
			return;
		}
		if (dynamic_cast<CPlayer*>(m_pPlayer)->GetInventory()[iUnwearNum - 1].bIsUsed == false)
		{
			cout << "미착용 중인 상품은 해제할 수 없습니다." << endl;
			system("pause");
			return;
		}

		dynamic_cast<CPlayer*>(m_pPlayer)->SetInventory().at(iUnwearNum - 1).bIsUsed = false;
		m_pPlayer->SetStatus().iMAXHP -= dynamic_cast<CPlayer*>(m_pPlayer)->GetInventory().at(iUnwearNum - 1).iHP;
		m_pPlayer->SetStatus().iATK -= dynamic_cast<CPlayer*>(m_pPlayer)->GetInventory().at(iUnwearNum - 1).iATK;
		m_pPlayer->SetStatus().iDEF -= dynamic_cast<CPlayer*>(m_pPlayer)->GetInventory().at(iUnwearNum - 1).iDEF;
		break;
	}
}

void CInventory::SellItem()
{
	if (dynamic_cast<CPlayer*>(m_pPlayer)->GetInventory().empty())
	{
		cout << "인벤토리가 비었습니다." << endl;
		system("pause");
		return;
	}

	cout << "판매할 아이템 번호를 입력하세요.(아이템 가의 70퍼가격 판매)" << endl;
	int iSellNum;
	while (true)
	{
		cin >> iSellNum;
	
		if (iSellNum <= 0 || iSellNum > m_pPlayer->GetStatus().iInvenMaxSize)
		{
			cout << "해당하는 번호의 아이템이 없습니다. 번호를 확인하세요." << endl;
			system("pause");
			return;
		}
		if (dynamic_cast<CPlayer*>(m_pPlayer)->GetInventory()[iSellNum-1].bIsUsed)
		{
			cout << "착용 중인 상품은 판매할 수 없습니다." << endl;
			system("pause");
			return;
		}
		m_pPlayer->SetStatus().iGold += (dynamic_cast<CPlayer*>(m_pPlayer)->GetInventory()[iSellNum - 1].iGold *0.7f);
		vector<STATUS>::iterator iter = dynamic_cast<CPlayer*>(m_pPlayer)->SetInventory().begin();
		dynamic_cast<CPlayer*>(m_pPlayer)->SetInventory().erase(iter + iSellNum - 1);
		m_pPlayer->SetStatus().iInvenSize = dynamic_cast<CPlayer*>(m_pPlayer)->GetInventory().size();
		break;
	}

}
