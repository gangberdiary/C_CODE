#include "mine.h"

void menu()
{
	printf("###############################\n");
	printf("####  ��ӭ����ɨ����Ϸ��  #####\n");
	printf("###############################\n");
	printf("####       1.����Ϸ       #####\n");
	printf("####       2.�˳���Ϸ     #####\n");
	printf("###############################\n");
}

int main()
{
	int select = 0;
	do{
		menu();
		printf("��ѡ��>");
		scanf("%d", &select);
		switch (select){
		case 1:
			Game();
			printf("��Ϸ������\n");
			break;
		case 2:
			printf("�˳��ɹ���\n");
			break;
		default:
			printf("����������������룡\n");
			break;
		}
	} while(2 != select);

	system("pause");
	return 0;
}