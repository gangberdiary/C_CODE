#include <stdio.h>
#include <windows.h>
#include <assert.h>

char* my_strcat(char arr[], const char *str)
{
	char *arr1 = arr;
	assert(arr && str);//����
	while (*arr1){
		arr1++;//��ʹ��ƴ�ӵ��ַ���ָ��\0��
	}
	while (*arr1++ = *str++){//��Ҫƴ�ӵ��ַ���ƴ����ȥ
		;
	}
	return arr1;
}

int main()
{
	char arr[20] = "hello ";
	my_strcat(arr, "world");//�Լ�ʵ�ֵ�strcat()
	printf("%s\n", arr);
	system("pause");
	return 0;
}