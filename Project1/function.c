#include "Function.h"

void gotoxy(int x, int y)
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE); // 콘솔 핸들 가져오기
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(consoleHandle, pos);
	//SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void HideCursor()
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursorInfo;
	cursorInfo.dwSize = 1;
	cursorInfo.bVisible = 0;
	SetConsoleCursorInfo(consoleHandle, &cursorInfo);
}

void EntryStory()
{
	char story[][100] = {
		{"3021년 지구에는 많은 사람들이 예상했던 외계인 침공이 눈 앞에 다가왔다."},
		{"외계인들은 우리에게 목숨을 담보로 하는 한가지 제안을 했다."},
		{"외계인들의 제안은 30일간 매일 미니게임을 해서 지구를 탈출하면 되는 것이다."},
		{"외계인들이 제안한 미니게임의 규칙은 매우 간단하였다."},
		{"미니게임을 통해서 얻은 아이템을 제작하여 우주선 및 우주복을 제작하는 것이다."},
		{"하지만 제작에는 문제점이 있다. 그것은 바로 저녁에만 제작이 가능하다."},
		{"제작된 우주선과 우주복을 이용하여 30일 안에 지구를 탈출하면 된다."}
	};
	char CountNum[3][5][4] = {
		// NUM 1
		{{0,0,1,0},
		{0,0,1,0},
		{0,0,1,0},
		{0,0,1,0},
		{0,0,1,0}},
		// NUM 2
		{{1,1,1,1},
		{0,0,0,1},
		{1,1,1,1},
		{1,0,0,0},
		{1,1,1,1}},
		// NUM 3
		{{1,1,1,1},
		{0,0,0,1},
		{1,1,1,1},
		{0,0,0,1},
		{1,1,1,1}},
	};
	char Start[5][5][5] = { // START
		// S
		{{1,1,1,1,1},
		{1,0,0,0,0},
		{1,1,1,1,1},
		{0,0,0,0,1},
		{1,1,1,1,1}},
		// T
		{{1,1,1,1,1},
		{0,0,1,0,0},
		{0,0,1,0,0},
		{0,0,1,0,0},
		{0,0,1,0,0}},
		// A
		{{0,0,1,0,0},
		{0,1,0,1,0},
		{0,1,1,1,0},
		{1,0,0,0,1},
		{1,0,0,0,1}},
		// R
		{{1,1,1,1,0},
		{1,0,0,1,0},
		{1,1,1,1,0},
		{1,0,1,0,0},
		{1,0,0,1,0}},
		// T
		{{1,1,1,1,1},
		{0,0,1,0,0},
		{0,0,1,0,0},
		{0,0,1,0,0},
		{0,0,1,0,0}}
	};
	int x = 42, y = 7;
	// entrystory
	for (int i = 0; i < STORYNUM; i++) {
		for (int j = 0; j < STORYMAX; j++) {
			printf("%c", story[i][j]);
			Sleep(50);
		}
		system("cls");
	}
	// count
	for (int i = 2; i > -1; i--) {
		for (int j = 0; j < 5; j++) {
			gotoxy(x, y);
			for (int k = 0; k < 4; k++) {
				printf("%s", CountNum[i][j][k] == 1 ? "■" : "　");
			}
			printf("\n");
			y++;
		}
		Sleep(1000);
		system("cls");
		y = 7;
	}
	// start
	x = 18, y = 10;
	for (int i = 0; i < 5; i++) {

		for (int j = 0; j < 5; j++) {
			gotoxy(x, y);
			for (int k = 0; k < 5; k++) {
				printf("%s", Start[i][j][k] == 1 ? "■" : "　");
			}
			printf("\n");
			y++;
		}
		Sleep(200);
		x += 12; y = 10;
	}
	system("cls");
}

void init()
{
	system("mode con:cols=96 lines=40");
	setColor(YELLOW);
}

int menuDraw()
{
	int x = 42, y = 22;
	gotoxy(x - 2, y);
	printf("> 게임시작");
	gotoxy(x, y + 1);
	printf("게임정보");
	gotoxy(x, y + 2);
	printf("  종료  ");
	while (1) {
		int n = keyControl(); // 키보드 이벤트를 키값으로 받아오기
		switch (n) {
		case UP: {
			if (y > 22) {
				gotoxy(x - 2, y);
				printf(" ");
				gotoxy(x - 2, --y);
				printf(">");
			}
			break;
		}
		case DOWN: {
			if (y < 24) {
				gotoxy(x - 2, y);
				printf(" ");
				gotoxy(x - 2, ++y);
				printf(">");
			}
			break;
		}
		case SUBMIT: {
			return y - 22;
		}
		case ENTER: {
			return y - 22;
		}
		}
	}
}

