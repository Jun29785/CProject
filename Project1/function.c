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
	{"3021년의 지구는 많은 인간들이 상상만하던 외계인의 침공이 눈 앞에 다가왔다."},
	{"외계인들은 인간들에게 지구를 침략할 것이라고 선전포고를 하였다."},
	{"하지만 외계인들은 살 수 있는 한가지 제안을 한다."},
	{"제안은 간단했다. 30일안에 지구를 탈출하는 것이었다."},
	{"지구를 탈출하기 위한 방법은 간단했다."},
	{"1. 매일 미니게임을 통해 재료를 얻는다."},
	{"2. 얻은 재료를 통해 우주선과 우주복을 제작한다."},
	{"3. 제작은 저녁에만 가능하다."},
	{"부디 탈출하길 빌겠습니다. GOOD LUCK"},
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
	setColor(YELLOW);
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
	gotoxy(x, y); printf("┃   우주선 : %d   우주복 : %d         ┃", rocket, spacesuit); y++;
	gotoxy(x, y); printf("┃                                   ┃"); y++;
	gotoxy(x, y); printf("┗");
	for (int i = 0; i < 35; i++) printf("━");
	printf("┛");
	for (int k = 0; k < 96; k++) {
		gotoxy(k, 22);
		printf("━");
	}
	y += 2;
	gotoxy(x, y); printf("┏");
	for (int i = 0; i < 35; i++) {
		printf("━");
	}
	printf("┓");
	gotoxy(x + 13, y);
	printf(" 오늘의 소식 ");
	y++;
	gotoxy(x, y); printf("┃                                   ┃"); y++;
	gotoxy(x, y); printf("┃                                   ┃"); y++;
	gotoxy(x, y); printf("┃                                   ┃"); y++;
	gotoxy(x, y); printf("┃                                   ┃"); y++;
	gotoxy(x, y); printf("┃                                   ┃"); y++;
	gotoxy(x, y); printf("┃                                   ┃"); y++;
	gotoxy(x, y); printf("┃                                   ┃"); y++;
	gotoxy(x, y); printf("┃                                   ┃"); y++;
	gotoxy(x, y); printf("┃                                   ┃"); y++;
	gotoxy(x, y); printf("┗");
	for (int i = 0; i < 35; i++) printf("━");
	printf("┛");
	x = 62, y = 16;


	if (news == 1) {
		gotoxy(x + 5, y);
		printf("하잉");
	}
	else {
		gotoxy(x + 10, y);
		printf("없습니다");
	}
}

