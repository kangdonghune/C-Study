#include "stdafx.h"
#include "Lobby.h"
#include "Player.h"
#include "Field.h"
#include "Easy.h"
#include "BeginnerStore.h"
CLobby::CLobby()
{
	
}


CLobby::~CLobby()
{
}

void CLobby::Save(CPlayer* pPlayer)
{
	if (pPlayer == nullptr)
	{
		cout << "������ ������ �����ϴ�." << endl;
	}
	FILE* fp;
	errno_t err = fopen_s(&fp, "./Save.txt", "wb");
	
	if (!err)
	{
		cout << "���� ����" << endl;
		fwrite(pPlayer->GetStatus(), sizeof(STATUS),1, fp);
		//�����Լ��� ������ �ִ� Ŭ������ ��� ���������� �����Լ� ������ ���� ������ �ִ�. ������ �����Լ� �������� ��� ���� �ø��� �� �ּҰ� �ٲ� �� �ִٴ� ���ε�
		//Ŭ������ ��°�� �Ѱ��� �� �ش� �����Լ� �����ͱ��� �ѱ� �� �ְ� �̰� �״�� �ҷ����� ���� �� �����Լ� ������ �ּ� ������ ������ �߻��� �� �ִ�.
		cout << "���� �Ϸ�" << endl;
		fclose(fp);
	}
	else
	{
		cout << "���� ����" << endl;
	}
}

void CLobby::LobbyPlay(CPlayer * pPlayer)
{
	while (true)
	{
		system("cls");
		pPlayer->ShowInfo();
		CEasy tEasy;
		CBeginnerStore tBeginStore;
		cout << "1. �ʵ� ����.  2. ����.   3. �ҷ�����. 4. ����. 5. ���� ����." << endl;
		int iLobbySelect = 0;
		int iFieldSelect = 0;
		int iStoreSelect = 0;
		cin >> iLobbySelect;
		switch (iLobbySelect)
		{
		case 1:
			cout << "1. �ʺ��� ����. 2. �߱� ����. 3. ��� ����." << endl;
			cin >> iFieldSelect;
			switch (iFieldSelect)
			{
			case 1:
				tEasy.Start(pPlayer);
				break;
			case 2:
				break;
			case 3:
				break;
			default:
				break;
			}
			break;
		case 2:
			CLobby::Save(pPlayer);
			break;
		case 3:
			break;
		case 4:
			system("cls");
			cout << "1. �ʺ��� ����. 2. �߱��� ����. 3. ������ ����. 4. ���ư���" << endl;
			cin >> iStoreSelect;
			switch (iStoreSelect)
			{
			case 1:
				tBeginStore.ShowEquipments(pPlayer);
				break;
			default:
				break;
			}
			break;
		case 5:
			return;
		default:
			cout << "�Է� �����Դϴ�. ���Է��ϼ���." << endl;
			break;
		}
	}
}
