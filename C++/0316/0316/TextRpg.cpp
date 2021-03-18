/*
TextRPG �����
���� �� �ؽ�Ʈ �������� ������ �߿���.
�ʳװ� ��� ���� �� �Ẹ��
����.
1. �÷��̾�� ü�°� �����̶� �����͸� ���´�.enum Occupation{ warrior, mage, thief } struct Player { Occupation int _hp, int _attak; }
2. ������ �����ϸ� �÷��̾��� ������ ����(����, ����, ����) �޴� ��� -> switch�� ��� ->���� ���� ���
3.�÷��̾ �����ϸ� �÷��̾��� ������ ��� �����ش�(�޴� �����̵� ������) system("cls")
4.�޴����� ������ ���� �ִ�.(��,��,��) ���� ���� �޴� ��� -> switch�� -> ���� �̵� ���
5.�� ���� �� ���̵��� ���� ���Ͱ� �����Ѵ� enum Tribe { Orc, Skelleton, Slime} struct Monster { Tribe, int _Hp, int _Attack }
6. ���̵��� ���� ������ ������ �ɷ�ġ�� �ٸ���. ���ʹ� �̸�, ���ݷ�, ü���� ���´�.
7.���������� �÷��̾� �����Ӹ� �ƴ϶� ���� ������ ���� ����Ѵ�. // ���� ���� �� �������� ���� ���.
//���ͷ��� �������� �ο�. ������ ���� �������ͽ� ���� �ο�.
8.������ ���� �޴����� ���ݰ� ������ �ִ�. //���� �� ���� ���� ���ȭ��. ���� �� ���� ����
9.������ �����ϸ� ���ʹ� �÷��̾� ���ݷ� ��ŭ, �÷��̾�� ���� ���� ��ŭ ü���� ��´�. ������ �÷��̾��.
10. ������ ü���� 0�̵Ǹ� ��� ���� ���� ������ ����ġ ���. ���� ����.
11.�÷��̾��� ü���� 0�̵Ǹ� ���� ���� �� �޴��� ���ư���. ü���� �ʱⰪ���� ���µǾ� �Ѵ�. ������ �״�� ����ġ�� ����. ������ ��ȥ
*/

#include <iostream>
#include <string>
#include <time.h>


enum class JOB
{
	Warrior = 1, // hp 200/ att 25  �������� ü�� +20 ���ݷ� +10
	Mage, // hp 100/ att 50 �������� ü�� +10 ���ݷ� +15
	Thief, // hp 130/ att 40 �������� ü�� +15 ���ݷ� + 12
	JobSize
};

enum class TRIBE
{
	Sliem = 1,
	Skelleton,
	Orc,
	TribeSize
};
struct WARRIOR { int Hp = 200; int Attack = 25; char JobName[255] = "����"; };
struct MAGE { int Hp = 100; int Attack = 50; char JobName[255] = "����"; };
struct THIEF { int Hp = 130; int Attack = 40; char JobName[255] = "����"; };
struct JOBSTATUS {WARRIOR WARRIOR; MAGE MAGE; THIEF THIEF;};

struct SLIME { int Hp = 50; int Attack = 10; int Experience = 15; char TribeName[255] = "������"; };
struct SKELLETON { int Hp = 100; int Attack = 50; int Experience = 30; char TribeName[255] = "�ذ񺴻�"; };
struct ORC { int Hp = 130; int Attack = 40; int Experience = 50; char TribeName[255] = "��ũ"; };
struct MONSTERSTATUS { SLIME SLIME; SKELLETON SKELLETON; ORC ORC; };


typedef struct // hp, att �� ������ ����ü�� ������ Player�� �� �Ѱ��ϴ� ����ü�� ����.
{
	JOB JOB;
	char JobName[255];
	int Hp;
	int Attack;
	char Name[255];
	int Level = 1; //1���� ����.
	int Experience = 0; //1���� 100. ������ 20�� ����.
	int MaxExperience = 100; //100���� ���� �������� 20����.
}PLAYER;

typedef struct
{
	TRIBE Tribe;
	char TribeName[255];
	int Hp;
	int Attack;
	int Level;
	int Experience;

}MONSTER; 