int keyControl()
{
	FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
	char temp = getch();

	if (temp == ' ' || temp == '\r')
		return SUBMIT;
	else if (temp == 'w' || temp == 'W')
		return UP;
	else if (temp == 's' || temp == 'S')
		return DOWN;
	else if (temp == '1')
		return NUM1;
	else if (temp == '2')
		return NUM2;
	else if (temp == '3')
		return NUM3;
	else return NONE;
}

void menuTitleDraw()
{
	printf("┌─────────────┐");
	gotoxy(0, 1); printf("│    %d Day    │", day);
	gotoxy(0, 2); printf("└─────────────┘");
	gotoxy(4, 4);
	if (DAN == 0)
	{
		setColor(VIOLET);
		printf("Morning");
		setColor(YELLOW);
	}
	else if (DAN == 1)
	{
		gotoxy(5, 4);
		setColor(VIOLET);
		printf("Night");
		setColor(YELLOW);
	}
	gotoxy(18, 1);  printf("미니게임 가능 횟수 : %d", minigamecount);


	// 인벤토리 
	int x = 58, y = 0;
	gotoxy(x, y); printf("┌");
	for (int i = 0; i < 26; i++) {
		if (i == 14) {
			printf("인벤토리");
		}
		printf("─");
	}
	printf("┐");
	y++;
	gotoxy(x, y); printf("│                                  │"); y++;
	gotoxy(x, y); printf("│    수소 : %d                      │", hydro); y++;
	gotoxy(x, y); printf("│                                  │"); y++;
	gotoxy(x, y); printf("│    산소 : %d                      │", oxy); y++;
	gotoxy(x, y); printf("│                                  │"); y++;
	gotoxy(x, y); printf("│    탄소 : %d                      │", carb); y++;
	gotoxy(x, y); printf("│                                  │"); y++;
	gotoxy(x, y); printf("│                                  │"); y++;
	gotoxy(x, y); printf("│                                  │"); y++;
	gotoxy(x, y); printf("└");
	for (int i = 0; i < 34; i++) printf("─");
	printf("┘");
	gotoxy(0, 22); printf("────────────────────────────────────────────────────────────────────────────────────────────────");
	//int inventory[6][10][10] = {
	//	// 1
	//	{{1,1,1,1,1,1,1,0,0,0},
	//	{1,1,1,1,1,1,1,0,0,0},
	//	{1,1,1,1,1,1,1,0,0,0},
	//	{1,1,1,0,1,1,1,0,0,0},
	//	{1,1,1,1,1,1,1,0,0,0},
	//	{1,1,1,1,1,1,1,0,0,0},
	//	{1,1,1,1,1,1,1,0,0,0},
	//	{1,1,1,1,1,1,1,0,0,0},
	//	{1,1,1,1,1,1,1,0,0,0},
	//	{1,1,1,1,1,1,1,0,0,0}},
	//};
	//int x = 10, y = 10, sleep = 100;
	//for (int i = 0; i < 1; i++)
	//{
	//	for (int k = 0; k < 10; k++)
	//	{
	//		gotoxy(x, y);
	//		for (int j = 0; j < 10; j++)
	//			printf("%s", inventory[i][k][j] == 1 ? "■" : "　");
	//		printf("\n");
	//		y++;
	//		Sleep(sleep);
	//	}

	//	y = 10;
	//}
	//sleep += 200;
}

int mainDraw()
{
	int x = 42, y = 26;
	gotoxy(x - 2, y);
	printf("> 미니게임");
	gotoxy(x, y + 1);
	printf("  제작  ");
	gotoxy(x, y + 2);
	printf("  잠자기");
	gotoxy(x, y + 3);
	printf("  준비중  ");
	while (1) {
		int k = keyControl(); // 키보드 이벤트를 키값으로 받아오기
		switch (k) {
		case UP: {
			if (y > 26) {
				gotoxy(x - 2, y);
				printf(" ");
				gotoxy(x - 2, --y);
				printf(">");
			}
			break;
		}
		case DOWN: {
			if (y < 29) {
				gotoxy(x - 2, y);
				printf(" ");
				gotoxy(x - 2, ++y);
				printf(">");
			}
			break;
		}
		case SUBMIT: {
			return y - 26;
		}
		//case ENTER: {
		//	return y - 26;
		//}
		}
	}
	return 0;
}

