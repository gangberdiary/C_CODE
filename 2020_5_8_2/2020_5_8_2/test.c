#include <stdio.h>
#include <windows.h>

#pragma warning(disable:4996)

void Sn(int a, int n)
{
	int i = 0;;
	int num = a;
	int sum = 0;//算式和
	for (i = 0; i < n; i++){
		sum += num;
		if (n - 1 != i){
			printf("%d + ", num);
		}
		else{
			printf("%d = ", num);
		}
		num = num * 10 + a;
	}
	printf("%d\n", sum);
}

int main()
{
	int a, n;
	printf("请分别输入a和n：");
	scanf("%d %d", &a, &n);
	Sn(a, n);
	system("pause");
	return 0;
}