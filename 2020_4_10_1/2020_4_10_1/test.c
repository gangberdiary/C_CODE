#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>

#pragma warning(disable:4996)

void game()
{
	int num = 0;//生成的随机数
	int input = 0;//输入的数字
	srand((unsigned int)time(NULL));
	num = rand() % 100 + 1;//1~100
	while (1){
		printf("请在1~100中选一个数：>");
		scanf("%d", &input);
		if (input > num){
			printf("猜大了\n");
		}
		else if (input < num){
			printf("猜小了\n");
		}
		else{
			printf("恭喜你猜对了！\n");
			return;
		}
	}
}

void menu()
{
	printf("#####################\n");
	printf("#####  1.猜数字 #####\n");
	printf("#####  2.退出   #####\n");
	printf("#####################\n");
}

void Guess_num()
{
	int input = 0;
	menu();
	printf("请选择：>");
	scanf("%d", &input);
	do{
		switch (input){
		case 1:
			game();
			menu();
			printf("再来一局？\n");
			scanf("%d", &input);
			break;
		case 2:
			input = 0;
			printf("游戏结束！\n");
			break;
		default:
			printf("输入错误，请重新输入！\n");
			break;
		}
	}while (0 != input);
}

int main()
{
	Guess_num();
	system("pause");
	return 0;
}