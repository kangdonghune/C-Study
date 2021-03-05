#include <iostream>
#include <stdio.h>

using namespace std;
//�������� int������ �ϸ� ��հ��� ������ �������� ���������� �����⿡ �Ҽ� �κ��� �߸��� ������ �߻��Ѵ�.
//�� �� �̿��� �� �ִ� �� ����ȯ�� �ִ�.
//������ ����ȯ-����ڰ� ����ȯ�� ������� ������ ������ ����ȯ�� �Ͼ��. int a = 10.f ��� �ϸ� float 10.f �� int �������� ����ȯ �ȴ�.
//����� ����ȯ-����ڰ� ����ϴ� ��. int j = (int)3.14f or int(3.14f)
//����ȯ �켱���� 
// long double > double > float > long long > long = int > short > char > bool ������ �ս��� ����� ����.
// �̸� �̿��ϸ� ��� = (int ������)/ 3.f �� �ϸ� ������ ����ȯ�� ���� �켱������ float�� �ڵ� ����ȯ�� �Ǿ� ����� �ǰ� ������ �ȴ�.
//������
// ���� ��ü�� �Ǽ��� �� �ʿ伺�� ������ int �������� �ϰ� ����� ����ϴ� �κп����� ����ȯ�Ͽ� ����ϴ� ��������.

float Average(int a, int b, int c)
{
	return (a + b + c) / 3.f;
}

float Total(int a, int b, int c)
{
	return a + b + c;
}

void InputScore()
{
	cout << "����1 ���� ���� ���� ������ �Է� �ް� ��հ� ���� ���ϰ� ����ϱ�" << endl;
	cout << "" << endl;
	int iKorean = 0, iEnglish = 0, iMath = 0;

	cout << "���� ������ �Է��Ͻÿ�." << endl;
	cin >> iKorean;
	//printf("���� ������ %lf���Դϴ�.\n", dKorean);
	cout << "���� ������ �Է��Ͻÿ�." << endl;
	cin >> iEnglish;
	cout << "���� ������" << iEnglish << "���Դϴ�." << endl;
	//printf("���� ������ %lf���Դϴ�.\n", dEnglish);
	cout << "���� ������ �Է��Ͻÿ�." << endl;
	cin >> iMath;
	cout << "���� ������" << iMath << "���Դϴ�." << endl;
	//printf("���� ������ %lf���Դϴ�.\n", dMath);
	cout << "��� ������" << Average(iKorean, iEnglish, iMath) << "�� �Դϴ�." << endl;
	cout << "������ " << Total(iKorean, iEnglish, iMath) << "���Դϴ�." << endl;
}


	////����2 10000 �̸��� ������ �Է¹޾� �� �ڸ��� �и��ؼ� ����ϱ� 


	//���� ������ ����� ��� ������ �ߴµ� 1�� �ڸ����� ������ ����� ����� ���� ������ ����� �� ���� ��
	//�׸��� �ϵ� �ڵ��� �ؼ� ���� �� ����
	//������ ��ó�� õ���ڸ� ���� 10 ���ϰ� �̷� �ͺ��� (i%���ϰ��� �ϴ� �ڸ��뺸�� �� �ڸ� �� ū ��)/���ϰ��� �ϴ� �ڸ��� �� �ϴ� �� �� ��
	//���� �ڸ� = (i%1000)/100.
void Classification() {
	cout << "����2 10000 �̸��� ������ �Է¹޾� �� �ڸ��� �и��ؼ� ����ϱ� " << endl;;
	cout << "" << endl;
	int i;
	cin >> i;
	//���� �Է°��� 10000���� Ŭ ���
	i = (i >= 10000) ? i % 10000 : i; // ��� 1-���� �Ѵ� �ڸ���� �����Ѵ�.
	cout << "�Է°�:" << i << endl;
	cout << " õ�� �ڸ�: " << i / 1000 << endl; //1000���� ���� ��.
	cout << " ���� �ڸ�: " << (i / 100) - ((i / 1000) * 10) << endl; //100���� ������ õ�� �ڸ����� ���Ե�. �߰������� õ�� �ڸ� ��*10�� �ؼ� �׷��� ���� �ذ�
	cout << " ���� �ڸ�: " << (i % 100) / 10 << endl; // �Է°��� 100���� ���� ���� �������� 10���� ������ �ڸ��� ����.
	cout << " ���� �ڸ�: " << i % 10 << endl; //�Է°��� 10���� ���� �������� 1�� �ڸ��� ���� �ȴ�.
	cout << "" << endl;
}




	////����3 �� ������ �� �¹ٲٱ� 
void Swap(int a, int b) {
	cout << "����3 �� ������ �� �¹ٲٱ� " << endl;
	cout << "" << endl;
	int iswap;
	cout << "a = " << a << " b = " << b << "\n" << endl;
	cout << "-----swap-----" << "\n" << endl;
	iswap = a;
	a = b;
	b = iswap;
	cout << "a = " << a << " b = " << b << endl;
	cout << "" << endl;
}
	

	//����4 �����׷��� ���� ������ �Է� �ް� ���� ������ ����ϴ� �ڵ� ���� . hint: ������ n���� ������ �׷������� �ִ��� ���� �� : n(n-1)/2��

int GetLines(int iPoint)
{
	int result = iPoint*(iPoint - 1)/2;

	return result;
}


void HowManyLines() 
{
	cout << "����4 �����׷��� ���� ������ �Է� �ް� ���� ������ ����ϴ� �ڵ� ���� " << endl;
	cout << "" << endl;
	int iPoint, iLinecount;
	cin >> iPoint;
	iLinecount = iPoint*(iPoint - 1) / 2;
	cout << "���� ������ " << iPoint << "�� �Դϴ�." << endl;
	cout << "���� ������ " << GetLines(iPoint) << "�� �Դϴ�." << endl;

}
	

void main()
{
	InputScore();
	Classification();
	Swap(4, 25);
	HowManyLines();
}