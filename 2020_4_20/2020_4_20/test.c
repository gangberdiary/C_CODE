#include <stdio.h>
#include <windows.h>

#pragma warning(disable:4996)

void Bubble_Sort(int arr[], int num)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < num - 1; i++){
		int flag = 0;
		for (j = 0; j < num - 1 - i; j++){
			if (arr[j] > arr[j + 1]){
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
				flag = 1;
			}
		}
		if (0 == flag){
			return;
		}
	}
}

int main()
{
	int arr[] = { 0, 3, 5, 6, 4, 1, 9, 8, 7, 10 };
	int i = 0;
	int num = sizeof(arr) / sizeof(arr[0]);//数组元素的个数
	Bubble_Sort(arr, num);//冒泡排序
	for (i = 0; i < num; i++){
		printf("%d ", arr[i]);
	}
	system("pause");
	return 0;
}