#include <stdio.h>
#include <windows.h>
#define N 6//杨辉三角的行数

int arr[N][N] = { 0 };

void Yanghui()
{
	int i = 0;//横坐标
	int j = 0;//纵坐标
	for (i = 0; i < N; i++){
		arr[i][0] = 1;
	}
	for (i = 1; i < N; i++){
		for (j = 1; j <= i; j++){
			arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
		}
	}
}

void Show()//打印
{
	int i, j;
	for (i = 0; i < N; i++){
		for (j = 0; j <= i; j++){
			printf("%2d ", arr[i][j]);
		}
		printf("\n");
	}
}

int main()
{
	Yanghui();
	Show();
	system("pause");
	return 0;
}