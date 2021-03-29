/*
TextRPG �����
���� �� �ؽ�Ʈ �������� ������ �߿���.
�ʳװ� ��� ���� �� �Ẹ��
����.
1.�÷��̾�� ü�°� �����̶� �����͸� ���´�.enum Occupation{ warrior, mage, thief } struct Player { Occupation int _hp, int _attak; }
2.������ �����ϸ� �÷��̾��� ������ ����(����, ����, ����) �޴� ��� -> switch�� ��� ->���� ���� ���
3.�÷��̾ �����ϸ� �÷��̾��� ������ ��� �����ش�(�޴� �����̵� ������) system("cls")
4.�޴����� ������ ���� �ִ�.(��,��,��) ���� ���� �޴� ��� -> switch�� -> ���� �̵� ���
5.�� ���� �� ���̵��� ���� ���Ͱ� �����Ѵ� enum Tribe { Orc, Skelleton, Slime} struct Monster { Tribe, int _Hp, int _Attack }
6.���̵��� ���� ������ ������ �ɷ�ġ�� �ٸ���. ���ʹ� �̸�, ���ݷ�, ü���� ���´�.
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
void MakePlayer(PLAYER* pPlayer); //���� ���� ��°� ���� ����.
void MakeRandomArr(int* ptrarr, int size); //������ ���� �迭 ����
MONSTER MonsterPickUp(SLIME SlimeStatus, int pRandomArr[]); // ����(������) ����
void NewPlayOrLoad(PLAYER* pPlayer); // ���� ó������ ���� �̾ �� �� ����.
void LevelUp(PLAYER* pPlayer); //������ �� �� ȸ��. �������ͽ� ����.
void Load(PLAYER* pPlayer); //�÷��̾� �������ͽ� �����ͼ� �����ϱ�.
void PlayGame(PLAYER* pPlayer);//���� ó������ ����
void PrintMonsterStatus(MONSTER* pMonster); //���� �������ͽ� ���
void PrintPlayerStatus(PLAYER* pPlayer); //�÷��̾� �������ͽ� ���
void RebornPlayer(PLAYER* pPlayer); //������ ����ġ �ʱ�ȭ
void RecoverPlayer(PLAYER* pPlayer); //�������� �� ȸ��.
void Save(PLAYER* pPlayer);//�÷��̾� �������ͽ� ����.
void TownSelect(PLAYER* pPlayer,int pRandomArr[]); // ���� ������

using namespace std;

/*���� �̱�����
1. �Ǵ��� save load ���� �� �� �� Ȯ���� ����.
2.����.

���� �������� ���͸� �� ������ ���̸� ������ ���ư��� �� ������ ���������� ���ᰡ ���� �ʴ´�.
*/

