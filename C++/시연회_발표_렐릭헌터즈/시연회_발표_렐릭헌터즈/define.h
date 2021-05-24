#pragma once

//기본 window 크기
#define WINCX 800
#define WINCY 600


//함수 성공 여부
#define Function_Fail 0
#define Function_Pass 1

//오브젝트 상태
#define DEAD		0b00000000000000000000000000000001
#define READYDEAD	0b00000000000000000000000000000010
#define WALK		0b00000000000000000000000000000100
#define RUN			0b00000000000000000000000000001000
#define MELEE		0b00000000000000000000000000010000
#define EGG			0b00000000000000000000000000100000
#define EGGCRACK	0b00000000000000000000000001000000
#define IDLE		0b11111111111111111111111111111110

//플레이어 캐릭터 INFO

#define PLAYER_ICX 114
#define PLAYER_ICY 94
#define PLAYER_SPEED 7.0f
#define PLAYER_HITBOXCX 60
#define PLAYER_HITBOXCY 94


//몬스터 정보
#define M_TURTLE_CX 49
#define M_TURTLE_CY 80
#define M_TURTLE_DEADCX 114
#define M_TURTLE_DEADCY 80

//보스
#define Boss_CX 228
#define Boss_CY 188
#define Boss_HitX 105
#define Boss_HitY 118


//gameobject INFO
#define GUN_ICX 80 //머신건
#define GUN_ICY 80
//총알
#define Bullet_ICX 60 //머신건 총알
#define Bullet_ICY 60
#define Pistol_bC  30
#define Machgun_bC 46
#define Bossgun_bC 46
//총알
#define Grenade_CX 22
#define Grenade_CY 22
#define Grenade_BoomCX 266
#define Grenade_BoomCY 250
#define Boss_GunCX 120
#define Boss_GunCY 120
#define PISTOL_C 60
#define SHOTGUN_C 64


//item
#define Pistol_itemCX 60
#define Pistol_itemCY 22

#define MachinGun_itemCX 60
#define MachinGun_itemCY 24

#define ShotGun_itemCX 64
#define ShotGun_itemCY 22

#define GrenadeBox_CX 50
#define GrenadeBox_CY 74





//main_logo
#define MainLogo_CX 545
#define MainLogo_CY 243
#define MainArrow 36
#define Enterbar_CX 600
#define Enterbar_CY 52
#define StageEffectCX 1070
#define StageEffectCY 194
#define StageEffectRendX 800
#define StageEffectRendY 145





//mapobject INFO
#define TILECX 768
#define TILECY 768
#define Celling_CX  128
#define Celling_CY  150
#define Wall_SideCX  64
#define Wall_SideCY  128
#define Celling_ImgCX  144
#define Celling_ImgCY  144
#define Wall_SideImgCX  64
#define Wall_SideImgCY  128
#define Portal_CX 90
#define Portal_CY 26
#define PushButton_CX 30
#define PushButton_CY 38

//UI
#define PLAYER_HPFACECX 93
#define PLAYER_HPFACECY 99
#define PLAYER_HPFACERENDX 62
#define PLAYER_HPFACERENDY 66

#define  PLAYER_HPBARCX 114
#define  PLAYER_HPBARCY 30
#define  PLAYER_HPBARRENDX 114
#define  PLAYER_HPBARRENDY 44

#define BOSS_HPFACECX 120
#define BOSS_HPFACECY 92
#define BOSS_HPFACERENDX 62
#define BOSS_HPFACERENDY 66

#define  BOSS_HPBARCX 114
#define  BOSS_HPBARCY 30
#define  BOSS_HPBARRENDX 620
#define  BOSS_HPBARRENDY 44



//color
#define bmi_BackGround RGB(255, 0, 255)