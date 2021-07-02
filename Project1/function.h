#pragma once
#include "GameDefine.h"

#pragma region Avoid Block
typedef struct {
	int x;
	int y;
	int act;
}Block;

typedef struct {
	int x;
}Block_Player;

int block_width;

Block block[SCR_WIDTH/2];
Block_Player player;
#pragma endregion

#pragma region EndGame
typedef struct {
    int x;
    int y;
    char* image;
    int width;
    int height;
}Object, * p_Object;

int EndGameScore;
bool IsGame;
bool Player_Bullet_Reload;

Object User;
p_Object Enemy[EndGame_Max_Enemy];

p_Object P_Bullet_Array[MAX_BULLETS];
#pragma endregion
//랜덤 코인 전역변수
int rnd_dice;
int rnd_coin;

bool GAMEEND;

//제작 전역변수
int lv_2;
int lv_3;
int createany;
int news;

int minigamecount;
int day;
int hydro, oxy, carb;
int hydro2, oxy2, carb2;
int hydro3, oxy3, carb3;
int rocket;
int spacesuit;
int OddEvencheck;
int hoctemp;
int DAN;
int rsswap;

// 색상
enum {
    BLACK,
    DARK_BLUE,
    DARK_GREEN,
    DARK_SKYBLUE,
    DARK_RED,
    DARK_VOILET,
    DAKR_YELLOW,
    GRAY,
    DARK_GRAY,
    BLUE,
    GREEN,
    SKYBLUE,
    RED,
    VIOLET,
    YELLOW,
    WHITE,
};


void gotoxy(int x, int y);
void HideCursor();
void EntryStory();
void init(); // 초기화 함수
int menuDraw(); // 메인메뉴 그리기 함수
void menuTitwleDraw();
int keyControl();
int mainDraw();
void infoDraw();
void startDraw();
int Dice();
int minigameDraw();
void gamemainDraw();
int Coin(); // 동전 앞뒤	
void RSP(); // 가위바위보 
int RSPgameDraw();
int DicegameDraw();
void DicemainDraw();
int hocDraw();
void hocmainDraw();
void Block_init();
int Block_iskeydown(int key);
void Block_create();
void Block_move();
void Block_delete();
int Block_contain_player();
void Block_move_player();
void Block_print_map(int score);
void Block_Avoid(); // 게임 실행 함수
void spaceship();
void setColor(unsigned short text);
void DayAlter(int day);
int coingameDraw();
void coinmainDraw();
void NextSleep();
int NextmainDraw();
void NextgameDraw();
void EndGame_Main();
void EndGame_Init();
void EndGame_Draw();
void EndGame_Enemy();
void EndGame_Enemy_Create();
void EndGame_Enemy_Move(int n);
void EndGame_Enemy_Delete(int n);
void EndGame_Player();
void EndGame_Player_Controll();
void EndGame_Player_Bullet();
void EndGame_Bullet_Create();
void EndGame_Bullet_Move(int n);
void EndGame_Bullet_Delete(int n);
void EndGame_Collision_Enemy_Bullet();
void EndGame_Collision_Enemy_Player();
void onetwothree();
void create();
int lv3();
int lv2();
int creategameDraw();
int createnextDraw();
void OddEvendote(int num);
void frontbackdote(int num);
void anvil();
void hammer();
void anvilhammer();
void endlosesin();
void endsuccedsin();
void AilenBeam();
void Delivery();
void Water();








int creategameDraw();
int createnextDraw();
void OddEvendote(int num);
void frontbackdote(int num);
void anvil();
void hammer();
void anvilhammer();
void hiddenEnding(int n);
void ChckHiddenEnd();

void hydroBomb();
void oxid();
void earth_death();
void no_money();
void Ending_TItle();









