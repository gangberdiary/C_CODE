#include <stdio.h>
#include <windows.h>

#pragma warning(disable:4996)

void Print(int *p, int sz)
{
	int i = 0;
	for (; i < sz; i++){
		printf("%d ", *(p + i));
	}
	printf("\n");
}

int main()
{
	int arr[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	Print(arr, sz);
	system("pause");
	return 0;
}