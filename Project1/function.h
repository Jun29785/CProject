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
void RSP(); // ���������� 
int DicegameDraw();
void DicemainDraw();
void CreateBlock();
void PrintBlock();
void MoveBlock();
void AvoidBlock();
int hocDraw();
void hocmainDraw();