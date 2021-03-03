#include <string>
#include <iostream>
#include <vector>
#include <random>
using namespace std;

//문제 1.
//void main() {
//	int a = 12, b = 2;
//	//a는 월 b는 일 일 떄 a월 b일의 요일을 구하시오
//	//해당 년도는 윤년. 1월 1일은 금요일이다.
//	//금1토2일3월4화5수6목0 
//
//	//1. a달 까지 각 달의 일수를 다 더한다.
//	//2. 그 다음의 a달의 총 일수에서 b일만큼을 뺸 값을 위의 값에서 뺀다.
//	//3. 나온 결과값을 7로 %하면 나머지값에 따라 요일이 정해진다. 
//
//
//	int Month[] = {0, 31,29,31,30,31,30,31,31,30,31,30,31 }; //생각하자 인덱스는 0부터 시작한다.
//	int date = 0;
//	string answer = "";
//
//	for (int i = 0; i < a; i++)
//	{
//		date += Month[i+1];
//	}
//	date -= Month[a] - b; //해당 월의 일수 계산. 1월 때문에
//	int day = date % 7; //day 요일 date는 366일 중 특정일 1월 1일은 1일 2월8일은 60일
// 
//	//1월 1일 a 1 b1  date 31  > 31 -(31-1) > 1 
//	//2월 8일 a 2 b 8 date 31+ 29 > 60- (29-8)> 39%7 =4 
//
//	switch (day)
//	{
//	case 0:
//		answer = "THU";
//		break;
//	case 1:
//		answer = "FRI";
//		break;
//	case 2:
//		answer = "SAT";
//		break;
//	case 3:
//		answer = "SUN";
//		break;
//	case 4:
//		answer = "MON";
//		break;
//	case 5:
//		answer = "TUE";
//		break;
//	case 6:
//		answer = "WED";
//		break;
//	defalut:
//		answer = "error";
//		break;
//
//	}
//
//	cout << answer;
//
//}

//문제 2 특정 수 n 의 제곱근이 양의 정수이면 해당 (제곱근+1)^2를 반환하고 
//양의 정수가 아니면 -1 반환하도록 하라
//n는 1~50000000000 사이의 무작위 수.
int main()
{
	srand(50000000);
	long long n = rand();
	int ianswer;

	int iSquare = sqrt(n);// sqrt(수) 제곱근
	if ((int)iSquare == iSquare)
	{
		ianswer = pow(iSquare + 1, 2);
		cout << "n: " << n << endl;
		cout << "n의 제곱근: " << iSquare << endl;
		cout << "반환값: " << ianswer << endl;
		return pow(iSquare + 1, 2); //pow(a,b) =a^b //return 하면 break를 한 것처럼 빌드를 종료한다. 
	
	}
	else {
		ianswer = -1;
		cout << "n: " << n << endl;
		cout << "n의 제곱근: " << iSquare << endl;
		cout << "반환값: " << ianswer << endl;
		return -1;
	}
	cout << "n: " << n << endl;
	cout << "n의 제곱근: " << iSquare << endl;
	cout << "반환값: " << ianswer << endl;

}