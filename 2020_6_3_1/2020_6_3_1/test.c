#include <stdio.h>
#include <windows.h>
#include <stdlib.h>

int com_int(const void* x, const void* y)
{
	int *a = (int *)x;
	int *b = (int *)y;
	if (*a > *b){
		return 1;
	}
	else if (*a < *b){
		return -1;
	}
	else{
		return 0;
	}
}

int main()
{
	int i = 0;
	int arr[] = { 4, 32, 2, 4, 8, 7, 5, 4, 1, 9 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	qsort(arr, sz, sizeof(int), com_int);
	for (i = 0; i < sz; i++){
		printf("%2d ", arr[i]);
	}
	system("pause");
	return 0;
}