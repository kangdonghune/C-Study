#include <iostream> //#은 전 처리 지시자 . 전처리 단계에서 실행. include 는 포함하다. iostream 입출력 관련된 라이브러리를 포함하겠다.
/*

*/
using namespace std;//std라는 이름 공간을 사용하겠다. 같은 이름의 메소드의 중복 오류를 방지하기 위해 사용. standard 의 약자. 표준. 마소에서 제공하는 기능 대부분이 포함. ex) cout

namespace A
{
	void Show()
	{
		cout << "A가 사용하는 쇼 기능" << endl;
	}
}

namespace B
{
	void Show()
	{
		cout << "b가 사용하는 쇼 기능" << endl;
	}
}

using namespace B; //using namespace를 남용하지 말자. 이왕이면 네임스페이스 연산자로
void main() //void 는 반환하는 값이 없다. main 은 함수의 이름. 진입점 함수. 시스템에서 호출. 반드시 단 하나만 존재해야 한다. ()외부에서 이 함수를 호출할 때 외부의 데이터를 받아올 수 있는 공간. 비어있으면 안 받겠다.
{
	// :: (네임스페이스 연산자) 
	A::Show();
	Show();
	cout << "hello world" << endl; //cout = 콘솔창을 통해 출력하겠다.  endl = end lind 문자를 개행할 때 쓰는 것. cout endl 둘 다 객체다.; 은 이 줄이 끝났다고 알리는 것.
}