#pragma once
#ifndef Field_h
#define Field_h

/*
필드 입장 시
1. 플레이어 정보 출력
2. 몬스터 생성 후 몬스터 정보 출력
3. 싸울 지 여부 물어봄. -> 1 싸운다 (플레이어 선빵) 몬스터 생존 시 몬스터 반격. 처음 질문으로 2. 도망친다 몬스터 선빵 생존 시 마을 귀환 사망 시 경험치 초기화 후 마을귀환 . 마을 입장 시 풀컨디션회복

+
몬스터 사냥을 통해 플레이어의 경험치가 최대 경험치를 돌파할 경우 레벨업 하며 풀 컨디션 회복

*/


class CPlayer;
class CMonster;
class CEasy;

class CField
{
public:
	CField(CPlayer* pPlayer);
	~CField();
public:


public:
	CEasy* m_pEasy;
};


#endif // !Field_h
