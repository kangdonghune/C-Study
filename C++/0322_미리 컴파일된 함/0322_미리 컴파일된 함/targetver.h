#pragma once //비표준이지만 보다 간단하게 해당 헤더가 한 번만 정의되도록 해준다. 하지만 호환성을 위해 헤더가드를 사용해주는 쪽이 좋다. 
#ifndef CALC_H //처음 들어올 떄만 함수 정의를 해주고 중복되서 들어올 때는 CALC가 define 되어 있기에 함수가 정의되지 않는다.
#define CALC_H
	//함수정의
#endif // !CALC_H

// SDKDDKVer.h를 포함하면 최고 수준의 가용성을 가진 Windows 플랫폼이 정의됩니다.

// 이전 Windows 플랫폼에 대해 응용 프로그램을 빌드하려는 경우에는 SDKDDKVer.h를 포함하기 전에
// WinSDKVer.h를 포함하고 _WIN32_WINNT 매크로를 지원하려는 플랫폼으로 설정하십시오.

#include <SDKDDKVer.h>
