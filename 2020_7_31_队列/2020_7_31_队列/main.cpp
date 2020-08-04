#include "queue.h"

int main()
{
	int input = 0;

	Queue Q;
	QueueInit(&Q);

	printf("请输入数据（以-1为结束标志）：");
	while (scanf("%d", &input) && input != -1){
		QueuePush(&Q, input);
	}
	QueueShow(&Q);
	QueuePop(&Q);
	QueuePop(&Q);
	QueueShow(&Q);
	system("pause");
	return 0;
}