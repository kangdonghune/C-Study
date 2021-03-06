#include <iostream>
using namespace std;

//함수 오버로딩
//함수를 재정의하는 문법 c++ 부터 출시
//같은 함수명으로 여러 함수를 정의하는 것. 매개 변수나 반환 값의 차이만 두는 방식.
//인자의 개수나 타입으로 호출할 함수를 결정.
//반환타입으로는 함수 호출에 영향을 주지 않는다.
//마찬가지로 변수명으로도 호출을 구분을 가질 수 없다.
//별도의 오버로딩이 없을 경우 묵시적 형변환이 이루어지는데 이를 방지하고자 오버로딩을 타입별로 해두면 같은 상황에서 여러 호출이 이루어질 수 있기 때문에 컴파일 에러에 걸린다.
//디폴트 매개변수를 걸어두면 모호성 문제가 발생할 수 있으니 잘 고려하고 걸어두자.


int Add(int a, int b)
{
	return a + b;
}

float Add(float a, float b)
{
	return a + b;
}

int main()
{
	cout << Add(3, 2) << endl;
	cout << Add(3.f, 2.f) << endl;
}