#include "Function.h"

int main()
{
	srand((unsigned int)time(NULL));
	int x = 30, y = 10;
	block_width = SCR_WIDTH / 2;
	gotoxy(x, y);
	HideCursor();
	minigamecount = 3;
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

	//// 원소 1레벨
	//hydro = 5;
	//oxy = 5;
	//carb = 5;
	//// 원소 2레벨
	//hydro2 = 5;
	//oxy2 = 5;
	//carb2 = 5;
	//// 원소 3레벨
	//hydro3 = 3;
	//oxy3 = 2;
	//carb3 = 3;
	rocket = 0;
	spacesuit = 0;
	news = 100;
	while (1) {
		int menuCode = menuDraw();
		if (menuCode == 0) {
			//게임시작 
			EntryStory();
			startDraw();
			// 엔딩
			Ending_Title();
		}
		else if (menuCode == 1) {
			// 게임정보
			infoDraw();
		}
		else if (menuCode == 2) {
			read();
			if (memo == 0) {
				gotoxy(54, 25);
				setColor(RED);
				printf("저장된 데이터가 없습니다.");
				setColor(YELLOW);
				Sleep(400);
			}
			else if (memo >= 1) {
				read();
				loading();
				Sleep(1000);
				DayAlter(day);
				startDraw();
			}

		}
		else if (menuCode == 3) {
			return 0; // 종료
		}
		system("cls");
	}
}