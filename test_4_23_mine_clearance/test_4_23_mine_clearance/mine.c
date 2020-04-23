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
	for (j = 1; j < col - 1; j++){//��ӡ�б�
		printf("| %-2d", j);
	}
	printf("\n");
	for (i = 1; i < row - 1; i++){
		printf("-------------------------------------------\n");
		printf("%2d|", i);//��ӡ�б�
		for (j = 1; j < col - 1; j++){
			printf("%2c |", board[i][j]);
		}
		printf("\n");
	}
}

char Getnum(char mine[ROW][COL], int x, int y)
{
	return mine[x - 1][y - 1] + mine[x - 1][y] + mine[x - 1][y + 1] + \//��һ�е��׵ĸ���
		mine[x][y - 1] + mine[x][y + 1] + \//�������ߵ���
		mine[x + 1][y - 1] + mine[x + 1][y] + mine[x + 1][y + 1] - 7 * '0';//��һ�е��׵ĸ���
}

void Game()
{
	char board[ROW][COL];//������ʾɨ�׽���
	char mine[ROW][COL];//��Ų������׵�λ��

	int count = (ROW - 2) * (COL - 2) - NUM;//��ҿ���ɨ��λ�õ� ����

	srand((unsigned int)time(NULL));//���������

	Initboard(board, ROW, COL, '*');//ȫ����ʼ��Ϊ��*��
	Initboard(mine, ROW, COL, '0');//��0�������λ��û���ף���1����������

	Setmine(mine, ROW, COL, NUM);//���������

	do{
		system("cls");//����
		int x = 0;//������
		int y = 0;//������
		Showboard(board, ROW, COL);//��ӡ����
		printf("������ɨ��λ��<x,y>:");
		scanf("%d,%d", &x, &y);
		if (x < 1 || x >10 || y < 1 || y > 10){
			printf("�������淶Χ�����������룡\n");
			continue;
		}
		if (board[x][y] != '*'){
			printf("��λ���Ѿ�ɨ�������������룡\n");
			continue;
		}
		if (mine[x][y] == '0'){
			count--;
			char num = Getnum(mine, x, y);
			board[x][y] = num;
		}
		else{
			printf("���ź�����ɨ�����ף���Ϸʧ�ܣ�\n");
			Showboard(mine, ROW, COL);
			break;
		}
	} while (count > 0);
	if (0 == count){
		Showboard(mine, ROW, COL);
		printf("��ϲ�㣬��Ӯ�ˣ�\n");
	}
}