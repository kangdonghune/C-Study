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
		cout << "1. �����ϱ�. 2. �����ϱ�. 3. �Ǹ��ϱ�. 4.���ư���" << endl;
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
			cout << "��ȣ�� Ȯ���ϼ���." << endl;
			system("pause");
			continue;
		}
	}


}

void CInventory::ShowInventory()
{
	for (int i = 0; i < dynamic_cast<CPlayer*>(m_pPlayer)->GetInventory().size(); i++)
	{
		cout << i + 1 << "��" << endl;
		cout << "-------------������-------------" << endl;
		cout << "�̸�:\t" << dynamic_cast<CPlayer*>(m_pPlayer)->GetInventory().at(i).szName << endl;
		cout << "ü��:\t" << dynamic_cast<CPlayer*>(m_pPlayer)->GetInventory().at(i).iHP << endl;
		cout << "���ݷ�:\t" << dynamic_cast<CPlayer*>(m_pPlayer)->GetInventory().at(i).iATK << endl;
		cout << "����:\t" << dynamic_cast<CPlayer*>(m_pPlayer)->GetInventory().at(i).iDEF << endl;
		if (dynamic_cast<CPlayer*>(m_pPlayer)->GetInventory().at(i).bIsUsed)
		{
			cout << "���� ��" << endl;
		}
		else
		{
			cout << "������ ��" << endl;
		}
		cout << "--------------------------------" << endl;
	}
}

void CInventory::WearItem()
{
	if (dynamic_cast<CPlayer*>(m_pPlayer)->GetInventory().empty())
	{
		cout << "�κ��丮�� ������ϴ�." << endl;
		system("pause");
		return;
	}

	cout << "������ ������ ��ȣ�� �Է��ϼ���." << endl;
	int iWearNum;
	
	while (true)
	{
		cin >> iWearNum;
	
		if (iWearNum <= 0 || iWearNum > m_pPlayer->GetStatus().iInvenMaxSize)
		{
			cout << "�ش��ϴ� ��ȣ�� �������� �����ϴ�. ��ȣ�� Ȯ���ϼ���." << endl;
			system("pause");
			return;
		}
		if (dynamic_cast<CPlayer*>(m_pPlayer)->GetInventory()[iWearNum - 1].bIsUsed)
		{
			cout << "���� ���� ��ǰ�� ������ �� �����ϴ�." << endl;
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
		cout << "�κ��丮�� ������ϴ�." << endl;
		system("pause");
		return;
	}

	cout << "������ ������ ��ȣ�� �Է��ϼ���." << endl;
	int iUnwearNum;
	while (true)
	{
		cin >> iUnwearNum;

		if (iUnwearNum <= 0 || iUnwearNum > m_pPlayer->GetStatus().iInvenMaxSize)
		{
			cout << "�ش��ϴ� ��ȣ�� �������� �����ϴ�. ��ȣ�� Ȯ���ϼ���." << endl;
			system("pause");
			return;
		}
		if (dynamic_cast<CPlayer*>(m_pPlayer)->GetInventory()[iUnwearNum - 1].bIsUsed == false)
		{
			cout << "������ ���� ��ǰ�� ������ �� �����ϴ�." << endl;
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
		cout << "�κ��丮�� ������ϴ�." << endl;
		system("pause");
		return;
	}

	cout << "�Ǹ��� ������ ��ȣ�� �Է��ϼ���.(������ ���� 70�۰��� �Ǹ�)" << endl;
	int iSellNum;
	while (true)
	{
		cin >> iSellNum;
	
		if (iSellNum <= 0 || iSellNum > m_pPlayer->GetStatus().iInvenMaxSize)
		{
			cout << "�ش��ϴ� ��ȣ�� �������� �����ϴ�. ��ȣ�� Ȯ���ϼ���." << endl;
			system("pause");
			return;
		}
		if (dynamic_cast<CPlayer*>(m_pPlayer)->GetInventory()[iSellNum-1].bIsUsed)
		{
			cout << "���� ���� ��ǰ�� �Ǹ��� �� �����ϴ�." << endl;
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