bool GameEnd = false;


void Attack(PLAYER* pPlayer, MONSTER* pMonster, int pRandomArr[]); //�÷��̾ ���� ����
void Attack(MONSTER* pMonster, PLAYER* pPlayer, int pRandomArr[]);//�÷��̾ ���� ����
void BegginnerDungeon(PLAYER* pPlayer, int pRandomArr[]); //���� Slime ����. ������ 1~5�� ��������. ������ ���ݷ� +2 ü�� +3  ����ġ +1
void LevelUp(PLAYER* pPlayer); //������ �� �� ȸ��. �������ͽ� ����.
void MakeRandomArr(int* ptrarr, int size); //������ ���� �迭 ����
void MakePlayer(PLAYER* pPlayer); //���� ���� ��°� ���� ����.
MONSTER MonsterPickUp(SLIME SlimeStatus, int pRandomArr[]); // ����(������) ����
void PrintMonsterStatus(MONSTER* pMonster); //���� �������ͽ� ���
void PrintPlayerStatus(PLAYER* pPlayer); //�÷��̾� �������ͽ� ���
void RebornPlayer(PLAYER* pPlayer); //������ ����ġ �ʱ�ȭ
void RecoverPlayer(PLAYER* pPlayer); //�������� �� ȸ��.
void TownSelect(PLAYER* pPlayer,int pRandomArr[]); // ���� ������

using namespace std;

/*���� �̱�����
1.����.

���� �������� ���͸� �� ������ ���̸� ������ ���ư��� �� ������ ���������� ���ᰡ ���� �ʴ´�.
*/

int main()
{
	PLAYER Player;
	int RandomArr[100];
	MakeRandomArr(RandomArr, size(RandomArr));
	MakePlayer(&Player);
	PrintPlayerStatus(&Player);
	while(!GameEnd)
	{
		TownSelect(&Player, RandomArr);
	}
	
}

void MakeRandomArr(int* ptrarr, int size) //Ƚ���� ũ�ٺ��� ���ۿ� �ɸ���. ���� �ۿ��� ������ ��ȯ������.
{
	srand(unsigned(time(NULL)));
	for (int i = 0; i < size; i++)
	{
		ptrarr[i] = i;
	}
	for (int i = 0; i < 10000; i++)
	{
			int Dest = rand() % size; 
			int Src = rand()%size;
			int temp = ptrarr[Dest];
			ptrarr[Dest] = ptrarr[Src];
			ptrarr[Src] = temp;
	}
}

void MakePlayer(PLAYER* pPlayer) //���� ���� ��°� ���� ����.
{
	cout << "�̸��� �Է��ϼ���: ";
	char Name[255];
	cin >> Name;
	cout << endl;
	strcpy_s(pPlayer->Name, Name);

	cout << "������ ���� �Ͻÿ�.(1. ���� 2. ���� 3. ����)" << endl;
	cout << endl;
	JOBSTATUS _JobStatus;
	int iSelect;
	cin >> iSelect;
	switch (iSelect)
	{
	case (int)JOB::Warrior:
		pPlayer->JOB = JOB::Warrior;
		pPlayer->Hp = _JobStatus.WARRIOR.Hp;
		pPlayer->Attack = _JobStatus.WARRIOR.Attack;
		strcpy_s(pPlayer->JobName, _JobStatus.WARRIOR.JobName);
		break;
	case (int)JOB::Mage:
		pPlayer->JOB = JOB::Mage;
		pPlayer->Hp = _JobStatus.MAGE.Hp;
		pPlayer->Attack = _JobStatus.MAGE.Attack;
		strcpy_s(pPlayer->JobName, _JobStatus.MAGE.JobName);
		break;
	case (int)JOB::Thief:
		pPlayer->JOB = JOB::Thief;
		pPlayer->Hp = _JobStatus.THIEF.Hp;
		pPlayer->Attack = _JobStatus.THIEF.Attack;
		strcpy_s(pPlayer->JobName, _JobStatus.THIEF.JobName);
		break;
	default:
		cout << "�߸��� �Է��Դϴ�. �ٽ� ����ּ���." << endl;
		cout << endl;
		MakePlayer(pPlayer);
		break;
	}
	system("cls");
}

