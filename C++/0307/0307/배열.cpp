#include <iostream>
using namespace std;

// int* pArr 로 하면 배열을 매개변수로 넘겨주면 해당배열의 첫 주소를 받아온다. 이후 이를 배열처럼 쓸 수 있기도 함. pArr[i] 처럼.
// 매개변수로 Array(int pArr[]) 로 매개변수를 넘겨줄 수 있다. 근데 이것도 배열을 넘겨주는 게 아니고 포인터 변수를 넘겨주네?
// c언어는 함수 호출 시 배열의 저장된 값을 전달하는 게 아니고 주소를 넘겨준다
void RenderArray(int pArr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << pArr[i] << endl;
	}
}


int main()
{
	//유사한 목적의 변수를 여러 개 선언하고 싶을 때 사용.
	//배열 선언 방법
	//타입명 배열이름 [배열크기];
	//배열 크기에는 상수값이 들어가야 한다.
	int intArray[5] = {}; // 모든 배열 원소를 0으로 초기화. 또는 괄호 안에 순서대로 값을 집어넣는 것으로 해당 값으로 초기화 가능.
	int intArary2[5]{}; //유니폼 초기화. 위와 같은 방식으로 c++11 부터 등장해서 사용.
	int intArray3[] = { 1,2,3,4,5 }; //이런 식으로 하면 초기화하는 중괄호 안의 원소 개수에 따라서 배열크기가 자동으로 설정됨.
	intArray[0] = 20;
	//배열명[몇 번째 배열, index]; 에 접근. index는 0부터 시작하기에 마지막 인덱스는 항상 배열 크기보다 1작다.
	intArray[1]= 23;
	
	for (int i = 0; i < 5; i++)
	{
		cout << intArray[i] << endl;
	} 
	cout << size(intArray) << endl;

	//size를 쓸 수 도 있고 
	int isize = sizeof(intArray) / sizeof(intArray[0]); //전체 배열 크기 / 한 개 원소 크기 = 배열의 길이, 크기

	//지금 내용들은 정적배열이다.
	//정적과 동적-대부분 컴파일의 시점으로 보냐, 런타임 시점이냐
	//컴파일은 빌드할 때 모든 게 결정되냐 런타임-실행하는 와중에 결정되냐의 차이.
	//정적 배열은 빌드할 때 크기가 다 결정되고 이후 변경 못한다.

	for (int i = 0 ; i < size(intArray); i++)
	{ 
		cout << &intArray[i] << endl;
	}


	//주소를 보면 알 수 있듯이 배열은 연속된 메모리 공간에 할당된다.
	//일반 변수는 연속적으로 선언한다고 해서 연속된 메모리 공간에 할당되는 건 아니다.

	cout << intArray << endl;  //배열 이름으로 출력하면 해당 배열의 첫번째 원소의 주소값이 뜬다.
	cout << &intArray << endl; //배열의 이름은 상수 포인터 형식이구나. int* const intArray 인 느낌.
	//배열의 첫 주소를 반환하기 때문에 그 값을 함부로 바꿀 수가 없다.
	//첫 주소인 0번쨰 인덱스의 값은 변경 가능한 걸 보면 const int* const iArr는 아니다.
	//포인터와 배열
	int iArr[5] = {};
	int* ptr = iArr; //배열의 이름은 상수 포인터
	*ptr = 3; 
	cout << iArr[0] << endl;
	cout << ptr << endl;
	cout << ptr + 1 << endl; // 타입형이 int타입의 주소를 받았기에 +1만 자동으로 4바이트 만큼의 크기를 벌려준다.
	cout << iArr + 1 << endl; // 타입형이 int타입의 주소를 받았기에 +1만 자동으로 4바이트 만큼의 크기를 벌려준다.
	cout << ++ptr << endl;
	cout << ++ptr << endl;
	//참고로 ++iArr 는 안 된다. 위와 달리 이 방식은 값 자체를 변경하기 떄문이다.
	//반면 상수 포인터가 아닌 ptr 은 ++ptr이 된다.
	//[]와 포인터 연산에는 + - 만 존재한다.
	//포인터 연산은 연속된 메모리 공간일 때만 가능할 것. 즉 배열 형식일 경우에만 사용할 것.
	//포인터 연산을 할 경우 현재 내가 가지고 있는 주소타입형의 크기 만큼 더하거나 빼준다.
	//포안터 연산을 하는데 딱히 제약은 없지만 내가 알고 있는 범위세먼 사용해야한다.

	RenderArray(intArray, size(intArray));
}