#include <iostream>

using namespace std;

int gValue=100;
//전역 변수. 특징으로 값을 초기화 하지 않아도 자동으로 0으로 초기화. 또한 전역에서 수정이 가능함
static int iStatic;
//static(정적) 변수-값을 초기화하지 않아도 자동 초기화.
//지금은 전역에서도 사용가능하다.
//전역 변수와 차이점.
//전역 변수는 지역에서 선언 불가능하지만 static은 가능하다.
//static을 붙이면 생명 주기가 블럭 단위에서 프로그램 단위로 변경되어 선언된 블록이 끝나도 소멸하지 않고 잔재한다.
//따라서 해당 함수나 다른 곳에서 선언되어 호출되어도 초기화가 되지 않고 유지된다.
//
//

int Add(int a, int b)
{
	cout << gValue << endl;
	iStatic++;
	cout << &iStatic << endl;
	int iTotal = a + b;
	return iTotal;

}

int main()
{
	//함수 사용 이유
	//1. 재사용성.
	//2. 가독성
	
	//함수의 정의
	//보안등급 반환타입 함수명 (인자 혹은 파라미터, 혹은 매개변수)
	//{
	//  함수 내용
	//}
	//반환 타입- 함수가 종료되면서 값을 반환할 때 어떤 형식으로 반환할 지 명시, 생략 불가.
	//함수명 - 함수의 이름. 함수를 불러다 쓸 때 호출. 기능에 맞는 명시적 이름 작명
	//인자&파라미터&매개변수- 내가 함수를 호출할 때 기능을 수행하면서 외부에서 데이터를 받는 용도. 호출하는 김에 함수가 필요로 하는 데이터를 넣어줄 떄 사용	//인자를 받는 갯수는 정해져 있지 않음. n개 까지 받을 수 있다.
	
	//매개변수로 넘겨준 값은 아예 똑같은 게 아니라 값만 복사해준 것이다.
	//int a; 와  Add(a,b)에 있는 매개변수는 같은 게 아니라 a의 값을 복사해 임시로 만든 a에 대입해준다는 뜻이다.
	
	//메모리 영역(Ram) 
	//code- 작성한 소스코드, 코드 시작시 할당된 값.프로그램 시작과 끝
	//stack-지역 변수, 함수 시작 함수 끝이 생명주기 
	//data- 전역 변수, 문자열 상수. 프로그램 시작 시 할당, 종료시 삭제
	//Heap- 사용자가 할당하면 생성, 사용자가 소멸시키면 종료.
	
	//전역변수- 함수에 속하지 않은 영역, 중괄호에 구애받지 않는 영역

	//변수 생성 시 함수 안에서도 {}를 주고 잠깐 쓰고 버릴 수 있다.- 데이터 절약

	{
	/*	int a = 10;
		cout << &a << endl;*/
		//&은 어드레스 연산자. 해당 변수의 주소값을 가져옴.
	} //다음과 같이.
	//지역변수는 프로그램 실행 때마다 바뀐다.
	//전역변수는 어디서든 주소값을 가진다.
	//지역변수는 이름이 같아도 다른 함수에서 생성해 쓸 때마다 주소값이 다르다.

	
	int a = Add(3,5);
	cout << a << endl;
	cout << &a << endl;
	Add(0, 7);
	Add(0, 7);
	Add(0, 7);
	Add(0, 7);
	//cout << &a << endl;
}