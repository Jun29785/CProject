#include "Function.h"

#pragma region Settings

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

void init()
{
	system("mode con:cols=96 lines=40");
	setColor(YELLOW);
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

// 콘솔 텍스트 색상 변경해주는 함수
void setColor(unsigned short text)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), text);
}

#pragma endregion

void onetwothree()
{
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

	int x = 42, y = 21;
	Sleep(200);
	// entrystory
	for (int i = 0; i < STORYNUM; i++) {
		system("cls");
		gotoxy(22, 29);  printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓");
		gotoxy(25, 31);  printf("spacebar를 누를시 기초 스토리를 스킵합니다.");
		gotoxy(22, 33);  printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛");
		spaceship();
		gotoxy(0, 22);
		for (int j = 0; j < STORYMAX; j++) {
			printf("%c", story[i][j]);
			if (GetAsyncKeyState(VK_SPACE) & 0x8000) {
				system("cls");

				day++;
				DayAlter(day);
				return;
			}
			Sleep(20);
		}
	}
	day++;
	DayAlter(day);
	//// count
	//for (int i = 2; i > -1; i--) {
	//	for (int j = 0; j < 5; j++) {
	//		gotoxy(x, y);
	//		for (int k = 0; k < 4; k++) {
	//			printf("%s", CountNum[i][j][k] == 1 ? "■" : "　");
	//		}
	//		printf("\n");
	//		y++;
	//	}
	//	Sleep(1000);
	//	system("cls");
	//	y = 7;
	//}
	//// start
	//x = 18, y = 10;
	//for (int i = 0; i < 5; i++) {

	//	for (int j = 0; j < 5; j++) {
	//		gotoxy(x, y);
	//		for (int k = 0; k < 5; k++) {
	//			printf("%s", Start[i][j][k] == 1 ? "■" : "　");
	//		}
	//		printf("\n");
	//		y++;
	//	}
	//	Sleep(200);
	//	x += 12; y = 10;
	//}
	//system("cls");
			/*onetwothree();*/
}

#pragma region Draw 

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

void menuTitleDraw()
{
	gotoxy(25, 10);
	//DayAlter(4);
	if (day < 10) {
		gotoxy(0, 0); printf("┏━━━━━━━━━━━━━━┓");
		gotoxy(0, 1); printf("┃    %2d Day    ┃", day);
		gotoxy(0, 2); printf("┗━━━━━━━━━━━━━━┛");
	}
	else if (day >= 10) {
		gotoxy(0, 0); printf("┏━━━━━━━━━━━━━━┓");
		gotoxy(0, 1); printf("┃    %2d Day    ┃", day);
		gotoxy(0, 2); printf("┗━━━━━━━━━━━━━━┛");
	}
	gotoxy(4, 4);
	if (minigamecount != 0)
	{
		setColor(RED);
		printf("Morning");
		setColor(YELLOW);
	}
	else if (minigamecount == 0)
	{
		gotoxy(5, 4);
		setColor(VIOLET);
		printf("Night");
		setColor(YELLOW);
	}
	gotoxy(18, 1);  printf("미니게임 가능 횟수 : %d", minigamecount);



	// 인벤토리 
	int x = 58, y = 0;
	gotoxy(x, y); printf("┏");
	for (int i = 0; i < 35; i++) {
		printf("━");
	}
	printf("┓");
	gotoxy(x + 13, y);
	printf("  인벤토리 ");
	y++;
	gotoxy(x, y); printf("┃          Lv1   Lv2   Lv3          ┃"); y++;
	gotoxy(x, y); printf("┃    수소 : %d     %d     %d           ┃", hydro, hydro2, hydro3); y++;
	gotoxy(x, y); printf("┃                                   ┃"); y++;
	gotoxy(x, y); printf("┃    산소 : %d     %d     %d           ┃", oxy, oxy2, oxy3); y++;
	gotoxy(x, y); printf("┃                                   ┃"); y++;
	gotoxy(x, y); printf("┃    탄소 : %d     %d     %d           ┃", carb, carb2, carb3); y++;
	gotoxy(x, y); printf("┃                                   ┃"); y++;
	gotoxy(x, y); printf("┃                                   ┃"); y++;
	gotoxy(x, y); printf("┃                                   ┃"); y++;
	gotoxy(x, y); printf("┗");
	for (int i = 0; i < 35; i++) printf("━");
	printf("┛");
	for (int k = 0; k < 96; k++) {
		gotoxy(k, 22);
		puts("━");
	}
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
	if (day != 30) {
		printf("  준비중  ");
	}
	else if (day == 30) {
		printf(" 탈출");
	}

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

	while (1) {
		menuTitleDraw();
		int menuCode = mainDraw();
		if (menuCode == 0 && minigamecount == 0) {
			gotoxy(54, 29);
			setColor(RED);
			printf("미니게임 횟수가 충분하지 않습니다.");
			setColor(YELLOW);
			Sleep(400);
		}
		if (menuCode == 0 && minigamecount != 0) {
			gamemainDraw();
			//게임시작
		}
		else if (menuCode == 1) {
			// 제작
			infoDraw();
		}
		else if (menuCode == 2 && minigamecount == 0) {
			// 잠자기
			NextgameDraw();
		}
		else if (menuCode == 2 && minigamecount != 0) {
			gotoxy(54, 29);
			setColor(RED);
			printf("잠을 잘수 있는 시간이 아닙니다.");
			setColor(YELLOW);
			Sleep(400);
		}
		else if (menuCode == 3 && day == 30) {
			// 탈출
			printf("탈출 게임");
		}
		system("cls");
	}
	//while (1) {
	//	if (keyControl() == SUBMIT || keyControl() == ENTER) {
	//		break;
	//	}
	//}

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
		coinmainDraw();
	}
	else if (menuCode == 2) {
		hoctemp = hocDraw();
		RSP();
	}
	else if (menuCode == 3) {
		hoctemp = hocDraw();
		Block_Avoid();
	}
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
	for (int k = 0; k < 96; k++) {
		gotoxy(k, 22);
		printf("━");
	}
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

