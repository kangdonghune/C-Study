#include <iostream>

using namespace std;

void main()
{
	//분기문- 기준을 잡아서 나눈다
	//goto, if else if else, switch
//	cout << "hello" << endl;
//	goto Down; //코드의 흐름을 내가 지정한 부분으로 이동시킴. 근데 제약이 굉장히 많다.
//	cout << "world" << endl;
//Down:
//	cout << "아아" << endl;
//	cout << "지옥을" << endl;
//UP:
//	goto UP;
//	cout << "보여줄까" << endl;

	//보면 알겠지만 실행 결과를 유추하기도 어렵고 읽기도 어렵다. 이래서 사용이 제한된다.
	//goto 는 논리없이 무작정 보내버리기 때문에 코드의 흐름,논리를 해칠 수 있다.
	//goto 문법은 회사에서 사용할 경우 사수부터 윗사람까지 보고하고 사용할 정도로 위험한 문법이다.
	//사용을 제한하는 삼대장 문법 다중상속, 프렌드, goto 중 하나.
	
	if (true)//if (조건) 조건이 참이라면 {} 안의 내용을 수행하라.
	{
		cout << "오류 테스트";
	}
	else if(true) // 위의 if 문의 조건이 false라면 else if 문의 조건을 보고 수행여부 결정
	{ }
	else{} // 위의 if else if 가 전부 생략되었을 때 수행.
	/*switch(값) case 값:   스위치 값이 case 값과 동일하다면 : 의 내용을 수행하고 아니면 생략.
	defalut는 case값이 별도로 없고 최종적으로 실행.
	각 케이스 별로 break를 안 넣어주면 case 값과 swich 값이 같이도 해당 내용 수행 후 아래 케이스를 훑어 내려간다.
	이를 원하지 않으면 케이스 별로 break를 넣어 해당 케이스 실행 후 switch문을 더 이상 수행하지 않고 나간다.
	if문만 쓰는 것과 elseif를 섞어 쓰는 것의 차이는 if문만 쓰면 조건이 전부 참이면 전부 실행되지만 elseif는 위의 문이 실행되면 조건 참거짓여부와 상관없이 실행이 안된다.

	if문이나 다른 것에서도 마찬가지지만 {} 중괄호 안에 변수를 설정하면 해당 중괄호 밖에서는 해당 변수를 쓸 수 없다.
	보통 이런 경우를 해당 지역에서만 쓰이는 변수라 하여 지역 변수라 한다.
	*/
	int ivalue = 0;
	const int i = 1;
	switch (ivalue) {
	case 'a':
		//return;
		break;
	case (bool)(i < 1) :
		cout << "걸림" << endl;
		break;
	case i-3:
		break;
	default:
		break;
	}
	//스위치 문에서의 조건은 항상 정수를 받아야 한다.
	//case 에는 항상 상수가 들어가야 한다.
	//분기를 나누기 위해선 break, return 으로 해당 케이스에 걸릴 경우 switch문을 탈출하게 해야한다.
	//break는 가장 가까운 반복문, 스위치문을 빠져나가는 용도. return은 값을 반환하고 함수 자체를 종료시킨다.
	//continue 가장 가까운 반복문을 반복 도중에 다음 반복으로 생략하는 용도
	//항상 상수로 하는 이유는 실수까지 하게 되면 부동소수점의 오차가 문제를 발생시킬 수 있기 때문이다.
	//그냥 case 안에선 변수를 생성할 수 없다.(조건에 따라 생성 여부가 결정되는 건 문제가 생길 수 있기 때문에 막아놨다.)굳이 생성하고 싶다면 case : {} 중괄호를 쓰는 것으로 해당 케이스 안으로 지역을 제한해줘야 한다.
	

}