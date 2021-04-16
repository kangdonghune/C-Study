#include "stdafx.h"
#include "Field.h"
#include "Monster.h"
#include "Player.h"

CField::CField()
	:m_pPlayer(nullptr)
{
}


CField::~CField()
{
}

void CField::FieldUpdate()
{
	while (true)
	{

		C_Object* pMonster = nullptr; // 구태여 포인터 형식으로 만든 것은 넘겨줄 때도 편하기도 하고 C_Object* 형과도 맞춰주기 위해서?
		system("cls");
		m_pPlayer->ShowStatus();
		cout << "1. 초보자 던전.\t 2. 중급자 던전.\t 3. 고급자 던전.\t 4. 돌아가기" << endl;
		
		int iFieldSelect;
		cin >> iFieldSelect;

		switch (iFieldSelect)
		{
		case 1:
			pMonster = new CMonster;
			pMonster->ReadyGameObj("슬라임", 50, 15, 8, 5, 20, 10);
			pMonster->ShowStatus();
			break;
		case 2:
			pMonster = new CMonster;
			pMonster->ReadyGameObj("스켈레톤", 100, 30, 16, 10, 50, 30);
			pMonster->ShowStatus();
			break;
		case 3:
			pMonster = new CMonster;
			pMonster->ReadyGameObj("오크", 200, 60, 32, 20, 120, 100);
			pMonster->ShowStatus();
			break;
		case 4:
			dynamic_cast<CPlayer*>(m_pPlayer)->ReSetHP();
			return;
		default:
			continue;
		}
		Fight(m_pPlayer, pMonster);
		C_Static::deleteAllocation(pMonster); // 쌈 다 끝났으면 소멸해라.

	}
}

void CField::Fight(C_Object * pPlayer, C_Object * pMonster)
{
	while (true)
	{
		system("cls");
		pPlayer->ShowStatus();
		pMonster->ShowStatus();
		cout << "1. 싸운다. 2. 도망친다." << endl;
		int iFightSelect;
		cin >> iFightSelect;
		switch (iFightSelect)
		{
		case 1:
			pPlayer->SetDamege(pMonster);
			if (0 >= pMonster->GetStatus().iHP)
			{
				cout << "몬스터가 죽었습니다." << endl;
				pPlayer->SetStatus().iEXP += pMonster->GetStatus().iMAXEXP;
				pPlayer->SetStatus().iGold += pMonster->GetStatus().iGold;
				if (pPlayer->GetStatus().iEXP >= pPlayer->GetStatus().iMAXEXP)
				{
					dynamic_cast<CPlayer*>(pPlayer)->LevelUp();
				}
				system("pause");
				return;
			}
			pMonster->SetDamege(pPlayer);
			if (0 >= pPlayer->GetStatus().iHP)
			{
				cout << "플레이어가 죽었습니다." << endl;
				pPlayer->SetStatus().iEXP = 0;
				dynamic_cast<CPlayer*>(pPlayer)->ReSetHP();
				system("pause");
				return;
			}
			break;
		case 2:
			return;
		default:
			cout << "입력한 번호를 다시 확인하세요." << endl;
			break;
		}

	}
	
}

