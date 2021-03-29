#pragma once //중복되어 호출 방지.

//함수의 선언부. 즉 어떤 함수가 있는 지에 대한 영역
int Add(int a, int b);
int Sub(int a, int b);
//헤더에 함수를 선언하면 두 번 정의하게 되는 문제가 있다. 해결법이 없는 건 아니다.