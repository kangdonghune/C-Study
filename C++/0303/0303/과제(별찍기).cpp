#include <iostream>

using namespace std;

void DrawRightIncreaseStar()
{
	for (int i = 1; i < 6; i++)
	{
		for (int j = 0; j < i; j++)
		{
			cout << "*";
		}
		cout << "" << endl;
	}
}

void DrawRightDecreaseStar()
{
	for (int i = 5; i > 0; i--)
	{
		for (int j = 0; j < i; j++)
		{
			cout << "*";
		}
		cout << "" << endl;
	}
}

void DrawLeftIncreaseStar()
{
	for (int i = 1; i < 6; i++)
	{
		for (int j = 5 - i; j > 0; j--)
		{
			cout << " ";
		}
		for (int k = 0; k < i; k++)
		{
			cout << "*";
		}
		cout << "" << endl;
	}
}

void DrawLeftDecreaseStar()
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < i; j++)
		{
			cout << " ";
		}
		for (int k = 5 - i; k > 0; k--)
		{
			cout << "*";
		}
		cout << "" << endl;
	}
}
int main()
{
	DrawRightIncreaseStar();
	DrawRightDecreaseStar();
	DrawLeftIncreaseStar();
	DrawLeftDecreaseStar();
}