void PrintPlayerStatus(PLAYER* pPlayer) //�÷��̾� �������ͽ� ���
{
	cout << "�̸�: " << pPlayer->Name << endl;
	cout << "����: " << pPlayer->JobName << endl;
	cout << "HP: " << pPlayer->Hp << endl;
	cout << "���ݷ�: " << pPlayer->Attack << endl;
	cout << "LV: " << pPlayer->Level << endl;
	cout << "���� ����ġ: " << (pPlayer->MaxExperience) - (pPlayer->Experience) << endl;
	cout << endl;
}

void PrintMonsterStatus(MONSTER* pMonster) //���� �������ͽ� ���
{
	cout << "����: " << pMonster->TribeName << endl;
	cout << "HP: " << pMonster->Hp << endl;
	cout << "���ݷ�: " << pMonster->Attack << endl;
	cout << "LV: " << pMonster->Level << endl;
	cout << "����ġ: " << pMonster->Experience << endl;
	cout << endl;
}

void TownSelect(PLAYER* pPlayer,int* pRandomArr)
{
	system("cls");
	RecoverPlayer(pPlayer);
	PrintPlayerStatus(pPlayer);
	cout << "1.�ʱ� ���� ����" << endl;
	cout << "2.�߱� ���� ����" << endl;
	cout << "3.��� ���� ����" << endl;
	cout << "4.���� ����" << endl;
	cout << "����: ";
	int _iSelect = 0;
	while (!GameEnd)
	{
		cin >> _iSelect;
		switch (_iSelect)
		{
		case 1:
			//�ʱ� ���� ���� �Լ�
			BegginnerDungeon(pPlayer, pRandomArr);
			break;
		case 2:
			//�߱� ���� ���� �Լ�
			break;
		case 3:
			//��� ���� ���� �Լ�.
			break;
		case 4:
			GameEnd = true;
			return;
		default:
			GameEnd = true;
			cout << "�Է� ����. ���Է� �ٶ�." << endl;
			continue;
		}
	}

}
//point�� null ���� �Ѱ����� �� ���� point�� �ϸ� ���� �������൵ �Լ��� ������ �� �� ���ư��� ������ ������ �ȵȴ�.
//�׷� ���� ���� �����ͷ� �Ű����� int** pt2 = &pt1 ������ �������� �ּҸ� �Ѱ��༭ �ش� �������� �ּҿ� ������ ���� �������ָ� ������ �ȴ�.
void BegginnerDungeon(PLAYER* pPlayer, int pRandomArr[]) //���� Slime ����. ������ 1~5�� ��������. ������ ���ݷ� +2 ü�� +3  ����ġ +1
{
	SLIME SlimeStatus;
	//���� �Ⱦ�
	MONSTER Slime = MonsterPickUp(SlimeStatus, pRandomArr);
	//���� ���� ���;
	//���� �Ǵ� ���� ����
	while (true)
	{
		system("cls");
		PrintPlayerStatus(pPlayer);
		PrintMonsterStatus(&Slime);
		int iFightOrRun = 0;
		cout << "1. ����.		2. ����" << endl;
		cin >> iFightOrRun;
		switch (iFightOrRun)
		{
		case 1:
			Attack(pPlayer, &Slime, pRandomArr);
			if (0 >= Slime.Hp)
			{
				cout << "���Ͱ� �׾����ϴ�." << endl;
				pPlayer->Experience += Slime.Experience;
				system("pause");
				Slime = MonsterPickUp(SlimeStatus, pRandomArr);
				break;
			}
			Attack(&Slime, pPlayer, pRandomArr);
			if (0 >= pPlayer->Hp)
			{
				cout << "�÷��̾ �׾����ϴ�." << endl;
				RebornPlayer(pPlayer);
				system("pause");
			}
			TownSelect(pPlayer, pRandomArr);
			break;

		case 2:
			Attack(&Slime, pPlayer, pRandomArr);
			if (0 >= pPlayer->Hp)
			{
				cout << "�÷��̾ �׾����ϴ�." << endl;
				RebornPlayer(pPlayer);
				system("pause");
			}
			TownSelect(pPlayer, pRandomArr);
			return;

		default:
			cout << "�Է� ����" << endl;
			system("pause");
			continue;
		}
	}
	
}

