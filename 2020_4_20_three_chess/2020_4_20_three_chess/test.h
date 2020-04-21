#ifndef _TEST_H_
#define _TEST_H_

#pragma warning(disable:4996)

#include <stdio.h>
#include <windows.h>
#include <time.h>
#include <stdlib.h>

#define ROW 3//��
#define COL 3//��

#define BLACK_PIECE 'X'//����ߺ���
#define WHITE_PIECE 'O'//�����߰���

void Game();
void Initboard(char board[ROW][COL], int row, int col);
void Showboard(char board[ROW][COL], int row, int col);
int Playermove(char board[ROW][COL], int row, int col);
void Computermove(char board[ROW][COL], int row, int col);
char JudgeResult(char board[ROW][COL], int row, int col);

#endif