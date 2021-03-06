#include <iostream>
#include <bitset>
using namespace std;
//포인터 - 값은 주소값을 가지는 새로운 변수 생성. 별도의 메모리공간 생성. 
//참조 와 복사
//복사는 흔히 하던 대입 같은 경우.
//참조-메모리의 접근하는 방식. 
//직접 참조(reference)와 간접 참조
//직접-아무것도 거치지 않고 직접적으로 데이터 전달. int& 변수명. 으로 사용. 특정 변수의 주소값을 공유. 특정 변수의 이름만 바꾼다는 느낌.
//그렇기에 별도의 메모리공간을 생성하지 않는다. 대신 null 초기화가 안되고 초기화한 변수 외에 다른 변수로 값 변경이 안 된다. 포인터는 된다.
//간접-어떠한 대상을 통해서 데이터를 전달 <-포인터가 여기에 해당.
//포인터는 주소값을 담는다. 주소값을 통해서 원본의 값을 변경한다.
//함수를 호출하며 넘겨준 매개변수를 해당 함수를 통해 값을 변경하고 싶을 때, 원본에 영향을 줄 수 있도록 포인트 변수를 사용.

void Plus(int* a)//매개변수에도 int타입의 포인터 변수를 받겠다. 라고 표시를 해줘야 주소값을 매개변수로 받을 수 있다.
{
	++(*a);
}

void Swap(int* a, int* b)
{
	int swap = *a;
	*a = *b;
	*b = swap;

}

void main() 
{
	int i = 10;
	//Plus(i);
	//포인트 변수 선언
	//포인터 변수는 선언과 동시에 초기화 해주는 게 좋기에 null초기화를 해준다. 값을 넣어줄 게 있으면 값을 너주고
	int* ptr = NULL;
	int* ptr2 = nullptr; //포인터 값에 0을 넣어준다는 걸 명시적으로 표현한 것. 위 NULL과 같은 것.
	ptr = &i; //포인터로 지정하겠다고 타입에 표시를 해줌. * 에스크리터 연산자. 포인트 변수를 선언할 때 사용. 대입할 때는 어드레스 연산자라고 하자.
	//절대 ptr 자체가 i가 되는 게 아니다. 그저 값으로 i의 주소를 가지고 저장되는 위치는 별도의 주소를 가진다.
	//여기서는 int* ptr 이나 int *ptr이나 같은 거다. 띄어쓰기의 차이가 없다.
	*ptr = 99; 
	//포인터 변수명 앞에 * 연산자(역참조 연산자)를 붙여주면 포인터변수가 가진 값의 주소로 찾아가 거기에 대입을 한다는 의미가 된다.
	//역참조를 붙여주면 해당 포인터가 가지고 있는 주소값에 들어있는 값에 접근하게 된다.
	cout << i << endl;
	Plus(ptr);
	cout << i << endl;
	cout << *ptr << endl;
	//굳이 이런 식으로 포인터 변수를 따로 생성하기보다는 바로 &변수 식으로 전달해도 문제될 건 없다.
	Plus(&i);
	//어차피 Plus 함수에서 매개변수에 int타입의 자료형을 저장하는 주소를 받겠다. 라고 선언을 해두었기에 해당 타입에 맞는 변수의 주소를 넘겨줘도 작동한다.
	//굳이 포인터를 쓰는 이유가 있는지? 직접 주소를 넘겨주는 방식으로 하면 좀 더 간소화 할 수 있지 않을끼?
	//이유 1: 매개변수로 넘겨주는 방식에서 변수타입 설정으로 했기에 주소값을 넘겨받을 방법이 없다.
	//->그래서 포인터 타입 매개변수에 어드레스 연산자로 넘겨주나? 직접 전송은 전역 변수 뿐인가?.
	//그렇지 않다  걍 &로 바로 넘겨줘도 된다.

	//float f1 = 1.32f;
	//float f2 = 1.32;
	//double d3 = 1.32; 
	////형변환을 하면 실수는 특정 비트 뒤의 값들이 다 잘린다.(반면 인트는 앞에서부터 잘린다.)
	////그렇기에 더블을 float으로 바꾸면 소수점을 나타내는 비트가 잘려 실제 값과 오차가 커진다.
	//bool a = (f1 == d3);
	//cout << a << endl;

	//cout.precision(64);
	//cout << f2 << endl;
	//cout << d3 << endl;
	int c = i * (*ptr);
	cout << c << endl;

	//잘못된 참조
	//int* ptr3 = nullptr; 
	//*ptr3 = 20;//null 주소값에 값을 대입할 수 없다. 에러 발생.
	//cout << ptr3 << endl;
	
	//변수 주소값은 실행 때마다 바뀌기 때문에 이전 주소값으로 무엇을 하려 하면 안된다. 그렇기에 포인터 값에 대입해줄 때도 수동으로 확인한 주소값을 넣어주는 건 방지하자.


	//스왚
	int a1 = 5;
	int a2 = 10;
	Swap(&a1, &a2);
	cout << a1 << ", " << a2 << endl;


	int a = 0; int b = 1;
	const int* ptr8 = &a; //참조하는 대상의 값이 상수화 되어 포인터에서 참조대상 값 변경 불가
	//*ptr8 = 2; 참조대상 a의 값 변경 불가
	ptr8 = &b; //참조 주소를 바꾸는 건 가능
 	int* const ptr9 = &a; //주소값이 상수화 되어 주소값 변경 불가.
	*ptr9 = 3; // 참조하는 주소가 가진 값을 변경하는 건 가능
	//*ptr9 = &b; 참조하는 주소를 바꾸는 건 불가능


}