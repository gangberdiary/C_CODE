#include "seqList.h"

int main()
{
	int input = 1;//输入
	int select = 1;//选择
	
	SeqList List;//定义顺序表

	SeqListInit(&List);//顺序表初始化

	int value = 0;//值
	int pos = 0;//位置

	do{
		printf("*********************************************\n");
		printf("*  [1] push_back           [2] push_front   *\n");
		printf("*  [3] show_list           [4] find_pos     *\n");
		printf("*  [5] pop_back            [6] pop_front    *\n");
		printf("*  [7] insert_pos          [8] pop_pos   *\n");
		printf("*  [9] destory             [0]exit          *\n");
		printf("*********************************************\n");
		printf("请选择:>");
		scanf("%d", &select);
		switch (select){
		case 0:
			return 0;
		case 1:
			printf("请输入数据(以-1为结束标志):>");
			while (scanf("%d", &input) && input != -1){
				SeqListPushBack(&List, input);
			}
			printf("尾插法插入成功！\n");
			break;
		case 2:
			printf("请输入数据(以-1为结束标志):>");
			while (scanf("%d", &input) && input != -1){
				SeqListPushFront(&List, input);
			}
			printf("头插法插入成功！\n");
			break;
		case 3:
			SeqListPrint(&List);
			break;
		case 4:
			printf("请输入要查找的值：>");
			scanf("%d", &value);
			printf("下标为：%d", SeqListFind(&List, pos));
			break;
		case 5:
			SeqListPopBack(&List);
			break;
		case 6:
			SeqListPopFront(&List);
			break;
		case 7:
			printf("请输入要插入的值：>");
			scanf("%d", &value);
			printf("请输入要插入的位置：>");
			scanf("%d", &pos);
			SeqListInsert(&List, pos, value);
			break;
		case 8:
			printf("请输入要删除的位置：>");
			scanf("%d", &pos);
			SeqListErase(&List, pos);
			break;
		case 9:
			SeqListDestory(&List);
			break;
		default:
			printf("输入错误，请重新输入！\n");
			break;
		}
		system("pause");
		system("cls");
	} while (input);

	system("pause");
	return 0;
}