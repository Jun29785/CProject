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

int block_width = SCR_WIDTH/2;

Block block[SCR_WIDTH/2];
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
void init(); // �ʱ�ȭ �Լ�
int menuDraw(); // ���θ޴� �׸��� �Լ�
int keyControl();
int mainDraw();
void infoDraw();
void startDraw();
int Dice();
int minigameDraw();
void gamemainDraw();
void Coin(); // ���� �յ�	
int RSP(); // ���������� 
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
void Block_Avoid(); // ���� ���� �Լ�












