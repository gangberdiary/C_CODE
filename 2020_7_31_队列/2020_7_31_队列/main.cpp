#include "queue.h"

int main()
{
	int input = 0;

	Queue Q;
	QueueInit(&Q);

	printf("���������ݣ���-1Ϊ������־����");
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