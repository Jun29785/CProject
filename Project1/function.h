#pragma once
#include "GameDefine.h"

int hydro, oxy, carb;
int OddEvencheck;
int hoctemp;
int minigamecount1;
int minigamecount2;
int minigamecount3;

int BlockNum;
typedef struct Object {
	char* image;
	int X, Y;
	int height, width;
}Object;

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
void RSP(); // 가위바위보 
int DicegameDraw();
void DicemainDraw();
void CreateBlock();
void PrintBlock();
void MoveBlock();
void AvoidBlock();
int hocDraw();
void hocmainDraw();