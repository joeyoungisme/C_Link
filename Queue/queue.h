#ifndef QUEUE_H
#define QUEUE_H

#include<stdio.h>
#include<stdlib.h>

#define MAX_QUEUE_SIZE			1000
#define SWAP_EVENT(x)			((x) + sizeof(int) >= MAX_QUEUE_SIZE ? 1:0)
#define ADDR_ADD(x)			(((x) + sizeof(int)) % MAX_QUEUE_SIZE)
#define INTERNAL			0
#define EXTERNAL			1

unsigned char DataSection = 0;

typedef enum {
	QUEUE_ADD = 0,
	QUEUE_GET,
	QUEUE_ACT_AMOUNT
}QUEUE_ACTION;

typedef enum {
	QUEUE_NORMAL = 0,
	QUEUE_EMPTY,
	QUEUE_FULL,
	QUEUE_STATUS_AMOUNT
}QUEUE_STATUS;

typedef enum {
	SHOW_QUEUE = 0,
	SHOW_STATUS,
	SHOW_INDEX,
	SHOW_ADDRESS,
	SHOW_MSG_AMOUNT
}QUEUE_SHOW;

void *queueStart = NULL;
void *queueEnd = NULL;

int iHead = 0;
int iTail = 0;

int Queue_Init();
int Queue_Add(unsigned int data);
int Queue_Get();
int Queue_Show(QUEUE_SHOW showWhat);
int Queue_Close();

#endif
