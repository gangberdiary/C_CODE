#include "stack.h"

int main()
{
	int input = 0;
	Stack S;
	StackInit(&S);
	printf("请输入数据(以-1结束)：");
	while (scanf("%d", &input) && input != -1){
		StackPush(&S, input);
	}
	StackShow(&S);
	StackPop(&S);
	StackPop(&S);
	StackShow(&S);
	system("pause");
	return 0;
}