// 0330_const.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"

class CConst
{
public:
	CConst() // 멤버 이니셜 라이져 라는 문법은 시작은 :으로 하고 여러개 하고 싶으면 , 으로 n개 까지 가능.
		//const 멤버 변수를 초기화하고 싶다면 반드시 이니셜라이져를 활용해야 한다.
		:m_iConst(0)
		,m_iA(1)
	{
		//객체 생성 순거
		//선언->메모리할당 -> 이니셜 라이져 문법 실행->생성자 호출
		//이미 메모리가 할당된 이후라 이 초기화 문구를 단순 대입으로 값변경이라 컴파일러는 생각한다.
		cout << "기본 생성자" << endl;
	}
	//이니셜라이져 장점
	//1.이니셜 라이져는 생성과 동시에 초기화. 일반 대입보다 더 빠르다.
	//2.초기화 대상을 명확하게 인식할 수 있다.

	//const 멤버 함수

	//컨스트 함수 내부에서 멤버 변수에 대해 어떠한 값변경도 못하게 하겠다.
	void RenderNonConst() const //함수 뒤에 붙이면 const 멤버 함수가 된다. 함수 내부를 상수화 하겠다.
	{
		//m_iNotConst = 1; // const 멤버 변수가 아님에도 값 변경이 불가한 상수상태가 됨.
		cout << m_iNotConst << endl; // 읽기 자체는 가능. 쓰기가 불가.  .rodata
		int a = 10;
		a = 12; // 지역 변수는 값 변경이 가능하다.
		//const 멤버 함수 안에서는 일반 멤버 함수를 호출할 수 없다. const 함수 호출은 문제 없다. 
		//해당 함수에서 멤버 변수의 변경을 일으킬 수 있기 때문이다.
		//getter 함수의 경우는 혹시나 사태를 방지하기 위해 const를 붙이는 게 좋다.
		//포인터 멤버 변수를 getter 함수를 쓰는 경우 반환 값에 const int* getter() const 식으로 해야지 포인트 주소, 주소가 가지는 값 둘 다 변경이 안되도록 설정해야한다.

		cout << "dd" << endl;
	}


private:
	//const int m_iConst; //문제는 이러면 기본 생성자에서 초기화를 못한다는 문제가 생긴다.
	//const int m_iConst = 0; //멤버 이니셜라이져 문법 c++ 11 이전 버전에서는 이러한 문법 사용 불가. 이를 이용해 const 멤버 변수 초기화.
	//위 방식으로 할 때 문제는 클래스 같은 경우는 헤더에 있는데 헤더는 컴파일이 돌아가는 부분이 아니다. 그러다보니 간혹 초기화가 안 되는 문제가 발생한다.
	const int m_iConst;
	const int m_iA;
	int m_iNotConst;
};

class CConst2
{
public:
	void Render()
	{
		cout << m_iA << endl;
	}

	void Render() const //이렇게 오버로딩도 된다. 근데 이렇게 해서 별로 좋을 게 없으니 되도록 쓰지 말자.
	{
		cout << m_iA <<"const 함수" <<endl;
	}
private:
	int m_iA;
};

/*
레퍼런스 활용
원본 자체는 const 값이 아니더라도
레퍼런스가 const int& 처럼 쓰면 레퍼런스 명으로 쓸 때만 const로 쓸 수 있다.

*/
int main()
{
	CConst tConst;
	CConst2 tConst2;
	tConst2.Render();
	const CConst2 tConst3;
	tConst3.Render(); //이런 식으로 하면 오버로딩된 const함수 호출 가능.
    return 0;
}

