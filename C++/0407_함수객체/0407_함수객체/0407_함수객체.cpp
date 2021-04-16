// 0407_함수객체.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
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
	} //함수 객체의 장점. 일반함수가 가지지 못하는 멤버 변수를 가질 수 있다.

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

//abstract - 추상 클래스로 만드는 명령어. 순수 가상 함수가 없어도 추상클래스로 만든다. 명시적인 목적도 있다. 더 이상 객체화할 생각이 없을 때 사용. 부모로 쓰기 위해 만든 클래스. 순수 가상 함수를 단 하나라도 들고 있으면 추상 클래스가 된다. 객체 생성 불가. 불완전한 코드
//final - 더 이상 상속을 하지 않겠다는 의미. 해당 클래스는 더 이상 부모 클래스가 되지 못한다.
//override - 오버라이딩 되었다는 명시적 표기. 있어도 되고 없어도 된다.

//임시 객체. 이름 없는 메모리 공간에 한 줄에서만 허용하는 객체를 만드는 것.

class CParents abstract
{
public:
	virtual void Render() = 0;
};

class CChild final : public CParents
{
	// CParents을(를) 통해 상속됨
	virtual void Render() override
	{
	}
};

int main()
{
	//() 함수호출연산자. 결국 이거도 오버로딩이다.
	//함수 객체. 이거도 결국 객체다.
	CAddObject tAdd;
	cout << tAdd(10, 20) << endl;
	TestFunc(tAdd);
	CAddObject()(10, 20); // 앞의 () 생성자, 뒤의 ()는 오버라이드 된 연산자. 이렇게 쓰면 임시 객체로 이 한 줄 안에서 생성되고 소멸된다.
    return 0;
}

