#pragma once
#include "GameDefine.h"

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













