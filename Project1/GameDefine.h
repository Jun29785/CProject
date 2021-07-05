#pragma once
#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include <mmsystem.h>
#pragma comment(lib,"winmm.lib")

#define SCR_HEIGHT 36
#define SCR_WIDTH 96
#define UP 0
#define DOWN 1
#define SUBMIT 4 // 선택 ( 스 페 이 스 바 )
#define ENTER 5 // 선택 (  E N T E R )
#define NUM1 101
#define NUM2 102
#define NUM3 103
#define NONE 1000
#define STORYNUM 9 // 스토리 개수
#define STORYMAX 85 // 글자수 최대
#define BlockMaxNum 30
#define MAX_BULLETS 7
#define EndGame_WIDTH 70
#define EndGame_HEIGHT 40
#define EndGame_Max_Enemy 50