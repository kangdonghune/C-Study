#include "stdafx.h"
#include "BeginnerStore.h"
#include "Item.h"
#include "Sword.h"
#include "Player.h"


CBeginnerStore::CBeginnerStore()
{
}


CBeginnerStore::~CBeginnerStore()
{
	/*if (m_pEquipments != nullptr)
	{
		delete m_pEquipments;
		m_pEquipments = nullptr;
	}
	if (m_pPosions != nullptr)
	{
		delete m_pPosions;
		m_pPosions = nullptr;
	}*/
}

void CBeginnerStore::Init(CPlayer* pPlayer)
{
	system("pls");
	cout << "1. ��� ����.  2. �Ҹ�ǰ ����.  3. ���� ������." << endl;
	int iStoreSelect = 0;
	while (iStoreSelect != 3) 
	{
		cin >> iStoreSelect;
		switch (iStoreSelect)
		{
		case 1:
			ShowEquipments(pPlayer);
			break;
		case 2:
			ShowPosions(pPlayer);
			break;
		case 3:
			return;
		default:
			cout << "�Է� ����. �ٽ� �Է��ϼ���." << endl;
			break;
		}
	}	
}

void CBeginnerStore::ShowEquipments(CPlayer* pPlayer)
{
	while (true)
	{
		system("cls");
		int iItemNum = 0;
		int iSize = 3;
		m_pEquipments = new CSword[iSize]; //EQUIP-STATUS ũ�� ��ŭ ���� �Ҵ�
		BEGGINERSWORD T;
		m_pEquipments[0] = CSword(T);
		NORMALSWORD N;
		m_pEquipments[1] = CSword(N);
		MASTERSWORD M;
		m_pEquipments[2] = CSword(M);

		for (int i = 0; i < 3; i++)
		{
			cout << i + 1 << "�� ��ǰ" << endl;
			m_pEquipments[i].ShowInfo();
		}
		cout << "1. ����.  2. ��������" << endl;
		int iSelect = 0;
		cin >> iSelect;
		switch (iSelect)
		{
		case 1:
			cout << "�����ϰ��� �ϴ� ������ ��ȣ�� �Է��ϼ���." << endl;
			while (true)
			{
				cin >> iItemNum;
				if (0 >= iItemNum || iSize < iItemNum)
				{
					cout << "�����ϰ��� �ϴ� ��ǰ�� �����ϴ�." << endl;
					system("pause");
					continue;
				}
				BuyEquipments(pPlayer, iItemNum-1);
				break;
			}
			break;
		case 2:
			delete m_pEquipments[0].GetEquipStat();
			m_pEquipments = nullptr;
			return;
		default:
			cout << "�Է� ��ȣ�� Ȯ���ϼ���" << endl;
			system("pause");
			break;
		}
	/*	delete m_pEquipments;
		m_pEquipments = nullptr;
	*/	
	}
	
	
}

void CBeginnerStore::ShowPosions(CPlayer* pPlayer)
{
}

void CBeginnerStore::BuyEquipments(CPlayer* pPlayer, int iGoodsNum)
{	
	if ( pPlayer->GetStatus()->m_iMaxInvenSize <= pPlayer->GetStatus()->m_vecInventory.size())
	{
		cout << "�κ��丮�� ����á���ϴ�. �κ��丮�� Ȯ���ϼ���." << endl;
	}

	if (pPlayer->GetStatus()->m_iGold >= m_pEquipments[iGoodsNum].GetPrice())
	{
		cout << iGoodsNum+1 << "�� ��ǰ�� �����߽��ϴ�." << endl;
		pPlayer->GetStatus()->m_iGold -= m_pEquipments[iGoodsNum].GetPrice();
		EQUIPMENT_STATUS E = *(m_pEquipments->GetEquipStat());
		pPlayer->GetStatus()->m_vecInventory.push_back(E);
		cout << "�ܱ�: " << pPlayer->GetStatus()->m_iGold << endl;
		system("pause");
	}
	else
	{
		cout << "���� �ݾ��� �����մϴ�." << endl;
		system("pause");
	}
}

void CBeginnerStore::BuyPosions(CPlayer* pPlayer, int iGoodsNum)
{
}
