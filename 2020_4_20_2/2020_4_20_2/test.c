#include <stdio.h>
#include <windows.h>

#pragma warning(disable:4996)

#define NUM 10

//≥ı ºªØ
void init(int arr[])
{
	int i = 0;
	while (i++ < NUM){
		arr[i] = 0;
	}
}

void print(int arr[])
{
	int i = 0;
	while (i < NUM){
		printf("%d ", arr[i]);
		i++;
	}
	printf("\n");
}

void reverse(int arr[])
{
	int left = 0;
	int right = NUM - 1;
	while (left <= right){
		int temp = arr[left];
		arr[left] = arr[right];
		arr[right] = temp;
		left++;
		right--;
	}
}

int main()
{
	int arr[NUM];
	int i = 0;
	init(arr);
	printf("«Î ‰»Î£∫\n");
	for (i = 0; i < NUM; i++){
		scanf("%d", &arr[i]);
	}
	printf("BEFORE:");
	print(arr);
	reverse(arr);
	printf("AFTER:");
	print(arr);
	system("pause");
	return 0;
}