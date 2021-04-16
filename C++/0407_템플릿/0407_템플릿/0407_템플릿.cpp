// 0407_템플릿.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"

int Add(int a, int b)
{
	static int iStatic = 1;//함수가 몇 개나 생기는 지 체크. 1이 나올 때마다 새로운 함수 생성. 아니면 같은 함수 주소를 공유하는 경우.
	cout << iStatic++ << endl; 
	return a + b;
}// 타입에 따라 일일이 만들기 귀찮고 코드가 길어진다.

//함수 템플릿(기본적으로 함수의 형태를 보이지만 실체는 템플릿) -> 템플릿 함수

template<typename T> //추후 자료형과 매칭 이게 함수 템플릿 ...


T AddT(T a, T b) //그리고 문제가 되는 게 만약 타입이 포인터 형식이라면 포인터 끼리 더하는 게 안 된다. 연산자 오버로딩이 안되있다면. 그럴 때 대비한 게 템플릿 특수화
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
//template<typename T, typename P> //타입은 여러 개 가능.
//
//template<class TT> //클래스도 가능. class 와 typename 이 하는 역할을 같다. class 쓰기 싫으면 안 써도 된다.


//구조체 템플릿, 템플릿 구조체

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

//동적 할당 해제에도 템플릿.
template<typename T>
void Safe_Release(T* ptr) //이러면 값복사가 되어 ptr의 nullptr 초기화가 안 된다. 넘겨주는 ptr과 현재 함수 안에서 생성된 ptr과 데이터로 같은 주소값을 가지지만 별개의 주소값에 할당된다.
{
	if (ptr)
	{
		delete *ptr;
		*ptr = nullptr;
	}
}

//템플릿 클래스의 경우 파일 분할이 안 된다. 헤더에서 정의까지 다 해주던가 cpp까지 include를 해야한다. 선언부와 정의부가 분리가 안 된다.
//그래서 일부만 템플릿화 시키기 위해 클래스가 가지고 있는 함수를 템플릿 화.

//템플릿 장점-편하다. 일반화 프로그래밍이 가능하다. 컴파일 단계에서 오류잡아내기 때문에 안전하다.
//단점- 코드 비대화. 들어가는 자료형을 다 고려하다보니 컴파일러가 그 코드를 여러 개 찍어내야 한다. -> 실행파일이 커진다.
int main()
{
	//템플릿 - 거푸집
	//cout << AddT<int>(1, 10) << endl; //이게 함수 템플릿을 기반으로 만든 템플릿 함수.
	//cout << AddT(15, 20) << endl; // 들어가는 값에 따라서 자동으로 타입을 정해주기도 한다.
	//const char* pChar = AddT<char*>("이건", "어때?");
	//cout << pChar << endl;
	//MyStruct<int, float, double> tM = { 1, 23.8f, 88.84 }; //템플릿 구조체. 반드시 <> 안에서 값을 정해줘야 한다.자동 지정이 안된다.
	////MyStruct tM2 = { 1, 23.8f, 88.84 };// 반드시 <> 안에서 값을 정해줘야 한다.자동 지정이 안된다.

	//CTest<int> t; // 멤버를 여기서 정해준다.

	int* ptr = new int;
	*ptr = 1;
	cout << ptr << endl;
	cout << *ptr << endl;

	Safe_Release(&ptr);
	cout << ptr << endl;
	cout << *ptr << endl; //접근 막아버리기. delete하면 ptr을 별도 주소로 변경해버리는데 이후 nullptr로 바꿔주니 역참조로 값 출력을 못한다.
    return 0;
}