void infoDraw()
{
	system("cls");
	printf("\n\n");
	printf("[조작법]\n\n");
	printf("이동 : W, S\n");
	printf("선택 : SPACE, ENTER\n");
	printf("개발자 : 이준 , 전승원 \n");
	printf("재밋게 즐겨주세요 .");
	while (1) {
		if (keyControl() == SUBMIT || keyControl() == ENTER) {
			break;
		}
	}
}

void startDraw()
{
	system("cls");
	//EntryStory();
	while (1) {
		menuTitleDraw();
		int menuCode = mainDraw();
		if (menuCode == 0 && minigamecount != 0) {
			gamemainDraw();
			//게임시작
		}
		else if (menuCode == 1) {
			// 게임정보
			infoDraw();
		}
		else if (menuCode == 2) {
			return 0; // 종료
		}
		system("cls");
	}
	//while (1) {
	//	if (keyControl() == SUBMIT || keyControl() == ENTER) {
	//		break;
	//	}
	//}

}

int Dice()
{
	int dice[6][7][7] = {
		// 1
		{{1,1,1,1,1,1,1},
		{1,1,1,1,1,1,1},
		{1,1,1,1,1,1,1},
		{1,1,1,0,1,1,1},
		{1,1,1,1,1,1,1},
		{1,1,1,1,1,1,1},
		{1,1,1,1,1,1,1}},
		// 2
		{{1,1,1,1,1,1,1},
		{1,0,1,1,1,1,1},
		{1,1,1,1,1,1,1},
		{1,1,1,1,1,1,1},
		{1,1,1,1,1,1,1},
		{1,1,1,1,1,0,1},
		{1,1,1,1,1,1,1}},
		// 3
		{{1,1,1,1,1,1,1},
		{1,0,1,1,1,1,1},
		{1,1,1,1,1,1,1},
		{1,1,1,0,1,1,1},
		{1,1,1,1,1,1,1},
		{1,1,1,1,1,0,1},
		{1,1,1,1,1,1,1}},
		// 4
		{{1,1,1,1,1,1,1},
		{1,0,1,1,1,0,1},
		{1,1,1,1,1,1,1},
		{1,1,1,1,1,1,1},
		{1,1,1,1,1,1,1},
		{1,0,1,1,1,0,1},
		{1,1,1,1,1,1,1}},
		// 5
		{{1,1,1,1,1,1,1},
		{1,0,1,1,1,0,1},
		{1,1,1,1,1,1,1},
		{1,1,1,0,1,1,1},
		{1,1,1,1,1,1,1},
		{1,0,1,1,1,0,1},
		{1,1,1,1,1,1,1}},
		// 6
		{{1,1,1,1,1,1,1},
		{1,0,1,1,1,0,1},
		{1,1,1,1,1,1,1},
		{1,0,1,1,1,0,1},
		{1,1,1,1,1,1,1},
		{1,0,1,1,1,0,1},
		{1,1,1,1,1,1,1}}
	};
	int x = 10, y = 10, sleep = 70;
	int rnd_dice = rand() % 6;
	for (int g = 0; g < 3; g++)
	{
		for (int i = 0; i < 6; i++)
		{
			for (int k = 0; k < 7; k++)
			{
				gotoxy(x, y);
				for (int j = 0; j < 7; j++)
					printf("%s", dice[i][k][j] == 1 ? "■" : "　");
				printf("\n");
				y++;
			}
			Sleep(sleep);
			y = 10;
		}
		sleep += 150;
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
	Sleep(500);
	for (int k = 0; k < 7; k++)
	{
		gotoxy(x, y);
		for (int j = 0; j < 7; j++)
			printf("%s", dice[rnd_dice][k][j] == 1 ? "■" : "　");
		printf("\n");
		y++;
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
	Sleep(1000);
	return rnd_dice;
}

int minigameDraw()
{
	system("cls");
	menuTitleDraw();
	int x = 42, y = 26;
	gotoxy(x - 2, y);
	printf(">   주사위   ( 캡슐 획득 가능 수( 1 ~ 6 )"); // 0
	gotoxy(x, y + 1);
	printf("동전던지기 ( 캡슐 획득 가능 수( 1 ~ 6 )"); // 1
	gotoxy(x, y + 2);
	printf("가위바위보 ( 캡슐 획득 가능 수( 3 ~ 8 )"); // 2
	gotoxy(x, y + 3);
	printf("블럭피하기 ( 캡슐 획득 가능 수( 1 ~ 12 )"); // 3
	gotoxy(x, y + 4);
	printf(" 돌아가기 "); // 4
	while (1) {
		int n = keyControl(); // 키보드 이벤트를 키값으로 받아오기
		switch (n) {
		case UP: {
			if (y > 26) {
				gotoxy(x - 2, y);
				printf(" ");
				gotoxy(x - 2, --y);
				printf(">");
			}
			break;
		}
		case DOWN: {
			if (y < 30) {
				gotoxy(x - 2, y);
				printf(" ");
				gotoxy(x - 2, ++y);
				printf(">");
			}
			break;
		}
		case SUBMIT: {
			return y - 26;
		}
		case ENTER: {
			return y - 26;
		}
		}
	}
}

void gamemainDraw()
{
	system("cls");
	int menuCode = minigameDraw();
	int test = menuCode;
	if (menuCode == 0) {
		hoctemp = hocDraw();
		DicemainDraw();
	}
	else if (menuCode == 1) {
		hoctemp = hocDraw();
		Coin();
	}
	else if (menuCode == 2) {
		hoctemp = hocDraw();
		RSPmainDraw();
	}
	else if (menuCode == 3) {
		Block_Avoid();
	}
}

void Coin()
{
	int coin[][7][7] = {
		// front
		{{0,0,1,1,1,0,0},
		 {0,1,1,1,1,1,0},
		 {1,1,1,2,1,1,1},
		 {1,1,2,2,2,1,1},
		 {1,1,1,2,1,1,1},
		 {0,1,1,1,1,1,0},
		 {0,0,1,1,1,0,0}},

		 // turn 1
		 {{0,0,0,0,0,0,0},
		  {0,0,1,1,1,0,0},
		  {0,1,1,1,1,1,0},
		  {1,1,2,2,2,1,1},
		  {0,1,1,1,1,1,0},
		  {0,0,1,1,1,0,0},
		  {0,0,0,0,0,0,0}},

		  // turn 2
		 {{0,0,0,0,0,0,0},
		  {0,0,0,0,0,0,0},
		  {0,0,0,0,0,0,0},
		  {1,1,1,1,1,1,1},
		  {0,0,0,0,0,0,0},
		  {0,0,0,0,0,0,0},
		  {0,0,0,0,0,0,0}},

		  // turn 3
		 {{0,0,0,0,0,0,0},
		  {0,0,1,1,1,0,0},
		  {0,1,1,1,1,1,0},
		  {1,1,1,1,1,1,1},
		  {0,1,1,1,1,1,0},
		  {0,0,1,1,1,0,0},
		  {0,0,0,0,0,0,0}},

		  //back
		  {{0,0,1,1,1,0,0},
		  {0,1,1,1,1,1,0},
		  {1,1,1,1,1,1,1},
		  {1,1,1,1,1,1,1},
		  {1,1,1,1,1,1,1},
		  {0,1,1,1,1,1,0},
		  {0,0,1,1,1,0,0}},

		  // turn 3
		  {{0,0,0,0,0,0,0},
		   {0,0,1,1,1,0,0},
		   {0,1,1,1,1,1,0},
		   {1,1,1,1,1,1,1},
		   {0,1,1,1,1,1,0},
		   {0,0,1,1,1,0,0},
		   {0,0,0,0,0,0,0}},

		   // turn 2
		  {{0,0,0,0,0,0,0},
		   {0,0,0,0,0,0,0},
		   {0,0,0,0,0,0,0},
		   {1,1,1,1,1,1,1},
		   {0,0,0,0,0,0,0},
		   {0,0,0,0,0,0,0},
		   {0,0,0,0,0,0,0}},

		   // turn 1
		  {{0,0,0,0,0,0,0},
		   {0,0,1,1,1,0,0},
		   {0,1,1,1,1,1,0},
		   {1,1,2,2,2,1,1},
		   {0,1,1,1,1,1,0},
		   {0,0,1,1,1,0,0},
		   {0,0,0,0,0,0,0}},

	};
	int x = 10, y = 10;

	int rnd_coin = rand() % 2;
	for (int g = 0; g < 3; g++) {
		for (int i = 0; i < 8; i++) {
			for (int k = 0; k < 7; k++) {
				gotoxy(x, y);
				for (int j = 0; j < 7; j++) {
					printf("%s", coin[i][k][j] == 1 ? "▣" : "　");
				}
				printf("\n");
				y++;
			}
			Sleep(70);
			y = 10;
		}
	}

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
	if (rnd_coin)
		for (int k = 0; k < 7; k++) {
			gotoxy(x, y);
			for (int j = 0; j < 7; j++) {
				printf("%s", coin[0][k][j] == 1 ? "▣" : "　");
			}
			printf("\n");
			y++;
		}
	else
		for (int k = 0; k < 7; k++) {
			gotoxy(x, y);
			for (int j = 0; j < 7; j++) {
				printf("%s", coin[4][k][j] == 1 ? "▣" : "　");
			}
			printf("\n");
			y++;
		}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);

	Sleep(1000);
}

int RSP()
{
	int rsp[3][16][13] = {
		// 주먹
		{{0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,1,0,1,0,0,0,0,0,0},
		{0,0,0,1,0,1,0,1,1,0,0,0,0},
		{0,0,0,1,0,1,0,1,0,1,0,0,0},
		{0,0,0,1,0,1,0,1,0,1,1,0,0},
		{0,0,1,1,0,1,0,1,0,1,0,1,0},
		{0,1,0,1,0,1,0,1,0,1,0,1,0},
		{0,1,0,1,1,1,1,0,1,1,0,1,0},
		{0,1,0,0,0,0,0,1,0,1,0,1,0},
		{0,1,0,0,1,1,1,0,0,0,1,0,0},
		{0,0,1,0,0,0,0,0,0,0,1,0,0},
		{0,0,0,1,0,0,0,0,0,1,0,0,0},
		{0,0,0,0,1,1,1,1,1,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0}},

		// 가위
		{{0,0,0,0,0,0,0,0,0,0,0,0,0},
		 {0,0,0,0,0,0,1,0,0,0,0,0,0},
		 {0,1,0,0,0,1,0,1,0,0,0,0,0},
		 {1,0,1,0,0,1,0,1,0,0,0,0,0},
		 {1,0,0,1,0,1,0,1,0,0,0,0,0},
		 {0,1,0,1,0,1,0,1,1,0,0,0,0},
		 {0,1,0,0,1,1,0,1,0,1,0,0,0},
		 {0,0,1,0,1,1,0,1,0,1,1,0,0},
		 {0,0,1,1,0,1,0,1,0,1,0,1,0},
		 {0,1,0,1,1,1,1,0,1,1,0,1,0},
		 {0,1,0,0,0,0,0,1,0,1,0,1,0},
		 {0,1,0,0,1,1,1,0,0,0,1,0,0},
		 {0,0,1,0,0,0,0,0,0,0,1,0,0},
		 {0,0,0,1,0,0,0,0,0,1,0,0,0},
		 {0,0,0,0,1,1,1,1,1,0,0,0,0},
		 {0,0,0,0,0,0,0,0,0,0,0,0,0}},

		 // 보
		 {{0,0,0,0,0,0,0,0,0,0,0,0,0},
		 {0,0,0,0,0,0,1,0,0,0,0,0,0},
		 {0,0,0,0,1,1,0,1,1,0,0,0,0},
		 {0,0,0,1,0,1,0,1,0,1,0,0,0},
		 {0,0,0,1,0,1,0,1,0,1,1,0,0},
		 {0,0,1,1,0,1,0,1,0,1,0,1,0},
		 {0,1,0,1,0,1,0,1,0,1,0,1,0},
		 {0,1,0,1,0,1,0,1,0,1,0,1,0},
		 {0,1,0,1,0,1,0,1,0,1,0,1,0},
		 {0,1,0,0,0,0,0,0,0,0,0,1,0},
		 {0,1,0,0,0,0,0,0,0,0,0,1,0},
		 {0,1,0,0,0,0,0,0,0,0,0,1,0},
		 {0,0,1,0,0,0,0,0,0,0,1,0,0},
		 {0,0,0,1,0,0,0,0,0,1,0,0,0},
		 {0,0,0,0,1,1,1,1,1,0,0,0,0},
		 {0,0,0,0,0,0,0,0,0,0,0,0,0}}
	};
	int x = 10, y = 5;
	int rnd_rsp = rand() % 3, sleep = 100;
	for (int g = 0; g < 3; g++) {
		for (int i = 0; i < 3; i++) {
			for (int k = 0; k < 16; k++) {
				gotoxy(x, y);
				for (int j = 0; j < 13; j++) {
					printf("%s", rsp[i][k][j] == 1 ? "■" : "　");
				}
				printf("\n");
				y++;
			}
			Sleep(sleep);
			y = 5, sleep += 50;
		}
	}

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
	for (int k = 0; k < 16; k++) {
		gotoxy(x, y);
		for (int j = 0; j < 13; j++) {
			printf("%s", rsp[rnd_rsp][k][j] == 1 ? "■" : "　");
		}
		printf("\n");
		y++;
	}
	Sleep(2000);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);

	return rnd_rsp;
}

