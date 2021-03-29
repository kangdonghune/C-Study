#include <iostream>

using namespace std;

int main()
{
	////동적할당
	////런타임 시점에서 결정
	////c 때 쓰던 함수들. 실제 쓰이진 않는데 면접에 자주 나온다. malloc, calloc 함수
	//int size;
	//cin >> size;
	//int* ptr = (int*)malloc(sizeof(int) * size); malloc 자체는 크기만 주고 해당 크기가 어떤 타입형인지는 미정. 따라서 앞에 형변환으로 타입도 지정해준다.
	////void 포인터는 데이터 보관용. 그 자체로는 타입이 없기에 쓰지를 못한다. 역참조하여 쓰기 불가.
	////애는 단순히 공간을 할당만 해주는 역할. 어디 쓸 지는 고려를 안 한다.
	////런타임 시점에서 크기 설정 가능.
	////현재는 12바이트 할당.
	//*ptr = 12;
	//cout << *ptr << endl;
	////할당을 해지하는 함수
	//free(ptr); //해당 힙 영역을 제거해라.
	////free(ptr); 이걸 뎅글링 포인터. 지운거를 또 지운다는 거.
	////참고로 해당 공간 자체를 지운 게 아니고 해당 공간의 값만 지운거다. 그래서 포인터 자체가 가지고 있는 주소값으로  접근은 가능한데 굉장히 위험한 접근이다
	////왜냐면 해당 주소에 다른 값이 할당되엇을 경우 해당 값을 변경시켜버리면 충돌이 난다.
	////당장은 안 터지는데 언젠가 터진다는 게 문제다. 비정기 터짐이라서 문제를 확정짓기가 힘들다.
	////free 함수는 포인터가 가지고 있는 주소값에 접근해 해당 값을 제거하는 거. 포인터가 가지고 있는 주소를 건들지는 않는다.
	//ptr = nullptr;
	////싹 밀어버리고 나서는 ptr 주소값도 nullptr로 초기화 해주자.
	//ptr = (int*)calloc(size, sizeof(int)); //해당 바이트를 몇 배로 만들지 정도의 차이, 자동 0초기화 malloc 과 다를 게 없다.
	//free(ptr);
	//ptr = nullptr;
	////동적 할당 시 주의사항
	////동적할당된 메모리의 주소값을 잃어버리지 않도록 주의하자.

	//NULL 과 nullptr 차이는 NULL은 0으로 인식되기에 0으로 구분하는 경우 걸린다는 문제가 발생. 반면 nullptr

	//int* ptr1 = (int*)malloc(sizeof(int));
	//int* ptr2 = ptr1;
	//cout << ptr1 << endl;
	//cout << ptr2 << endl;
	//free(ptr1);
	//ptr1 = nullptr;
	//cout << ptr1 << endl;
	//cout << ptr2 << endl; 
	////위에서 참조해두면 ptr1 주소가 바뀌어도 ptr2는 원래 ptr1의 주소를 계속 가지고 있는다.4
	//이경우 뎅글링 포인터가 발생한 상황이다. 이런 경우를 고려하여 할당해제를 할 때는 해당 대상을 참조하는 모든 포인터를 해제해주는 것을 신경써줘여한다.


	//c++ new 연산자. c와 차이는 함수냐 연산자냐 차이
	int* ptr4 = new int;//형변환 필요가 없다. 자료형 자체를 명시.
	//ptr4 = nullptr;
	*ptr4 = 12;
	cout << *ptr4 << endl;
	cout << ptr4 << endl;
	int* ptr5 = ptr4;
	delete ptr4;
	cout << ptr4 << endl;
	cout << ptr5 << endl; // delete 되어 ptr4의 값은 자동 변경되었지만 ptr의 값을 참조하고 있던 ptr5는 그대로다. 이 경우 ptr5를 통해 delete된 주소에 접근하게 되어 문제 발생
	ptr4 = nullptr;
	//*ptr4 = 13;
	//cout << ptr4 << endl; //여기서는 값 대입 자체가 안된다. delete 한 것에 간섭하는 순간 멈춰버린다.
	//cout << *ptr4 << endl;
	//delete를 하는 순간 뎅글링포인터를 하는 포인터가 가지고 있던 주소값을 자동으로 임의로 변경해버린다.
	//이러면 뎅글링 포인터가 안 생길거 같은데 ptr4를 참조하고 있던 또 다른 포인터가 있을 경우 해당 포인터를 nullptr로 변경을 안 해줄 경우
	//똑같이 뎅글링 포인터가 발생된다.
	//int s = 2;
	//int* ptr5 = new int[s]; // 동적배열
	//ptr5[0] = 1;
	//cout << ptr5[0] << endl;
	//delete[] ptr5; //배열 지울 떈 배열임을 명시.

	if(ptr4) // nullptr은 false로 인식이 된다
	{
		cout << "nullptr은 true로 인식된다";
	}
}