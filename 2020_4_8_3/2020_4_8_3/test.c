#include <stdio.h>
#include <windows.h>

#pragma warning(disable:4996)

int Cmp(int arr[])
{
	int temp = arr[0];
	int i = 1;
	for (; i < 10; i++){
		if (temp < arr[i]){
			temp = arr[i];
		}
	}
	return temp;
}

int main()
{
	int arr[10] = { 0 };
	int i = 0;//�±�
	int max;//���ֵ
	printf("������ʮ������\n");
	for (; i < 10; i++){
		scanf("%d", &arr[i]);
	}
	max = Cmp(arr);
	printf("���ֵΪ��%d\n", max);
	system("pause");
	return 0;
}