int RSPgameDraw()
{
	system("cls");
	int x = 42, y = 26;
	gotoxy(x - 2, y);
	printf("> 주먹"); // 0
	gotoxy(x, y + 1);
	printf("가위"); // 1
	gotoxy(x, y + 2);
	printf("  보  "); // 2
	while (1) {
		int n = keyControl(); // 키보드 이벤트를 키값으로 받아오기
		switch (n) {
		case UP: {
			if (y > 26) {
				gotoxy(x - 2, y);
				printf(" ");
				gotoxy(x - 2, --y);
				printf(">");
			}
			break;
		}
		case DOWN: {
			if (y < 28) {
				gotoxy(x - 2, y);
				printf(" ");
				gotoxy(x - 2, ++y);
				printf(">");
			}
			break;
		}
		case SUBMIT: {
			return y - 26;
		}
		case ENTER: {
			return y - 26;
		}
		}
	}
}

void RSPmainDraw()
{
	system("cls");
	int menuCode = RSPgameDraw();
	int num = RSP();
	
	if (menuCode - num == 0) {
		printf("비겼습니다.");
		Sleep(1000);
	}
	else if (menuCode - num == -1 || menuCode - num == 2) {
		printf("이겼습니다.");
		Sleep(1000);
	}
	else {
		printf("졌습니다.");
		Sleep(1000);
	}
}

