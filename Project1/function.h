#pragma once
#include "GameDefine.h"

struct SMALL_RECT {
	SHORT Left;
	SHORT Top;
	SHORT Right;
	SHORT Bottom;
};

// Avoid Block
typedef struct {
	int x;
	int y;
	int act;
}Block;

typedef struct {
	int x;
}Player;

Block block[SCR_WIDTH];
Player player;

int hydro, oxy, carb;
int OddEvencheck;
int hoctemp;
int minigamecount1;
int minigamecount2;
int minigamecount3;

void gotoxy(int x, int y);
void HideCursor();
void EntryStory();
void init(); // 초기화 함수
int menuDraw(); // 메인메뉴 그리기 함수
int keyControl();
int mainDraw();
void infoDraw();
void startDraw();
int Dice();
int minigameDraw();
void gamemainDraw();
void Coin(); // 동전 앞뒤	
int RSP(); // 가위바위보 
int RSPgameDraw();
void RSPmainDraw();
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












