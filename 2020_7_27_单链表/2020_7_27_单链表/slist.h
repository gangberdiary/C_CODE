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

// 动态申请一个节点
SListNode* BuySListNode(SLTDateType x);
// 单链表打印
void SListPrint(SListNode* plist);
// 单链表尾插
void SListPushBack(SListNode** pplist, SLTDateType x);
// 单链表的头插
void SListPushFront(SListNode** pplist, SLTDateType x);
// 单链表的尾删
void SListPopBack(SListNode** pplist);
// 单链表头删
void SListPopFront(SListNode** pplist);
// 单链表查找
SListNode* SListFind(SListNode* plist, SLTDateType x);
// 单链表在pos位置之后插入x
void SListInsertAfter(SListNode* pos, SLTDateType x);
// 单链表删除pos位置之后的值
void SListEraseAfter(SListNode* pos);
// 单链表的销毁
void SListDestory(SListNode** plist);
///////////////////////////////////////////////////////////////

// 动态申请一个节点
SListNode* BuySListNode(SLTDateType x)
{
	SListNode* s = (SListNode*)malloc(sizeof(SListNode));
	s->data = x;
	s->next = NULL;
	return s;
}

// 单链表打印
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

// 单链表尾插
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

// 单链表的头插
void SListPushFront(SListNode** pplist, SLTDateType x)
{
	assert(pplist);
	SListNode* p = BuySListNode(x);
	p->data = x;
	p->next = *pplist;
	*pplist = p;
}

// 单链表的尾删
void SListPopBack(SListNode** pplist)
{
	assert(pplist);
	SListNode* p = *pplist;
	SListNode* prev = NULL;

	if (p == NULL){//结点为空
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

// 单链表头删
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

//单链表查找
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

// 单链表在pos位置之后插入x
void SListInsertAfter(SListNode* pos, SLTDateType x)
{
	assert(pos);
	SListNode* next = pos->next;
	SListNode* p = BuySListNode(x);
	pos->next = p;
	p->next = next;
}

// 单链表删除pos位置之后的值
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

// 单链表的销毁
void SListDestory(SListNode** plist)
{
	assert(plist);
	while (*plist != NULL){
		SListPopFront(plist);
	}
}

#endif _SLIST_H_