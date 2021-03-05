#include <iostream>

using namespace std;

//함수는 반환값을 넘기는데 문제는 함수 하나당 하나 밖에 반환을 못함.
//값을 여러 개 넘기고 싶을 때 쓰는 게 포인터 형식

//call by value 값 복사에 의한 함수 호출

int test(int a, int b)
{
	a = 10;
	b = 12;
	return a, b; // return , 를 찍으면 걍 뒤에거를 반환해버림.
}

int main()
{
	int a = 0, b = 0;
	test(a, b); 
	//이런 방식이 call by value. 해당 변수의 주소값이 아닌 값을 전달해주는 것 
	//주소가 아닌 값을 넘겨주는 것이기에 넘겨준 값에 뭔 짓거리를 해도 본판은 변하지 않는다.
	//반면 call by reference 는 주소값 자체를 넘겨주는 것이기에 가져간 함수가 뭔 짓거리를 하면 본판도 영향을 받는다.

}