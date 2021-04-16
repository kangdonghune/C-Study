#include "stdafx.h"
#include "Main.h"
#include "Player.h"
#include "Field.h"
#include "Shop.h"
#include "Inventory.h"

CMain::CMain()
	:m_pPlayer(nullptr)
	,m_pField(nullptr)
	,m_pShop(nullptr)
	,m_pInventory(nullptr)
{
}


CMain::~CMain()
{
	dynamic_cast<CPlayer*>(m_pPlayer)->~CPlayer();
	C_Static::deleteAllocation(m_pPlayer);
	C_Static::deleteAllocation(m_pField);
	C_Static::deleteAllocation(m_pShop);
	C_Static::deleteAllocation(m_pInventory);
	cout << "할당해제 완료" << endl;
}

void CMain::ReadyMain()
{
	if (m_pPlayer == nullptr)
	{
		m_pPlayer = new CPlayer;
		SelectNeworLoad();
	}
	m_pField = new CField;
	m_pField->SetPlayer(m_pPlayer);
	m_pShop = new CShop;
	m_pShop->SetPlayer(m_pPlayer);
	m_pInventory = new CInventory;
	m_pInventory->SetPlayer(m_pPlayer);

}

void CMain::UpdateMain()
{
	while (true)
	{
		system("cls");
		m_pPlayer->ShowStatus();
		cout << "1. 필드 가기.\t 2. 상점 가기.\t 3. 인벤토리.\t 4. 저장. \t 5. 불러오기\t 6. 게임종료" << endl;
		int iMainSelect;
		cin >> iMainSelect;
		switch (iMainSelect)
		{
		case 1:
			m_pField->FieldUpdate();
			break;
		case 2:
			m_pShop->ShopUpdate();
			break;
		case 3:
			m_pInventory->InventoryUpdate();
			break;
		case 4:
			Save();
			break;
		case 5:
			Load(&m_pPlayer);
			break;
		case 6:
			return;
		default:
			cout << "번호를 확인하세요." << endl;
			system("pause");
			break;
		}

	}
}

void CMain::SelectNeworLoad()
{
	cout << "1. 새로하기. 2. 이어하기" << endl;
	int iSelect;
	cin >> iSelect;
	switch (iSelect)
	{
	case 1:
		SelectClass();
		break;
	case 2:
		Load(&m_pPlayer);
		break;
	default:
		cout << "입력 오류" << endl;
		break;
	}
}

void CMain::SelectClass()
{
	while (true)
	{
		system("cls");
		cout << "게임을 새로 시작합니다." << endl;
		cout << "1. 전사.\t 2. 법사.\t 3. 도적." << endl;
		int iClassSelect;
		char szName[32];
		cin >> iClassSelect;
		switch (iClassSelect)
		{
		case 1:
			m_pPlayer->ReadyGameObj("전사", 100, 20, 10);
			system("cls");
			cout << "이름을 입력하세요." << endl;
			cin >> szName;
			strcpy_s(m_pPlayer->SetStatus().szName, szName);
			return;
		case 2:
			m_pPlayer->ReadyGameObj("법사", 50, 40, 5);
			system("cls");
			cout << "이름을 입력하세요." << endl;
			cin >> szName;
			strcpy_s(m_pPlayer->SetStatus().szName, szName);
			return;
		case 3:
			m_pPlayer->ReadyGameObj("도적", 80, 25, 8);
			system("cls");
			cout << "이름을 입력하세요." << endl;

			cin >> szName;
			strcpy_s(m_pPlayer->SetStatus().szName, szName);
			return;

		default:
			cout << "번호를 확인하세요" << endl;
			system("pause");
			break;
		}
	}
}

void CMain::Save()
{
	if (m_pPlayer == nullptr)
	{
		cout << "저장할 내용이 없습니다." << endl;
	}
	FILE* fp;
	errno_t err = fopen_s(&fp, "./Save.txt", "wb");
	STATUS temp[100]{};
	for (int i = 0; i < m_pPlayer->GetStatus().iInvenSize; i++)
	{
		temp[i] = dynamic_cast<CPlayer*>(m_pPlayer)->GetInventory()[i];
	}

	if (!err)
	{
		cout << "저장 시작" << endl;
		fwrite(&(m_pPlayer->GetStatus()), sizeof(STATUS), 1, fp);
		fwrite(&temp, sizeof(STATUS), m_pPlayer->GetStatus().iInvenSize, fp);
		cout << "저장 완료" << endl;
		system("pause");
		fclose(fp);
	}
	else
	{
		cout << "저장 실패" << endl;
	}
}

void CMain::Load(C_Object ** ppPlayer)
{
	if (m_pPlayer == nullptr)
	{
		cout << "초기화 중." << endl;
		if (!dynamic_cast<CPlayer*>(*ppPlayer)->GetInventory().empty())
		{
			cout << "인벤토리 제거" << endl;
			dynamic_cast<CPlayer*>(*ppPlayer)->SetInventory().swap(vector<STATUS>());//플레이어 소멸 시 할당된 벡터 제거.
		}
		delete *ppPlayer;
	}

	STATUS temp[100]{};

	FILE* fp;
	errno_t err = fopen_s(&fp, "./Save.txt", "rb");

	if (!err)
	{
		cout << "불러오기 실행" << endl;
		fread(&((*ppPlayer)->SetStatus()), sizeof(STATUS), 1, fp);
		fread(&temp, sizeof(STATUS), (*ppPlayer)->GetStatus().iInvenSize, fp);
		fclose(fp);
		for (int i = 0; i < m_pPlayer->GetStatus().iInvenSize; i++)
		{
			dynamic_cast<CPlayer*>(m_pPlayer)->SetInventory().push_back(temp[i]);
		}
		cout << "불러오기 완료" << endl;
	}
	else
	{
		cout << "불러오기 실패" << endl;
		system("pause");
	}
}




