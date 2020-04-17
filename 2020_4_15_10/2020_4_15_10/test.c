#include <stdio.h>
#include <windows.h>

#pragma warning(disable:4996)

int Result(int num, int k)
{
	 if(k > 0){
		return num * Result(num, k - 1);
		printf("%d \n", k);
	}
	 else{
		 return 1;
	 }
}

int main()
{
	int num = 0;
	int k = 0;
	int ret = 0;
	printf("Çë·Ö±ðÊäÈë£º>");
	scanf("%d %d", &num, &k);
	ret = Result(num, k);
	printf("%d", ret);
	system("pause");
	return 0;
}