int DicegameDraw()
{
	system("cls");
	for (int k = 0; k < 96; k++) {
		gotoxy(k, 22);
		printf("━");
	}
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
		OddEvendote(menuCode);
		num = Dice();
		minigamecount--;
		Sleep(500);
		if (num % 2 == 0)
		{
			gotoxy(54, 29);
			setColor(RED);
			printf("Win");
			setColor(YELLOW);
			switch (hoctemp)
			{
			case 0:
				hydro += num + 1;
				gotoxy(54, 30);
				setColor(RED);
				printf("\n수소 +%d / 현재 수소 %d", num + 1, hydro);
				setColor(YELLOW);
				break;
			case 1:
				oxy += num + 1;
				gotoxy(54, 30);
				setColor(RED);
				printf("\n산소 +%d / 현재 산소 %d", num + 1, oxy);
				setColor(YELLOW);
				break;
			case 2:
				carb += num + 1;
				gotoxy(54, 30);
				setColor(RED);
				printf("\n탄소 +%d / 현재 탄소 %d", num + 1, carb);
				setColor(YELLOW);
				break;
			}
		}
		else
		{
			gotoxy(54, 29);
			setColor(RED);
			printf("Lose");
			setColor(YELLOW);
		}
		break;
	case 1:
		OddEvendote(menuCode);
		num = Dice();
		minigamecount--;
		if (num % 2 != 0)
		{
			gotoxy(54, 29);
			setColor(RED);
			printf("Win");
			setColor(YELLOW);
			switch (hoctemp)
			{
			case 0:
				hydro += num + 1;
				gotoxy(20, 30);
				setColor(RED);
				printf("\n수소 +%d / 현재 수소 %d", num + 1, hydro);
				setColor(YELLOW);
				break;
			case 1:
				oxy += num + 1;
				gotoxy(54, 30);
				setColor(RED);
				printf("\n산소 +%d / 현재 산소 %d", num + 1, oxy);
				setColor(YELLOW);
				break;
			case 2:
				carb += num + 1;
				gotoxy(54, 30);
				setColor(RED);
				printf("\n탄소 +%d / 현재 탄소 %d", num + 1, carb);
				setColor(YELLOW);
				break;
			}
		}
		else
		{
			gotoxy(54, 29);
			setColor(RED);
			printf("Lose");
			setColor(YELLOW);
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
#pragma endregion

#pragma region MiniGame

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
	for (int k = 0; k < 22; k++) {
		gotoxy(44, k);
		printf("┃");
	}
	for (int k = 0; k < 90; k++) {
		gotoxy(k, 22);
		if (k != 44) {
			printf("━");
		}
		else {
			printf("┻");
		}
	}

	int x = 64, y = 7, sleep = 70;
	rnd_dice = rand() % 6;
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
			y = 7;
		}
		sleep += 150;
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
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
	Sleep(300);
	return rnd_dice;
}

