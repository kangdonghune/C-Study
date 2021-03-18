#include <iostream>
#include <string>  //.h 가 붙은 애들은 C 때 나온 애들

using namespace std;

int main()
{
	string str1 = "Hello World!"; //스트링이란 클래스는 기본적으로 28바이트를 차지하고 있다.
	cout << str1 << endl;
	str1 = "change";
	cout << str1 << endl;
	str1 = "hello+";
	str1 += "world";
	cout << str1 << endl;
	string str2 = str1;
	cout << str2 << endl;
	cout << (str1 == str2) << endl;
	cout << str2.size() << endl;
	cout << str1.length() << endl;//둘다 문자길이 반환.

	const char* pstr = str1.c_str(); //const char*타입으로 반환. string 타입을 char 문자배열이 받을 수 있도록 넘겨주는 함수.
	cout << pstr << endl;
	char ch1[255] = "char to string"; //반대로 넘겨줄 때는 대입 연산자만 쓰면 된다. 연산자 함수 오버로딩 되어있다.
	str1 = ch1;
	cout << str1 << endl;
	cout << sizeof(str1) << endl;
	//근데 strcmp, strlenm strcpy_s, strcat_s 등이 쓸모 없는가하면 그것도 아닌게 나중에 언제든 원시문자열을 쓸 일이 생긴다.
	//이러한 이유로 원시문자열에 익숙해지기 위해 지금 당장 쓰지 않는 걸 추천한다.
}