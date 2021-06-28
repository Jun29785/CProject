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

// ����
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
void init(); // �ʱ�ȭ �Լ�
int menuDraw(); // ���θ޴� �׸��� �Լ�
void menuTitleDraw();
int keyControl();
int mainDraw();
void infoDraw();
void startDraw();
int Dice();
int minigameDraw();
void gamemainDraw();
void Coin(); // ���� �յ�	
void RSP(); // ���������� 
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
void Block_Avoid(); // ���� ���� �Լ�
void spaceship();
void setColor(unsigned short text);
void DayAlter(int day);
int coingameDraw();
void coinmainDraw();
void NextSleep();
int NextmainDraw();
void NextgameDraw();











