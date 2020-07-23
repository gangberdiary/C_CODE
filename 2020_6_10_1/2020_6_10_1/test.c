#include <stdio.h>
#include <windows.h>
#include <assert.h>

char* my_strcat(char arr[], const char *str)
{
	char *arr1 = arr;
	assert(arr && str);//断言
	while (*arr1){
		arr1++;//先使被拼接的字符串指向‘\0’
	}
	while (*arr1++ = *str++){//把要拼接的字符串拼接上去
		;
	}
	return arr1;
}

int main()
{
	char arr[20] = "hello ";
	my_strcat(arr, "world");//自己实现的strcat()
	printf("%s\n", arr);
	system("pause");
	return 0;
}