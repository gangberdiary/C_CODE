#include <stdio.h>
#include <windows.h>

#pragma warning(disable:4996)

void Search(int arr[], int left, int right, int num)
{
	int i = 0;
	int mid = 0;
	while (left <= right){
		mid = (left + right) / 2;
		if (arr[mid] > num){
			right = mid;
		}
		else if (arr[mid] < num){
			left = mid;
		}
		else{
			printf("�±�Ϊ��%d\n", mid);
			return;
		}
	}
	printf("�Ҳ���!\n");
}

int main()
{
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 24 };
	int num = 0;
	int left = 0;
	int right = sizeof(arr) / sizeof(arr[0]) - 1;
	printf("������Ҫ�Ѳ������>");
	scanf("%d", &num);
	Search(arr, left, right, num);
	system("pause");
	return 0;
}