int DicegameDraw()
{
	system("cls");
	int x = 42, y = 26;
	gotoxy(x - 2, y);
	printf("> 홀"); // 0
	gotoxy(x, y + 1);
	printf("짝"); // 1
	while (1) {
		int n = keyControl(); // 키보드 이벤트를 키값으로 받아오기
		switch (n) {
		case UP: {
			if (y > 26) {
				gotoxy(x - 2, y);
				printf(" ");
				gotoxy(x - 2, --y);
				printf(">");
			}
			break;
		}
		case DOWN: {
			if (y < 27) {
				gotoxy(x - 2, y);
				printf(" ");
				gotoxy(x - 2, ++y);
				printf(">");
			}
			break;
		}
		case SUBMIT: {
			return y - 26;
		}
		case ENTER: {
			return y - 26;
		}
		}
	}
}

void DicemainDraw()
{
	int num;
	int count = 0;
	system("cls");
	int menuCode = DicegameDraw();
	switch (menuCode) {
	case 0:
		num = Dice();
		minigamecount--;
		if (num % 2 == 0)
		{
			printf("Win");
			switch (hoctemp)
			{
			case 0:
				hydro += num + 1;
				printf("\n수소 +%d / 현재 수소 %d", num + 1, hydro);
				break;
			case 1:
				oxy += num + 1;
				printf("\n산소 +%d / 현재 산소 %d", num + 1, oxy);
				break;
			case 2:
				carb += num + 1;
				printf("\n탄소 +%d / 현재 탄소 %d", num + 1, carb);
				break;
			}
		}
		else
		{
			printf("Lose");
		}
		break;
	case 1:
		num = Dice();
		minigamecount--;
		if (num % 2 != 0)
		{
			printf("Win");
			switch (hoctemp)
			{
			case 0:
				hydro += num + 1;
				printf("\n수소 +%d / 현재 수소 %d", num + 1, hydro);
				break;
			case 1:
				oxy += num + 1;
				printf("\n산소 +%d / 현재 산소 %d", num + 1, oxy);
				break;
			case 2:
				carb += num + 1;
				printf("\n탄소 +%d / 현재 탄소 %d", num + 1, carb);
				break;
			}
		}
		else
		{
			printf("Lose");
		}
		break;
	}
	Sleep(2500);
}

