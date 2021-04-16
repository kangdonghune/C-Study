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
	cout << "�Ҵ����� �Ϸ�" << endl;
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
		cout << "1. �ʵ� ����.\t 2. ���� ����.\t 3. �κ��丮.\t 4. ����. \t 5. �ҷ�����\t 6. ��������" << endl;
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
			cout << "��ȣ�� Ȯ���ϼ���." << endl;
			system("pause");
			break;
		}

	}
}

void CMain::SelectNeworLoad()
{
	cout << "1. �����ϱ�. 2. �̾��ϱ�" << endl;
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
		cout << "�Է� ����" << endl;
		break;
	}
}

void CMain::SelectClass()
{
	while (true)
	{
		system("cls");
		cout << "������ ���� �����մϴ�." << endl;
		cout << "1. ����.\t 2. ����.\t 3. ����." << endl;
		int iClassSelect;
		char szName[32];
		cin >> iClassSelect;
		switch (iClassSelect)
		{
		case 1:
			m_pPlayer->ReadyGameObj("����", 100, 20, 10);
			system("cls");
			cout << "�̸��� �Է��ϼ���." << endl;
			cin >> szName;
			strcpy_s(m_pPlayer->SetStatus().szName, szName);
			return;
		case 2:
			m_pPlayer->ReadyGameObj("����", 50, 40, 5);
			system("cls");
			cout << "�̸��� �Է��ϼ���." << endl;
			cin >> szName;
			strcpy_s(m_pPlayer->SetStatus().szName, szName);
			return;
		case 3:
			m_pPlayer->ReadyGameObj("����", 80, 25, 8);
			system("cls");
			cout << "�̸��� �Է��ϼ���." << endl;

			cin >> szName;
			strcpy_s(m_pPlayer->SetStatus().szName, szName);
			return;

		default:
			cout << "��ȣ�� Ȯ���ϼ���" << endl;
			system("pause");
			break;
		}
	}
}

void CMain::Save()
{
	if (m_pPlayer == nullptr)
	{
		cout << "������ ������ �����ϴ�." << endl;
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
		cout << "���� ����" << endl;
		fwrite(&(m_pPlayer->GetStatus()), sizeof(STATUS), 1, fp);
		fwrite(&temp, sizeof(STATUS), m_pPlayer->GetStatus().iInvenSize, fp);
		cout << "���� �Ϸ�" << endl;
		system("pause");
		fclose(fp);
	}
	else
	{
		cout << "���� ����" << endl;
	}
}

void CMain::Load(C_Object ** ppPlayer)
{
	if (m_pPlayer == nullptr)
	{
		cout << "�ʱ�ȭ ��." << endl;
		if (!dynamic_cast<CPlayer*>(*ppPlayer)->GetInventory().empty())
		{
			cout << "�κ��丮 ����" << endl;
			dynamic_cast<CPlayer*>(*ppPlayer)->SetInventory().swap(vector<STATUS>());//�÷��̾� �Ҹ� �� �Ҵ�� ���� ����.
		}
		delete *ppPlayer;
	}

	STATUS temp[100]{};

	FILE* fp;
	errno_t err = fopen_s(&fp, "./Save.txt", "rb");

	if (!err)
	{
		cout << "�ҷ����� ����" << endl;
		fread(&((*ppPlayer)->SetStatus()), sizeof(STATUS), 1, fp);
		fread(&temp, sizeof(STATUS), (*ppPlayer)->GetStatus().iInvenSize, fp);
		fclose(fp);
		for (int i = 0; i < m_pPlayer->GetStatus().iInvenSize; i++)
		{
			dynamic_cast<CPlayer*>(m_pPlayer)->SetInventory().push_back(temp[i]);
		}
		cout << "�ҷ����� �Ϸ�" << endl;
	}
	else
	{
		cout << "�ҷ����� ����" << endl;
		system("pause");
	}
}




