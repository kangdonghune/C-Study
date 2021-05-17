#pragma once

//기본 window 크기
#define WINCX 800
#define WINCY 600


//함수 성공 여부
#define Function_Fail 0
#define Function_Pass 1

//오브젝트 상태
#define DEAD	0b00000000000000000000000000000001
#define WALK	0b00000000000000000000000000000010
#define RUN		0b00000000000000000000000000000100
#define MELEE	0b00000000000000000000000000001000
#define IDLE	0b11111111111111111111111111111110

//플레이어 캐릭터 INFO

#define PLAYER_ICX 114
#define PLAYER_ICY 94
#define PLAYER_SPEED 10.0f

//gameobject INFO
#define GUN_ICX 60
#define GUN_ICY 24
#define Bullet_ICX 46
#define Bullet_ICY 30

//mapobject INFO
#define TILECX 128
#define TILECY 128
#define Celling_CX  64
#define Celling_CY  64
#define Wall_SideCX  32
#define Wall_SideCY  64
#define Celling_ImgCX  144
#define Celling_ImgCY  144
#define Wall_SideImgCX  64
#define Wall_SideImgCY  128


//color
#define bmi_BackGround RGB(255, 0, 255)