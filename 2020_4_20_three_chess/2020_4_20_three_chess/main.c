#include "test.h"

void menu()
{
	printf("################################\n");
	printf("##### 欢迎来到三子棋游戏室 #####\n");
	printf("################################\n");
	printf("#####      1.玩游戏        #####\n");
	printf("#####      2.退出游戏      #####\n");
	printf("################################\n");
}

int main()
{
	int select = 0;
	do{
		menu();//目录
		printf("请选择：");
		scanf("%d", &select);
		switch (select){
		case 1:
			Game();
			printf("再来一把？\n");
			break;
		case 2:
			printf("退出游戏！\n");
			break;
		default:
			printf("输入错误，请重新输入！\n");
		}
	} while (2 != select);
	system("pause");
	return 0;
}