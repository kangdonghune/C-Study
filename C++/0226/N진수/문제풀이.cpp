#include <string>
#include <iostream>
#include <vector>
#include <random>
using namespace std;

//���� 1.
//void main() {
//	int a = 12, b = 2;
//	//a�� �� b�� �� �� �� a�� b���� ������ ���Ͻÿ�
//	//�ش� �⵵�� ����. 1�� 1���� �ݿ����̴�.
//	//��1��2��3��4ȭ5��6��0 
//
//	//1. a�� ���� �� ���� �ϼ��� �� ���Ѵ�.
//	//2. �� ������ a���� �� �ϼ����� b�ϸ�ŭ�� �A ���� ���� ������ ����.
//	//3. ���� ������� 7�� %�ϸ� ���������� ���� ������ ��������. 
//
//
//	int Month[] = {0, 31,29,31,30,31,30,31,31,30,31,30,31 }; //�������� �ε����� 0���� �����Ѵ�.
//	int date = 0;
//	string answer = "";
//
//	for (int i = 0; i < a; i++)
//	{
//		date += Month[i+1];
//	}
//	date -= Month[a] - b; //�ش� ���� �ϼ� ���. 1�� ������
//	int day = date % 7; //day ���� date�� 366�� �� Ư���� 1�� 1���� 1�� 2��8���� 60��
// 
//	//1�� 1�� a 1 b1  date 31  > 31 -(31-1) > 1 
//	//2�� 8�� a 2 b 8 date 31+ 29 > 60- (29-8)> 39%7 =4 
//
//	switch (day)
//	{
//	case 0:
//		answer = "THU";
//		break;
//	case 1:
//		answer = "FRI";
//		break;
//	case 2:
//		answer = "SAT";
//		break;
//	case 3:
//		answer = "SUN";
//		break;
//	case 4:
//		answer = "MON";
//		break;
//	case 5:
//		answer = "TUE";
//		break;
//	case 6:
//		answer = "WED";
//		break;
//	defalut:
//		answer = "error";
//		break;
//
//	}
//
//	cout << answer;
//
//}

//���� 2 Ư�� �� n �� �������� ���� �����̸� �ش� (������+1)^2�� ��ȯ�ϰ� 
//���� ������ �ƴϸ� -1 ��ȯ�ϵ��� �϶�
//n�� 1~50000000000 ������ ������ ��.
int main()
{
	srand(50000000);
	long long n = rand();
	int ianswer;

	int iSquare = sqrt(n);// sqrt(��) ������
	if ((int)iSquare == iSquare)
	{
		ianswer = pow(iSquare + 1, 2);
		cout << "n: " << n << endl;
		cout << "n�� ������: " << iSquare << endl;
		cout << "��ȯ��: " << ianswer << endl;
		return pow(iSquare + 1, 2); //pow(a,b) =a^b //return �ϸ� break�� �� ��ó�� ���带 �����Ѵ�. 
	
	}
	else {
		ianswer = -1;
		cout << "n: " << n << endl;
		cout << "n�� ������: " << iSquare << endl;
		cout << "��ȯ��: " << ianswer << endl;
		return -1;
	}
	cout << "n: " << n << endl;
	cout << "n�� ������: " << iSquare << endl;
	cout << "��ȯ��: " << ianswer << endl;

}