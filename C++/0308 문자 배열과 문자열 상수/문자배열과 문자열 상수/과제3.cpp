#include <iostream>
#include <time.h>
using namespace std;



void MakeBingo(int(*Bingo)[5]);
void PrintBingo(int(*Bingo)[5]);
void ChoiceNum(int(*Bingo)[5]);
void CountBingo(int(*Bingo)[5], int* BingoCount);

void main()
{
	srand(unsigned(time(NULL)));
	const int size = 5;
	int BingoCount = 0;
	int Bingo[size][size] = {};

	MakeBingo(Bingo);
	while (!(4 == BingoCount))
	{
		if (BingoCount <= 3)
			BingoCount = 0;
		PrintBingo(Bingo);
		ChoiceNum(Bingo);
		CountBingo(Bingo, &BingoCount);
		cout <<"현재 빙고:" << BingoCount << endl;
		
	}
	cout << "현재 빙고:" << BingoCount << endl;
	PrintBingo(Bingo);
	cout << "게임을 종료합니다." << endl;

}


void MakeBingo(int(*Bingo)[5])
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++) {
			Bingo[i][j] = (5 * i + j) + 1;
		}
	}
	// 1~ 25 순서대로 채우기
	for (int i = 0; i < 10000; i++)
	{
		int dest1 = rand() % 5;
		int src1 = rand() % 5;
		int dest2 = rand() % 5;
		int src2 = rand() % 5;
		int temp = Bingo[dest1][dest2];
		Bingo[dest1][dest2] = Bingo[src1][src2];
		Bingo[src1][src2] = temp;
	}
}

void PrintBingo(int(*Bingo)[5])
{
	cout << "" << endl;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++) {
			cout << Bingo[i][j] << "\t";
		}
		cout << "" << endl;
	}
	cout << "" << endl;
}

void ChoiceNum(int(*Bingo)[5])
{
	cout << "" << endl;
	int select;
	cin >> select;

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++) {
			if (select == Bingo[i][j])
				Bingo[i][j] = 0;
		}
	}
	
}

void CountBingo(int(*Bingo)[5], int* BingoCount)
{
	int BingoHorizon = 0, BingoVertical = 0, BingoDiagonal = 0, RBingoDiagonal = 0;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			BingoHorizon += Bingo[i][j];
			BingoVertical += Bingo[j][i];
		}
		if (0 == BingoHorizon)
		{
			*BingoCount = *BingoCount + 1;
			BingoHorizon = 0;
		}
			
		if (0 == BingoVertical)
		{
			*BingoCount = *BingoCount + 1;
			BingoVertical = 0;
		}	
	}

	for (int i = 0; i < 5; i++)
	{
		BingoDiagonal += Bingo[i][i];
		RBingoDiagonal += Bingo[i][4 - i];
	}
	if (0 == BingoDiagonal)
		*BingoCount = *BingoCount + 1;

	if (0 == RBingoDiagonal)
		*BingoCount = *BingoCount + 1;

	cout << "" << endl;
}