int hocDraw()
{
	system("cls");
	menuTitleDraw();
	int x = 42, y = 26;
	gotoxy(x - 2, y);
	printf("> 수소"); // 0
	gotoxy(x, y + 1);
	printf("산소");// 1
	gotoxy(x, y + 2);
	printf("탄소");
	while (1) {
		int n = keyControl(); // 키보드 이벤트를 키값으로 받아오기
		switch (n) {
		case UP: {
			if (y > 26) {
				gotoxy(x - 2, y);
				printf(" ");
				gotoxy(x - 2, --y);
				printf(">");
			}
			break;
		}
		case DOWN: {
			if (y < 28) {
				gotoxy(x - 2, y);
				printf(" ");
				gotoxy(x - 2, ++y);
				printf(">");
			}
			break;
		}
		case SUBMIT: {
			return y - 26;
		}
		case ENTER: {
			return y - 26;
		}
		}
	}
}

void hocmainDraw()
{
}

block_width = SCR_WIDTH;

void Block_init()
{
	for (int i = 0; i < block_width; i++)
		block[i].act = FALSE;

	player.x = block_width / 2;
}

int Block_iskeydown(int key)
{
	return ((GetAsyncKeyState(key) & 0x8000) != 0);
}

void Block_create()
{
	for (int i = 0; i <= block_width + 3; i++) {
		if (!block[i].act) {
			block[i].x = rand() % block_width;
			block[i].y = SCR_HEIGHT - 1;

			block[i].act = TRUE;
			return;
		}
	}
}

