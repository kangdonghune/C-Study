#include <iostream>

using namespace std;

void main()
{
	//헝가리안 표기법
	//변수명에 자료형을 표기해주는 방식 int i변수명 와 같이
	int i = 0;
	char ch = 0;
	bool b = 0;
	short n = 10;
	long l = 100;
	long long ll = 1000;
	float f = 10.0f;
	double d = 10.0;
	long double ld = 10.0;

	//연산자
	//단항 연산자(피연산자 1개) 이항 연산자 (피연산자 2개) 삼항 연산자 (피연산자 3개) 그 외에 산술 연산, 대입연산, sizeof연산자, 대소비교연산자, 논리연산자, 비트단위, 쉬프트 등등
	//산술 연산자 + - * / %(나머지)-대표적으로 홀짝 나눌 때 쓰기 좋다
	//대입연산자 =
	//sizeof 연산자 피 연산자의 크기를 반환해주는 연산자. int 같은 경우는 바이트 크기 반환. 참고로 이거 함수 아님
	//쓸일이 많으니 기억을 해두자
	//대소 비교 연산자 > <  >= <= == !=  bool형식으로 반환.
	//논리 연산자 &&(and) 둘 다 참이면 참 ||(or) 둘 중 하나만 참이어도 참 !(not) 참이면 거짓으로 거짓이면 참으로 
	//and 연산자의 경우 앞에 거짓이 먼저 온다면 뒤는 더 이상 연산하지 않는다. 논리연산과 대소비교 연산을 같이 쓰니 이 점은 명심하자.
	//|| 연산자는 앞에가 참이면 뒤에 오는 걸 연산을 안 한다. 이거도 굉장히 중요하다.
	//비트단위 연산자. & and 둘 다 1일 때만 1  | or 둘 중 하나만 1이면 1 ~ not 1은 0으로 0은 1로(참고로 모든 비트가 1이면 -1이다) ^ xor 두 비트 중 하나만 1이면 1을 반환하고 나머지는 0을 반환. 이걸 대체 왜 쓰는 걸까 싶긴하다.
	//대표적으로 플래그 연산에 쓰인다. 플래그 연산을 쓰면 1 바이트로도 8개의 bool 변수를 쓰는 것과 같은 쓰임이 가능하다. 장점 메모리 절약은 좋으나 단점은 가독성이 곱창난다.
	
	//그 외에도 간단한 출석 프로그램을 제작한다고 고려하면 출석 은 출 결 둘 중 하나기에 boolean을 쓰면 된다,
	//근데 bool은 1바이트인데 0 또는 1만 표시하기에 8비트 중 1비트만 쓴다. 데이터 측면에서 손해.
	//이를 개선하고자 32비트 int로 표현하고 각 비트당 1일의 출석을 0 또는 1로 표현한다면 4바이트로 31일을 전부 표현할 수 있다.( 기존의 bool으로 표현한다면 31바이트)
	//이후 해당 출석을 표시한 바이트와 pow(2,n)를 &연산 하는 것으로 해당일에 출석했으면 1이 나와 이를 통해 확인 가능해진다.
	//이런 잔대가리는 대체 어떻게 떠올리는 건지 미친놈들.
	//쉬프트 연산자 << >>  이걸 언제 쓰이냐. 2의 n 승을 구할 떄 좋다. 굳이 곱셈이나 나눗셈을 두고 이걸 쓰면 좋은 이유는 비트단위로 연산하기 떄문에 속도가 빠르다. << n 을 하면 2의 n  >> n 을 하면 2의 -n 
	//축약 연산자. += -= *= /= |=(A |= B == A= A|B) <<= >>=  등
	//증감 연산자 ++ --  전위 후위
	//삼항 연산자  조건 ? 참 : 거짓 ex ) bool b = (10 == 20) ? 조건이 참이면 해당 값 반환  : 조건이 거짓이면 해당 값 반환

	int ia = 10;
	cout <<sizeof(ia) << endl;

	int ib = 1;
	cout << (true && (ib = 1)) << endl;
	cout << "ib= " <<ib << endl;
	cout << (true && (ib -= 1)) << endl; //대입의 경우에는 피연산자의 결과 값이 0이면 거짓, 그 외의 값이면 참이 된다.
	cout << "ib= " << ib << endl;
	cout << (false && (ib += 1)) << endl;
	cout << "ib= " << ib << endl;

	cout << (10 & 8) << endl;

	int ic = 1 << 3; // 1 = 0001  << 연산자는 모든 비트를 좌측 또는 우측으로 민다. 이 경우는 좌측으로 3칸 밀기 0001 -> 1000
	ic = ic >> 3; 
	cout << "ic= " << ic << endl;

	signed int itest = 0b0000000000000000000000000000001;
	cout << "itest = " << itest << endl;
	itest = itest >> 1;
	cout << "itest = " << itest << endl;

	int isome;
	cin >> isome; //cout이 콘솔창을 통한 출력이라면 cin은 콘솔창을 통한 입력
	cout << isome << endl;
}



