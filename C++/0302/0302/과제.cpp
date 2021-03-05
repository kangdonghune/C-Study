#include <iostream>
#include <time.h>
using namespace std;

//����ǥ ����� + ����
/*
100~ 90 A����
90~80 B
80~70 C
70~60 D
�� �������� F
*/

int InputScore()
{
	int iScore = 0;
	do
	{
		cout << "������ �Է��ϼ���.(0~100�� ����)" << endl;
		cin >> iScore;
	} while (!(100 >= iScore && 0 <= iScore));

	return iScore;
}

void OutputGrade(int score)
{
	if (90 <= score)
		cout << "������ " << score << "���Դϴ�. ������ A�Դϴ�." << endl;
	else if (80 <= score)
		cout << "������ " << score << "���Դϴ�. ������ B�Դϴ�." << endl;
	else if (70 <= score)
		cout << "������ " << score << "���Դϴ�. ������ C�Դϴ�." << endl;
	else if (60 <= score)
		cout << "������ " << score << "���Դϴ�. ������ D�Դϴ�." << endl;
	else
		cout << "������ " << score << "���Դϴ�. ������ F�Դϴ�." << endl;


	switch (score / 10)
	{
	case 10:
	case 9:
		cout << "������ " << score << "���Դϴ�. ������ A�Դϴ�." << endl;
		break;
	case 8:
		cout << "������ " << score << "���Դϴ�. ������ B�Դϴ�." << endl;
		break;
	case 7:
		cout << "������ " << score << "���Դϴ�. ������ C�Դϴ�." << endl;
		break;
	case 6:
		cout << "������ " << score << "���Դϴ�. ������ D�Դϴ�." << endl;
		break;
	default:
		cout << "������ " << score << "���Դϴ�. ������ F�Դϴ�." << endl;
		break;
	}
}

/*
���Ǳ⸸���
-�������� �Է¹޴´�.
-���� �������� ���� �ܾ� ǥ��
-�޴����
=�޴��� 3�� �߰��� ������
-������ ������ �ܾ� ��� �� ����
-�ش� ��� ���Ž� �ش� ��ǰ ���� �Ϸ� ���� ����ֱ�
�� �ش� �ݾ׺��� �������� ������ �ܾ���� ���
*/

int InputMoney()
{
	int iMoney = 0;
	do
	{
		cout << "�������� �Է��ϼ���.(0�� �̻�)" << endl;
		cin >> iMoney;
	} while (!(0 <= iMoney));

	return iMoney;
}

void BuyDrink(int iMoney)
{
	int iSelect;
	do
	{
		cout << iMoney << "���� ������ �ֽ��ϴ�." << endl;
		cout << "1.���̴�(500��) 2.�ݶ�(200��) 3.������ ���̴�(1700��) 4.������" << endl;
		cin >> iSelect;
		switch (iSelect)
		{
		case 1:
			if (500 > iMoney)
			{
				cout << "�������� �����մϴ�. ���� �ܾ�: " << iMoney << endl;
				break;
			}
				cout << "���̴ٸ� �����߽��ϴ�." << endl;
				iMoney -= 500;
				break;
		case 2 :
			if (200 > iMoney)
			{
				cout << "�������� �����մϴ�. ���� �ܾ�: " << iMoney << endl;
				break;
			}
			cout << "�ݶ� �����߽��ϴ�." << endl;
			iMoney -= 200;
			break;

		case 3:
			if (1700 > iMoney)
			{
				cout << "�������� �����մϴ�. ���� �ܾ�: " << iMoney << endl;
				break;
			}
			cout << "�ݶ� �����߽��ϴ�." << endl;
			iMoney -= 1700;
			break;
		default:
			break;
		}
	} while (!(4 == iSelect));
	cout<< "�ǸŸ� �����մϴ�. " << iMoney << "���� ���ҽ��ϴ�." << endl;
}

int MakeRandomNum() //���� ���� �ĤѸ� ���� ����� �̰� �����̵ǳ�?
{
	srand(unsigned(time(NULL)));
	int num = rand();
	num %= 10;

	return num;
}

