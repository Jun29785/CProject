#include "Function.h"

int main()
{
	srand((unsigned int)time(NULL));
	int x = 30, y = 10;
	block_width = SCR_WIDTH / 2;
	gotoxy(x, y);
	HideCursor();
	minigamecount = 3;

	init();

	//// ���� 1����
	//hydro = 5;
	//oxy = 5;
	//carb = 5;
	//// ���� 2����
	//hydro2 = 5;
	//oxy2 = 5;
	//carb2 = 5;
	//// ���� 3����
	//hydro3 = 3;
	//oxy3 = 2;
	//carb3 = 3;
	rocket = 0;
	spacesuit = 0;
	news = 100;
	test();
}