int main()
{
	PLAYER Player;
	NewPlayOrLoad(&Player);
}
void Attack(PLAYER* pPlayer, MONSTER* pMonster, int pRandomArr[]) //�÷��̾ ���� ����
{
	pMonster->Hp -= pPlayer->Attack;


}
void Attack(MONSTER* pMonster, PLAYER* pPlayer, int pRandomArr[]) //���Ͱ� �÷��̾� ����
{
	pPlayer->Hp -= pMonster->Attack;
}
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
				if ((pPlayer->MaxExperience - pPlayer->Experience) <= 0)
				{
					LevelUp(pPlayer);
				}
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
				TownSelect(pPlayer, pRandomArr);
			}
			
			break;

		case 2:
			Attack(&Slime, pPlayer, pRandomArr);
			if (0 >= pPlayer->Hp)
			{
				cout << "�÷��̾ �׾����ϴ�." << endl;
				RebornPlayer(pPlayer);
				system("pause");
				TownSelect(pPlayer, pRandomArr);
			}
			return;

		default:
			cout << "�Է� ����" << endl;
			system("pause");
			continue;
		}
	}

}
void MakePlayer(PLAYER* pPlayer) //���� ���� ��°� ���� ����.
{
	system("cls");
	cout << "�̸��� �Է��ϼ���: ";
	char Name[255];
	cin >> Name;
	cout << endl;
	strcpy_s(pPlayer->Name, Name);
	int iSelect;
	do
	{
		system("cls");
		cout << "������ ���� �Ͻÿ�.(1. ���� 2. ���� 3. ����)" << endl;
		cout << endl;
		JOBSTATUS _JobStatus;
		
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
			std::system("pause");
			continue;
		}
	} while (0 >= iSelect || 4 <= iSelect);
	system("cls");
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
		int Src = rand() % size;
		int temp = ptrarr[Dest];
		ptrarr[Dest] = ptrarr[Src];
		ptrarr[Src] = temp;
	}
}
MONSTER MonsterPickUp(SLIME SlimeStatus, int pRandomArr[])
{
	MONSTER Slime;
	unsigned int RandNum = rand() % 100;
	Slime.Tribe = TRIBE::Sliem;
	strcpy_s(Slime.TribeName, SlimeStatus.TribeName);
	Slime.Level = (pRandomArr[RandNum]) / 20;
	Slime.Hp = SlimeStatus.Hp + Slime.Level * 3;
	Slime.Attack = SlimeStatus.Attack + Slime.Level * 2;
	Slime.Experience = SlimeStatus.Experience + Slime.Level;
	return Slime;
}
void NewPlayOrLoad(PLAYER* pPlayer)
{
	std::system("cls");
	
	int iNPL_Select;
	do 
	{
		system("cls");
		cout << "1. �����ϱ�\t 2.�ҷ�����" << endl;
		cin >> iNPL_Select;
		switch (iNPL_Select)
		{
		case 1:
			cout << "������ ���� �����մϴ�." << endl;
			std::system("pause");
			MakePlayer(pPlayer);
			PlayGame(pPlayer);	
			break;
		case 2:
			//���Ͻý����� ���� ������ �� ���� �ҷ�����.
			cout << "������ �ҷ��ɴϴ�." << endl;
			std::system("pause");
			Load(pPlayer);
			PlayGame(pPlayer);
			break;
		default:
			cout << "�Է� ���� �Դϴ�." << endl;
			break;
		}
	} while (0 >= iNPL_Select || 2 <= iNPL_Select);
	
	system("cls");
}
void LevelUp(PLAYER* pPlayer)
{
	pPlayer->Level++;
	pPlayer->Experience = 0;
	pPlayer->MaxExperience += 20;
	RecoverPlayer(pPlayer);
}
void Load(PLAYER* pPlayer)
{
	FILE* fPlayerIntstatus = nullptr;
	FILE* fPlayerCharstatus = nullptr;
	errno_t err1 = fopen_s(&fPlayerIntstatus, "Save/SaveData(int).txt", "rt");
	errno_t err2 = fopen_s(&fPlayerCharstatus, "Save/SaveData(char).txt", "rt");

	//JOB JOB;
	//char JobName[255];
	//int Hp;
	//int Attack;
	//char Name[255];
	//int Level = 1; //1���� ����.
	//int Experience = 0; //1���� 100. ������ 20�� ����.
	//int MaxExperience = 100; //100���� ���� �������� 20����.

	fseek(fPlayerIntstatus, 0, SEEK_END);
	int	iSize = ftell(fPlayerIntstatus) / 4;
	int* iOut = new int[iSize];
	fseek(fPlayerIntstatus, 0, SEEK_SET);

	if (0 == err1)
	{
		std::cout << "����" << std::endl;
		fread(iOut, sizeof(iOut)*iSize, 1, fPlayerIntstatus);
		pPlayer->JOB = (JOB)iOut[0];
		pPlayer->Hp = iOut[1];
		pPlayer->Attack = iOut[2];
		pPlayer->Level = iOut[3];
		pPlayer->Experience = iOut[4];
		pPlayer->MaxExperience = iOut[5];
	}
	//fclose(fPlayerIntstatus); //���� ��δ� �ϳ� ��������  �� �ݾ��ָ� ������ �� �� ���� �� �ν��� �ȵȴ�"?

	fseek(fPlayerCharstatus, 0, SEEK_END); //�̰� �и� EOF�� ������ �������� ���������ڸ� �̵���Ų ���ٵ�
	int	ichSize = ftell(fPlayerCharstatus)+1;//�� ���������ڰ� ������ ������ ������ �ܾ���µ� �Ϻΰ� �߸���. fwrite�� null���� ���� �ִ´�. �ٵ� �װɷ� ����� ��� null���ڿ������� �ϳ� �����Ѵ�. �׷��� +1;
	char* chOut = new char[ichSize];  //null���� ������ ���� ����ũ�⺸�� 1������ ũ�� ������ �Ѵ�.
	fseek(fPlayerCharstatus, 0, SEEK_SET);
	JOBSTATUS Job;
	if (0 == err2) //�������� ���� ���ؼ� ������� �Ѵ�.
	{
		std::cout << "����" << std::endl;
		fgets(chOut, ichSize, fPlayerCharstatus);
		int iJobLength;
		switch ((int)pPlayer->JOB)
		{
		case (int)JOB::Warrior:
			iJobLength= strlen(Job.WARRIOR.JobName);
			for (int i = 0; i < iJobLength; i++)
			{
				pPlayer->JobName[i] = chOut[i];
			}
			pPlayer->JobName[iJobLength] = '\0';
			break;
		case (int)JOB::Mage:
			iJobLength = strlen(Job.MAGE.JobName);
			for (int i = 0; i < iJobLength; i++)
			{
				pPlayer->JobName[i] = chOut[i];
			}
			pPlayer->JobName[iJobLength] = '\0';
			break;
		case (int)JOB::Thief:
			iJobLength = strlen(Job.THIEF.JobName);
			for (int i = 0; i < iJobLength; i++)
			{
				pPlayer->JobName[i] = chOut[i];
			}
			pPlayer->JobName[iJobLength] = '\0';
			break;
		default:
			cout << "�ҷ����� JOB���� ����. �ڵ带 Ȯ���ϼ���." << endl;
			std::system("cls");
			return;
		}
		for (int i = iJobLength, j=0; i < ichSize; i++,j++)
		{
			pPlayer->Name[j] = chOut[i];
			if (chOut[i] == EOF)
			{
				pPlayer->Name[j] = '\0';
				break;
			}
			cout << (int)chOut[i] << endl;
		}


	}

	fclose(fPlayerIntstatus);
	fclose(fPlayerCharstatus);//


	delete[] chOut;
	delete[] iOut;
}
void PlayGame(PLAYER* pPlayer)
{
	int RandomArr[100];
	MakeRandomArr(RandomArr, size(RandomArr));
	PrintPlayerStatus(pPlayer);
	while (!GameEnd)
	{
		TownSelect(pPlayer, RandomArr);
	}
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
void RebornPlayer(PLAYER* pPlayer) //������ ����ġ �ʱ�ȭ
{
	JOBSTATUS _JobStatus;
	switch ((int)pPlayer->JOB)
	{
	case (int)JOB::Warrior:
		pPlayer->JOB = JOB::Warrior;
		pPlayer->Hp = _JobStatus.WARRIOR.Hp + (pPlayer->Level * 20);
		pPlayer->Attack = _JobStatus.WARRIOR.Attack + (pPlayer->Level * 10);
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
void Save(PLAYER * pPlayer) //������ �Ϸ�
{
	FILE* fPlayerIntstatus = nullptr;
	FILE* fPlayerCharstatus = nullptr;
	errno_t err1 = fopen_s(&fPlayerIntstatus, "Save/SaveData(int).txt", "wt");
	errno_t err2 = fopen_s(&fPlayerCharstatus, "Save/SaveData(char).txt", "wt");
	//JOB JOB;
	//char JobName[255];
	//int Hp;
	//int Attack;
	//char Name[255];
	//int Level = 1; //1���� ����.
	//int Experience = 0; //1���� 100. ������ 20�� ����.
	//int MaxExperience = 100; //100���� ���� �������� 20����.
	int iSpec[] = { (int)pPlayer->JOB, pPlayer->Hp, pPlayer->Attack, pPlayer->Level,pPlayer->Experience, pPlayer->MaxExperience };
	strcat_s(pPlayer->JobName, strlen(pPlayer->JobName) + strlen(pPlayer->Name) + 2, pPlayer->Name);
	int i = sizeof(iSpec);
	if (0 == err1)
	{
		cout << "int�� �ڷ��� ������ �Ϸ�Ǿ����ϴ�." << endl;
		fwrite(iSpec, sizeof(iSpec), 1,fPlayerIntstatus);//int�� �ڷ����� �ؽ�Ʈ�� ���� �Ϸ�. 
	
		//fputs("�׽�Ʈ", fPlayerstatus);
	}
	if (0 == err2)
	{
		cout << "char�� �ڷ��� ������ �Ϸ�Ǿ����ϴ�." << endl;
		fwrite(pPlayer->JobName, strlen(pPlayer->JobName), 1, fPlayerCharstatus);//char�� �ڷ����� �ؽ�Ʈ�� ���� �Ϸ�.
	}
	
	std::system("pause");
}
void TownSelect(PLAYER* pPlayer, int pRandomArr[])
{
	int _iSelect = 0;
	while (!GameEnd)
	{
		system("cls");
		RecoverPlayer(pPlayer);
		PrintPlayerStatus(pPlayer);
		cout << "1.�ʱ� ���� ����" << endl;
		cout << "2.�߱� ���� ����" << endl;
		cout << "3.��� ���� ����" << endl;
		cout << "4.���� ����" << endl;
		cout << "����: ";
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
			Save(pPlayer);
			//�̸�,����,ü��,���� ����ġ �� ���� �� ����.
			return;
		default:
			cout << "�Է� ����. ���Է� �ٶ�." << endl;
			continue;
		}
	}
	//point�� null ���� �Ѱ����� �� ���� point�� �ϸ� ���� �������൵ �Լ��� ������ �� �� ���ư��� ������ ������ �ȵȴ�.(�����͸� �����ͷ� ������ �����ϴ� ���� ptr�� ���ε� ���ּҿ� ���� �������ְ� �ּҸ� �������൵ �Լ��� ������ �����͸� �������� ���� ���� �ʱ�ȭ�ǰ� ������ ���� �״�� nullptr. �׷��� ���� �����ͷ� �������� ������ �ּҰ� ��ü�� ��ȭ�ش�.
	//�׷� ���� ���� �����ͷ� �Ű����� int** pt2 = &pt1 ������ �������� �ּҸ� �Ѱ��༭ �ش� �������� �ּҿ� ������ ���� �������ָ� ������ �ȴ�.
}

//���������͸� ����ұ� �ߴµ� �����ͺ��� nullptr�� �����쵵 ����ؾ��ϴ� �����������ʹ� ���������ͷ� ������غ���.





