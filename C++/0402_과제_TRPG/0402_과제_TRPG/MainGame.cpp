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
	cout << "1. 새로하기. 2. 이어하기." << endl;
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
		cout << "입력 오류" << endl;
		break;
	}
	cout << endl;
	cout << "직업을 결정하세요. (1.전사 2.법사 3.도적)";
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
			cout << "입력이 잘못되었습니다. 다시 입력하세요." << endl;
			continue;
		}
	}
	cout << "이름을 입력하세요: ";
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
		cout << "초기화 진행 중" << endl;
		std::system("pause");
		delete *ppPlayer;
		*ppPlayer = nullptr;
	} //불러올 때 플레어어가 nullptr이 아니면 초기화.

	*ppPlayer = new CPlayer;
	FILE* fp;
	errno_t err = fopen_s(&fp, "./Save.txt", "rb");

	if (!err)
	{
		cout << "불러오기 실행" << endl;
		fread((*ppPlayer)->GetStatus(), sizeof(STATUS), 1, fp);
		fclose(fp);
		cout << "불러오기 완료" << endl;
		CLobby tLobby;
		tLobby.LobbyPlay(*ppPlayer);
		system("pause");
	}
	else
	{
		cout << "불러오기 실패" << endl;
	}
}

