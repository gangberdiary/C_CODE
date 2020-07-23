#ifndef _TEST_H_
#define _TEST_H_

#include <stdio.h>
#include <windows.h>
#include <assert.h>
#include <string.h>

#pragma warning(disable:4996)

#define MAX 100

typedef struct People
{
	char name[20];
	char telephone[20];
}People;

typedef struct Contact
{
	People data[MAX];
	int sz;
}Contact;

void menu();
void InitContact(Contact* con);
void Add(Contact* con);
void Delete(Contact* con);
void Serch(Contact* con);
void Alter(Contact* con);
void Show(Contact* con);
void Clear(Contact* con);
void OrderByName(Contact* con);

#endif _TEST_H_