#include <stdio.h>
#include <windows.h>

#pragma warning(disable:4996)

int Count(int ret)
{
	int count = 0;
	while (ret){
		count++;
		ret &= (ret - 1);
	}
	return count;
}

int Dif(int m, int n)
{
	return m ^ n;
}

int main()
{
	int m = 0;
	int n = 0;
	int ret = 0;
	printf("������(m,n)��");
	scanf("%d,%d", &m, &n);
	ret = Dif(m, n);//��m��n�������в�ͬ�ı���λ���1
	ret = Count(ret);//����1�ĸ���
	printf("%d��%d��%d������λ��ͬ\n", m, n, ret);
	system("pause");
	return 0;
}