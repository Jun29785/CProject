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
			return 0; // 종료
		}
		system("cls");
	}
}