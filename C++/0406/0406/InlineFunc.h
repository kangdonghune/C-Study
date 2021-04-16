#pragma once
class CInlineFunc
{
public:
	CInlineFunc();
	~CInlineFunc();
public:
	inline void Render() // 사용자가 인라인 키워드를 붙인다고 해서 무조건 인라인 함수가 되는 게 아니다. 
	{
		cout << "이 것이 인 라인 함수" << endl;
	} //Render를 호출하는 시점에서 해당 내용일 해당 부분으로 삽입되는 느낌. 함수처럼 기능하니 함수라고 하지 실제 함수는 아니다.
	//매크로 함수의 장점을 취하고 단점을 뺀 방식
	//호출에 소모되는 비용이 없다. 바로 대치 되는 식이기에.
	//긴 문장을 꾸리기 힘들고 디버깅이 어렵다는 단점을 극복.
	//인라인화가 결정되는 것은 사용자가 아니라 컴파일러가 결정한다.
	//인라인을 붙이는 건 이 것이 인라인화가 될 거 같을 경우 요청하는 정도. 명시적으로 붙이기도 하고.
	//한계는 매크로 함수처럼 자료형의 제한을 벗어나지는 못했다는 점이다.
	int Get_A(); //이런 함수의 경우는 컴파일러가 자동으로 인라인화를 해준다.
	int Add(int a, int b);
	void Print(int(*get)());

	//인라인함수가 일반 함수가 되는 경우
	//1.함수 포인터(주소값)가 필요한 경우. 2. 재귀함수에 호출되는 경우.
	//()는 함수 호출 연산자. 그걸 빼고 cout << endl; 을 하면 해당 함수의 주소값을 보여준다. 함수도 주소값이 부여된다.
	//보이드 포인터로 해당 주소를 받을 수 있다.
	//반환 변수타입 (*변수명)(인자 개수) = 함수명;
	//변수명(); 하면 해당 함수가 호출된다.
	int(*Func)() = nullptr;
	int(*AddFunc)(int, int);

	//재귀함수.
	//함수 안에서 해당 함수를 부르는 것. 재귀함수는 반드시 내부에서 탈출 문구를 가져야 한다.

	void SelfCall(int Count)
	{
		cout << "나를 부른다." << Count-- << "번째" << endl;
		if (Count < 1)
			return;
		SelfCall(Count);
		cout << "재귀함수 아래 부분은 최종 재귀부터 실행된다." << Count << "번째 호출" << endl;
	}

private:
	int m_iA;
};

