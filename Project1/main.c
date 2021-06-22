#include "Function.h"

int main()
{
	srand((unsigned int)time(NULL));
	int x = 30, y = 10;
	minigamecount1 = 10;
	minigamecount2 = 10;
	minigamecount3 = 10;
	block_width = SCR_WIDTH / 2;
	gotoxy(x, y);
	HideCursor();
	//while (1)
	//{
	//	if (GetAsyncKeyState(VK_RIGHT))
	//		x++;
	//	if (GetAsyncKeyState(VK_LEFT))
	//		x--;
	//	system("cls");
	//	gotoxy(x, y);
	//	printf("■");
	//	printf("TEST");	
	//}
	init();
	while (1) {
		int menuCode = menuDraw();
		if (menuCode == 0) {
			startDraw();
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
}