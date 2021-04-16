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

		C_Object* pMonster = nullptr; // ���¿� ������ �������� ���� ���� �Ѱ��� ���� ���ϱ⵵ �ϰ� C_Object* ������ �����ֱ� ���ؼ�?
		system("cls");
		m_pPlayer->ShowStatus();
		cout << "1. �ʺ��� ����.\t 2. �߱��� ����.\t 3. ����� ����.\t 4. ���ư���" << endl;
		
		int iFieldSelect;
		cin >> iFieldSelect;

		switch (iFieldSelect)
		{
		case 1:
			pMonster = new CMonster;
			pMonster->ReadyGameObj("������", 50, 15, 8, 5, 20, 10);
			pMonster->ShowStatus();
			break;
		case 2:
			pMonster = new CMonster;
			pMonster->ReadyGameObj("���̷���", 100, 30, 16, 10, 50, 30);
			pMonster->ShowStatus();
			break;
		case 3:
			pMonster = new CMonster;
			pMonster->ReadyGameObj("��ũ", 200, 60, 32, 20, 120, 100);
			pMonster->ShowStatus();
			break;
		case 4:
			dynamic_cast<CPlayer*>(m_pPlayer)->ReSetHP();
			return;
		default:
			continue;
		}
		Fight(m_pPlayer, pMonster);
		C_Static::deleteAllocation(pMonster); // �� �� �������� �Ҹ��ض�.

	}
}

void CField::Fight(C_Object * pPlayer, C_Object * pMonster)
{
	while (true)
	{
		system("cls");
		pPlayer->ShowStatus();
		pMonster->ShowStatus();
		cout << "1. �ο��. 2. ����ģ��." << endl;
		int iFightSelect;
		cin >> iFightSelect;
		switch (iFightSelect)
		{
		case 1:
			pPlayer->SetDamege(pMonster);
			if (0 >= pMonster->GetStatus().iHP)
			{
				cout << "���Ͱ� �׾����ϴ�." << endl;
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
				cout << "�÷��̾ �׾����ϴ�." << endl;
				pPlayer->SetStatus().iEXP = 0;
				dynamic_cast<CPlayer*>(pPlayer)->ReSetHP();
				system("pause");
				return;
			}
			break;
		case 2:
			return;
		default:
			cout << "�Է��� ��ȣ�� �ٽ� Ȯ���ϼ���." << endl;
			break;
		}

	}
	
}

