#include <stdio.h>
#include <windows.h>
#include <assert.h>

int my_strlen(const char *arr)
{
	int count = 0;//¼ÆÊı
	while (*arr++){
		count++;
	}
	return count;
}

int main()
{
	char arr[] = "hello world";
	int num = my_strlen(arr);
	printf("%d\n", num);
	system("pause");
	return 0;
}