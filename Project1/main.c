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
			//���ӽ��� 
			EntryStory();
			startDraw();
			// ����
			Ending_Title();
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
}