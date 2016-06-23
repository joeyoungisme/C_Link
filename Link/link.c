#include "link.h"

LinkList *LinkList_FindEnd(LinkList *head)
{
	if(head == NULL) return NULL;

	if(head -> pNext == NULL) return head;
	
	return LinkList_FindEnd(head -> pNext);
}

LinkList *LinkList_NewItem()
{
	return malloc(sizeof(struct _LinkList));
}

void LinkList_Print(LinkList *head)
{
	if(head == NULL) return;
	else
	{
		printf(" -> %4d", head -> data);
		LinkList_Print(head -> pNext);
	}
}

void LinkList_Free(LinkList *head)
{
	if(head -> pNext == NULL) return;
	else
	{
		LinkList_Free(head -> pNext);
		free(head -> pNext);
	}
}

int LinkList_Init()
{
	root = NULL;
}

int LinkList_Add(int data)
{
	LinkList *pEnd = NULL;

	if (root == NULL)
	{
		root = LinkList_NewItem();
		root -> data = data;
	}
	else
	{
		pEnd = LinkList_FindEnd(root);
		pEnd -> pNext = LinkList_NewItem();
		pEnd -> pNext -> data = data;
	}

	return 0;
}

int LinkList_Get()
{
	int getData = 0;
	return getData;
}

int LinkList_List()
{
	printf("Root");
	LinkList_Print(root);
	printf("\n");
	return 0;
}

void LinkList_Close()
{
	LinkList_Free(root);
}
