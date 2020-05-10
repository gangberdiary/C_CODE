#include <stdio.h>
#include <string.h>
#include <windows.h>

void reverse(char *arr)
{
	char *left = arr;
	char *right = arr + strlen(arr) - 1;
	while (left < right){//交换最两边的值，向内递进
		char temp = *left;//创建一个临时变量存放左边的值
		*left = *right;
		*right = temp;
		left++, right--;
	}
}

int main()
{
	char arr[] = "Hello world";
	printf("Before:%s\n", arr);
	reverse(arr);//将字符串逆序
	printf("After :%s\n", arr);
	system("pause");
	return 0;
}