#include <iostream>
#include <string>
using namespace std;

int main()
{
	char name[6] = { 'j','u', 's', 'i', 'n' , '\0'};
	char name2[6] = "jusin"; //문자열 특성 상 문자 뒤에는 null 문자(\0)가 붙는다.(끝났다는 걸 알려주기 위해서) 그렇기에 글자 수보다 1개를 추가해서 배열크기를 잡아야 한다.
	//name2 = "hello"; //이거 절대 안 된다. 절대 쓰지마라. 이건 초기화한 주소의 주소값을 변경하겠다는 건데 배열의 시작 주소 값을 hello 가 있는 주소값으로 변경하겠다는 인식인데 포인터값으로 변경한다는 거다.
	//"hello" 는 문자열 상수로 데이터 어딘가에 저장되어 있다.
	//초기화 이후엔 크기를 늘리거나 줄일 수 없다. 
	//반드시 기억해야 할 것은 문자열은 기본적으로 문자의 끝에 null 문자를 삽입한다는 특성이 있다.
	//일반 배열은 이름을 출력하면 주소값이 출력되지만 문자배열은 주소가 아니라 문자열이 출력된다.
	cout << name << endl;
	cout << &"hello" << endl;

	//배열의 데이터 읽기 및 쓰기
	name[0] = 'J'; //인덱스를 통해 특정 원소의 접근,변경은 가능하다.
	cout << name << endl;
	
	char names[32] = {'a','b','c'};
	cin >> names;
	cout << names << endl; //일반 배열과 달리 인덱스를 지정해서 넣는 게 아니라 배열의 이름만 넘겨주면 한 번에 다 넣을 수 있다.
	//이 방식으로 하면 기존의 있던 원소들을 덮어 쓴다.
	//포인터 사용방법은 일반배열과 동일
	char* ptr = name;
	cout << ptr << endl; //똑같이 문자열 출력
	
	const char* pTest = "jusin"; //배열을 선언 후 대입이 아니라 문자열 상수 자체를 대입시켜도 똑같이 기능할 수 있다.
	//문자열 포인터를 사용할 떄는 const를 붙여주는 게 문제발생을 줄인다.
	cout << pTest << endl;
	pTest = "game"; 
	const char* pTest2 = pTest;
	cout << pTest2 << endl; 
	//포인터로 하면 초기화 이후에도 값 변경이 가능하다.
	//다만 문자배열과 포인터의 차이점은 읽기가 아니고 쓰기가 가능하냐이다.
	//문자배열은 공간을 받아서 배열을 만들어기에 특정 인덱스의 문자를 변경 가능하다.
	//반면 포인터는 데이터 영역에 있는 상수를 읽어오는 것이기에 해당 상수를 수정하는 게 불가하다.
	//"문자열" 은 데이터 영역에 저장되어 있기에 어디서 접근하든 같은 주소값을 가지며 특정 함수 종료 시 사라지는 값이 아니다.
	//

	char Text[5] = "Text";
	const char* pText = Text; //const 가 타입 앞에 붙으면 주소값 변경 가능 변수명 앞에 붙으면 주소가 가리키는 값 변경 가능
	pText = name;
	cout << Text << endl;
	cout << pText << endl;
	
	//기본적으로 문자를 다루는 함수를 만들어 놨다.
	//strlen, strcmp, strcpy_s, strcat_s

	cout << strlen(Text) << endl;//null문자를 제외한 순수 문자열의 길이 반환.
	//sizeof 와 차이점은 strlen은 null 문자는 포함하지 않지만 sizeof는 순수문자열의 길이가 아닌 배열의 전체적인 크기를 출력. 또한 포인터 형식일 때 sizeof는 주소크기인 4를 반환하나  strlen()은 배열의 순수문자열 크기를 반환한다.
	cout << strcmp(name, Text) << endl;// 두 문자열을 비교. 두 문자열이 같을 경우 0 다를 경우 그 외의 숫자를 반환.
	strcpy_s(name, Text);//strcpy는 지금은 사용하지 않는다. 앞에 있는 문자배열에 뒤에 있는 문자열 포인터 값을 복사해준다.
	cout << name << endl;
	cout << sizeof(name) << endl; //부족한 공간은 null 문자로 채워준다. 반대로 작은 공간에 큰 문자열을 복사해 넣으면 에러가난다.
	//strcpy_s(a,b) 에서 앞의 a에 포인터 값이 들어가면 함수 자체에서 해당 배열의 길이를 구할 수가 없다. 그래서 별도로
	//오버로드된 strcpy_s(복사값을 넣어줄 대상, 넣고자 하는 크기, 넣고자 하는 문자열)를 이용해야 한다.
	//보통 main보다 넘겨받은 외부 함수에서 쓰는 경우가 많다보니 위 경우가 더 많이 쓰이긴 한다.
	
	char szName[256] = "jusin";
	char* szname3 = szName;
	char szName2[10] = "gaming";
	//strcat_s(szName, szName2);// 뒤에 덧붙이는 것. 문자열 두개를 결합. (결합받을 대상, 결합하고자 하는 크기. 결합하고자 하는 대상)
	cout << szName << endl; // 마찬가지로 결합받을 대상의 크기가 총 결합한 길이보다 크기가 작다면 에러가 생긴다.
	strcat_s(szname3, strlen(szName) + strlen(szName2)+1, szName2);//두 문자열 길이 + 널문자 1개크기 만금 영역 지정,
	cout << szname3 << endl; //포인터로 주소값을 가지고 있기에 변동된 값 읽어옴.ㄴ
	//근데 이럴거면 애초에 그냥 앞에 배열 크기를 쥰내게 크게 해서 sizeof를 쓰는 게 편하다.
}