void Block_move()
{
	for (int i = 0; i < block_width; i++) {
		if (block[i].act) {
			block[i].y--;
		}
	}
}

void Block_delete()
{
	for (int i = 0; i < block_width; i++) {
		if (block[i].act && block[i].y < 0) {
			block[i].act = FALSE;
		}
	}
}

int Block_contain_player()
{
	for (int i = 0; i < block_width; i++) {
		if ((block[i].act) && (block[i].y < 2) && (block[i].x == player.x))
			return TRUE;
	}
	return FALSE;
}

void Block_move_player()
{
	if ((Block_iskeydown(VK_LEFT) || Block_iskeydown('a') || Block_iskeydown('a')) && player.x >= 0)
		player.x--;
	if ((Block_iskeydown(VK_RIGHT) || Block_iskeydown('d') || Block_iskeydown('D')) && player.x < block_width - 2)
		player.x++;
}

void Block_print_map()
{
	system("cls");
	for (int i = 0; i < block_width; i++) {
		if (block[i].act) {
			gotoxy(block[i].x, SCR_HEIGHT - block[i].y);
			printf("■");
		}
	}

	gotoxy(player.x, SCR_HEIGHT);
	printf("♤");

	gotoxy(0, SCR_HEIGHT + 1);
	for (int i = 0; i < SCR_HEIGHT - 7; i++)
		printf("▤");
}

void Block_Avoid()
{
	char key;
	Block_init();

	do {
		srand((int)malloc(NULL));

		Block_create();
		Block_move();
		Block_delete();

		Block_move_player();

		Block_print_map();

		Sleep(10);
	} while (!(Block_contain_player()));
}

void spaceship()
{
	int rocket[21][19] = {
		//   0,1,2,3,4,5,6,7,8,9,0,1,2,3,4
			{0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0}, // 0
			{0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0}, // 1
			{0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0}, // 2
			{0,0,0,0,0,1,1,1,1,1,1,1,0,0,0,0,0,0,0}, // 3
			{0,0,0,0,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0},//  4 헤드
			{0,0,0,0,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0}, // 5
			{0,1,0,0,1,1,1,1,1,1,1,1,1,0,0,1,0,0,0}, // 6
			{1,1,1,0,1,1,1,1,1,1,1,1,1,0,1,1,1,0,0}, // 7
			{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0},//  8
			{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0}, // 9
			{1,1,1,0,1,1,1,1,1,1,1,1,1,0,1,1,1,0,0}, // 10
			{0,1,0,0,1,1,1,1,1,1,1,1,1,0,0,1,0,0,0}, // 11
			{0,0,0,0,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0}, // 12몸체
			{0,0,0,0,0,1,1,1,1,1,1,1,0,0,0,0,0,0,0}, // 13
			{0,0,0,0,0,1,1,1,1,1,1,1,0,0,0,0,0,0,0}, // 14
			{0,0,0,0,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0}, // 15
			{0,0,0,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0}, // 16
			{0,0,0,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0}, // 17
			{0,0,0,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0}, // 18
			{0,0,0,1,0,1,0,1,1,1,0,1,0,1,0,0,0,0,0}, // 19
			{0,0,0,1,0,1,0,1,1,1,0,1,0,1,0,0,0,0,0}, // 20
	};
	int x = 29, y = 0;
	int color = 2;
	for (int i = 0; i < 21; i++) {
		gotoxy(x, y);
		setColor(WHITE);
		for (int j = 0; j < 19; j++) {
			if (i == 20 && j == 3) setColor(RED);
			if (i == 20 && j == 2) setColor(RED);
			if (i <= 17 && j > 8) setColor(DARK_GRAY);
			if (j == 12 && j >= 7 && j <= 10) setColor(DARK_GRAY);
			if (i >= 18 && i < 19) {
				setColor(SKYBLUE);
				if (j == 2 || j == 4 || j >= 6 && j <= 8 || j == 10 || j == 12) {
					setColor(DARK_SKYBLUE);
				}

			}


			printf("%s", rocket[i][j] == 1 ? "■" : "　");
		}
		printf("\n");
		y++;
	}
	setColor(YELLOW);
}
// 콘솔 텍스트 색상 변경해주는 함수
void setColor(unsigned short text)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), text);
}

void setcolor(unsigned short text)
{
}

