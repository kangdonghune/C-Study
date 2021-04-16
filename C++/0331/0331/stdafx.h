// stdafx.h : 자주 사용하지만 자주 변경되지는 않는
// 표준 시스템 포함 파일 또는 프로젝트 관련 포함 파일이
// 들어 있는 포함 파일입니다.
//

#pragma once

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>
#include <iostream>
using namespace std;


// TODO: 프로그램에 필요한 추가 헤더는 여기에서 참조합니다.
extern int g_iValue;// extern을 붙여주면 cpp에 상관없이 모든 cpp에서 해당 전역 변수 접근 가능.
//static 변수와의 차이점은 static은 cpp에 종속적이라 한 cpp에서 변수 값을 수정해도 다른 cpp의 static 변수값에 영향을 주지 못한다.
//static 변수는 각 cpp마다 별도로 생성.
