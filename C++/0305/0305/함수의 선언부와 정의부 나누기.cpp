#include <iostream>
using namespace std;
//함수는 선언부와 정의부를 나눌 수 있다.
//컴파일러는 코드를 위에서부터 읽어오는데 코드 순서가 맞지 않더라도 상단에 해당 함수의 선언만 해두면 함수에 대한 인식이 있기에 컴파일 오류가 생기지 않는다.
//타입 함수명(); 함수명 뒤에 세미콜론을 붙여두면 해당 함수에 대한 선언이 이루어진다. 추후 아래에서 정의를 따로 해줘야 한다.
//이를 이용하면 함수 순서상의 문제로 발생하는 오류를 해결할 수 있다.
//장점은 기능의 분석과 흐름 파악이 용이해진다.
//선언부에 커서를 올려두고 f11을 누르면 해당 함수 정의부로 이동한다.

//디폴트 매개변수. c++문법. 매개변수에 디폴트 값을 지정해줄 ㅅ 있다.
// int BuyDrink (int iCash, int iDrink = 400); 등과 같이
//정의부에는 안 적어도 오류가 발생하지 않는다. 선언부에서 디폴트 매개변수 값을 정의했는데 선언부에 또 적으면 재정의로 인한 오류가 발생한다.
//그러니 정의부에는 주석으로 디폴트 매개변수값을 적어주자.
//디폴트 매개변수는 반드시 우측 끝에서부터 삽입을 해야한다. 그렇지 않을 경우 에러발생
//ex) int Buy(int a, int b = 100) 가능 int Buy (int a = 100, int b) 는 불가능.

int main()
{
	
}