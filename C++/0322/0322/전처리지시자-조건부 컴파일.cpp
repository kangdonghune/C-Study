#include <iostream>
#define PI 3.141592
//#define BADCOM // 만약 컴이 좋지 않으면 맵을 불러오지 않고 플레이어만 불러온다.
using namespace std;

int main()
{
	//조건부 컴파일 -조건에 따라 컴파일 결정
#if 0 
	cout << "전처리 시점에서 거짓이면 실행 안함" << endl;
	//전처리 시점에서 조건 확인.
	//변수와 연동해서 쓰기는 힘든 게 변수 생성은 컴파일 단계이기 떄문에 적용이 안된다. ㄱ
	//그래서 매크로 상수, 함수 등으로 조건 설정.보통 잘 안쓰인다.
#endif

#ifdef PI // 만약 매크로가 정의되어 있다면 수행을 해라.
	cout << "PI가 정의되어 있음" << endl;
#endif // PI // 만약 매크로가 정의되어 있다면 수행을 해라. #조건부 컴파일은 시작과 endif까지가 범위다. 반드시 endif가 선언되야 한다.
	//치트키 쓸 때 자주 쓰인다.
	//뭔가 나에게 맞춰 작업을 해야할 때도 설정할 수 있다.

#ifdef _DEBUG //디버그 모드라면 실행. 기본적으로 깔려있음. 디버그와 릴리즈 차이는 디버그는 개발 릴리즈는 배포.

#endif // _DEBUG //디버그 모드라면 실행. 기본적으로 깔려있음. 디버그와 릴리즈 차이는 디버그는 개발 릴리즈는 배포.

#ifndef BADCOM //이것이 정의되어 있지 않다면 실행.
	#define BADCOM //더 이상 중복되어 맵을 불러오지 않도록 BADCOM을 정의해주고
	cout << "맵을 불러옵니다." << endl; //맵 불러오기 실행.
#endif // !BADCOM //이것이 정의되어 있지 않다면 실행.


}