#include <iostream>

using namespace std;

int main()
{
	int iA;
	memset(&iA, 0, sizeof(int)); //메모리를 초기화할 떄 주로 사용되는 함수. 내가 두번째 인자로 넘겨준 value값은 1바이트 단위로 값을 초기화한다.
	cout << iA << endl;
	//1바이트 단위로 초기화되다보니 다루기 어려워 대부분 0초기화의 목적으로 쓰인다.
	int iArr[5]{ 1,2,3,4,5 };
	int iArr2[5]{ 1,2,3,4,7 };
	int iPlayerArr[5]{};
	memcpy(iPlayerArr, iArr, sizeof(iArr));//바이너로 코드로 단순 대입. 메모리대 메모리 복사. 일반적인 복사보다는 빠르다. 비표준
	//이경우는 주소안에 들어있는 바이너리 코드 자체를 단순 초기화이기 떄문에 내부적으로 포인터를 가지고 있는 경우 이런 식의 초기화는 문제를 만든다.
	//string 같은 경우. 단순 포인터 변수만 가지고 있으면 갠춘한데 포인터 변수를 초기화해서 가지고 있는 경우면 주소떄문에 문제가 발생된다.
	for (int i = 0; i < size(iPlayerArr); i++)
	{
		cout << iPlayerArr[i] << endl;
	}

	memmove(iPlayerArr, iArr2, sizeof(iArr)); //메모리 대 메모리 복사는 똑같다. memcpy는 다이렉트로 집어넣는 방식. 
	//memmove는 임시로 버퍼를 만들어 데이터를 옮긴다음에 버퍼에서 대상으로 옮김. 속도가 좀 느리다. 표준
	
	for (int i = 0; i < size(iPlayerArr); i++)
	{
		cout << iPlayerArr[i] << endl;
	}
}