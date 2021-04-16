#include "stdafx.h"
#include "Easy.h"
#include "Player.h"
#include "Slime.h"

CEasy::CEasy()
{
		
}


CEasy::~CEasy()
{
}

void CEasy::Start(CPlayer* pPlayer)
{
	while (true)
	{
		CSlime tSlime;// 새로 입장하거나 몬스터를 잡아서 새로 생성될 경우 반복문 돌리기
		while (0 < tSlime.GetStatus()->m_iHP)
		{
			system("cls");
			pPlayer->ShowInfo();
			tSlime.ShowInfo();
			cout << "몬스터와 마주했습니다. (1. 싸운다. 2. 도망친다)" << endl;
			int iSelect = 0;
			cin >> iSelect;
			switch (iSelect)
			{
			case 1:
				pPlayer->Attck(pPlayer, &tSlime); //이 부분은 고민을 해봐야 할 듯.
				if (0 < tSlime.GetStatus()->m_iHP) //몬스터가 안 죽었으면
				{
					tSlime.Attck(&tSlime, pPlayer);
					if (0 >= pPlayer->GetStatus()->m_iHP)
					{
						pPlayer->GetStatus()->m_iEXP = 0;
						return;
					}
					break;
				}
				else //죽으면
				{
					pPlayer->GetStatus()->m_iEXP += tSlime.GetStatus()->m_iEXP;
					pPlayer->GetStatus()->m_iGold += tSlime.GetStatus()->m_iGold;
					if (pPlayer->GetStatus()->m_iEXP >= pPlayer->GetStatus()->m_iMaxExp) // 경험치가 최대량을 돌파하면 레벨업
					{
						pPlayer->LeverUp();
					}
					break;
				}

				break;
			case 2:
				tSlime.Attck(&tSlime, pPlayer);
				if (0 >= pPlayer->GetStatus()->m_iHP)
					pPlayer->GetStatus()->m_iEXP = 0;
				pPlayer->GetStatus()->m_iHP = 50;
				return;
			default:
				cout << "입력 오류 입니다. 재입력 바랍니다." << endl;
				continue;
			}
		}
	}
}
