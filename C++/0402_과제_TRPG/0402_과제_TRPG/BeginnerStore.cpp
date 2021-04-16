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
	cout << "1. 장비 보기.  2. 소모품 보기.  3. 상점 나가기." << endl;
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
			cout << "입력 오류. 다시 입력하세요." << endl;
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
		m_pEquipments = new CSword[iSize]; //EQUIP-STATUS 크기 만큼 힙에 할당
		BEGGINERSWORD T;
		m_pEquipments[0] = CSword(T);
		NORMALSWORD N;
		m_pEquipments[1] = CSword(N);
		MASTERSWORD M;
		m_pEquipments[2] = CSword(M);

		for (int i = 0; i < 3; i++)
		{
			cout << i + 1 << "번 상품" << endl;
			m_pEquipments[i].ShowInfo();
		}
		cout << "1. 구입.  2. 이전으로" << endl;
		int iSelect = 0;
		cin >> iSelect;
		switch (iSelect)
		{
		case 1:
			cout << "구매하고자 하는 아이템 번호를 입력하세요." << endl;
			while (true)
			{
				cin >> iItemNum;
				if (0 >= iItemNum || iSize < iItemNum)
				{
					cout << "구매하고자 하는 상품이 없습니다." << endl;
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
			cout << "입력 번호를 확인하세요" << endl;
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
		cout << "인벤토리가 가득찼습니다. 인벤토리를 확장하세요." << endl;
	}

	if (pPlayer->GetStatus()->m_iGold >= m_pEquipments[iGoodsNum].GetPrice())
	{
		cout << iGoodsNum+1 << "번 상품을 구매했습니다." << endl;
		pPlayer->GetStatus()->m_iGold -= m_pEquipments[iGoodsNum].GetPrice();
		EQUIPMENT_STATUS E = *(m_pEquipments->GetEquipStat());
		pPlayer->GetStatus()->m_vecInventory.push_back(E);
		cout << "잔금: " << pPlayer->GetStatus()->m_iGold << endl;
		system("pause");
	}
	else
	{
		cout << "가진 금액이 부족합니다." << endl;
		system("pause");
	}
}

void CBeginnerStore::BuyPosions(CPlayer* pPlayer, int iGoodsNum)
{
}
