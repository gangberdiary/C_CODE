#include <stdio.h>
#include <windows.h>

#pragma warning(disable:4996)

void Swap(int a[], int b[], int sz)
{
	int i = 0;
	for (i = 0; i < sz; i++){
		int temp = a[i];
		a[i] = b[i];
		b[i] = temp;
	}
}

void print(int arr[], int sz)
{
	int i = 0;
	for (i = 0; i < sz; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int main()
{
	int a[] = { 2, 7, 6, 5, 3, 9, 8, 0, 1, 4 };
	int b[] = { 5, 2, 4, 1, 3, 9, 8, 7, 0, 6 };
	int sz = sizeof(a) / sizeof(a[0]);
	Swap(a, b, sz);
	print(a, sz);
	print(b, sz);
	system("pause");
	return 0;
}