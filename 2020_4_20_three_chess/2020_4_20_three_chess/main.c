#include "test.h"

void menu()
{
	printf("################################\n");
	printf("##### ��ӭ������������Ϸ�� #####\n");
	printf("################################\n");
	printf("#####      1.����Ϸ        #####\n");
	printf("#####      2.�˳���Ϸ      #####\n");
	printf("################################\n");
}

int main()
{
	int select = 0;
	do{
		menu();//Ŀ¼
		printf("��ѡ��");
		scanf("%d", &select);
		switch (select){
		case 1:
			Game();
			printf("����һ�ѣ�\n");
			break;
		case 2:
			printf("�˳���Ϸ��\n");
			break;
		default:
			printf("����������������룡\n");
		}
	} while (2 != select);
	system("pause");
	return 0;
}