#include "Function.h"

void gotoxy(int x, int y)
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE); // �ܼ� �ڵ� ��������
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
		{"3021�� �������� ���� ������� �����ߴ� �ܰ��� ħ���� �� �տ� �ٰ��Դ�."},
		{"�ܰ��ε��� �츮���� ����� �㺸�� �ϴ� �Ѱ��� ������ �ߴ�."},
		{"�ܰ��ε��� ������ 30�ϰ� ���� �̴ϰ����� �ؼ� ������ Ż���ϸ� �Ǵ� ���̴�."},
		{"�ܰ��ε��� ������ �̴ϰ����� ��Ģ�� �ſ� �����Ͽ���."},
		{"�̴ϰ����� ���ؼ� ���� �������� �����Ͽ� ���ּ� �� ���ֺ��� �����ϴ� ���̴�."},
		{"������ ���ۿ��� �������� �ִ�. �װ��� �ٷ� ���ῡ�� ������ �����ϴ�."},
		{"���۵� ���ּ��� ���ֺ��� �̿��Ͽ� 30�� �ȿ� ������ Ż���ϸ� �ȴ�."}
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
				printf("%s", CountNum[i][j][k] == 1 ? "��" : "��");
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
				printf("%s", Start[i][j][k] == 1 ? "��" : "��");
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
	system("mode con cols=96 lines=32 | title 30�ϻ�������");
}

int menuDraw()
{
	int x = 42, y = 22;
	gotoxy(x - 2, y);
	printf("> ���ӽ���");
	gotoxy(x, y + 1);
	printf("��������");
	gotoxy(x, y + 2);
	printf("  ����  ");
	while (1) {
		int n = keyControl(); // Ű���� �̺�Ʈ�� Ű������ �޾ƿ���
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

int mainDraw()
{
	int x = 42, y = 22;
	gotoxy(x - 2, y);
	printf("> �̴ϰ���");
	gotoxy(x, y + 1);
	printf("  ����  ");
	gotoxy(x, y + 2);
	printf("  �غ���  ");
	while (1) {
		int k = keyControl(); // Ű���� �̺�Ʈ�� Ű������ �޾ƿ���
		switch (k) {
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
	return 0;
}

void infoDraw()
{
	system("cls");
	printf("\n\n");
	printf("[���۹�]\n\n");
	printf("�̵� : W, S\n");
	printf("���� : SPACE, ENTER\n");
	printf("������ : ���� , ���¿� \n");
	printf("��԰� ����ּ��� .");
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
		int menuCode = mainDraw();
		if (menuCode == 0) {
			gamemainDraw();
			//���ӽ���
		}
		else if (menuCode == 1) {
			// ��������
			infoDraw();
		}
		else if (menuCode == 2) {
			return 0; // ����
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
	int x = 10, y = 10, sleep = 100;
	int rnd_dice = rand() % 6;
	for (int g = 0; g < 3; g++)
	{
		for (int i = 0; i < 6; i++)
		{
			for (int k = 0; k < 7; k++)
			{
				gotoxy(x, y);
				for (int j = 0; j < 7; j++)
					printf("%s", dice[i][k][j] == 1 ? "��" : "��");
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
			printf("%s", dice[rnd_dice][k][j] == 1 ? "��" : "��");
		printf("\n");
		y++;
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	Sleep(1000);
	return rnd_dice;
}

int minigameDraw()
{
	system("cls");
	int x = 42, y = 22;
	gotoxy(x - 2, y);
	printf("> �ֻ���"); // 0
	gotoxy(x, y + 1);
	printf("����������"); // 1
	gotoxy(x, y + 2);
	printf("  �ͼ���  "); // 2
	gotoxy(x, y + 3);
	printf(" ���ư��� ");
	while (1) {
		int n = keyControl(); // Ű���� �̺�Ʈ�� Ű������ �޾ƿ���
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
			if (y < 25) {
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

void gamemainDraw()
{
	system("cls");

	int menuCode = minigameDraw();
	switch (menuCode) {
	case 0:
		DicemainDraw();
		break;
	case 1:
		break;
	case 2:
		break;
	case 3:
		break;
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
					printf("%s", coin[i][k][j] == 1 ? "��" : "��");
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
				printf("%s", coin[0][k][j] == 1 ? "��" : "��");
			}
			printf("\n");
			y++;
		}
	else
		for (int k = 0; k < 7; k++) {
			gotoxy(x, y);
			for (int j = 0; j < 7; j++) {
				printf("%s", coin[4][k][j] == 1 ? "��" : "��");
			}
			printf("\n");
			y++;
		}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);

	Sleep(1000);
}

void RSP()
{
	int rsp[3][16][13] = {
		// �ָ�
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

		// ����
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

		 // ��
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
					printf("%s", rsp[i][k][j] == 1 ? "��" : "��");
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
			printf("%s", rsp[rnd_rsp][k][j] == 1 ? "��" : "��");
		}
		printf("\n");
		y++;
	}
	Sleep(2000);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}

int DicegameDraw()
{
	system("cls");
	int x = 42, y = 22;
	gotoxy(x - 2, y);
	printf("> Ȧ"); // 0
	gotoxy(x, y + 1);
	printf("¦"); // 1
	while (1) {
		int n = keyControl(); // Ű���� �̺�Ʈ�� Ű������ �޾ƿ���
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
			if (y < 23) {
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

void DicemainDraw()
{
	int num;
	int count = 0;
	system("cls");
	int menuCode = DicegameDraw();
	switch (menuCode) {
	case 0:
		num = Dice();
		if (num % 2 == 0)
		{
			printf("Win");
			switch (hoctemp)
			{
			case 0:
				hydro++;
				printf("\n���� ���� %d", hydro);
				break;
			case 1:
				oxy++;
				printf("���� ���� %d", oxy);
				break;
			case 2:
				carb++;
				printf("ź�� ���� %d", carb);
				break;
			}
		}
		if (num % 2 != 0)
		{
			printf("Lose");
		}
		break;
	case 1:
		Dice();
		num = Dice();
		if (num % 2 != 0)
		{
			printf("Win");
			switch (hoctemp)
			{
			case 0:
				hydro++;
				printf("\n���� ���� %d", hydro);
				break;
			case 1:
				oxy++;
				printf("���� ���� %d", oxy);
				break;
			case 2:
				carb++;
				printf("ź�� ���� %d", carb);
				break;
			}
		}
		else if (num % 2 == 0)
		{
			printf("Lose");
		}
		break;
	}
	Sleep(2500);
}
// DropBlok
Object Player;
Object* Block = NULL;
void CreateBlock()
{
	if (BlockNum < BlockMaxNum)
	{
		Block = (Object*)malloc(sizeof(Object));

		Block->X = rand() % 66 + 10;
		Block->Y = rand() % 4 + 1;
		Block->image = "��";
	}
}

void PrintBlock()
{
	gotoxy(Block->X, Block->Y);
	printf("%s", Block->image);
}

void MoveBlock()
{
	if (Block->Y < 2)
		Block = NULL;
	else
	{
		gotoxy(Block->X, Block->Y - 1);
		printf("%s", " ");
		PrintBlock();
	}
}

void AvoidBlock()
{

}

int hocDraw()
{
	system("cls");
	int x = 42, y = 22;
	gotoxy(x - 2, y);
	printf("> ����"); // 0
	gotoxy(x, y + 1);
	printf("���");// 1
	gotoxy(x, y + 2);
	printf("ź��");
	while (1) {
		int n = keyControl(); // Ű���� �̺�Ʈ�� Ű������ �޾ƿ���
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

void hocmainDraw()
{
}