#include "stack.h"

STACK *Stack_Create(size_t size)
{
	STACK *pStack = (STACK *)malloc(size + sizeof(STACK));
	memset(pStack, 0, size + sizeof(STACK));

	pStack -> pTop = (char *)&pStack[1];
	pStack -> pBottom = pStack -> pTop + size;

	return pStack;
}

void Stack_Destory(STACK *pStack)
{
	free(pStack);
}

static size_t Stack_Available(STACK *pStack)
{
	return pStack -> pTop - pStack -> pBottom;
}

void *Stack_Push(STACK *pStack, size_t size)
{
	if(Stack_Available(pStack) < size)
		return NULL;

	void *memAddr = (void *)pStack -> pTop;

	pStack -> pTop += size;

	return memAddr;
}

void *Stack_Pop(STACK *pStack, size_t size)
{
	if(Stack_Available(pStack) < size)
		return NULL;

	pStack -> pTop -= size;

	return (void *)pStack -> pTop;
}
