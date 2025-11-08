#include "myProgram.h"

int main(int argc, char *argv[])
{
	printf("Link List Test : \n");

	int result = 0;

	/*
	//Call Link Init
	result = LinkList_Init();

	//Call Link Add
	//Call Link List
	int index = 0; 
	for(index = 10; index > 0; --index)
	{
		LinkList_List();
		result = LinkList_Add(index);
	}
	
	for(index = 0; index < 10; ++index)
	{
		LinkList_List();
		LinkList_Get(LINK_HEAD);
	}

	if(!root) printf("Root is NULL\n");
	else printf("Fuck root is not NULL\n");

	//Call Link Add
	//Call Link List
	for(index = 10; index > 0; --index)
	{
		LinkList_List();
		result = LinkList_Add(index);
	}
	for(index = 0; index < 10; ++index)
	{
		LinkList_List();
		LinkList_Get(LINK_TAIL);
	}

	//Call Link Close
	LinkList_Close();

	printf("\n\n\n");

	*/
	
	/*
	printf("Queue Test \n");

	result = Queue_Init();
	
	for(int runIndex = 0; runIndex < 5; ++runIndex)
	{
		for(int index = 0; index < 150; ++index)
		{
			Queue_Add(index);
			Queue_Show(SHOW_QUEUE);
		}
	
		Queue_Show(SHOW_STATUS);

		for(int index = 0; index < 150; ++index)
		{
			Queue_Get();
			Queue_Show(SHOW_QUEUE);
		}

		Queue_Show(SHOW_STATUS);
	}

	Queue_Close();

	*/
	
	/*
	printf("Stack Test \n");

	STACK *myStack = Stack_Create(1000);

	int iData = 10;
	char cData[] = "Hello World";
	float fData = 0.05;

	*(int *)Stack_Push(myStack, sizeof(iData)) = iData;

	//*(char *)Stack_Push(myStack, sizeof(cData)) = cData;
	memcpy(Stack_Push(myStack, strlen(cData)), cData, strlen(cData));

	*(float *)Stack_Push(myStack, sizeof(fData)) = fData;

	printf("Pop Float = %f\n", *(float *)Stack_Pop(myStack, sizeof(float)));
	printf("Pop char = %s\n", (char *)Stack_Pop(myStack, strlen(cData)));
	printf("Pop Int = %d\n", *(int *)Stack_Pop(myStack, sizeof(int)));

	Stack_Destory(myStack);

printf("joeyoung test\n");
	*/

	return 0;
}
