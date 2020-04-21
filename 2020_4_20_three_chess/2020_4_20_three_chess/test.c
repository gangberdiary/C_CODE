#include "test.h"

void Initboard(char board[ROW][COL], int row, int col)//将棋盘初始化为‘ ’
{
	int i = 0;//行
	int j = 0;//列
	for (; i < row; i++){
		for (j = 0; j < col; j++){
			board[i][j] = ' '; 
		}
	}
}

void Showboard(char board[ROW][COL], int row, int col)//打印棋盘
{
	int i = 0;//行
	int j = 0;//列
	printf("   | 1 | 2 | 3 |\n");
	for (; i < row; i++){
		printf("----------------\n");
		printf(" %d |", i + 1);
		for (j = 0; j < col; j++){
			printf(" %c |", board[i][j]);
		}
		printf("\n");
	}
}
int Playermove(char board[][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("请输入你要走的坐标<x,y>:");
	scanf("%d,%d", &x, &y);
	if (x < 0 || y < 0 || x > ROW || y > COL){
		return 1;//坐标超出棋盘范围
	}
	else if (' ' != board[x - 1][y - 1]){
		return 2;//坐标已被占用
	}
	else{
		board[x - 1][y - 1] = BLACK_PIECE;
		return 3;
	}
}

char JudgeResult(char board[ROW][COL], int row, int col)//判断胜负 ‘N’表示继续‘X’表示玩家赢‘O’表示电脑赢‘P’表示平局
{
	int i = 0;
	int j = 0;
	int flag = 0;
	//判断行
	for (i = 0; i < row; i++){
		int temp = board[i][0];
		for (j = 0; j < col - 1; j++){
			if (board[i][j] != ' ' && temp == board[i][j + 1]){
				flag = 1;
			}
			else{
				flag = 0;
				goto p1;
			}
		}
	p1:
		if (1 == flag){
			return temp;
		}
	}
	//判断列
	for (j = 0; j < col; j++){
		int temp = board[0][j];
		for (i = 0; i < row - 1; i++){
			if (board[i][j] != ' ' && temp == board[i + 1][j]){
				flag = 1;
			}
			else{
				flag = 0;
				goto p2;
			}
		}
	p2:
		if (1 == flag){
			return temp;
		}
	}
	//判断左对角线
	for (i = 0; i < row - 1; i++){
		if (board[i][i] != ' ' && board[i][i] == board[i + 1][i + 1]){
			flag = 1;
		}
		else{
			flag = 0;
			break;
		}
	}
	if (1 == flag){
		return board[i][i];
	}
	//判断右对角线
	for (i = 0, j = row - i - 2; i < row - 1; i++, j--){
		if (board[i][j] != ' ' && board[i][j] == board[i + 1][j - 1]){
			flag = 1;
		}
		else{
			flag = 0;
			break;
		}
	}
	if (1 == flag){
		return board[i][j];
	}
	//判断棋盘是否被填充满
	for (i = 0; i < row; i++){
		for (j = 0; j < col; j++){
			if (board[i][j] == ' '){
				return 'N';//还有位置，继续走
			}
		}
	}
	return 'P';//没位置，平局
}

void Computermove(char board[ROW][COL], int row, int col)
{
	while (1){
		int i = rand() % row;
		int j = rand() % col;

		if (board[i][j] == ' '){
			board[i][j] = WHITE_PIECE;
			break;
		}
	}
	printf("电脑落子成功！\n");
}

void Game()//玩游戏
{
	char board[ROW][COL];//棋盘
	Initboard(board, ROW, COL);//初始化
	int flag = 0;

	char result = 'N';//判断胜负 ‘N’表示继续‘X’表示玩家赢‘O’表示电脑赢‘P’表示平局
	srand((unsigned int)time(NULL));//随机数种子

	while (1){
		Showboard(board, ROW, COL);
		flag = Playermove(board, ROW, COL);
		if (1 == flag){
			printf("坐标超出棋盘范围,请重新输入！\n");
			continue;//结束本次循环
		}
		else if (2 == flag){
			printf("该坐标已被占用,请重新输入！\n");
			continue;//结束本次循环
		}
		else{
			printf("玩家落子成功！\n");
		}
		result = JudgeResult(board, ROW, COL);
		if (result != 'N'){
			break;
		}
		Computermove(board, ROW, COL);
		result = JudgeResult(board, ROW, COL);
		if (result != 'N'){
			break;
		}
	}
	Showboard(board, ROW, COL);
	switch (result){
	case 'P':
		printf("恭喜你，你和电脑打了个平手!\n");
		break;
	case BLACK_PIECE:
		printf("恭喜你，你赢了!\n");
		break;
	case WHITE_PIECE:
		printf("对不起，电脑赢了!\n");
		break;
	default:
		printf("%c", result);
		//bug!!
		break;
	}
}