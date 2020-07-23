#include <stdio.h>
#include <string.h>
#include <windows.h>

#pragma warning(disable:4996)

int Is_rotate(char arr[], char str[])
{
	int j = 1;
	int right = strlen(arr) - 1;
	//×óĞı
	while (j <= right){
		int i = 1;
		char temp[20] = { 0 };
		int k = 0;
		while (i <= right - j + 1){
			temp[i - 1] = *(arr + i);
			i++;
		}
		while (k < j){
			temp[i] = *(arr + k);
		}
		if (0 == strcmp(temp, str)){
			return 1;
		}
	}

}

int main()
{
	char arr[10] = { 0 };
	char str[10] = { 0 };
	printf("ÇëÊäÈë£º");
	scanf("%s", arr);
	scanf("%s", str);
	if (Is_rotate(arr, str)){
		printf("1\n");
	}
	else{
		printf("0\n");
	}
}