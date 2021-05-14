#include <iostream>
#define PI 3.141592f
//어떠한 숫자나 데이터에 이름을 붙이는 방식. 메크로 상수
//장점: 명시적이다. 빠르다.
//단점: 디버깅이 안된다.
#define ADD(a, b) a+b
//장점
//빠르다. 자료형이 자유롭다.
//단점
//디버깅이어렵다. 긴 문장이 어렵다.

using namespace std;

const float PI2 = 3.141592f;

void main()
{
	//매크로 상수
	cout << PI << endl;
	cout << PI2 << endl;

	//매크로 함수. 생긴 게 비슷해서 그렇지 함수는 아니다.
	cout << ADD(20, 10) << endl;

 }