int mainDraw()
{
	int x = 42, y = 26;
	gotoxy(x - 2, y);
	printf("> 미니게임");
	gotoxy(x, y + 1);
	printf("제작  ");
	gotoxy(x, y + 2);
	printf("잠자기");
	gotoxy(x, y + 3);

	if (rsswap == 0) {
		printf("준비중  ");
	}
	if (rsswap == 1) {
		printf("탈출");
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
		if (rocket == 1 && spacesuit == 1) {
			rsswap++;
		}

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
		else if (menuCode == 1/* && minigamecount == 0*/) {
			// 제작
			EndGame_Main();
		}
		else if (menuCode == 1 && minigamecount != 0) {
			// 제작
			gotoxy(54, 29);
			setColor(RED);
			printf("제작 할 수 있는 시간이 아닙니다.");
			setColor(YELLOW);
			Sleep(400);
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
		else if (menuCode == 3 && rsswap == 1) {
			// 탈출
			EndGame_Main();
			Sleep(1000);
		}
		else if (menuCode == 3 && rsswap == 0) {
			gotoxy(54, 29);
			setColor(RED);
			printf("아직 개방되지 않았습니다.");
			setColor(YELLOW);
			Sleep(400);
		}
		//else if (menuCode == 3 && rsswap == 0) {
		//	Sleep(1000);
		//}
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
		setColor(GREEN);
		minigamecount--;
		Sleep(500);
		if (num % 2 == 0)
		{
			gotoxy(50, 27);
			printf("맞추셨습니다");
			switch (hoctemp)
			{
			case 0:
				hydro += num + 1;
				gotoxy(50, 28);
				printf("수소 +%d / 현재 수소 %d", num + 1, hydro);
				break;
			case 1:
				oxy += num + 1;
				gotoxy(50, 28);
				printf("산소 +%d / 현재 산소 %d", num + 1, oxy);
				break;
			case 2:
				carb += num + 1;
				gotoxy(50, 28);
				printf("탄소 +%d / 현재 탄소 %d", num + 1, carb);
				break;
			}
		}
		else
		{
			gotoxy(50, 27);
			printf("맞추지 못하셨습니다");
		}
		break;
	case 1:
		OddEvendote(menuCode);
		num = Dice();
		setColor(GREEN);
		minigamecount--;
		if (num % 2 != 0)
		{
			gotoxy(50, 27);
			printf("맞추셨습니다");
			switch (hoctemp)
			{
			case 0:
				hydro += num + 1;
				gotoxy(50, 28);
				printf("수소 +%d / 현재 수소 %d", num + 1, hydro);
				break;
			case 1:
				oxy += num + 1;
				gotoxy(50, 28);
				printf("산소 +%d / 현재 산소 %d", num + 1, oxy);
				break;
			case 2:
				carb += num + 1;
				gotoxy(50, 28);
				printf("탄소 +%d / 현재 탄소 %d", num + 1, carb);
				break;
			}
		}
		else
		{
			gotoxy(50, 27);
			printf("맞추지 못하셨습니다");
		}
		break;
	}
	setColor(YELLOW);
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
	int x = 64, y = 8;
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
			y = 8;
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
	int num = rand() % 8 + 3;
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

	//if (player - rnd_rsp == 0) {
	//	puts("비겼습니다.");
	//	Sleep(1000);
	//}
	//else if (player - rnd_rsp == -1 || player - rnd_rsp == 2) {
	//	puts("이겼습니다.");
	//}
	//else {
	//	puts("졌습니다.");
	//}
	if (player - rnd_rsp == -1 || player - rnd_rsp == 2) {
		gotoxy(50, 28);
		printf("이겼습니다");
		switch (hoctemp)
		{
		case 0:
			hydro += num + 1;
			gotoxy(50, 29);
			printf("수소 +%d / 현재 수소 %d", num + 1, hydro);
			break;
		case 1:
			oxy += num + 1;
			gotoxy(50, 29);
			printf("산소 +%d / 현재 산소 %d", num + 1, oxy);
			break;
		case 2:
			carb += num + 1;
			gotoxy(50, 28);
			printf("탄소 +%d / 현재 탄소 %d", num + 1, carb);
			break;
		}
		Sleep(2000);
	}
	else if (player - rnd_rsp == 0) {
		gotoxy(50, 28);
		printf("비겼습니다.");
		Sleep(2000);
	}
	else {
		gotoxy(50, 28);
		printf("졌습니다");
		Sleep(2000);
	}
	minigamecount--;
}

#pragma region Avoid_Block

block_width = SCR_WIDTH / 3;

void Block_init()
{
	for (int i = 0; i < block_width; i++)
		block[i].act = FALSE;

	player.x = SCR_WIDTH / 4;
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
			gotoxy(block[i].x, block[i].y);
			printf(" ");
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
	if ((Block_iskeydown(VK_LEFT) || Block_iskeydown('a') || Block_iskeydown('a')) && player.x >= 1) {
		gotoxy(player.x, SCR_HEIGHT);
		printf(" ");
		player.x--;
	}
	if ((Block_iskeydown(VK_RIGHT) || Block_iskeydown('d') || Block_iskeydown('D')) && player.x < block_width - 2) {
		gotoxy(player.x, SCR_HEIGHT);
		printf(" ");
		player.x++;
	}
}

void Block_print_map(int score)
{
	
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
	gotoxy(60, 1);
	printf("score : %6d", score);
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
	system("cls");
	int x = 25, y = 10;
	int score = 0;
	for (int i = 2; i > -1; i--) {
		Block_print_map(score);
		for (int j = 0; j < 5; j++) {
			gotoxy(x, y);
			for (int k = 0; k < 4; k++) {
				printf("%s", CountNum[i][j][k] == 1 ? "■" : "　");
			}
			printf("\n");
			y++;
		}
		Sleep(1000);
	
		y = 10;
	}
	do {
		system("cls");
		srand((int)malloc(NULL));
		score++;
		Block_create();
		Block_move();
		Block_delete();

		Block_move_player();

		Block_print_map(score);

		Sleep(20);
	} while (!(Block_contain_player()));
	minigamecount--;
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

int creategameDraw()
{
	system("cls");
	menuTitleDraw();
	int x = 42, y = 26;
	gotoxy(x - 2, y);
	printf("> Lv2 원소"); // 0
	gotoxy(x, y + 1);
	printf("Lv3 원소"); // 1
	gotoxy(x, y + 2);
	printf("우주선 [ Lv 3 수소, 산소, 탄소 각각 2개씩 필요 ]"); // 2
	gotoxy(x, y + 3);
	printf("우주복 [ Lv 3 수소, 산소, 탄소 각각 1개씩 필요 ]"); // 3
	gotoxy(x, y + 4);
	printf("돌아가기"); // 4
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

int lv2()
{
	system("cls");
	menuTitleDraw();
	int x = 42, y = 26;
	gotoxy(x - 2, y);
	printf("> Lv2 수소 [ Lv1 수소 5개 필요 ]"); // 0
	gotoxy(x, y + 1);
	printf("Lv2 산소 [ Lv1 산소 5개 필요 ]"); // 1
	gotoxy(x, y + 2);
	printf("Lv2 탄소 [ Lv1 탄소 5개 필요 ]");
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

void anvilhammer()
{
	for (int i = 0; i < 3; i++) {
		system("cls");
		anvil();
		hammer();
	}
	system("cls");
}

void AilenBeam()
{

}

void anvil()
{
	int anvil[6][14][18] = {
		// 1
	   {{0,0,0,0,2,2,2,2,2,2,2,2,2,2,2,2,2,2},
		{2,2,2,2,2,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,1,1},
		{0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,1,1},
		{0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,0},
		{0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0},
		{0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,0,0,0},
		{0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0},
		{0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,0},
		{0,0,0,0,0,1,0,1,1,1,1,1,1,1,1,0,1,0},
		{0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,1,0},
		{0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,0}},
	};

	int x = 30, y = 26, sleep = 70;
	for (int i = 0; i < 1; i++)
	{
		for (int k = 0; k < 14; k++)
		{
			gotoxy(x, y);
			for (int j = 0; j < 18; j++) {
				switch (anvil[i][k][j]) {
				case 0:
					printf("　");
					break;
				case 1:
					setColor(DARK_GRAY);
					printf("■");
					setColor(YELLOW);
					break;
				case 2:
					setColor(GRAY);
					printf("■");
					setColor(YELLOW);
				}
				/*printf("%s", anvil[i][k][j] == 1 ? "■" : "　");*/
			}
			printf("\n");
			y++;
		}
		Sleep(sleep);
		y = 26;
	}
	sleep += 150;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
}

void hammer() {
	int hammer[6][15][20] = {
		// 1
	   {{0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,1,1,0,0,1,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,1,1,1,0,0,0,0,1,0,0,0,0,0,0,0},
		{0,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0},
		{0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0},
		{0,0,0,0,1,0,0,0,0,0,1,2,0,0,0,0,0,0,0,0},
		{0,0,0,1,0,0,0,0,0,1,0,2,2,0,0,0,0,0,0,0},
		{0,0,0,1,0,0,0,0,1,2,0,0,2,2,0,0,0,0,0,0},
		{0,0,0,0,1,0,0,1,0,2,2,0,0,2,2,0,0,0,0,0},
		{0,0,0,0,0,1,1,0,0,0,2,2,0,0,2,2,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,2,2,0,0,2,2,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,2,2,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}},
		//2
		{{0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,1,1,0,0,1,1,0,0,0,0,0},
		{0,0,2,2,2,2,2,2,2,2,1,0,0,1,0,0,0,0,0,0},
		{0,0,2,2,2,2,2,2,2,2,1,0,0,1,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,1,1,0,0,1,1,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,4,4,4,4,4,4,4,4,4,4,4,4,0,0}},

		//3
	   {{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,1,1,0,0,1,1,0,3,0,0,0},
		{0,0,2,2,2,2,2,2,2,2,1,0,0,1,0,3,0,0,0,0},
		{0,0,2,2,2,2,2,2,2,2,1,0,0,1,0,4,0,0,0,0},
		{0,0,0,0,3,3,0,0,0,1,1,0,0,1,1,0,0,3,3,0},
		{0,0,0,0,0,0,4,0,0,1,0,0,0,0,1,0,4,0,0,0},
		{0,0,0,3,3,0,0,0,4,1,1,1,1,1,1,4,0,0,3,3},
		{0,0,0,0,0,4,0,0,4,4,3,3,3,3,4,4,0,4,0,0}},
	};
	//1
	int x = 42, y = 7, sleep = 150;
	for (int i = 0; i < 0; i++)
	{
		for (int k = 0; k < 15; k++)
		{
			gotoxy(x, y);
			for (int j = 0; j < 20; j++) {
				switch (hammer[i][k][j]) {
				case 0:
					printf("　");
					break;
				case 1:
					setColor(DARK_GRAY);
					printf("■");
					setColor(YELLOW);
					break;
				case 2:
					setColor(DARK_GRAY);
					printf("■");
					setColor(YELLOW);
					break;
				}

				/*printf("%s", anvil[i][k][j] == 1 ? "■" : "　");*/
			}
			printf("\n");
			y++;
		}

		Sleep(sleep);
		y = 0;
	}
	system("cls");
	sleep += 50;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
	//2
	x = 28, y = 10;
	anvil();
	for (int i = 1; i < 2; i++)
	{
		for (int k = 0; k < 15; k++)
		{
			gotoxy(x, y);
			for (int j = 0; j < 20; j++) {
				switch (hammer[i][k][j]) {
				case 0:
					printf("　");
					break;
				case 1:
					setColor(DARK_GRAY);
					printf("■");
					setColor(YELLOW);
					break;
				case 2:
					setColor(DARK_GRAY);
					printf("■");
					setColor(YELLOW);
					break;
				case 3:
					setColor(RED);
					printf("■");
					setColor(YELLOW);
					break;
				case 4:
					setColor(DARK_RED);
					printf("■");
					setColor(YELLOW);
					break;
				}
				/*printf("%s", anvil[i][k][j] == 1 ? "■" : "　");*/
			}
			printf("\n");
			y++;
		}
		Sleep(sleep);
		y = 0;
	}
	system("cls");
	sleep += 150;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
	Sleep(100);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
	//3
	x = 28, y = 10;

	anvil();
	for (int i = 2; i < 3; i++)
	{
		for (int k = 0; k < 15; k++)
		{
			gotoxy(x, y);
			for (int j = 0; j < 20; j++) {
				switch (hammer[i][k][j]) {
				case 0:
					printf("　");
					break;
				case 1:
					setColor(DARK_GRAY);
					printf("■");
					setColor(YELLOW);
					break;
				case 2:
					setColor(DARK_GRAY);
					printf("■");
					setColor(YELLOW);
					break;
				case 3:
					setColor(RED);
					printf("■");
					setColor(YELLOW);
					break;
				case 4:
					setColor(DARK_RED);
					printf("■");
					setColor(YELLOW);
					break;
				}
				/*printf("%s", anvil[i][k][j] == 1 ? "■" : "　");*/
			}
			printf("\n");
			y++;
		}
		Sleep(sleep);
		y = 0;
	}
	sleep += 150;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
	Sleep(500);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
}

int lv3() {
	system("cls");
	menuTitleDraw();
	int x = 42, y = 26;
	gotoxy(x - 2, y);
	printf("> Lv3 수소 [ Lv2 수소 5개 필요 ]"); // 0
	gotoxy(x, y + 1);
	printf("Lv3 산소 [ Lv2 산소 5개 필요 ]"); // 1
	gotoxy(x, y + 2);
	printf("Lv3 탄소 [ Lv2 탄소 5개 필요 ]");
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

int createnextDraw()
{
	system("cls");
	menuTitleDraw();
	int x = 42, y = 26;
	gotoxy(x - 2, y);
	printf("> 제작"); // 0
	gotoxy(x, y + 1);
	printf("돌아가기"); // 1
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
#pragma endregion


void NextSleep()
{
	day++;
	minigamecount = 3;
	news = rand() % 100;
	DayAlter(day);
	if (day == 31) {
		exit(0);
	}
	startDraw();

}

void coinmainDraw()
{
	system("cls");
	int menuCode = coingameDraw();
	int n;
	int num = rand() % 6 + 1;

	switch (menuCode) {
	case 0:
		frontbackdote(menuCode);
		n = Coin();
		setColor(GREEN);
		minigamecount--;
		if (menuCode != n) {
			gotoxy(50, 27);
			printf("맞추셨습니다");
			switch (hoctemp)
			{
			case 0:
				hydro += num + 1;
				gotoxy(50, 28);
				printf("수소 +%d / 현재 수소 %d", num + 1, hydro);
				break;
			case 1:
				oxy += num + 1;
				gotoxy(50, 28);
				printf("산소 +%d / 현재 산소 %d", num + 1, oxy);
				break;
			case 2:
				carb += num + 1;
				gotoxy(50, 28);
				printf("탄소 +%d / 현재 탄소 %d", num + 1, carb);
				break;
			}
			Sleep(2000);
		}
		else if (menuCode == n) {
			gotoxy(50, 27);
			printf("맞추지 못하셨습니다");
			Sleep(2000);
		}
		setColor(YELLOW);
		break;
	case 1:
		frontbackdote(menuCode);
		n = Coin();
		setColor(GREEN);
		minigamecount--;
		if (menuCode != n) {
			gotoxy(50, 27);
			printf("맞추셨습니다");
			switch (hoctemp)
			{
			case 0:
				hydro += num + 1;
				gotoxy(50, 28);
				printf("수소 +%d / 현재 수소 %d", num + 1, hydro);
				break;
			case 1:
				oxy += num + 1;
				gotoxy(50, 28);
				printf("산소 +%d / 현재 산소 %d", num + 1, oxy);
				break;
			case 2:
				carb += num + 1;
				gotoxy(50, 28);
				printf("탄소 +%d / 현재 탄소 %d", num + 1, carb);
				break;
			}
			Sleep(2000);
		}
		else if (menuCode == n) {
			gotoxy(50, 27);
			printf("맞추지 못하셨습니다");
			Sleep(2000);
		}
		setColor(YELLOW);
		break;
	}

}

void create() {

	int menuCode = creategameDraw();
	switch (menuCode) {
	case 0:
		lv_2 = lv2();
		if (lv_2 == 0 && hydro >= 5) {
			createany = createnextDraw();
			if (createany == 1) {
				return 0;
			}
			anvilhammer();
			hydro -= 5;
			hydro2++;
		}
		else if (lv_2 == 0 && hydro <= 4) {
			gotoxy(54, 29);
			setColor(RED);
			printf("제작할 재료가 부족합니다.");
			setColor(YELLOW);
			Sleep(400);
		}
		if (lv_2 == 1 && oxy >= 5) {
			createany = createnextDraw();
			if (createany == 1) {
				return 0;
			}
			anvilhammer();
			oxy -= 5;
			oxy2++;
		}
		else if (lv_2 == 1 && oxy <= 4) {
			gotoxy(54, 29);
			setColor(RED);
			printf("제작할 재료가 부족합니다.");
			setColor(YELLOW);
			Sleep(400);
		}
		if (lv_2 == 2 && carb >= 5) {
			createany = createnextDraw();
			if (createany == 1) {
				return 0;
			}
			anvilhammer();
			carb -= 5;
			carb2++;
		}
		else if (lv_2 == 2 && carb <= 4) {
			gotoxy(54, 29);
			setColor(RED);
			printf("제작할 재료가 부족합니다.");
			setColor(YELLOW);
			Sleep(400);
		}
		break;
	case 1:
		lv_3 = lv3();
		if (lv_3 == 0 && hydro2 >= 5) {
			createany = createnextDraw();
			if (createany == 1) {
				return 0;
			}
			anvilhammer();
			hydro2 -= 5;
			hydro3++;
		}
		else if (lv_3 == 0 && hydro2 <= 4) {
			gotoxy(54, 29);
			setColor(RED);
			printf("제작할 재료가 부족합니다.");
			setColor(YELLOW);
			Sleep(400);
		}
		if (lv_3 == 1 && oxy2 >= 5) {
			createany = createnextDraw();
			if (createany == 1) {
				return 0;
			}
			anvilhammer();
			oxy2 -= 5;
			oxy3++;
		}
		else if (lv_3 == 1 && oxy2 <= 4) {
			gotoxy(54, 29);
			setColor(RED);
			printf("제작할 재료가 부족합니다.");
			setColor(YELLOW);
			Sleep(400);
		}
		if (lv_3 == 2 && carb2 >= 5) {
			createany = createnextDraw();
			if (createany == 1) {
				return 0;
			}
			anvilhammer();
			carb2 -= 5;
			carb3++;
		}
		else if (lv_3 == 2 && carb2 <= 4) {
			gotoxy(54, 29);
			setColor(RED);
			printf("제작할 재료가 부족합니다.");
			setColor(YELLOW);
			Sleep(400);
		}
		break;
	case 2:
		if (menuCode == 2 && hydro3 >= 2 && oxy3 >= 2 && carb3 >= 2) {
			createany = createnextDraw();
			if (createany == 1) {
				return 0;
			}
			anvilhammer();
			rocket++;
			hydro3 -= 2;
			oxy3 -= 2;
			carb3 -= 2;
		}
		else {
			gotoxy(54, 31);
			setColor(RED);
			printf("제작할 재료가 부족합니다.");
			setColor(YELLOW);
			Sleep(400);
		}
		break;
	case 3:
		if (menuCode == 3 && hydro3 >= 1 && oxy3 >= 1 && carb3 >= 1) {
			createany = createnextDraw();
			if (createany == 1) {
				return 0;
			}
			anvilhammer();
			spacesuit++;
			hydro3 -= 1;
			oxy3 -= 1;
			carb3 -= 1;
		}
		else {
			gotoxy(54, 31);
			setColor(RED);
			printf("제작할 재료가 부족합니다.");
			setColor(YELLOW);
			Sleep(400);
		}
		break;
	case 4:
		break;
	}

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
	if (num == 0) {
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
	if (num == 1) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
		for (int i = 1; i < 2; i++) {
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

}

void frontbackdote(int num)
{
	//int fb[2][18][18] = {
	//	// 홀
	//   {{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	//	{0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0},
	//	{0,0,0,0,1,1,1,1,1,1,0,0,0,1,0,0,0,0},
	//	{0,0,0,1,0,0,0,0,0,0,1,0,0,1,0,0,0,0},
	//	{0,0,1,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0},
	//	{0,0,1,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0},
	//	{0,0,1,0,0,0,0,0,0,0,0,1,0,1,1,1,1,1},
	//	{0,0,1,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0},
	//	{0,0,1,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0},
	//	{0,0,1,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0},
	//	{0,0,0,1,0,0,0,0,0,0,1,0,0,1,0,0,0,0},
	//	{0,0,0,0,1,1,1,1,1,1,0,0,0,1,0,0,0,0},
	//	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	//	{0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0},
	//	{0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0},
	//	{0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0},
	//	{0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0},
	//	{0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0}},


	//	// 짝
	//   {{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	//	{0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0},
	//	{0,0,1,1,1,1,1,1,1,1,1,0,0,1,0,0,0,0},
	//	{0,0,1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0},
	//	{0,0,1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0},
	//	{0,0,1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0},
	//	{0,0,1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0},
	//	{0,0,1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0},
	//	{0,0,1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0},
	//	{0,0,1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0},
	//	{0,0,1,1,1,1,1,1,1,1,1,0,0,1,0,0,0,0},
	//	{0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0},
	//	{0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0},
	//	{0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0},
	//	{0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0},
	//	{0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0},
	//	{0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0},
	//	{0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0}}
	//};
	int fb[2][7][7] = {
		// front
		{{0,0,1,1,1,0,0},
		 {0,1,1,1,1,1,0},
		 {1,1,1,2,1,1,1},
		 {1,1,2,2,2,1,1},
		 {1,1,1,2,1,1,1},
		 {0,1,1,1,1,1,0},
		 {0,0,1,1,1,0,0}},


		 //back
		 {{0,0,1,1,1,0,0},
		 {0,1,1,1,1,1,0},
		 {1,1,1,1,1,1,1},
		 {1,1,1,1,1,1,1},
		 {1,1,1,1,1,1,1},
		 {0,1,1,1,1,1,0},
		 {0,0,1,1,1,0,0}},

	};

	int x = 16, y = 8;
	int sleep = 100;
	if (num == 0) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
		for (int i = 0; i < 1; i++) {
			for (int k = 0; k < 7; k++) {
				gotoxy(x, y);
				for (int j = 0; j < 7; j++) {
					printf("%s", fb[i][k][j] == 1 ? "▣" : "　");
				}
				printf("\n");
				y++;
			}
			Sleep(sleep);
			y = 2, sleep += 50;
		}
	}

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
	if (num == 1) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
		for (int i = 1; i < 2; i++) {
			for (int k = 0; k < 7; k++) {
				gotoxy(x, y);
				for (int j = 0; j < 7; j++) {
					printf("%s", fb[i][k][j] == 1 ? "▣" : "　");
				}
				printf("\n");
				y++;
			}
			Sleep(sleep);
			y = 2, sleep += 50;
		}

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
	}
}

#pragma region EndGame
void EndGame_Main()
{
	EndGame_Init();

	while (IsGame) {
		system("cls");
		EndGame_Draw();
		EndGame_Enemy();
		EndGame_Player();
		EndGame_Player_Bullet();
		EndGame_Collision_Enemy_Bullet();
		EndGame_Collision_Enemy_Player();
		Sleep(50);
	}

	for (int k = 0; k < MAX_BULLETS; k++) {
		if (P_Bullet_Array[k] != NULL) {
			free(P_Bullet_Array[k]);
			P_Bullet_Array[k] = NULL;
		}
	}

	for (int k = 0; k < EndGame_Max_Enemy; k++) {
		if (Enemy[k] != NULL) {
			free(Enemy[k]);
			Enemy[k] = NULL;
		}
	}
}

void EndGame_Init()
{
	for (int k = 0; k < MAX_BULLETS; k++) {
		P_Bullet_Array[k] = NULL;
	}
	User.image = "<=0=>";
	User.x = EndGame_WIDTH / 2;
	User.y = 30;
	User.width = 5;
	User.height = 1;

	for (int k = 0; k < EndGame_Max_Enemy; k++) {
		Enemy[k] = NULL;
	}
	Player_Bullet_Reload = true;
	IsGame = true;
	EndGameScore = 0;
}

void EndGame_Draw()
{
	for (int k = 0; k < 40; k++) {
		gotoxy(76, k);
		printf("┃");
	}

	gotoxy(78, 1);
	printf("Remain Kills : %3d", 150 - EndGameScore);
	gotoxy(User.x, User.y);
	printf("%s", User.image);

	for (int k = 0; k < EndGame_Max_Enemy; k++) {
		if (Enemy[k] != NULL) {
			gotoxy(Enemy[k]->x, Enemy[k]->y);
			printf("%s", Enemy[k]->image);
		}
	}

	for (int k = 0; k < MAX_BULLETS; k++) {
		if (P_Bullet_Array[k] != NULL) {
			gotoxy(P_Bullet_Array[k]->x, P_Bullet_Array[k]->y);
			printf("%s", P_Bullet_Array[k]->image);
		}
	}
}

void EndGame_Enemy()
{
	EndGame_Enemy_Create();

	for (int k = 0; k < EndGame_Max_Enemy; k++) {
		if (Enemy[k] != NULL) {
			EndGame_Enemy_Move(k);
			if (Enemy[k]->y > 36) {
				EndGame_Enemy_Delete(k);
			}
		}
	}
}

void EndGame_Enemy_Create()
{
	int b_ix = -1;
	for (int k = 0; k < EndGame_Max_Enemy; k++) {
		if (Enemy[k] == NULL) {
			b_ix = k;
			break;
		}
	}
	if (b_ix == -1) return;

	Enemy[b_ix] = (p_Object)malloc(sizeof(Object));
	Enemy[b_ix]->x = rand() % (EndGame_WIDTH - 1) + 1;
	Enemy[b_ix]->y = 1;
	Enemy[b_ix]->image = "<0>";
	Enemy[b_ix]->width = 3;
	Enemy[b_ix]->height = 1;
}

void EndGame_Enemy_Move(int n)
{
	int move = rand() % 4;
	switch (move)
	{
	case 0: // stay
		break;
	case 1: // left
		if (Enemy[n]->x > 0)
			Enemy[n]->x--;
		break;
	case 2: // right
		if (Enemy[n]->x < EndGame_WIDTH - 1)
			Enemy[n]->x++;
		break;
	case 3: // front
		if (Enemy[n]->y < 26);
			Enemy[n]->y++;
		break;
	default:
		break;
	}
}

void EndGame_Player()
{
	EndGame_Player_Controll();
}

void EndGame_Enemy_Delete(int n)
{
	free(Enemy[n]);
	Enemy[n] = NULL;
}

void EndGame_Player_Controll()
{
	if (GetAsyncKeyState(VK_UP) & 0x8000) {
		if (User.y > 0)
			User.y--;
	}
	if (GetAsyncKeyState(VK_DOWN) & 0x8000) {
		if (User.y < SCR_HEIGHT + 6) {
			User.y++;
		}
	}
	if (GetAsyncKeyState(VK_LEFT) & 0x8000) {
		if (User.x > 0) {
			User.x--;
		}
	}
	if (GetAsyncKeyState(VK_RIGHT) & 0x8000) {
		if (User.x < 70) {
			User.x++;
		}
	}
	if (GetAsyncKeyState(VK_SPACE) & 0x8000) {
		if (Player_Bullet_Reload) {
			EndGame_Bullet_Create();
			Player_Bullet_Reload = false;
		}
	}
	else {
		Player_Bullet_Reload = true;
	}
}

void EndGame_Player_Bullet()
{
	for (int k = 0; k < MAX_BULLETS; k++) {
		if (P_Bullet_Array[k] != NULL) {
			EndGame_Bullet_Move(k);
			if (P_Bullet_Array[k]->y < 1) {
				EndGame_Bullet_Delete(k);
			}
		}

	}
}

void EndGame_Bullet_Create()
{
	int b_ix = -1;
	for (int k = 0; k < MAX_BULLETS; k++) {
		if (P_Bullet_Array[k] == NULL) {
			b_ix = k;
			break;
		}
	}
	if (b_ix == -1) return;

	P_Bullet_Array[b_ix] = (p_Object)malloc(sizeof(Object));
	P_Bullet_Array[b_ix]->x = User.x + 2;
	P_Bullet_Array[b_ix]->y = User.y - 1;
	P_Bullet_Array[b_ix]->image = "!";
}

void EndGame_Bullet_Move(int n)
{
	P_Bullet_Array[n]->y--;
}

void EndGame_Bullet_Delete(int n)
{
	free(P_Bullet_Array[n]);
	P_Bullet_Array[n] = NULL;
}

void EndGame_Collision_Enemy_Bullet()
{
	for (int k = 0; k < EndGame_Max_Enemy; k++) {
		for (int i = 0; i < MAX_BULLETS; i++) {
			if (P_Bullet_Array[i] != NULL && Enemy[k] != NULL && (Enemy[k]->x - P_Bullet_Array[i]->x <3 && Enemy[k]->x - P_Bullet_Array[i]->x > -1 && Enemy[k]->y == P_Bullet_Array[i]->y)) {
				EndGame_Enemy_Delete(k);
				EndGame_Bullet_Delete(i);
				EndGameScore++;
			}
		}
	}
}

void EndGame_Collision_Enemy_Player()
{
	for (int k = 0; k < EndGame_Max_Enemy; k++) {
		if (Enemy[k] != NULL ){
			if (User.y == Enemy[k]->y && User.x - Enemy[k]->x >= -4 && User.x - Enemy[k]->x <= 2)
				IsGame = false;
		}
	}
}

#pragma endregion