int Coin()
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
	int x = 63, y = 7;
	for (int k = 0; k < 22; k++) {
		gotoxy(44, k);
		printf("┃");
	}
	for (int k = 0; k < 90; k++) {
		gotoxy(k, 22);
		if (k != 44) {
			printf("━");
		}
		else {
			printf("┻");
		}
	}
	rnd_coin = rand() % 2;
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
			y = 7;
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
	setColor(YELLOW);
	return rnd_coin;
}

void RSP()
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
	int player = RSPgameDraw();
	int x = 10, y = 5;
	int rnd_rsp = rand() % 3, sleep = 100;

	for (int k = 0; k < 22; k++) {
		gotoxy(44, k);
		printf("┃");
	}
	for (int k = 0; k < 90; k++) {
		gotoxy(k, 22);
		if (k != 44) {
			printf("━");
		}
		else {
			printf("┻");
		}
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0b);
	for (int k = 0; k < 16; k++) {
		gotoxy(x, y);
		for (int j = 0; j < 13; j++) {
			printf("%s", rsp[player][k][j] == 1 ? "■" : "　");
		}
		printf("\n");
		y++;
	}
	x = 54, y = 5;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0f);
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

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0a);
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

	if (player - rnd_rsp == 0) {
		puts("비겼습니다.");
		Sleep(1000);
	}
	else if (player - rnd_rsp == -1 || player - rnd_rsp == 2) {
		puts("이겼습니다.");
	}
	else {
		puts("졌습니다.");
	}
}

#pragma region Avoid_Block

block_width = SCR_WIDTH / 2;

void Block_init()
{
	for (int i = 0; i < block_width; i++)
		block[i].act = FALSE;

	player.x = block_width;
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
	if ((Block_iskeydown(VK_LEFT) || Block_iskeydown('a') || Block_iskeydown('a')) && player.x >= 1)
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
			printf("0");
		}
	}

	gotoxy(player.x, SCR_HEIGHT);
	printf("옷");

	gotoxy(0, SCR_HEIGHT + 1);
	for (int i = 0; i < SCR_HEIGHT - 7; i++)
		printf("▦");
}

