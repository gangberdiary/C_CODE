#include "test.h"

int main()
{
	int input = 0;
	Contact con;
	InitContact(&con);
	do{
		menu();
		printf("��ѡ��>");
		scanf("%d", &input);
		switch (input){
		case 1:
			Add(&con);//���
			break;
		case 2:
			Delete(&con);//ɾ��
			break;
		case 3:
			Serch(&con);//����
			break;
		case 4:
			Alter(&con);//�޸�
			break;
		case 5:
			Show(&con);//��ʾ
			break;
		case 6:
			Clear(&con);//���
			break;
		case 7:
			OrderByName(&con);//����������
			break;
		case 0:
			printf("�˳�\n");
			return 0;
		default:
			printf("����������������룡\n");
			break;
		}
	} while (input);
	system("pause");
	return 0;
}