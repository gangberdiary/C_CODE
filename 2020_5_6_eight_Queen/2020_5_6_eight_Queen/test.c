#include <stdio.h>
#include <windows.h>
#include <math.h>

#pragma warning(disable:4996)

#define N 8

int col[N] = { 0 };//存放每一行皇后的列标
int num = 0;//一共有几种方法

void print()
{
	int i = 0;//行
	for (i = 0; i < N; i++){
		printf("(%d,%d) ", i, col[i]);
	}
	printf("\n");
}

int check(int n)
{
	int i = 0;
	for (i = 0; i < n; i++){
		if (col[i] == col[n] || abs(col[i] - col[n]) == (n - i)){//判断放置的皇后和前面的皇后不在同一列，不在同一对角线
			return 0;
		}
	}
	return 1;
}

void put(int n)
{
	int i = 0;
	if (n < N){
		for (i = 0; i < N; i++){
			col[n] = i;
			if (check(n)){
				put(n + 1);//如果和前面放置的不冲突，则继续放置后面的皇后
			}
		}
	}
	else{
		num++;
		print();//打印出每种放法
	}
}

int main()
{
	put(0);//从第一行开始放
	printf("一共%d种方法\n", num);
	system("pause");
	return 0;
}