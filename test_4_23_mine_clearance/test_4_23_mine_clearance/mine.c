#include "mine.h"

void Initboard(char board[ROW][COL], int row, int col, char elem)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++){
		for (j = 0; j < col; j++){
			board[i][j] = elem;
		}
	}
}

void Setmine(char mine[ROW][COL], int row, int col, int num)
{
	while (num > 0){
		int i = rand() % (row - 2) + 1;
		int j = rand() % (col - 2) + 1;

		if (mine[i][j] == '0'){
			num--;
			mine[i][j] = '1';
		}
	}
}

void Showboard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	printf("  ");
	for (j = 1; j < col - 1; j++){//打印列标
		printf("| %-2d", j);
	}
	printf("\n");
	for (i = 1; i < row - 1; i++){
		printf("-------------------------------------------\n");
		printf("%2d|", i);//打印行标
		for (j = 1; j < col - 1; j++){
			printf("%2c |", board[i][j]);
		}
		printf("\n");
	}
}

char Getnum(char mine[ROW][COL], int x, int y)
{
	return mine[x - 1][y - 1] + mine[x - 1][y] + mine[x - 1][y + 1] + \//上一行的雷的个数
		mine[x][y - 1] + mine[x][y + 1] + \//左右两边的雷
		mine[x + 1][y - 1] + mine[x + 1][y] + mine[x + 1][y + 1] - 7 * '0';//下一行的雷的个数
}

void Game()
{
	char board[ROW][COL];//用来显示扫雷界面
	char mine[ROW][COL];//存放产生的雷的位置

	int count = (ROW - 2) * (COL - 2) - NUM;//玩家可以扫的位置的 个数

	srand((unsigned int)time(NULL));//随机数种子

	Initboard(board, ROW, COL, '*');//全部初始化为‘*’
	Initboard(mine, ROW, COL, '0');//‘0’代表该位置没有雷，‘1’代表有雷

	Setmine(mine, ROW, COL, NUM);//随机生成雷

	do{
		system("cls");//清屏
		int x = 0;//横坐标
		int y = 0;//纵坐标
		Showboard(board, ROW, COL);//打印界面
		printf("请输入扫雷位置<x,y>:");
		scanf("%d,%d", &x, &y);
		if (x < 1 || x >10 || y < 1 || y > 10){
			printf("超出界面范围，请重新输入！\n");
			continue;
		}
		if (board[x][y] != '*'){
			printf("该位置已经扫过，请重新输入！\n");
			continue;
		}
		if (mine[x][y] == '0'){
			count--;
			char num = Getnum(mine, x, y);
			board[x][y] = num;
		}
		else{
			printf("很遗憾！你扫到了雷，游戏失败！\n");
			Showboard(mine, ROW, COL);
			break;
		}
	} while (count > 0);
	if (0 == count){
		Showboard(mine, ROW, COL);
		printf("恭喜你，你赢了！\n");
	}
}