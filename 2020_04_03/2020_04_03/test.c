#include <stdio.h>
#include <windows.h>

#pragma warning(disable:4996)

void Gcd(int _num1, int _num2)
{
	int temp = 0;
	while (_num2 != 0){
		temp = _num2;
		_num2 = _num1 % temp;
		_num1 = temp;
	}
	printf("最大公约数：%d\n", temp);
}

int main()
{
	int num1, num2;
	int i = 0;
	printf("请输入两个数：>");
	scanf("%d %d", &num1, &num2);
	
	if (num1 < num2){
		int temp = num1;
		num1 = num2;
		num2 = temp;
	}
	
	Gcd(num1, num2);
	
	system("pause");
	return 0;
}