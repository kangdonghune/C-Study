// 0326_������.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"


class CConstruct
{
public:
	CConstruct() 
	{
		std::cout << "�αٵα� ������ ȣ��" << std::endl;
	}

	CConstruct(int a)
	{
		std::cout << "�αٵα� ������ ȣ��, �߰� ������" << std::endl;
		iCount = a;
	}
	int GetCount() { return iCount; }
private:
	int iCount = 10;;
};

int main()
{
	//Ŭ������ �����̵ǰ� �ڵ����� �����ϰ� ȣ���ϴ� 4���� �� �ϳ�.
	//��ȯ���� ���� ����
	//�Լ��� �����̱⿡ �����ε� ����.
	//CConstruct tConst = CConstruct(2); //����ڰ� ������ ������ ȣ�� �� �� �� ��ü�� ������ �� �����Ϸ��� �ڵ����� �⺻ ������ ȣ��. �⺻ �����ڰ� �����ִٸ�(private) �Ǵ� ����ڰ� �����ڸ� ������ٸ� ����ڰ� ������ ����� �Ѵ�.
	CConstruct tConst; //�⺻
	std::cout << tConst.GetCount() << std::endl;
	return 0;
}

