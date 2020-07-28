#ifndef _SLIST_H_
#define _SLIST_H_

#include "common.h"

// slist.h
typedef int SLTDateType;
typedef struct SListNode
{
	SLTDateType data;
	struct SListNode* next;
}SListNode;

// ��̬����һ���ڵ�
SListNode* BuySListNode(SLTDateType x);
// �������ӡ
void SListPrint(SListNode* plist);
// ������β��
void SListPushBack(SListNode** pplist, SLTDateType x);
// �������ͷ��
void SListPushFront(SListNode** pplist, SLTDateType x);
// �������βɾ
void SListPopBack(SListNode** pplist);
// ������ͷɾ
void SListPopFront(SListNode** pplist);
// ���������
SListNode* SListFind(SListNode* plist, SLTDateType x);
// ��������posλ��֮�����x
void SListInsertAfter(SListNode* pos, SLTDateType x);
// ������ɾ��posλ��֮���ֵ
void SListEraseAfter(SListNode* pos);
// �����������
void SListDestory(SListNode** plist);
///////////////////////////////////////////////////////////////

// ��̬����һ���ڵ�
SListNode* BuySListNode(SLTDateType x)
{
	SListNode* s = (SListNode*)malloc(sizeof(SListNode));
	s->data = x;
	s->next = NULL;
	return s;
}

// �������ӡ
void SListPrint(SListNode* plist)
{
	SListNode* p = plist;
	while (p != NULL)
	{
		printf("%d->", p->data);
		p = p->next;
	}
	printf("over\n");
}

// ������β��
void SListPushBack(SListNode** pplist, SLTDateType x)
{
	SListNode* p = BuySListNode(x);

	if (*pplist == NULL)
	{
		*pplist = p;
	}
	else
	{
		SListNode* tail = *pplist;
		while (tail->next != NULL)
		{
			tail = tail->next;
		}

		tail->next = p;
	}
}

// �������ͷ��
void SListPushFront(SListNode** pplist, SLTDateType x)
{
	assert(pplist);
	SListNode* p = BuySListNode(x);
	p->data = x;
	p->next = *pplist;
	*pplist = p;
}

// �������βɾ
void SListPopBack(SListNode** pplist)
{
	assert(pplist);
	SListNode* p = *pplist;
	SListNode* prev = NULL;

	if (p == NULL){//���Ϊ��
		return;
	}
	else{
		while (p->next != NULL){
			prev = p;
			p = p->next;
		}

		if (prev == NULL){
			*pplist = NULL;
		}
		else{
			prev->next = NULL;
		}
		free(p);
	}
}

// ������ͷɾ
void SListPopFront(SListNode** pplist)
{
	assert(pplist);
	SListNode* p = *pplist;
	if (p == NULL){
		return;
	}
	else{
		*pplist = p->next;
		free(p);
	}
}

//���������
SListNode* SListFind(SListNode* plist, SLTDateType x)
{
	SListNode* p = plist;
	while (p)
	{
		if (p->data == x)
			return p;

		p = p->next;
	}

	return NULL;
}

// ��������posλ��֮�����x
void SListInsertAfter(SListNode* pos, SLTDateType x)
{
	assert(pos);
	SListNode* next = pos->next;
	SListNode* p = BuySListNode(x);
	pos->next = p;
	p->next = next;
}

// ������ɾ��posλ��֮���ֵ
void SListEraseAfter(SListNode* pos)
{
	assert(pos);
	SListNode* next = pos->next;

	if (next != NULL)
	{
		SListNode* nextnext = next->next;
		free(next);
		pos->next = nextnext;
	}
}

// �����������
void SListDestory(SListNode** plist)
{
	assert(plist);
	while (*plist != NULL){
		SListPopFront(plist);
	}
}

#endif _SLIST_H_