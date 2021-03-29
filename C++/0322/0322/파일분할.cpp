#include <iostream>
#include "Calculator.h"
using namespace std;

int main() 
{
	//파일 분할
	//헤더와 cpp는 한 세트. 헤더는 메뉴판. 함수의 선언부를 두는 역할. 어떤 함수, 변수가 있다고 알려줌,
	//cpp는 실체 함수의 정의.
	//헤더와 cpp의 이름을 맞춰주자.
	int iA = 10;
	int iB = 20;
	
	cout << Add(iA, iB) << endl;
	cout << Sub(iA, iB) << endl;
}