MONSTER MonsterPickUp(SLIME SlimeStatus, int pRandomArr[])
{
	MONSTER Slime;
	unsigned int RandNum = rand()%100;
	Slime.Tribe = TRIBE::Sliem;
	strcpy_s(Slime.TribeName,SlimeStatus.TribeName);
	Slime.Level = (pRandomArr[RandNum])/20;
	Slime.Hp = SlimeStatus.Hp + Slime.Level * 3;
	Slime.Attack = SlimeStatus.Attack + Slime.Level * 2;
	Slime.Experience = SlimeStatus.Experience + Slime.Level;
	return Slime;
}
void Attack(PLAYER* pPlayer, MONSTER* pMonster, int pRandomArr[]) //�÷��̾ ���� ����
{
	pMonster->Hp -= pPlayer->Attack;
	
	if ((pPlayer->MaxExperience - pPlayer->Experience) <= 0)
	{
		LevelUp(pPlayer);
	}

}
void Attack(MONSTER* pMonster, PLAYER* pPlayer, int pRandomArr[]) //���Ͱ� �÷��̾� ����
{
	pPlayer->Hp -= pMonster->Attack;
}

void RecoverPlayer(PLAYER* pPlayer) //�������� �� ȸ��.
{
	JOBSTATUS _JobStatus;
	switch ((int)pPlayer->JOB)
	{
	case (int)JOB::Warrior:
		pPlayer->JOB = JOB::Warrior;
		pPlayer->Hp = _JobStatus.WARRIOR.Hp + (pPlayer->Level * 20);
		pPlayer->Attack = _JobStatus.WARRIOR.Attack + (pPlayer->Level * 10);
		break;
	case (int)JOB::Mage:
		pPlayer->JOB = JOB::Mage;
		pPlayer->Hp = _JobStatus.MAGE.Hp + (pPlayer->Level * 10);
		pPlayer->Attack = _JobStatus.MAGE.Attack + (pPlayer->Level * 15);
		break;
	case (int)JOB::Thief:
		pPlayer->JOB = JOB::Thief;
		pPlayer->Hp = _JobStatus.THIEF.Hp + (pPlayer->Level * 15);
		pPlayer->Attack = _JobStatus.THIEF.Attack + (pPlayer->Level * 12);
		break;
	default:
		cout << "�÷��̾� JOB�� �̼����Ǿ� �ֽ��ϴ�." << endl;
		break;
	}
}

void RebornPlayer(PLAYER* pPlayer) //������ ����ġ �ʱ�ȭ
{
	JOBSTATUS _JobStatus;
	switch ((int)pPlayer->JOB)
	{
	case (int)JOB::Warrior:
		pPlayer->JOB = JOB::Warrior;
		pPlayer->Hp = _JobStatus.WARRIOR.Hp +(pPlayer->Level*20);
		pPlayer->Attack = _JobStatus.WARRIOR.Attack+(pPlayer->Level*10);
		pPlayer->Experience = 0;
		break;
	case (int)JOB::Mage:
		pPlayer->JOB = JOB::Mage;
		pPlayer->Hp = _JobStatus.MAGE.Hp + (pPlayer->Level * 10);
		pPlayer->Attack = _JobStatus.MAGE.Attack + (pPlayer->Level * 15);
		pPlayer->Experience = 0;
		break;
	case (int)JOB::Thief:
		pPlayer->JOB = JOB::Thief;
		pPlayer->Hp = _JobStatus.THIEF.Hp + (pPlayer->Level * 15);
		pPlayer->Attack = _JobStatus.THIEF.Attack + (pPlayer->Level * 12);
		pPlayer->Experience = 0;
		break;
	default:
		cout << "�÷��̾� JOB�� �̼����Ǿ� �ֽ��ϴ�." << endl;
		break;
	}
}

void LevelUp(PLAYER* pPlayer)
{
	pPlayer->Level++;
	pPlayer->Experience = 0;
	pPlayer->MaxExperience += 20;
	RecoverPlayer(pPlayer);
}