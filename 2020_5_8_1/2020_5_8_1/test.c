#include <stdio.h>
#include <string.h>
#include <windows.h>

void reverse(char *arr)
{
	char *left = arr;
	char *right = arr + strlen(arr) - 1;
	while (left < right){//���������ߵ�ֵ�����ڵݽ�
		char temp = *left;//����һ����ʱ���������ߵ�ֵ
		*left = *right;
		*right = temp;
		left++, right--;
	}
}

int main()
{
	char arr[] = "Hello world";
	printf("Before:%s\n", arr);
	reverse(arr);//���ַ�������
	printf("After :%s\n", arr);
	system("pause");
	return 0;
}