#include "mine.h"

void menu()
{
	printf("###############################\n");
	printf("####  欢迎来到扫雷游戏室  #####\n");
	printf("###############################\n");
	printf("####       1.玩游戏       #####\n");
	printf("####       2.退出游戏     #####\n");
	printf("###############################\n");
}

int main()
{
	int select = 0;
	do{
		menu();
		printf("请选择：>");
		scanf("%d", &select);
		switch (select){
		case 1:
			Game();
			printf("游戏结束！\n");
			break;
		case 2:
			printf("退出成功！\n");
			break;
		default:
			printf("输入错误，请重新输入！\n");
			break;
		}
	} while(2 != select);

	system("pause");
	return 0;
}