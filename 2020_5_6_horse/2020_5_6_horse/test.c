#include <stdio.h>
#include <windows.h>
#include <math.h>

#pragma warning(disable:4996)

#define N (5 * 5)//棋盘大小5 * 5

int row[N] = { 0 };//存放行标
int col[N] = { 0 };//存放列标，意思是从（1，1）开始走
int num = 0;//一共有多少种方法

void print()
{
	int i = 0;
	int a, b;//因为C语言采用的是就近原则，所以这里不用row和col代表行和列，避免产生歧义
	int arr[5][5] = { 0 };
	for (i = 0; i < N; i++){
		/*a = row[i];
		b = col[i];
		arr[a][b] = i + 1;*/
		arr[row[i]][col[i]] = i + 1;
	}
	for (a = 0; a < 5; a++){
		for (b = 0; b < 5; b++){
			printf("%2d ", arr[a][b]);
		}
		printf("\n");
	}
	printf("\n");
}

int check(int n)
{
	int i = 0;
	if ((abs(row[n] - row[n - 1]) == 2 && abs(col[n] - col[n - 1]) == 1) || \
		(abs(row[n] - row[n - 1]) == 1 && abs(col[n] - col[n - 1]) == 2)){//判断是否走日
		for (i = 0; i < n; i++){
			if (row[i] == row[n] && col[i] == col[n]){
				return 0;//重复走则返回0
			}
		}
	}
	else{
		return 0;//不走日则返回0
	}
	return 1;//走日且不重复则返回1
}

void put(int n)
{
	int i = 0;
	int j = 0;
	if (n < N){
		for (i = 0; i < 5; i++){
			row[n] = i;
			for (j = 0; j < 5; j++){
				col[n] = j;
				if (check(n)){
					put(n + 1);//合适的话走下一步
				}
			}
		}
	}
	else{
		num++;
		print();//打印出每种方法
	}
}

int main()
{
	put(1);//从第二步开始，put(0)是第一步
	printf("一共有%d种方法\n", num);
	system("pause");
	return 0;
}