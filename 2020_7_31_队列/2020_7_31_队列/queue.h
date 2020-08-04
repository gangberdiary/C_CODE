#ifndef _QUEUE_H_
#define _QUEUE_H_
#include "common.h"

typedef int QDataType;
// ��ʽ�ṹ����ʾ���� 
typedef struct QListNode
{
	struct QListNode* next;
	QDataType data;
}QNode;

// ���еĽṹ 
typedef struct Queue
{
	QNode* front;
	QNode* rear;
}Queue;

// ��ʼ������ 
void QueueInit(Queue* q);
// ��β����� 
void QueuePush(Queue* q, QDataType data);
// ��ͷ������ 
void QueuePop(Queue* q);
//��ʾ
void QueueShow(Queue* q);
// ��ȡ����ͷ��Ԫ�� 
QDataType QueueFront(Queue* q);
// ��ȡ���ж�βԪ�� 
QDataType QueueBack(Queue* q);
// ��ȡ��������ЧԪ�ظ��� 
int QueueSize(Queue* q);
// �������Ƿ�Ϊ�գ����Ϊ�շ��ط�����������ǿշ���0 
int QueueEmpty(Queue* q);
// ���ٶ��� 
void QueueDestroy(Queue* q);
//////////////////////////////////////////////////////////////////////////////////////////////
// ��ʼ������ 
void QueueInit(Queue* q)
{
	assert(q);
	q->front = q->rear = NULL;
}

// ��β����� 
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

// ��ͷ������ 
void QueuePop(Queue* q)
{
	assert(q);
	if (q == NULL){
		printf("�����ѿգ�\n");
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

//��ʾ
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

// ��ȡ����ͷ��Ԫ��
QDataType QueueFront(Queue* q)
{
	assert(q);
	assert(q->front);
	return q->front->data;
}

// ��ȡ���ж�βԪ�� 
QDataType QueueBack(Queue* q)
{
	assert(q);
	assert(q->rear);
	return q->rear->data;
}

// ��ȡ��������ЧԪ�ظ��� 
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

// �������Ƿ�Ϊ�գ����Ϊ�շ��ط�����������ǿշ���0 
int QueueEmpty(Queue* q)
{
	assert(q);
	if (q->front == NULL){
		return 1;
	}
	return 0;
}

// ���ٶ��� 
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