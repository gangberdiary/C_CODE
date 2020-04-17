#include <stdio.h>
#include <windows.h>

#pragma warning(disable:4996)

int Fib(int n)
{
	if (n == 1 || n == 2){
		return 1;
	}
	else{
		return Fib(n - 1) + Fib(n - 2);
	}
}

int main()
{
	int n = 0;
	int ret = 0;
	printf("«Î ‰»Î£∫");
	scanf("%d", &n);
	ret = Fib(n);
	printf("%d", ret);
	system("pause");
	return 0;
}