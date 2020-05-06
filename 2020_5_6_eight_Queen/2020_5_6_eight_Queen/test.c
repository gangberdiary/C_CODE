#include <stdio.h>
#include <windows.h>
#include <math.h>

#pragma warning(disable:4996)

#define N 8

int col[N] = { 0 };//���ÿһ�лʺ���б�
int num = 0;//һ���м��ַ���

void print()
{
	int i = 0;//��
	for (i = 0; i < N; i++){
		printf("(%d,%d) ", i, col[i]);
	}
	printf("\n");
}

int check(int n)
{
	int i = 0;
	for (i = 0; i < n; i++){
		if (col[i] == col[n] || abs(col[i] - col[n]) == (n - i)){//�жϷ��õĻʺ��ǰ��Ļʺ���ͬһ�У�����ͬһ�Խ���
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
				put(n + 1);//�����ǰ����õĲ���ͻ����������ú���Ļʺ�
			}
		}
	}
	else{
		num++;
		print();//��ӡ��ÿ�ַŷ�
	}
}

int main()
{
	put(0);//�ӵ�һ�п�ʼ��
	printf("һ��%d�ַ���\n", num);
	system("pause");
	return 0;
}