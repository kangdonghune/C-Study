#include "stdafx.h"
#include "MainGame.h"
#include "Player.h"
#include "Wariior.h"
#include "Mage.h"
#include "Thief.h"
#include "Lobby.h"
CMainGame::CMainGame()
	:m_pPlayer(nullptr)
{
	
}


CMainGame::~CMainGame()
{
	if (m_pPlayer != nullptr)
	{
		delete m_pPlayer;
		m_pPlayer = nullptr;
	}
}

void CMainGame::NewStart()
{
	m_pPlayer = nullptr;
	cout << "1. �����ϱ�. 2. �̾��ϱ�." << endl;
	int GameSelect;
	cin >> GameSelect;
	switch (GameSelect)
	{
	case 1:
		break;
	case 2:
		Load(&m_pPlayer);
		
		return;

	default:
		cout << "�Է� ����" << endl;
		break;
	}
	cout << endl;
	cout << "������ �����ϼ���. (1.���� 2.���� 3.����)";
	CWariior tWarrior;
	CMage tMage;
	CThief tThief;
	int iClassSelect = 0;
	cin >> iClassSelect;
	cout << endl;
	while (m_pPlayer == nullptr )
	{
		switch (iClassSelect)
		{
		case 1:
			m_pPlayer = &tWarrior;
			break;
		case 2:
			m_pPlayer = &tMage;
			break;
		case 3:
			m_pPlayer = &tThief;
			break;
		default:
			cout << "�Է��� �߸��Ǿ����ϴ�. �ٽ� �Է��ϼ���." << endl;
			continue;
		}
	}
	cout << "�̸��� �Է��ϼ���: ";
	char szPlayerName[32];
	cin >> szPlayerName;
	strcpy_s(m_pPlayer->GetStatus()->m_szName, szPlayerName);
	CLobby tLobby;
	tLobby.LobbyPlay(m_pPlayer);
	
}

void CMainGame::Load(CPlayer** ppPlayer)
{
	if (*ppPlayer != nullptr)
	{
		cout << "�ʱ�ȭ ���� ��" << endl;
		std::system("pause");
		delete *ppPlayer;
		*ppPlayer = nullptr;
	} //�ҷ��� �� �÷��� nullptr�� �ƴϸ� �ʱ�ȭ.

	*ppPlayer = new CPlayer;
	FILE* fp;
	errno_t err = fopen_s(&fp, "./Save.txt", "rb");

	if (!err)
	{
		cout << "�ҷ����� ����" << endl;
		fread((*ppPlayer)->GetStatus(), sizeof(STATUS), 1, fp);
		fclose(fp);
		cout << "�ҷ����� �Ϸ�" << endl;
		CLobby tLobby;
		tLobby.LobbyPlay(*ppPlayer);
		system("pause");
	}
	else
	{
		cout << "�ҷ����� ����" << endl;
	}
}

