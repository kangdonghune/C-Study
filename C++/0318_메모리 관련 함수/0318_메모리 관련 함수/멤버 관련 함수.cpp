#include <iostream>

using namespace std;

int main()
{
	int iA;
	memset(&iA, 0, sizeof(int)); //메모리를 초기화할 떄 주로 사용되는 함수. 내가 두번째 인자로 넘겨준 value값은 1바이트 단위로 값을 초기화한다.
	cout << iA << endl;
	//1바이트 단위로 초기화되다보니 다루기 어려워 대부분 0초기화의 목적으로 쓰인다.
	//이경우는 주소안에 들어있는 바이너리 코드 자체를 단순 초기화이기 떄문에 내부적으로 포인터를 가지고 있는 경우 이런 식의 초기화는 문제를 만든다.
	//string 같은 경우. 단순 포인터 변수만 가지고 있으면 갠춘한데 포인터 변수를 초기화해서 가지고 있는 경우면 주소떄문에 문제가 발생된다.
	//해당 변수가 가지고 있는 모든 인자의 값이 0이 되는데 동적 할당된 포인터의 주소도 0초기화가 되면 그를 이용하는 내부 함수들도 터지기 마련이다.
	
	int iArr[5]{ 1,2,3,4,5 };
	int iArr2[5]{ 1,2,3,4,7 };
	int iPlayerArr[5]{};
	memcpy(iPlayerArr, iArr, sizeof(iArr));//바이너로 코드로 단순 대입. 메모리대 메모리 복사. 일반적인 복사보다는 빠르다. 비표준
	
	for (int i = 0; i < size(iPlayerArr); i++)
	{
		cout << iPlayerArr[i] << endl;
	}

	memmove(iPlayerArr, iArr2, sizeof(iArr)); //메모리 대 메모리 복사는 똑같다. memcpy는 다이렉트로 집어넣는 방식. 
	//memmove는 임시로 버퍼를 만들어 데이터를 옮긴다음에 버퍼에서 대상으로 옮김. 속도가 좀 느리다. 표준
	
	//memcpy 와 memmove의 차이는 memcpy의 경우 복사가 즉각적으로 일어난다.
	//이에 따라 memcpy를 하는 도중에 그 자체가 복사하는 배열에 영향을 준다면 복사값이 예상과 다르게 나올 수 있다.(https://m.blog.naver.com/PostView.nhn?blogId=sharonichoya&logNo=220510332768&proxyReferer=https:%2F%2Fwww.google.com%2F)
	//자기자신을 복사하여 자기자신의 시작주소 다음 인덱스부터 붙여넣을 경우 memcpy는 시작주소에 있던 값이 반복되어 채워진다.
	//반면 memmove는 임의 공간 버퍼에 복사할 내용을 다 밀어넣은 후 한 번에 집어넣기에 복사하고자 하는 배열에 변화를 주는 복사에서도 문제 없이 작동한다.


	for (int i = 0; i < size(iPlayerArr); i++)
	{
		cout << iPlayerArr[i] << endl;
	}
}