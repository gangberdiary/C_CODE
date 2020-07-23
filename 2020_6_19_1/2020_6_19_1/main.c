#include "test.h"

int main()
{
	int input = 0;
	Contact con;
	InitContact(&con);
	do{
		menu();
		printf("请选择：>");
		scanf("%d", &input);
		switch (input){
		case 1:
			Add(&con);//添加
			break;
		case 2:
			Delete(&con);//删除
			break;
		case 3:
			Serch(&con);//查找
			break;
		case 4:
			Alter(&con);//修改
			break;
		case 5:
			Show(&con);//显示
			break;
		case 6:
			Clear(&con);//清空
			break;
		case 7:
			OrderByName(&con);//按名字排序
			break;
		case 0:
			printf("退出\n");
			return 0;
		default:
			printf("输入错误，请重新输入！\n");
			break;
		}
	} while (input);
	system("pause");
	return 0;
}