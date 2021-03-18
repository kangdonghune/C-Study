/*
TextRPG 만들기
이제 이 텍스트 알피지가 굉장히 중요함.
너네가 배운 문법 다 써보셈
조건.
1. 플레이어는 체력과 공격이란 데이터를 갖는다.enum Occupation{ warrior, mage, thief } struct Player { Occupation int _hp, int _attak; }
2. 게임을 시작하면 플레이어의 직업을 고른다(전사, 법사, 도적) 메뉴 출력 -> switch문 사용 ->선택 직업 출력
3.플레이어를 생성하면 플레이어의 정보는 상시 보여준다(메뉴 선택이든 전투든) system("cls")
4.메뉴에서 던전을 고를수 있다.(초,중,고) 던전 선택 메뉴 출력 -> switch문 -> 던전 이동 출력
5.각 던전 별 난이도에 따라 몬스터가 등장한다 enum Tribe { Orc, Skelleton, Slime} struct Monster { Tribe, int _Hp, int _Attack }
6. 난이도에 따라 몬스터의 종류와 능력치는 다르다. 몬스터는 이름, 공격력, 체력을 갖는다.
7.던전에서는 플레이어 정보뿐만 아니라 몬스터 정보도 같이 출력한다. // 던전 입장 시 랜덤으로 몬스터 대면.
//몬스터레벨 랜덤으로 부여. 레벨에 따른 스테이터스 차이 부여.
8.던전에 들어가면 메뉴에는 공격과 도망이 있다. //도망 시 던전 선택 출력화면. 공격 시 전투 시작
9.공격을 선택하면 몬스터는 플레이어 공격력 만큼, 플레이어는 몬스터 공격 만큼 체력을 깎는다. 선턴은 플레이어에게.
10. 몬스터의 체력이 0이되면 사냥 성공 몬스터 죽으면 경험치 뱉기. 레벨 제도.
11.플레이어의 체력이 0이되면 게임 오버 후 메뉴로 돌아간다. 체력은 초기값으로 리셋되야 한다. 레벨은 그대로 경험치는 제로. 마을로 귀혼
*/

#include <iostream>
#include <string>
#include <time.h>


enum class JOB
{
	Warrior = 1, // hp 200/ att 25  레벨업당 체력 +20 공격력 +10
	Mage, // hp 100/ att 50 레벨업당 체력 +10 공격력 +15
	Thief, // hp 130/ att 40 레벨업당 체력 +15 공격력 + 12
	JobSize
};

enum class TRIBE
{
	Sliem = 1,
	Skelleton,
	Orc,
	TribeSize
};
struct WARRIOR { int Hp = 200; int Attack = 25; char JobName[255] = "전사"; };
struct MAGE { int Hp = 100; int Attack = 50; char JobName[255] = "법사"; };
struct THIEF { int Hp = 130; int Attack = 40; char JobName[255] = "도적"; };
struct JOBSTATUS {WARRIOR WARRIOR; MAGE MAGE; THIEF THIEF;};

struct SLIME { int Hp = 50; int Attack = 10; int Experience = 15; char TribeName[255] = "슬라임"; };
struct SKELLETON { int Hp = 100; int Attack = 50; int Experience = 30; char TribeName[255] = "해골병사"; };
struct ORC { int Hp = 130; int Attack = 40; int Experience = 50; char TribeName[255] = "오크"; };
struct MONSTERSTATUS { SLIME SLIME; SKELLETON SKELLETON; ORC ORC; };


