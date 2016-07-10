#ifndef STACK_H
#define STACK_H

#include<stdlib.h>
#include<stdio.h>
#include<string.h>

typedef struct _Stack
{
	char *pTop;
	char *pBottom;
}STACK;

STACK *Stack_Create(size_t size);

void Stack_Destory(STACK *pStack);

void *Stack_Push(STACK *pStack, size_t size);

void *Stack_Pop(STACK *pStack, size_t size);


#endif
