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
	int i = 0;//下标
	int max;//最大值
	printf("请输入十个数：\n");
	for (; i < 10; i++){
		scanf("%d", &arr[i]);
	}
	max = Cmp(arr);
	printf("最大值为：%d\n", max);
	system("pause");
	return 0;
}