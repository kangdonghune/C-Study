#include <iostream>
#include <stdio.h>

using namespace std;
//성적들을 int형으로 하면 평균값도 나누는 과정에서 정수형으로 나오기에 소수 부분이 잘리는 문제가 발생한다.
//이 떄 이용할 수 있는 게 형변환이 있다.
//묵시적 형변환-사용자가 형변환을 명시하지 않으면 묵시적 형변환이 일어난다. int a = 10.f 라고 하면 float 10.f 가 int 형식으로 형변환 된다.
//명목적 형변환-사용자가 명시하는 것. int j = (int)3.14f or int(3.14f)
//형변환 우선순위 
// long double > double > float > long long > long = int > short > char > bool 데이터 손실을 고려한 순서.
// 이를 이용하면 평균 = (int 점수합)/ 3.f 를 하면 묵시적 형변환을 통해 우선순위인 float로 자동 형변환이 되어 계산이 되고 대입이 된다.
//수정안
// 점수 자체는 실수로 할 필요성이 적으니 int 형식으로 하고 평균을 계산하는 부분에서만 형변환하여 사용하는 방향으로.

float Average(int a, int b, int c)
{
	return (a + b + c) / 3.f;
}

float Total(int a, int b, int c)
{
	return a + b + c;
}

void InputScore()
{
	cout << "문제1 국어 영어 수학 점수를 입력 받고 평균과 총점 구하고 출력하기" << endl;
	cout << "" << endl;
	int iKorean = 0, iEnglish = 0, iMath = 0;

	cout << "국어 성적을 입력하시오." << endl;
	cin >> iKorean;
	//printf("국어 점수는 %lf점입니다.\n", dKorean);
	cout << "영어 성적을 입력하시오." << endl;
	cin >> iEnglish;
	cout << "영어 점수는" << iEnglish << "점입니다." << endl;
	//printf("영어 점수는 %lf점입니다.\n", dEnglish);
	cout << "수학 성적을 입력하시오." << endl;
	cin >> iMath;
	cout << "수학 점수는" << iMath << "점입니다." << endl;
	//printf("수학 점수는 %lf점입니다.\n", dMath);
	cout << "평균 성적은" << Average(iKorean, iEnglish, iMath) << "점 입니다." << endl;
	cout << "총점은 " << Total(iKorean, iEnglish, iMath) << "점입니다." << endl;
}


	////문제2 10000 미만의 정수를 입력받아 각 자리수 분리해서 출력하기 


	//굳이 변수로 만들어 줘야 했을까 했는데 1의 자리부터 변수로 만드는 방식이 다음 변수를 만드는 게 편리할 듯
	//그리고 하드 코딩은 해서 좋을 게 없다
	//수정안 위처럼 천의자리 뺴고 10 곱하고 이런 것보다 (i%구하고자 하는 자리대보다 한 자리 대 큰 값)/구하고자 하는 자리대 로 하는 게 날 듯
	//백의 자리 = (i%1000)/100.
void Classification() {
	cout << "문제2 10000 미만의 정수를 입력받아 각 자리수 분리해서 출력하기 " << endl;;
	cout << "" << endl;
	int i;
	cin >> i;
	//만약 입력값이 10000보다 클 경우
	i = (i >= 10000) ? i % 10000 : i; // 방법 1-만을 넘는 자리대는 제거한다.
	cout << "입력값:" << i << endl;
	cout << " 천의 자리: " << i / 1000 << endl; //1000으로 나눈 값.
	cout << " 백의 자리: " << (i / 100) - ((i / 1000) * 10) << endl; //100으로 나누면 천의 자리까지 포함됨. 추가적으로 천의 자리 값*10을 해서 그러한 문제 해결
	cout << " 십의 자리: " << (i % 100) / 10 << endl; // 입력값을 100으로 나눈 값의 나머지를 10으로 나누어 자리수 얻음.
	cout << " 일의 자리: " << i % 10 << endl; //입력값을 10으로 나눈 나머지는 1의 자리의 값이 된다.
	cout << "" << endl;
}




	////문제3 두 변수의 값 맞바꾸기 
void Swap(int a, int b) {
	cout << "문제3 두 변수의 값 맞바꾸기 " << endl;
	cout << "" << endl;
	int iswap;
	cout << "a = " << a << " b = " << b << "\n" << endl;
	cout << "-----swap-----" << "\n" << endl;
	iswap = a;
	a = b;
	b = iswap;
	cout << "a = " << a << " b = " << b << endl;
	cout << "" << endl;
}
	

	//문제4 완전그래프 점의 갯수를 입력 받고 선의 갯수를 출력하는 코드 구현 . hint: 정점이 n개인 무방향 그래프에서 최대의 간선 수 : n(n-1)/2개

int GetLines(int iPoint)
{
	int result = iPoint*(iPoint - 1)/2;

	return result;
}


void HowManyLines() 
{
	cout << "문제4 완전그래프 점의 갯수를 입력 받고 선의 갯수를 출력하는 코드 구현 " << endl;
	cout << "" << endl;
	int iPoint, iLinecount;
	cin >> iPoint;
	iLinecount = iPoint*(iPoint - 1) / 2;
	cout << "점의 개수는 " << iPoint << "개 입니다." << endl;
	cout << "선의 개수는 " << GetLines(iPoint) << "개 입니다." << endl;

}
	

void main()
{
	InputScore();
	Classification();
	Swap(4, 25);
	HowManyLines();
}