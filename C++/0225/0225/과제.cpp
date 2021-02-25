#include <iostream>
#include <stdio.h>

using namespace std;

void main()
{
	//전제조건은 지금 너네가 배운 내용만 사용할 것. 분기문, 반복문, 함수 등등등.사용 금지.

	////문제1 국어 영어 수학 점수를 입력 받고 평균과 총점 구하고 출력하기 
	cout << "문제1 국어 영어 수학 점수를 입력 받고 평균과 총점 구하고 출력하기" << endl;
	cout << "" << endl;
	double dKorean, dEnglish, dMath;
	cout << "국어 성적을 입력하시오." << endl;
	cin >> dKorean;
	cout << "국어 점수는" << dKorean << "점입니다." << endl;
	//printf("국어 점수는 %lf점입니다.\n", dKorean);
	cout << "영어 성적을 입력하시오." << endl;
	cin >> dEnglish;
	cout << "영어 점수는" << dEnglish << "점입니다." << endl;
	//printf("영어 점수는 %lf점입니다.\n", dEnglish);
	cout << "수학 성적을 입력하시오." << endl;
	cin >> dMath;
	cout << "수학 점수는" << dMath<< "점입니다." << endl;
	//printf("수학 점수는 %lf점입니다.\n", dMath);
	cout << "평균 성적은" << (dKorean+dEnglish+dMath)/3 << "점 입니다." << endl;
	cout << "총점은 " << (dKorean + dEnglish + dMath) << "점입니다." <<endl;
	cout << "" << endl;

	////문제2 10000 미만의 정수를 입력받아 각 자리수 분리해서 출력하기 
	cout << "문제2 10000 미만의 정수를 입력받아 각 자리수 분리해서 출력하기 " << endl;;
	cout << "" << endl;
	int i;
	cin >> i;
	//만약 입력값이 10000보다 클 경우
	i = (i >= 10000) ? i % 10000 : i; // 방법 1-만을 넘는 자리대는 제거한다.
	cout << "입력값:" << i << endl;
	cout << " 천의 자리: " << i/1000 << endl; //1000으로 나눈 값.
	cout << " 백의 자리: " << (i/100)-((i/1000)*10) << endl; //100으로 나누면 천의 자리까지 포함됨. 추가적으로 천의 자리 값*10을 해서 그러한 문제 해결
	cout << " 십의 자리: " << (i%100)/10 << endl; // 입력값을 100으로 나눈 값의 나머지를 10으로 나누어 자리수 얻음.
	cout << " 일의 자리: " << i % 10 << endl; //입력값을 10으로 나눈 나머지는 1의 자리의 값이 된다.
	cout << "" << endl;


	////문제3 두 변수의 값 맞바꾸기 
	cout << "문제3 두 변수의 값 맞바꾸기 " << endl;
	cout << "" << endl;
	int ia = 25;
	int ib = 55;
	int iswap;
	cout << "a = " << ia << " b = " << ib << endl;
	cout << "" << endl;
	cout << "-----swap-----" << endl;
	cout << "" << endl;
	iswap = ia;
	ia = ib;
	ib = iswap;
	cout << "a = " << ia << " b = " << ib << endl;
	cout << "" << endl;

	//문제4 완전그래프 점의 갯수를 입력 받고 선의 갯수를 출력하는 코드 구현 . hint: 정점이 n개인 무방향 그래프에서 최대의 간선 수 : n(n-1)/2개
	cout << "문제4 완전그래프 점의 갯수를 입력 받고 선의 갯수를 출력하는 코드 구현 " << endl;
	cout << "" << endl; 
	int iPoint, iLinecount;
	cin >> iPoint;
	cout << "점의 개수는 " << iPoint << "개 입니다." << endl;
	cout << "선의 개수는 " << iPoint*(iPoint-1)/2 << "개 입니다." << endl;

}