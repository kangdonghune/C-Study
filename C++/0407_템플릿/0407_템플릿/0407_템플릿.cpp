// 0407_���ø�.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"

int Add(int a, int b)
{
	static int iStatic = 1;//�Լ��� �� ���� ����� �� üũ. 1�� ���� ������ ���ο� �Լ� ����. �ƴϸ� ���� �Լ� �ּҸ� �����ϴ� ���.
	cout << iStatic++ << endl; 
	return a + b;
}// Ÿ�Կ� ���� ������ ����� ������ �ڵ尡 �������.

//�Լ� ���ø�(�⺻������ �Լ��� ���¸� �������� ��ü�� ���ø�) -> ���ø� �Լ�

template<typename T> //���� �ڷ����� ��Ī �̰� �Լ� ���ø� ...


T AddT(T a, T b) //�׸��� ������ �Ǵ� �� ���� Ÿ���� ������ �����̶�� ������ ���� ���ϴ� �� �� �ȴ�. ������ �����ε��� �ȵ��ִٸ�. �׷� �� ����� �� ���ø� Ư��ȭ
{
	return a + b;
}

template<>
char* AddT(char* p1, char* p2)  
{
	int iSize = strlen(p1) + strlen(p2) + 1;
	char* pBuffer = new char[iSize];
	strcpy_s(pBuffer, iSize, p1);
	strcat_s(pBuffer, iSize, p2);
	return pBuffer;
}


//
//template<typename T, typename P> //Ÿ���� ���� �� ����.
//
//template<class TT> //Ŭ������ ����. class �� typename �� �ϴ� ������ ����. class ���� ������ �� �ᵵ �ȴ�.


//����ü ���ø�, ���ø� ����ü

template<typename T, typename P, typename A>
struct MyStruct
{
	T a;
	P b;
	A c;
};

template<typename T>
class CTest
{
private:
	T tSome;
};

//���� �Ҵ� �������� ���ø�.
template<typename T>
void Safe_Release(T* ptr) //�̷��� �����簡 �Ǿ� ptr�� nullptr �ʱ�ȭ�� �� �ȴ�. �Ѱ��ִ� ptr�� ���� �Լ� �ȿ��� ������ ptr�� �����ͷ� ���� �ּҰ��� �������� ������ �ּҰ��� �Ҵ�ȴ�.
{
	if (ptr)
	{
		delete *ptr;
		*ptr = nullptr;
	}
}

//���ø� Ŭ������ ��� ���� ������ �� �ȴ�. ������� ���Ǳ��� �� ���ִ��� cpp���� include�� �ؾ��Ѵ�. ����ο� ���Ǻΰ� �и��� �� �ȴ�.
//�׷��� �Ϻθ� ���ø�ȭ ��Ű�� ���� Ŭ������ ������ �ִ� �Լ��� ���ø� ȭ.

//���ø� ����-���ϴ�. �Ϲ�ȭ ���α׷����� �����ϴ�. ������ �ܰ迡�� ������Ƴ��� ������ �����ϴ�.
//����- �ڵ� ���ȭ. ���� �ڷ����� �� ����ϴٺ��� �����Ϸ��� �� �ڵ带 ���� �� ���� �Ѵ�. -> ���������� Ŀ����.
int main()
{
	//���ø� - ��Ǫ��
	//cout << AddT<int>(1, 10) << endl; //�̰� �Լ� ���ø��� ������� ���� ���ø� �Լ�.
	//cout << AddT(15, 20) << endl; // ���� ���� ���� �ڵ����� Ÿ���� �����ֱ⵵ �Ѵ�.
	//const char* pChar = AddT<char*>("�̰�", "�?");
	//cout << pChar << endl;
	//MyStruct<int, float, double> tM = { 1, 23.8f, 88.84 }; //���ø� ����ü. �ݵ�� <> �ȿ��� ���� ������� �Ѵ�.�ڵ� ������ �ȵȴ�.
	////MyStruct tM2 = { 1, 23.8f, 88.84 };// �ݵ�� <> �ȿ��� ���� ������� �Ѵ�.�ڵ� ������ �ȵȴ�.

	//CTest<int> t; // ����� ���⼭ �����ش�.

	int* ptr = new int;
	*ptr = 1;
	cout << ptr << endl;
	cout << *ptr << endl;

	Safe_Release(&ptr);
	cout << ptr << endl;
	cout << *ptr << endl; //���� ���ƹ�����. delete�ϸ� ptr�� ���� �ּҷ� �����ع����µ� ���� nullptr�� �ٲ��ִ� �������� �� ����� ���Ѵ�.
    return 0;
}

