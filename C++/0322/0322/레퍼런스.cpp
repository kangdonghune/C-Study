#include <iostream>

using namespace std;

//call by value - 값복사에 의한 호출
//call by reference -레퍼런스,참조자에 의해 호출
//call by pointer,adress - 포인터,주소로 호출


void Swap(int& rNum1, int& rNum2)
{
	int temp = rNum1;
	rNum1 = rNum2;
	rNum2 = temp;
}

char* Insert()
{
	char szName[32];
	cin >> szName;
	int iSize = strlen(szName);
	char* pName = new char[iSize];
	strcpy_s(pName, iSize, szName);
	return pName; // 이런 식으로 동적 할당한 배열을 넘겨줄 때는 포인터가 필요하다.
}
//
//void Insert(int* pA, int iA)
//{
//	pA = &iA; 
//}
// 포인터가 nullptr일 때 해당 포인터를 매개변수로 받아와서 값을 변경해줘도 해당 함수가 끝나는 순간 매개변수의 포인터는 사라진다,
// 메인함수의 pA= nullptr 매개변수 pA는 똑같이 nullptr의 주소를 가진 포인터 변수에서 iA의 주소를 값는 포인터 변수로 변경됨.
// 문제는 함수가 끝나는 순간 변경된 iA의 주소를 메인함수의 pA로 전달이 안된다. 그렇기에 이 방식은 메인의 포인터에 전달을 못해준다는 문제가 있다.
// 기존의 포인터는 값을 가지고 있으면 함수에서 변경 시 해당 원본 주소에도 변경이 일어나 저장되고 함수가 끝나도 메인함수의 포인터가 변경된 원본을 가리키기 때문에 변화가 저장되었음.


void Insert(int** ppA, int* iA)
{
	cout << ppA << endl;
	*ppA = iA; //ppA = &pA *ppA = *(&pA) 즉 포인터 변수 자체의 주소의 역참조 = 포인터 변수가 가지는 가지는 값.
	//메인함수 pA = nullptr 에서 nullptr 이었던 값을 *(&pA)로 접근 &iA로 변경.
	//이 방식으로 하면 nullptr 이었던 포인터에도 값을 변경해서 저장해줄 수 있다.
}
void Insert(int*& rA, int iA)
{
	rA = &iA; // pA = nullptr -> &iA;
}
//포인터 변수에 또 다른 rA라는 별명을 지어줌,
//rA = &iA를 하면 메인함수의 pA도 nullptr에서 &iA 값이 들어간다.(레퍼런스는 별도의 주소를 할당하고 값을 받는 게 아니고 말 그대로 해당 변수의 주소값을 그대로 쓰기에 이게 가능)


int Add(const int&a, const int&b)
{
	return a + b;
}
int main()
{
	////참조-메모리에 접근하는 방식
	////간접참조-포인터. 주소값에 접근해서 원본값에 접근
	////직접참조-레퍼런스.
	//int iA = 10;
	//int iB = 30;
	////int& rA = 10;// 레퍼런스에는 직접적으로 상수 값을 넣지 못한다. 또한 nullptr 초기화도 불가하다. 다만 자료형 앞에 const를 붙이면 가능은 하다.
	////처음 참조대상이 정해져 있어야한다.
	//int& rA = iA;
	//rA = 20; //값변경 가능. iA의 값이 변경.
	//cout << rA << endl;
	//cout << &iA << endl;
	//cout << &rA << endl; //두 변수의 주소값이 같네.
	////애초에 레퍼런스라는 변수는 주소를 할당받지 않는다. 즉 레퍼런스 변수의 크기는 0이다. 
	////이건 별명이다. 라고 생각하자. 해당 변수의 또 다른 이름.

	//int 코난 = 0;
	//int& 명탐정 = 코난;
	////이러면 명탐정으로도 접근할 수 있다.
	////주로 외부 함수의 매개변수에서 쓰인다.

	//cout << sizeof(iA) << endl;
	//cout << sizeof(rA) << endl; //rA의 크기가 아니고 iA의 크기다.

	//Swap(iA, iB);
	//cout << iA << endl;
	//cout << iB << endl;

	//rA = iB; //이건 레퍼런스의 주소를 바꿔주는 게 아니고 iA의 값을 IB의 값으로 바꿔준다는 뜻이다.
	//한 번 참조한 대상은 절대 바뀌지 않는다. 해당 레퍼런스 변수가 소멸하기 전까지.

	//포인터가 쓸 필요가 없어지진 않는다.
	//포인터 쓸 곳이 따로 레퍼런스 쓸 곳이 따로 있다.
	//포인터 같은 경우는 참조하는 주소값을 변경 가능하다는 점에서 주소값을 때마다 바꿔줘야 할 때 쓰면 좋을듯.

	//이중포인터 대신에 쓸 수도 있다.
	//int** 변수 -> int*& 변수명으로 하면 같은 방식으로 사용 가능. 이 부분은 자습시간에 구현 해볼 것.

	int iA = 10; // int& rA = iA; // iA의 주소값을 그대로 가지고 주소값이 가지는 값을 반환.
	int& rA2 = iA;
	int* pA = nullptr; 
	int*& rA = pA; // 포인터 pA의 역참조값을 가리키는 주소를 가지고 역참조 값을 반환.
	Insert(&pA, &iA);
	cout << pA << endl;
	cout << *pA << endl;


	//int a = 10;
	//int b = 20;
	//int iTotal = Add(a, b);
	//cout << iTotal << endl;

	//int iTotal = Add(10, 20); // 이 경우는 리터널 상수라서 안 된다.
	//근데 레퍼런스 앞에 const를 붙이면 된다.
	//리터널 상수는 임시 메모리. const를 붙이면 해당 임시메모리의 주소에 별명을 붙이는 것.(const를 붙여서 변수 값 변경 불가로 설정)
	//리터널 상수이기에 값 변경 자체는 안 된다.

	
}