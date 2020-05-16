#include <stdio.h>
#include <windows.h>

void Swap(int arr[], int sz)
{
	int left = 0;
	int right = sz - 1;
	int temp = 0;
	while (left<right){
		while ((left < right) && (arr[left] % 2 == 0)){
			left++;
		}
		while ((left < right) && (arr[right] % 2 == 1)){
			right--;
		}
		if (left < right){
			temp = arr[left];
			arr[left] = arr[right];
			arr[right] = temp;
		}
	}
}

int main()
{
	int i = 0;
	int arr[] = { 0, 8, 9, 3, 4, 5, 2, 1, 6, 7 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	Swap(arr, sz);
	for (i = 0; i < sz; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");
	system("pause");
	return 0;
}