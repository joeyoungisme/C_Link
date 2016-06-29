#ifndef LINK_H
#define LINK_H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define LINK_HEAD	0
#define LINK_TAIL	1


int LinkList_Init();
int LinkList_Add(int data);
int LinkList_Get();
int LinkList_List();
void LinkList_Close();

typedef struct _LinkList{
	struct _LinkList *pNext;
	int data;
}LinkList;

static LinkList *root;

#endif
