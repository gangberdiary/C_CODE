#include <stdio.h>
#include <windows.h>
#include <math.h>

#pragma warning(disable:4996)

#define N (5 * 5)//���̴�С5 * 5

int row[N] = { 0 };//����б�
int col[N] = { 0 };//����б꣬��˼�Ǵӣ�1��1����ʼ��
int num = 0;//һ���ж����ַ���

void print()
{
	int i = 0;
	int a, b;//��ΪC���Բ��õ��Ǿͽ�ԭ���������ﲻ��row��col�����к��У������������
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
		(abs(row[n] - row[n - 1]) == 1 && abs(col[n] - col[n - 1]) == 2)){//�ж��Ƿ�����
		for (i = 0; i < n; i++){
			if (row[i] == row[n] && col[i] == col[n]){
				return 0;//�ظ����򷵻�0
			}
		}
	}
	else{
		return 0;//�������򷵻�0
	}
	return 1;//�����Ҳ��ظ��򷵻�1
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
					put(n + 1);//���ʵĻ�����һ��
				}
			}
		}
	}
	else{
		num++;
		print();//��ӡ��ÿ�ַ���
	}
}

int main()
{
	put(1);//�ӵڶ�����ʼ��put(0)�ǵ�һ��
	printf("һ����%d�ַ���\n", num);
	system("pause");
	return 0;
}