#include <iostream>

using namespace std;

void main()
{
	//변수와 자료형. 변수는 값을 보관하기 위해서 쓴다.
	//변수명을 지을 때는 알파벳이 먼저 와야 한다. 12a 안 됨 . a12 됨.
	//변수명에는 _,$ 말고는 특수부호를 쓰지 못한다.
	//기본적으로 제공하는 문법은 변수명으로 넣을 수 없다.


	int i = 0; //이 형태는 변수 선언과 동시에 초기화 한 형태. 되도록 선언과 동시에 초기화하는 습관을 들이자.
	int b;
	b = 10; //선언과 초기화를 분리시킨 형태.
	cout << b << endl;
	cout << i << endl;
	cout << "hello world2" << endl;

}