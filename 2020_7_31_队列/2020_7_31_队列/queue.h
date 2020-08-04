#ifndef _QUEUE_H_
#define _QUEUE_H_
#include "common.h"

typedef int QDataType;
// 链式结构：表示队列 
typedef struct QListNode
{
	struct QListNode* next;
	QDataType data;
}QNode;

// 队列的结构 
typedef struct Queue
{
	QNode* front;
	QNode* rear;
}Queue;

// 初始化队列 
void QueueInit(Queue* q);
// 队尾入队列 
void QueuePush(Queue* q, QDataType data);
// 队头出队列 
void QueuePop(Queue* q);
//显示
void QueueShow(Queue* q);
// 获取队列头部元素 
QDataType QueueFront(Queue* q);
// 获取队列队尾元素 
QDataType QueueBack(Queue* q);
// 获取队列中有效元素个数 
int QueueSize(Queue* q);
// 检测队列是否为空，如果为空返回非零结果，如果非空返回0 
int QueueEmpty(Queue* q);
// 销毁队列 
void QueueDestroy(Queue* q);
//////////////////////////////////////////////////////////////////////////////////////////////
// 初始化队列 
void QueueInit(Queue* q)
{
	assert(q);
	q->front = q->rear = NULL;
}

// 队尾入队列 
void QueuePush(Queue* q, QDataType data)
{
	assert(q);
	QNode* s = (QNode*)malloc(sizeof(QNode));
	assert(s);
	s->data = data;
	s->next = NULL;
	if (q->front == NULL){
		q->front = q->rear = s;
	}
	else{
		q->rear->next = s;
		q->rear = s;
	}
}

// 队头出队列 
void QueuePop(Queue* q)
{
	assert(q);
	if (q == NULL){
		printf("队列已空！\n");
	}
	QNode* p = q->front;
	if (q->front == q->rear){
		q->front = q->rear = NULL;
	}
	else{
		q->front = p->next;
	}
	free(p);
	p = NULL;
}

//显示
void QueueShow(Queue* q)
{
	assert(q);
	QNode *p = q->front;
	while(p != NULL){
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}

// 获取队列头部元素
QDataType QueueFront(Queue* q)
{
	assert(q);
	assert(q->front);
	return q->front->data;
}

// 获取队列队尾元素 
QDataType QueueBack(Queue* q)
{
	assert(q);
	assert(q->rear);
	return q->rear->data;
}

// 获取队列中有效元素个数 
int QueueSize(Queue* q)
{
	int count = 0;
	assert(q);
	QNode *p = q->front;
	while (p != NULL){
		count++;
		p = p->next;
	}
	return count;
}

// 检测队列是否为空，如果为空返回非零结果，如果非空返回0 
int QueueEmpty(Queue* q)
{
	assert(q);
	if (q->front == NULL){
		return 1;
	}
	return 0;
}

// 销毁队列 
void QueueDestroy(Queue* q)
{
	assert(q);
	QNode* p = q->front;
	while (p != NULL){
		q->front = p->next;
		free(p);
		p = q->front;
	}
}

#endif _QUEUE_H_