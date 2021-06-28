#pragma once
#include "GameDefine.h"


// Avoid Block
typedef struct {
	int x;
	int y;
	int act;
}Block;

typedef struct {
	int x;
}Player;

int block_width;

Block block[SCR_WIDTH/2];
Player player;

int minigamecount;
int day;
int hydro, oxy, carb;
int OddEvencheck;
int hoctemp;
int DAN;

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
void menuTitleDraw();
int keyControl();
int mainDraw();
void infoDraw();
void startDraw();
int Dice();
int minigameDraw();
void gamemainDraw();
void Coin(); // 동전 앞뒤	
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
void Block_print_map();
void Block_Avoid(); // 게임 실행 함수
void spaceship();
void setColor(unsigned short text);
void DayAlter(int day);
int coingameDraw();
void coinmainDraw();
void NextSleep();
int NextmainDraw();
void NextgameDraw();











