#include "link.h"

LinkList *LinkList_SecondLast(LinkList *head, LinkList *pEnd)
{
	if(!head) return NULL;

	if(head -> pNext == pEnd) return head;
	
	return LinkList_SecondLast(head -> pNext, pEnd);
}

LinkList *LinkList_FindEnd(LinkList *head)
{
	if(head == NULL) return NULL;

	if(head -> pNext == NULL) return head;
	
	return LinkList_FindEnd(head -> pNext);
}

LinkList *LinkList_NewItem()
{
	LinkList *pNew;
	pNew = malloc(sizeof(struct _LinkList));
	memset(pNew, 0, sizeof(struct _LinkList));
	return pNew;
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

	if (!root)
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

int LinkList_Get(int flag)
{
	LinkList *pTemp;
	int getData = 0;
	
	if(!root)
	{
		printf("No Data\n");
		return 0;
	}

	switch(flag)
	{
		case LINK_HEAD:
			pTemp = root -> pNext;
			getData = root -> data;
			free(root);
			root = pTemp;
			return getData;
		case LINK_TAIL:
			pTemp = LinkList_SecondLast(root, LinkList_FindEnd(root));
			if(!pTemp)
			{
				getData = root -> data;
				free(root);
				root = pTemp;
			}
			else
			{
				getData = pTemp -> pNext -> data;
				free(pTemp -> pNext);
				pTemp -> pNext = NULL;
			}
			return getData;
		default:
			return 1;
	}
	return getData;
}

int LinkList_List()
{
	printf("Root");
	if(root) LinkList_Print(root);
	printf("\n");
	return 0;
}

void LinkList_Close()
{
	if(root) LinkList_Free(root);
}