typedef struct // hp, att 은 별도의 구조체가 가지고 Player는 그 총괄하는 구조체를 습득.
{
	JOB JOB;
	char JobName[255];
	int Hp;
	int Attack;
	char Name[255];
	int Level = 1; //1레벨 시작.
	int Experience = 0; //1레벨 100. 레벨당 20씩 증가.
	int MaxExperience = 100; //100으로 시작 레벨업당 20증가.
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


void Attack(PLAYER* pPlayer, MONSTER* pMonster, int pRandomArr[]); //플레이어가 몬스터 공격
void Attack(MONSTER* pMonster, PLAYER* pPlayer, int pRandomArr[]);//플레이어가 몬스터 공격
void BegginnerDungeon(PLAYER* pPlayer, int pRandomArr[]); //던전 Slime 출현. 레벨이 1~5로 랜덤출현. 레벨당 공격력 +2 체력 +3  경험치 +1
void LevelUp(PLAYER* pPlayer); //레벨업 시 피 회복. 스테이터스 상향.
void MakeRandomArr(int* ptrarr, int size); //무작위 난수 배열 생성
void MakePlayer(PLAYER* pPlayer); //직업 종류 출력과 직업 선택.
MONSTER MonsterPickUp(SLIME SlimeStatus, int pRandomArr[]); // 몬스터(슬라임) 생성
void PrintMonsterStatus(MONSTER* pMonster); //몬스터 스테이터스 출력
void PrintPlayerStatus(PLAYER* pPlayer); //플레이어 스테이터스 출력
void RebornPlayer(PLAYER* pPlayer); //죽으면 경험치 초기화
void RecoverPlayer(PLAYER* pPlayer); //마을가면 피 회복.
void TownSelect(PLAYER* pPlayer,int pRandomArr[]); // 마을 선택지

using namespace std;

/*현재 미구현점
1.보스.

현재 문제점은 몬스터를 한 마리라도 죽이면 마을로 돌아갔을 때 게임이 정상적으로 종료가 되지 않는다.
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

void MakeRandomArr(int* ptrarr, int size) //횟수가 크다보니 버퍼에 걸린다. 메인 밖에서 돌리고 반환해주자.
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

void MakePlayer(PLAYER* pPlayer) //직업 종류 출력과 직업 선택.
{
	cout << "이름을 입력하세요: ";
	char Name[255];
	cin >> Name;
	cout << endl;
	strcpy_s(pPlayer->Name, Name);

	cout << "직업을 선택 하시오.(1. 전사 2. 법사 3. 도적)" << endl;
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
		cout << "잘못된 입력입니다. 다시 골라주세요." << endl;
		cout << endl;
		MakePlayer(pPlayer);
		break;
	}
	system("cls");
}

void PrintPlayerStatus(PLAYER* pPlayer) //플레이어 스테이터스 출력
{
	cout << "이름: " << pPlayer->Name << endl;
	cout << "직업: " << pPlayer->JobName << endl;
	cout << "HP: " << pPlayer->Hp << endl;
	cout << "공격력: " << pPlayer->Attack << endl;
	cout << "LV: " << pPlayer->Level << endl;
	cout << "남은 경험치: " << (pPlayer->MaxExperience) - (pPlayer->Experience) << endl;
	cout << endl;
}

void PrintMonsterStatus(MONSTER* pMonster) //몬스터 스테이터스 출력
{
	cout << "종족: " << pMonster->TribeName << endl;
	cout << "HP: " << pMonster->Hp << endl;
	cout << "공격력: " << pMonster->Attack << endl;
	cout << "LV: " << pMonster->Level << endl;
	cout << "경험치: " << pMonster->Experience << endl;
	cout << endl;
}

void TownSelect(PLAYER* pPlayer,int* pRandomArr)
{
	system("cls");
	RecoverPlayer(pPlayer);
	PrintPlayerStatus(pPlayer);
	cout << "1.초급 던전 가기" << endl;
	cout << "2.중급 던전 가기" << endl;
	cout << "3.고급 던전 가기" << endl;
	cout << "4.게임 종료" << endl;
	cout << "선택: ";
	int _iSelect = 0;
	while (!GameEnd)
	{
		cin >> _iSelect;
		switch (_iSelect)
		{
		case 1:
			//초급 던전 입장 함수
			BegginnerDungeon(pPlayer, pRandomArr);
			break;
		case 2:
			//중급 던전 입장 함수
			break;
		case 3:
			//고급 던전 입장 함수.
			break;
		case 4:
			GameEnd = true;
			return;
		default:
			GameEnd = true;
			cout << "입력 오류. 재입력 바람." << endl;
			continue;
		}
	}

}
//point로 null 값을 넘겨줬을 때 받은 point가 암만 값을 수정해줘도 함수가 끝나면 싹 다 날아가서 변경이 저장이 안된다.
//그럴 떄는 더블 포인터로 매개변수 int** pt2 = &pt1 식으로 포인터의 주소를 넘겨줘서 해당 포인터의 주소에 접근해 값을 변경해주면 적용이 된다.
void BegginnerDungeon(PLAYER* pPlayer, int pRandomArr[]) //던전 Slime 출현. 레벨이 1~5로 랜덤출현. 레벨당 공격력 +2 체력 +3  경험치 +1
{
	SLIME SlimeStatus;
	//몬스터 픽업
	MONSTER Slime = MonsterPickUp(SlimeStatus, pRandomArr);
	//몬스터 정보 출력;
	//전투 또는 도주 선택
	while (true)
	{
		system("cls");
		PrintPlayerStatus(pPlayer);
		PrintMonsterStatus(&Slime);
		int iFightOrRun = 0;
		cout << "1. 전투.		2. 도주" << endl;
		cin >> iFightOrRun;
		switch (iFightOrRun)
		{
		case 1:
			Attack(pPlayer, &Slime, pRandomArr);
			if (0 >= Slime.Hp)
			{
				cout << "몬스터가 죽었습니다." << endl;
				pPlayer->Experience += Slime.Experience;
				system("pause");
				Slime = MonsterPickUp(SlimeStatus, pRandomArr);
				break;
			}
			Attack(&Slime, pPlayer, pRandomArr);
			if (0 >= pPlayer->Hp)
			{
				cout << "플레이어가 죽었습니다." << endl;
				RebornPlayer(pPlayer);
				system("pause");
			}
			TownSelect(pPlayer, pRandomArr);
			break;

		case 2:
			Attack(&Slime, pPlayer, pRandomArr);
			if (0 >= pPlayer->Hp)
			{
				cout << "플레이어가 죽었습니다." << endl;
				RebornPlayer(pPlayer);
				system("pause");
			}
			TownSelect(pPlayer, pRandomArr);
			return;

		default:
			cout << "입력 오류" << endl;
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
void Attack(PLAYER* pPlayer, MONSTER* pMonster, int pRandomArr[]) //플레이어가 몬스터 공격
{
	pMonster->Hp -= pPlayer->Attack;
	
	if ((pPlayer->MaxExperience - pPlayer->Experience) <= 0)
	{
		LevelUp(pPlayer);
	}

}
void Attack(MONSTER* pMonster, PLAYER* pPlayer, int pRandomArr[]) //몬스터가 플레이어 공격
{
	pPlayer->Hp -= pMonster->Attack;
}

void RecoverPlayer(PLAYER* pPlayer) //마을가면 피 회복.
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
		cout << "플레이어 JOB이 미설정되어 있습니다." << endl;
		break;
	}
}

void RebornPlayer(PLAYER* pPlayer) //죽으면 경험치 초기화
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
		cout << "플레이어 JOB이 미설정되어 있습니다." << endl;
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