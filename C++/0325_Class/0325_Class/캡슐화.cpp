#include "stdafx.h"

class CCapsule
{
public:
	void Eat()
	{
		std::cout << "���� �� �����" << std::endl;
	}
};
class CCapsule1
{
public:
	void Eat()
	{
		std::cout << "���� �� �����1" << std::endl;
	}
};
class CCapsule2
{
public:
	void Eat()
	{
		std::cout << "���� �� �����2" << std::endl;
	}
};

class CSynthesisCapsule
{
public:
	void Eat()
	{
		C0.Eat();
		C1.Eat();
		C2.Eat();
	}//�̷� ������ ĸ��ȭ�� Ŭ�������� ������ �������ְų� �ۼ��ڰ� ���ϴ� ������� �۵��ϰԲ� �����ϴ� ������ �Լ��� ��Ű�� �� ����.
private:	
	CCapsule C0;
	CCapsule1 C1;
	CCapsule2 C2;
};

void main()
{
	//ĸ��ȭ
	//�ʿ��� ��ɵ��� �� ���ε��� �����θ� ����� �������� ��ų �� �ִ�.
	//���� �ʿ��� ��ɵ��� �ϳ��� ���� �װ� �ϳ��� ȣ���ϸ� ������ ���������� �����ϸ� ���� �߻��� ���´�.
	CSynthesisCapsule CS;
	CS.Eat();
}