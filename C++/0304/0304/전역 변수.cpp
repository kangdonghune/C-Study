#include <iostream>

using namespace std;

int gValue; //��������
static int iStatic;
//static ������ ���������� ���� �����ϸ� �ʱ�ȭ�� �� �� ���� �ǽõȴ�. �׿� ���� �Լ��� �ݺ��ǵ� ������ �ʱ�ȭ���� �ʰ� ������ �� �ִ�.

//���� ������ static ������ �ϴ� �޸� ���� ���� �ִ�.
//���� ��� ���� �Ÿ� ������µ� �� �ι� ���� ���Ÿ� ��� ���ֽ�Ű�� �� �����
//�׸��� �������� �ǵ� �� �ִٴ� �Ŵ� ������ ������� �̷���� �� �ִٴ� �Ű� �� ������ �� �� �ִٴ� �Ŵ� �����ؼ� ����
//�׷��� �������� ���� �Ű����� ������ �����͸� �ǳ��ִ� ��.
void Test1() //������ ��� ����
{
	static int iStatic2 = 0;
	iStatic2++;
	cout << iStatic2 << endl;
}

void Test2() //������ �Ź� �ʱ�ȭ �Ǿ� �� ���� ����.
{
	int iNonStatic = 0;
	iNonStatic++;
	cout << iNonStatic << endl;
}

int main()
{
	Test1();
	Test1();
	Test1();
	Test1();
	Test1();

	Test2();
	Test2();
	Test2();
	Test2();
	Test2();
	Test2();
}

