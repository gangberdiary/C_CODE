#include "test.h"

void Initboard(char board[ROW][COL], int row, int col)//�����̳�ʼ��Ϊ�� ��
{
	int i = 0;//��
	int j = 0;//��
	for (; i < row; i++){
		for (j = 0; j < col; j++){
			board[i][j] = ' '; 
		}
	}
}

void Showboard(char board[ROW][COL], int row, int col)//��ӡ����
{
	int i = 0;//��
	int j = 0;//��
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
	printf("��������Ҫ�ߵ�����<x,y>:");
	scanf("%d,%d", &x, &y);
	if (x < 0 || y < 0 || x > ROW || y > COL){
		return 1;//���곬�����̷�Χ
	}
	else if (' ' != board[x - 1][y - 1]){
		return 2;//�����ѱ�ռ��
	}
	else{
		board[x - 1][y - 1] = BLACK_PIECE;
		return 3;
	}
}

char JudgeResult(char board[ROW][COL], int row, int col)//�ж�ʤ�� ��N����ʾ������X����ʾ���Ӯ��O����ʾ����Ӯ��P����ʾƽ��
{
	int i = 0;
	int j = 0;
	int flag = 0;
	//�ж���
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
	//�ж���
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
	//�ж���Խ���
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
	//�ж��ҶԽ���
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
	//�ж������Ƿ������
	for (i = 0; i < row; i++){
		for (j = 0; j < col; j++){
			if (board[i][j] == ' '){
				return 'N';//����λ�ã�������
			}
		}
	}
	return 'P';//ûλ�ã�ƽ��
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
	printf("�������ӳɹ���\n");
}

void Game()//����Ϸ
{
	char board[ROW][COL];//����
	Initboard(board, ROW, COL);//��ʼ��
	int flag = 0;

	char result = 'N';//�ж�ʤ�� ��N����ʾ������X����ʾ���Ӯ��O����ʾ����Ӯ��P����ʾƽ��
	srand((unsigned int)time(NULL));//���������

	while (1){
		Showboard(board, ROW, COL);
		flag = Playermove(board, ROW, COL);
		if (1 == flag){
			printf("���곬�����̷�Χ,���������룡\n");
			continue;//��������ѭ��
		}
		else if (2 == flag){
			printf("�������ѱ�ռ��,���������룡\n");
			continue;//��������ѭ��
		}
		else{
			printf("������ӳɹ���\n");
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
		printf("��ϲ�㣬��͵��Դ��˸�ƽ��!\n");
		break;
	case BLACK_PIECE:
		printf("��ϲ�㣬��Ӯ��!\n");
		break;
	case WHITE_PIECE:
		printf("�Բ��𣬵���Ӯ��!\n");
		break;
	default:
		printf("%c", result);
		//bug!!
		break;
	}
}