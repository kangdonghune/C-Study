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
		CSlime tSlime;// ���� �����ϰų� ���͸� ��Ƽ� ���� ������ ��� �ݺ��� ������
		while (0 < tSlime.GetStatus()->m_iHP)
		{
			system("cls");
			pPlayer->ShowInfo();
			tSlime.ShowInfo();
			cout << "���Ϳ� �����߽��ϴ�. (1. �ο��. 2. ����ģ��)" << endl;
			int iSelect = 0;
			cin >> iSelect;
			switch (iSelect)
			{
			case 1:
				pPlayer->Attck(pPlayer, &tSlime); //�� �κ��� ����� �غ��� �� ��.
				if (0 < tSlime.GetStatus()->m_iHP) //���Ͱ� �� �׾�����
				{
					tSlime.Attck(&tSlime, pPlayer);
					if (0 >= pPlayer->GetStatus()->m_iHP)
					{
						pPlayer->GetStatus()->m_iEXP = 0;
						return;
					}
					break;
				}
				else //������
				{
					pPlayer->GetStatus()->m_iEXP += tSlime.GetStatus()->m_iEXP;
					pPlayer->GetStatus()->m_iGold += tSlime.GetStatus()->m_iGold;
					if (pPlayer->GetStatus()->m_iEXP >= pPlayer->GetStatus()->m_iMaxExp) // ����ġ�� �ִ뷮�� �����ϸ� ������
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
				cout << "�Է� ���� �Դϴ�. ���Է� �ٶ��ϴ�." << endl;
				continue;
			}
		}
	}
}
