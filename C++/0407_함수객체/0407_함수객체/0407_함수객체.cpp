// 0407_�Լ���ü.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"

void Test()
{
	cout << "test call" << endl;
}

class CAddObject
{
public:
	CAddObject()
	{

	}

	CAddObject(int a, int b)
	{
		m_iA = a;
		m_iB = b;
	}

	inline int operator()(int a, int b)
	{
		return a + b;
	} //�Լ� ��ü�� ����. �Ϲ��Լ��� ������ ���ϴ� ��� ������ ���� �� �ִ�.

private:
	int m_iA;
	int m_iB;
};

void TestFunc(CAddObject tObj)
{
	cout << tObj(19, 29) << endl;
}

void SortArr(int pArr[], int iSize)
{
	
}

//abstract - �߻� Ŭ������ ����� ��ɾ�. ���� ���� �Լ��� ��� �߻�Ŭ������ �����. ������� ������ �ִ�. �� �̻� ��üȭ�� ������ ���� �� ���. �θ�� ���� ���� ���� Ŭ����. ���� ���� �Լ��� �� �ϳ��� ��� ������ �߻� Ŭ������ �ȴ�. ��ü ���� �Ұ�. �ҿ����� �ڵ�
//final - �� �̻� ����� ���� �ʰڴٴ� �ǹ�. �ش� Ŭ������ �� �̻� �θ� Ŭ������ ���� ���Ѵ�.
//override - �������̵� �Ǿ��ٴ� ����� ǥ��. �־ �ǰ� ��� �ȴ�.

//�ӽ� ��ü. �̸� ���� �޸� ������ �� �ٿ����� ����ϴ� ��ü�� ����� ��.

class CParents abstract
{
public:
	virtual void Render() = 0;
};

class CChild final : public CParents
{
	// CParents��(��) ���� ��ӵ�
	virtual void Render() override
	{
	}
};

int main()
{
	//() �Լ�ȣ�⿬����. �ᱹ �̰ŵ� �����ε��̴�.
	//�Լ� ��ü. �̰ŵ� �ᱹ ��ü��.
	CAddObject tAdd;
	cout << tAdd(10, 20) << endl;
	TestFunc(tAdd);
	CAddObject()(10, 20); // ���� () ������, ���� ()�� �������̵� �� ������. �̷��� ���� �ӽ� ��ü�� �� �� �� �ȿ��� �����ǰ� �Ҹ�ȴ�.
    return 0;
}