void EvenOrOdd()
{
	int iCount1 = 0; //�Ǹ��� +1. 3�� �Ǹ� ���� ����
	int iPlayerCount = 0; //���� ������ +1;
	bool bIsEven = false;
	do
		{
			int iNum = MakeRandomNum();
			//iNum = (iNum % 10)+1; //1~10;
			cout << "Ȧ������ ¦������ �Է��ϼ���. Ȧ: 0, ¦:1 " << endl;
			cin >> bIsEven;
			//1.���� ¦, ���� ¦
			//2.���� Ȧ, ���� Ȧ
			//3.�� �ܴ� ���� Ʋ�� �� ó��.
			if ((0 == iNum % 2) && bIsEven)
			{
				cout << "�����Դϴ�. ����: " << iNum << endl;
				iPlayerCount++;
			}
			else if ((0 != iNum % 2) && !bIsEven)
			{
				cout << "�����Դϴ�. ����: " << iNum << endl;
				iPlayerCount++;
			}
			else
			{
				cout << "Ʋ�Ƚ��ϴ�. ����: " << iNum << endl;
			}
			iCount1++;
		} while (!(iCount1 == 3));
		if(2 <= iPlayerCount)
		{ 
			cout << "�÷��̾ �¸��߽��ϴ�." << endl;
		}
		else
		{
			cout << "�÷��̾ �й��߽��ϴ�." << endl;
		}

}

//  ����������
//  �޴� 1���� 2���� 3��
//  �� 3��
//  ����ڰ� �� �� ��ǻ�Ͱ� �� �� ���ؼ� �̰���� ������ ������ ���ϸ� �ȴ�.
//  ���� ���� �� ��, ��, �� ���
//��ǻ�Ϳ� ���� ������ ���º�
//���� �̱�� �� ��, ���� ��ǻ�� ��


void WhoIsWinner(int iPlayerScore, int iComputerScore)
{
	if (iPlayerScore > iComputerScore)
	{
		cout << "�÷��̾� ���� �¸�." << endl;
	}
	else if (iPlayerScore < iComputerScore)
	{
		cout << "��ǻ�� ���� �¸�." << endl;
	}
	else
	{
		cout << "���� ���º�." << endl;
	}
}

void RockScissorPaper()
{
	int iCount = 0;//�Ǽ�
	int iPlayerScore = 0; //�̱� Ƚ��
	int iComputerScore = 0;
	int iRock = 0, iScissors = 1, iPaper = 2;
	int iPlayerPick = 0;
	int iComputerPick = 0;
	do
	{
		iComputerPick = rand()%3;
		cout << "�÷��̾��� ������ �����ּ���. 0.���� 1.���� 2.�� " << endl;
		cin >> iPlayerPick;
		if (3 <= iPlayerPick || -1 > iPlayerPick)
		{
			cout << "0~2 �߿� �ϳ��� ����ּ���." << endl;
			continue;
		}
		if ((iPlayerPick + 2) % 3 == iComputerPick) //��ǻ�� ��
		{
			cout << "��ǻ���� ����(0.���� 1.���� 2.��): "<<iComputerPick << endl;
			cout << "��ǻ�� �¸�." << endl;
			iComputerScore++;
		}
		else if ((iPlayerPick + 1) % 3 == iComputerPick) //�÷��̾� ��
		{
			cout << "��ǻ���� ����(0.���� 1.���� 2.��): " << iComputerPick << endl;
			cout << "�÷��̾� �¸�." << endl;
			iPlayerScore++;
		}
		else // ���º�.
		{
			cout << "��ǻ���� ����(0.���� 1.���� 2.��): " << iComputerPick << endl;
			cout << "���º�." << endl;
		}
		iCount++;
	} while (!(iCount == 3));

	WhoIsWinner(iPlayerScore, iComputerScore);
}

	
	
	

int main()
{
	OutputGrade(InputScore());
	BuyDrink(InputMoney());
	EvenOrOdd();
	RockScissorPaper();



}