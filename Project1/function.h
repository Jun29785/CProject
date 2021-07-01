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
}Object,*p_Object;

bool Player_Bullet_Reload;

Object User;
p_Object Enemy[EndGame_Max_Enemy];

p_Object P_Bullet_Array[MAX_BULLETS];
#pragma endregion
//���� ���� ��������
int rnd_dice;
int rnd_coin;

int minigamecount;
int day;
int hydro, oxy, carb;
int hydro2, oxy2, carb2;
int hydro3, oxy3, carb3;
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
int Coin(); // ���� �յ�	
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
void onetwothree();
void create();
void OddEvendote(int num);
void frontbackdote(int num);










