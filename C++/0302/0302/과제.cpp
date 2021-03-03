#include <iostream>
#include <time.h>
using namespace std;

int main()
{
	//성적표 만들기 + 학점
	/*
	 100~ 90 A학점
	 90~80 B
	 80~70 C
	 70~60 D
	 외 나머지는 F

	 if문 버젼 하나, switch 버전 하나씩.
	*/

	int iScore = 0;
	do
	{
		cout << "성적을 입력하세요.(0~100점 사이)" << endl;
		cin >> iScore;
	} while (!(100 >= iScore && 0 <= iScore));
	
	//1번 if문
	if (90 <= iScore)
		cout << "성적은 " << iScore << "점입니다. 학점은 A입니다." << endl;
	else if (80 <= iScore)
		cout << "성적은 " << iScore << "점입니다. 학점은 B입니다." << endl;
	else if (70 <= iScore)
		cout << "성적은 " << iScore << "점입니다. 학점은 C입니다." << endl;
	else if (60 <= iScore)
		cout << "성적은 " << iScore << "점입니다. 학점은 D입니다." << endl;
	else
		cout << "성적은 " << iScore << "점입니다. 학점은 F입니다." << endl;


	switch (iScore/10)
	{
	case 10:
	case 9:
		cout << "성적은 " << iScore << "점입니다. 학점은 A입니다." << endl;
		break;
	case 8:
		cout << "성적은 " << iScore << "점입니다. 학점은 B입니다." << endl;
		break;
	case 7:
		cout << "성적은 " << iScore << "점입니다. 학점은 C입니다." << endl;
		break;
	case 6:
		cout << "성적은 " << iScore << "점입니다. 학점은 D입니다." << endl;
		break;
	default:
		cout << "성적은 " << iScore << "점입니다. 학점은 F입니다." << endl;
		break;
	}

	/*
	 자판기만들기
	 -소지금을 입력받는다.
	 -현재 소지금의 보유 잔액 표시
	 -메뉴출력
	 =메뉴는 3개 추가로 나가기
	 -나가기 누르면 잔액 출력 후 종료
	 -해당 목록 구매시 해당 물품 구매 완료 문구 띄워주기
	 단 해당 금액보다 소지금이 없으면 잔약부족 출력
	*/

	int iMoney = 0;
	int iSelect;
	do
	{
		cout << "소지금을 입력하세요.(0원 이상)" << endl;
		cin >> iMoney;
	} while (!(0 <= iMoney));

	do
	{
		cout << iMoney << "원을 가지고 있습니다." << endl;
		cout << "1.사이다(500원) 2.콜라(200원) 3.나랑드 사이다(1700원) 4.나가기" << endl;
		cin >> iSelect;
		switch (iSelect)
		{
		case 1:
			if (500 > iMoney)
			{
				cout << "소지금이 부족합니다. 현재 잔액: " << iMoney << endl;
				break;
			}
				cout << "사이다를 구매했습니다." << endl;
				iMoney -= 500;
				break;
		case 2 :
			if (200 > iMoney)
			{
				cout << "소지금이 부족합니다. 현재 잔액: " << iMoney << endl;
				break;
			}
			cout << "콜라를 구매했습니다." << endl;
			iMoney -= 200;
			break;

		case 3:
			if (1700 > iMoney)
			{
				cout << "소지금이 부족합니다. 현재 잔액: " << iMoney << endl;
				break;
			}
			cout << "콜라를 구매했습니다." << endl;
			iMoney -= 1700;
			break;
		default:
			break;
		}
	} while (!(4 == iSelect));
	cout<< "판매를 종료합니다. " << iMoney << "원이 남았습니다." << endl;
	/*
	  홀짝 게임
	  -난수를 이용하여 0~9, 1~10을 구한다.
	  -메뉴는 1홀2짝3종료
	  총3판
	  매라운드마다 난수는 새로 뽑기
	  게임이 종료된 후 승, 패 출력
	*/
	srand(unsigned(time(NULL)));	
	int iCount1 = 0; //판마다 +1. 3이 되면 게임 종료
	int iPlayerCount = 0; //맞출 때마다 +1;
	bool bIsEven = false;
	do
	{
		int iNum = rand();
		iNum = iNum % 10; // 0~9
		//iNum = (iNum % 10)+1; //1~10;
		cout << "홀수인지 짝수인지 입력하세요. 홀: 0, 짝:1 " << endl;
		cin >> bIsEven;
		//1.난수 짝, 정답 짝
		//2.난수 홀, 정답 홀
		//3.그 외는 전부 틀린 답 처리.
		if ((0 == iNum % 2) && bIsEven)
		{
			cout << "정답입니다. 난수: " << iNum << endl;
			iPlayerCount++;
		}
		else if ((0 != iNum % 2) && !bIsEven)
		{
			cout << "정답입니다. 난수: " << iNum << endl;
			iPlayerCount++;
		}
		else
		{
			cout << "틀렸습니다. 난수: " << iNum << endl;
		}
		iCount1++;
	} while (!(iCount1 == 3));
	if(2 <=iPlayerCount)
	{ 
		cout << "플레이어가 승리했습니다." << endl;
	}
	else
	{
		cout << "플레이어가 패배했습니다." << endl;
	}

	/*
	  가위바위보
	  메뉴 1가위 2바위 3보
	  총 3판
	  사용자가 낸 것 컴퓨터가 낸 것 비교해서 이겼는지 졌는지 비겼는지 구하면 된다.
	  게임 종료 후 승, 패, 무 출력
	*/

	//컴퓨터와 내가 같으면 무승부
	//내가 이기면 내 승, 지면 컴퓨터 승
	int iCount = 0;//판수
	int iPlayerScore = 0; //이긴 횟수
	int iComputerScore = 0;
	int iRock = 0, iScissors = 1, iPaper = 2;
	int iPlayerPick = 0;
	int iComputerPick = 0;
	do
	{
		iComputerPick = rand()%3;
		cout << "플레이어의 선택을 정해주세요. 0.바위 1.가위 2.보 " << endl;
		cin >> iPlayerPick;
		if (3 <= iPlayerPick || -1 > iPlayerPick)
		{
			cout << "0~2 중에 하나를 골라주세요." << endl;
			continue;
		}
		if ((iPlayerPick + 2) % 3 == iComputerPick) //컴퓨터 승
		{
			cout << "컴퓨터의 선택(0.바위 1.가위 2.보): "<<iComputerPick << endl;
			cout << "컴퓨터 승리." << endl;
			iComputerScore++;
		}
		else if ((iPlayerPick + 1) % 3 == iComputerPick) //플레이어 승
		{
			cout << "컴퓨터의 선택(0.바위 1.가위 2.보): " << iComputerPick << endl;
			cout << "플레이어 승리." << endl;
			iPlayerScore++;
		}
		else // 무승부.
		{
			cout << "컴퓨터의 선택(0.바위 1.가위 2.보): " << iComputerPick << endl;
			cout << "무승부." << endl;
		}
		iCount++;
	} while (!(iCount == 3));
	if (iPlayerScore > iComputerScore)
	{
		cout << "플레이어 최종 승리." << endl;
	}
	else if (iPlayerScore < iComputerScore)
	{
		cout << "컴퓨터 최종 승리." << endl;
	}
	else
	{
		cout << "최종 무승부." << endl;
	}
}