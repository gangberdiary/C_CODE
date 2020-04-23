#ifndef _MINE_H_
#define _MINE_H_

#include <stdio.h>
#include <windows.h>
#include <time.h>
#include <stdlib.h>

#pragma warning(disable:4996)

#define ROW 12
#define COL 12

#define NUM 20//产生雷的个数

void Game();
void Initboard(char board[ROW][COL], int row, int col, char elem);
void Setmine(char mine[ROW][COL], int row, int col, int num);
void Showboard(char board[ROW][COL], int row, int col);
char Getnum(char mine[ROW][COL], int x, int y);

#endif