void Block_Avoid()
{

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
	char key;
	Block_init();
	int x = 25, y = 10;

	for (int i = 2; i > -1; i--) {
		Block_print_map();
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

		y = 10;
	}
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

#pragma endregion

#pragma endregion

void DayAlter(int day)
{
	int CountNum[10][5][4] = {
		// NUM 0
		{{0,1,1,1},
		{0,1,0,1},
		{0,1,0,1},
		{0,1,0,1},
		{0,1,1,1}},
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

	system("cls");

	gotoxy(16, 12);
	puts("┏");
	gotoxy(80, 12);
	puts("┓");
	gotoxy(16, 20);
	puts("┗");
	gotoxy(80, 20);
	puts("┛");
	for (int k = 17; k < 80; k++) {
		gotoxy(k, 12);
		puts("━");
		gotoxy(k, 20);
		puts("━");
	}

	int x = 22, y = 14;
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
	x = 32, y = 14;
	for (int j = 0; j < 5; j++) {
		gotoxy(x, y);
		for (int k = 0; k < 4; k++) {
			printf("%s", CountNum[day % 10][j][k] == 1 ? "■" : "　");
		}
		printf("\n");
		y++;
	}
	x = 42, y = 14;
	for (int i = 0; i < 3; i++) {
		for (int k = 0; k < 5; k++) {
			gotoxy(x, y);
			for (int j = 0; j < 5; j++) {
				printf("%s", Day[i][k][j] == 1 ? "■" : "　");
			}
			printf("\n");
			y++;
		}
		x += 12, y = 14;
	}
	Sleep(1200);
	system("cls");
}

int coingameDraw()
{
	system("cls");
	int x = 42, y = 26;
	for (int k = 0; k < 96; k++) {
		gotoxy(k, 22);
		printf("━");
	}
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

int NextmainDraw()
{
	menuTitleDraw();
	int x = 42, y = 26;
	gotoxy(x - 2, y);
	printf("> 네"); // 0
	gotoxy(x, y + 1);
	printf("아니요"); // 1
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

void NextgameDraw()
{
	int num;
	int count = 0;
	system("cls");
	int menuCode = NextmainDraw();
	switch (menuCode) {
	case 0:
		NextSleep();
		break;
	case 1:
		break;
	}
}
#pragma region EndGame

enemy = 20;
e_width = SCR_WIDTH - 20;

void EndGame_init()
{
	for (int k = 0; k < Enemy; k++) {
		Enemy[k].act = FALSE;
	}
	for (int k = 0; k < 10; k++) {
		P_Bullet[k].act = FALSE;
	}

	User.x = (e_width) / 2;
	User.y = SCR_HEIGHT - SCR_HEIGHT / 4;
}

int EndGame_iskeydown(int key)
{
	return ((GetAsyncKeyState(key) & 0x8000) != 0);
}

void EndGame_Enemy_Create()
{
	for (int k = 0; k < enemy; k++) {
		if (!Enemy[k].act) {
			Enemy[k].x = rand() % (e_width);
			Enemy[k].y = SCR_HEIGHT - 1;
			Enemy[k].width = 3;
			Enemy[k].image = "<0>";

			Enemy[k].act = TRUE;
			return;
		}
	}
}

void EndGame_Enemy_Move()
{
	Sleep(300);
	for (int n = 0; n < enemy; n++) {
		if (Enemy[n].act) {
			switch (rand() % 3)
			{
			case 0:
				if (Enemy[n].y < SCR_HEIGHT - 10) {
					Enemy[n].y++; break;
				}
				else {
					break;
				}
			case 1:
				if (Enemy[n].x < e_width) {
					Enemy[n].x++; break;
				}
				else {
					break;
				}
			case 2:
				if (Enemy[n].x > 0) {
					Enemy[n].x--; break;
				}

			default:
				break;
			}
		}
	}

}

void EndGame_Enemy_Delete()
{
	for (int k = 0; k < enemy; k++) {
		if (Enemy[k].act && Enemy[k].y < 0) {
			Enemy[k].act = FALSE;
		}
	}
}

int EndGame_Enemy_Contain_Player()
{
	for (int k = 0; k < enemy; k++) {
		if (User.x - Enemy[k].x > -5 || User.x - Enemy[k].x < 3) {
			return TRUE;
		}
	}
	return FALSE;
}

void EndGame_Print_Map()
{
	for (int k = 0; k < SCR_HEIGHT; k++) {
		gotoxy(e_width + 2, k);
		puts("┃");
	}
}

void EndGame_Player_Move()
{
	if ((EndGame_iskeydown(VK_LEFT) || EndGame_iskeydown('a') || EndGame_iskeydown('a')) && User.x >= 1)
		User.x--;
	if ((EndGame_iskeydown(VK_RIGHT) || EndGame_iskeydown('d') || EndGame_iskeydown('D')) && User.x < e_width - 2)
		User.x++;
	if ((EndGame_iskeydown(VK_UP) || EndGame_iskeydown('w') || EndGame_iskeydown('W')) && User.y > SCR_HEIGHT / 2)
		User.y++;
	if ((EndGame_iskeydown(VK_DOWN) || EndGame_iskeydown('s') || EndGame_iskeydown('S')) && User.y < SCR_HEIGHT - 1)
		User.y--;
}

void EndGame_Player_Shot()
{
	for (int k = 0; k < 10; k++) {
		if ((EndGame_iskeydown(VK_SPACE)) && !P_Bullet[k].act) {
			EndGame_Player_Bullet_Create();
		}
	}
}

void EndGame_Player_Bullet_Create()
{
	for (int k = 0; k < 10; k++) {
		if (!P_Bullet[k].act) {
			P_Bullet[k].image = "!";
			P_Bullet[k].x = User.x + 2;
			P_Bullet[k].y = User.y - 1;

			P_Bullet[k].act = TRUE;
			return;
		}
	}
}

void EndGame_Player_Bullet_Move()
{
	for (int k = 0; k < 10; k++) {
		if (P_Bullet[k].act) {
			P_Bullet[k].y--;
		}
	}
}

void EndGame_Plyaer_Bullet_Delete()
{
	for (int k = 0; k < 10; k++) {
		if (P_Bullet[k].y < 0 && P_Bullet[k].act) {
			P_Bullet[k].act = FALSE;
		}
	}
}

int EndGame_Enemy_Contain_Bullet()
{
	for (int k = 0; k < enemy; k++) {
		for (int i = 0; i < 10; i++) {
			if (Enemy[k].x - P_Bullet[i].x > -3 && Enemy[k].x - P_Bullet[i].x < 1 && Enemy[k].act && P_Bullet[i].act) {
				Enemy[k].act = FALSE;
				P_Bullet[k].act = FALSE;
			}
		}
	}
}

void EndGame_Main()
{
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
	char key;
	EndGame_init();
	int x = 25, y = 10;

	for (int i = 2; i > -1; i--) {
		EndGame_Print_Map();
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

		y = 10;
	}
	do {
		srand((int)malloc(NULL));

		EndGame_Enemy_Create();
		EndGame_Enemy_Move();
		EndGame_Enemy_Delete();

		EndGame_Player_Move();
		EndGame_Player_Shot();

		EndGame_Print_Map();

		Sleep(10);
	} while (!(EndGame_Enemy_Contain_Player()));
}

#pragma endregion


void NextSleep()
{
	day++;
	minigamecount = 3;
	DayAlter(day);
	startDraw();

}
void coinmainDraw()
{
	system("cls");
	int menuCode = coingameDraw();
	int n;
	switch (menuCode) {
	case 0:
		frontbackdote(menuCode);
		n = Coin();
		minigamecount--;
		if (menuCode != n) {
			printf("이겼습니다.");
			Sleep(2000);
		}
		else {
			printf("졌습니다.");
			Sleep(2000);
		}
		break;
	case 1:
		frontbackdote(menuCode);
		n = Coin();
		minigamecount--;
		if (menuCode != n) {
			printf("이겼습니다.");
			Sleep(2000);
		}
		else {
			printf("졌습니다.");
			Sleep(2000);
		}
		break;
	}
}

void create() {

}


void OddEvendote(int num) {
	int rsp[2][18][13] = {
		// 홀
	   {{0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,1,0,0,0,0,0,0,0},
		{0,0,1,1,1,1,1,1,1,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,1,1,1,0,0,0,0,0,0},
		{0,0,0,1,0,0,0,1,0,0,0,0,0},
		{0,0,0,1,0,0,0,1,0,0,0,0,0},
		{0,0,0,1,0,0,0,1,0,0,0,0,0},
		{0,0,0,0,1,1,1,0,0,0,0,0,0},
		{0,0,0,0,0,1,0,0,0,0,0,0,0},
		{0,0,0,0,0,1,0,0,0,0,0,0,0},
		{1,1,1,1,1,1,1,1,1,1,1,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,1,1,1,1,1,1,1,0,0,0,0},
		{0,0,0,0,0,0,0,0,1,0,0,0,0},
		{0,0,1,1,1,1,1,1,1,0,0,0,0},
		{0,0,1,0,0,0,0,0,0,0,0,0,0},
		{0,0,1,1,1,1,1,1,1,0,0,0,0}},


		// 짝
	   {{0,0,0,0,0,0,0,0,0,0,1,0,0},
		{1,1,1,1,1,1,1,1,1,0,1,0,0},
		{0,0,0,1,0,1,0,0,0,0,1,0,0},
		{0,0,1,0,1,0,1,0,0,0,1,0,0},
		{0,1,0,1,0,1,0,1,0,0,1,1,1},
		{1,0,1,0,1,0,1,0,1,0,1,0,0},
		{0,0,0,0,0,0,0,0,0,0,1,0,0},
		{0,0,0,0,0,0,0,0,0,0,1,0,0},
		{0,1,1,1,1,1,1,1,1,1,0,0,0},
		{0,0,0,0,0,0,0,0,0,1,0,0,0},
		{0,0,0,0,0,0,0,0,0,1,0,0,0},
		{0,0,0,0,0,0,0,0,0,1,0,0,0},
		{0,0,0,0,0,0,0,0,0,1,0,0,0},
		{0,0,0,0,0,0,0,0,0,1,0,0,0},
		{0,0,0,0,0,0,0,0,0,1,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0}},
	};
	/*int x = 60, y = 2;*/
	int x = 10, y = 2;
	int sleep = 100;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
		for (int i = 0; i < 1; i++) {
			for (int k = 0; k < 18; k++) {
				gotoxy(x, y);
				for (int j = 0; j < 13; j++) {
					printf("%s", rsp[i][k][j] == 1 ? "■" : "　");
				}
				printf("\n");
				y++;
			}
			Sleep(sleep);
			y = 2, sleep += 50;
		}
		
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
	}