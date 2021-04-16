// 0405.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"

class C_Obj
{
	void CO_Test()
	{
		cout << "O" << endl;
	}

	virtual void Render() = 0;
};

class CP : public C_Obj
{
public:
	void CP_Test()
	{
		cout << "P" << endl;
		cout << m_iA << endl;
	}
	virtual void Render()
	{

	};

private:
	int m_iA = 10;

};

class CM : public C_Obj
{
public:

	void CM_Test()
	{
		cout << "M" << endl;
	}
	virtual void Render()
	{

	};
};
int main()
{
	C_Obj* pTest = new CP;
	C_Obj* pTest3 = new CM;
	//����ƽ ĳ��Ʈ�� �θ� ������ �����ε� ĳ������ �ȴ�. ������ ������ ���� �ٸ� ��������� ������ ���� �� �̿� ������ �� ������ �߻��� �� �ִ�.
	//���̳��� ĳ��Ʈ�� ��Ÿ�� ������ ����. ��Ӱ���� ���� �Լ��� ������ ������. �����Լ� ������ ����ȯ�� �ȵȴ�. �ּ� 1�� �̻�
	//����ȯ�� �������� �ʴ� �Ǵ��ϸ� nullptr�� ��ȯ�Ѵ�.
	//���̳��� ĳ��Ʈ�� �ؿ��� nullptr üũ�� ���ִ� �� ���� �����̴�.
	dynamic_cast<CP*>(pTest)->CP_Test();
	CM* tCm = dynamic_cast<CM*>(pTest);
	tCm->CM_Test(); //���� CM�� ����� ������ ���� �� �ƴ϶� ���� ��ü�� �ȳ����� ������ �����̴�. �ֳĸ� ���� tCm = nullptr ����.
	if (tCm == nullptr)
		cout << "tCm�� ����ִ�." << endl;
	CP* pTest2 = dynamic_cast<CP*>(pTest);
	pTest2->CP_Test();
	//reinterpret_cast �� ����ȯ ����� ������ Ȥ�� ���۷����� ������� �Ѵ�.
	//c ��Ÿ�� ����ȯ�� ����. �߸� ���� ���� ������ �ʴ´�.

	//const_cast
	//������ Ȥ�� ���۷������� ����ȯ�� �㰡.
	int iA = 10;
	const int* ptr = &iA; // �� ��� �� ������ �� �� ���µ� const ĳ��Ʈ�� �̰� �����ϰ� ���ش�. 
	//const ������ ����Ʈ����. �ٵ� ���� �ٲ��� ����� const�� �ص� �ǵ� �װ� �Ժη� Ǫ�� �Ŵ� ��뿡 �ɻ��������.
	//����(iA)�� const �� const ĳ��Ʈ�� �ص� ���� ������ �ʴ´�. �ٵ� ����� ���ȿ��� ���� ���� �ɷ� �ν��� �ȴٴ� ������ ������ ��������.
	//���⼭ �߻��ϴ� �� ���߿� const ĳ��Ʈ �� �ɷ� ������ �ؼ� ������ �����ع����� �� ������ �� �ٲ� ������ ����. �ٵ� ����� �� ���� ������ �״��.

    return 0;
}

