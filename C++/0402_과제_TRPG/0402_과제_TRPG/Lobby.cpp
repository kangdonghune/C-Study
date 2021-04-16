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
		cout << "저장할 내용이 없습니다." << endl;
	}
	FILE* fp;
	errno_t err = fopen_s(&fp, "./Save.txt", "wb");
	
	if (!err)
	{
		cout << "저장 시작" << endl;
		fwrite(pPlayer->GetStatus(), sizeof(STATUS),1, fp);
		//가상함수를 가지고 있는 클래스의 경우 내부적으로 가상함수 포인터 또한 가지고 있다. 문제는 가상함수 포인터의 경우 실행 시마다 그 주소가 바뀔 수 있다는 점인데
		//클래스를 통째로 넘겨줄 시 해당 가상함수 포인터까지 넘길 수 있고 이걸 그대로 불러오면 실행 시 가상함수 포인터 주소 때문에 에러가 발생할 수 있다.
		cout << "저장 완료" << endl;
		fclose(fp);
	}
	else
	{
		cout << "저장 실패" << endl;
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
		cout << "1. 필드 가기.  2. 저장.   3. 불러오기. 4. 상점. 5. 게임 종료." << endl;
		int iLobbySelect = 0;
		int iFieldSelect = 0;
		int iStoreSelect = 0;
		cin >> iLobbySelect;
		switch (iLobbySelect)
		{
		case 1:
			cout << "1. 초보자 던전. 2. 중급 던전. 3. 상급 던전." << endl;
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
			cout << "1. 초보자 상점. 2. 중급자 상점. 3. 마스터 상점. 4. 돌아가기" << endl;
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
			cout << "입력 오류입니다. 재입력하세요." << endl;
			break;
		}
	}
}
