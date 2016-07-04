#include "queue.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Queue_CheckSection()
{
	//int currSection = DataSection;

	if(iHead > iTail) DataSection = EXTERNAL;
	else DataSection = INTERNAL;

	//if(currSection != DataSection)
	//	printf("Swap Event!!!\n");
}
	
void Queue_Print()
{
	int index;
	index = iHead;

	while(index != iTail)
	{
		printf("%d ->", *(int *)(queueStart + index));
		index = ADDR_ADD(index);
	}
	printf("End\n", iHead, iTail);
}


int Queue_Init()
{
	queueStart = malloc(sizeof(char) * MAX_QUEUE_SIZE);
	memset(queueStart, 0, sizeof(char) * MAX_QUEUE_SIZE);
	printf("------ Queue Init Message ------\n");
	iHead = 0;
	iTail = 0;
	printf("iHead = %d\n", iHead);
	printf("iTail = %d\n", iTail);
	queueEnd = queueStart + MAX_QUEUE_SIZE;
	printf("Queue Start : %X\n", queueStart);
	printf("Queue End : %X\n", queueEnd);
	printf("--------------------------------\n");
}

int Queue_Add(unsigned int data)
{
	if(DataSection == INTERNAL)
	{
		if(SWAP_EVENT(iTail) && (ADDR_ADD(iTail) >= iHead))
		{
			printf("Error : Full Queue\n");
			return 1;
		}
	}
	else if(DataSection == EXTERNAL)
	{
		if(ADDR_ADD(iTail) >= iHead)
		{
			printf("Error : Full Queue\n");
			return 1;
		}
	}
	else
	{
		return 1;
	}

	/*
	if(DataSection == INTERNAL)
		printf("Add (Internal) Queue Address %X\n", queueStart + iTail);
	else
		printf("Add (External) Queue Address %X\n", queueStart + iTail);
	*/

	for(int index = 0; index < sizeof(int); ++index)
	{
		memcpy(queueStart + iTail, (void *)&data + index, 1);
		iTail = (iTail + 1) % MAX_QUEUE_SIZE;
	}
	

	Queue_CheckSection();

	return 0;
}

int Queue_Get()
{
	int index = 0;
	int getData = 0;

	//Queue Empty Check
	if(iHead == iTail)
	{
		printf("Error : Empty Queue\n");
		return 1;
	}
	else if(DataSection == INTERNAL)
	{
		if(ADDR_ADD(iHead) > iTail)
		{
			printf("Error : Empty Qeueu\n");
			return 1;
		}
	}
	else if(DataSection == EXTERNAL)
	{
		if(SWAP_EVENT(iHead) && ADDR_ADD(iHead) > iTail)
		{
			printf("Error : Empty Queue\n");
			return 1;
		}
	}
	else
	{
		return 1;
	}

	for(index = 0; index < sizeof(int); ++index)
	{
		memcpy((void *)&getData + index, queueStart + iHead, 1);
		iHead = (iHead + 1) % MAX_QUEUE_SIZE;
	}

	Queue_CheckSection();

	return getData;
}

int Queue_Show(QUEUE_SHOW showWhat)
{
	switch(showWhat)
	{
		case SHOW_QUEUE:
			Queue_Print();
			return 0;
		case SHOW_STATUS:
			break;
		case SHOW_INDEX:
			break;
		case SHOW_ADDRESS:
			break;
		default:
			break;
	}
	printf("------- Queue Show Message ------\n");
	printf("Head : %X (%d)\n", queueStart + iHead, iHead);
	printf("Tail : %X (%d)\n", queueStart + iTail, iTail);
	if(DataSection == INTERNAL)
		printf("Data Section : Internal\n");
	else if(DataSection == EXTERNAL)
		printf("Data Section : External\n");
	Queue_Print();
	printf("---------------------------------\n");
}

int Queue_Close()
{
	memset(queueStart, 0, sizeof(char) * MAX_QUEUE_SIZE);
	free(queueStart);
	queueStart = NULL;
	queueEnd = NULL;
	iHead = 0;
	iTail = 0;
}