void DayAlter(int day)
{
	int CountNum[10][5][4] = {
		// NUM 0
		{{1,1,1,1},
		{1,0,0,1},
		{1,0,0,1},
		{1,0,0,1},
		{1,1,1,1}},
		// NUM 1
		{{0,0,1,0},
		{0,0,1,0},
		{0,0,1,0},
		{0,0,1,0},
		{0,0,1,0}},
		// NUM 2
		{{1,1,1,1},
		{0,0,0,1},
		{1,1,1,1},
		{1,0,0,0},
		{1,1,1,1}},
		// NUM 3
		{{1,1,1,1},
		{0,0,0,1},
		{1,1,1,1},
		{0,0,0,1},
		{1,1,1,1}},
		// NUM 4
		{{1,0,0,0},
		{1,0,1,0},
		{1,0,1,0},
		{1,1,1,1},
		{0,0,1,0}},
		// NUM 5
		{{1,1,1,1},
		{1,0,0,0},
		{1,1,1,1},
		{0,0,0,1},
		{1,1,1,1}},
		// NUM 6
		{{1,1,0,0},
		{1,0,0,0},
		{1,1,1,1},
		{1,0,0,1},
		{1,1,1,1}},
		// NUM 7
		{{1,1,1,1},
		{1,0,0,1},
		{0,0,0,1},
		{0,0,0,1},
		{0,0,0,1}},
		// NUM 8
		{{1,1,1,1},
		{1,0,0,1},
		{1,1,1,1},
		{1,0,1,1},
		{1,1,1,1}},
		// NUM 9
		{{1,1,1,1},
		{1,0,0,1},
		{1,1,1,1},
		{0,0,0,1},
		{1,1,1,1}}
	};

	int Day[3][5][5] = {	
		// D
		{{0,1,1,1,0},	
		{0,1,0,0,1},	
		{0,1,0,0,1},	
		{0,1,0,0,1},	
		{0,1,1,1,0}},	
		// A
		{{0,0,1,0,0},
		{0,1,0,1,0},
		{0,1,1,1,0},
		{1,0,0,0,1},
		{1,0,0,0,1}},
		// Y
		{{1,0,0,0,1},
		{0,1,0,1,0},
		{0,0,1,0,0},
		{0,0,1,0,0},
		{0,0,1,0,0}}
	};

	int x=12, y = 7;
	system("cls");
	if (day > 19) {
		for (int j = 0; j < 5; j++) {
			gotoxy(x, y);
			for (int k = 0; k < 4; k++) {
				printf("%s", CountNum[2][j][k] == 1 ? "■" : "　");
			}
			printf("\n");
			y++;
		}
	}
	else if (day > 9) {
		for (int j = 0; j < 5; j++) {
			gotoxy(x, y);
			for (int k = 0; k < 4; k++) {
				printf("%s", CountNum[1][j][k] == 1 ? "■" : "　");
			}
			printf("\n");
			y++;
		}
	}
	else {
		for (int j = 0; j < 5; j++) {
			gotoxy(x, y);
			for (int k = 0; k < 4; k++) {
				printf("%s", CountNum[0][j][k] == 1 ? "■" : "　");
			}
			printf("\n");
			y++;
		}
	}
	x = 22, y = 7;
	for (int j = 0; j < 5; j++) {
		gotoxy(x, y);
		for (int k = 0; k < 4; k++) {
			printf("%s", CountNum[day%10][j][k] == 1 ? "■" : "　");
		}
		printf("\n");
		y++;
	}
	x = 34, y = 7;
	for (int i = 0; i < 3; i++) {
		for (int k = 0; k < 5; k++) {
			gotoxy(x, y);
			for (int j = 0; j < 5; j++) {
				printf("%s", Day[i][k][j] == 1 ? "■" : "　");
			}
			printf("\n");
			y++;
		}
	}
}

int coingameDraw()
{
	system("cls");
	int x = 42, y = 26;
	gotoxy(x - 2, y);
	printf("> 앞"); // 0
	gotoxy(x, y + 1);
	printf("뒤"); // 1
	while (1) {
		int n = keyControl(); // 키보드 이벤트를 키값으로 받아오기
		switch (n) {
		case UP: {
			if (y > 26) {
				gotoxy(x - 2, y);
				printf(" ");
				gotoxy(x - 2, --y);
				printf(">");
			}
			break;
		}
		case DOWN: {
			if (y < 27) {
				gotoxy(x - 2, y);
				printf(" ");
				gotoxy(x - 2, ++y);
				printf(">");
			}
			break;
		}
		case SUBMIT: {
			return y - 26;
		}
		case ENTER: {
			return y - 26;
		}
		}
	}
}
void coinmainDraw()
{
	
}