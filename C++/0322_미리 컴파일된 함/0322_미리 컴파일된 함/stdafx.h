// stdafx.h : 자주 사용하지만 자주 변경되지는 않는
// 표준 시스템 포함 파일 또는 프로젝트 관련 포함 파일이
// 들어 있는 포함 파일입니다.
//

#pragma once //중복 참조 방지
#ifndef CALC_H //처음 들어올 떄만 함수 정의를 해주고 중복되서 들어올 때는 CALC가 define 되어 있기에 함수가 정의되지 않는다.
#define CALC_H
//함수정의
#endif // !CALC_H 이 방식이 정석에 가까우니 이런 방식을 습관화 들이자.
//예를 들어 stdafx.h 가 여러번 include 되거나 하면 선언이 반복되며 함수의 중복 정의가 발생해 오류가 발생한다.
//이런 식으로 define 가드를 안 해주면 헤더 순서 문제로 머리 터지는 경우가 많다고 하니 유의하자.

//미리 컴파일 된 헤더. 빌드 시간 단축.
//다만 여기 있는 것들 중에 하나라도 변경이 되면 전부 재빌드 후 실행하게 된다. 그러니 자주 변경되지 않는 것들만 넣자.
#include "targetver.h"

#include <stdio.h>
#include <tchar.h>
#include <iostream>
using namespace std;
//이렇게 하면 다른 cpp에서 iostream이나 namespace를 선언하지 않아도 stdafx.f 만 #include하면 추가된다.



// TODO: 프로그램에 필요한 추가 헤더는 여기에서 참조합니다.
