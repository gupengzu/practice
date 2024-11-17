#include<stdio.h>
#include <stdlib.h>

//定义栈节点结构
typedef struct stackNode
{
	int data;
	struct stackNode* next;
}stackNode;

//定义栈结构
typedef struct Stack
{
	stackNode* top;
}Stack;

//创建一个栈
Stack createStack()
{
	Stack* stack = (Stack*)malloc(sizeof(Stack));
	stack->top = NULL;
}

//判断栈是否为空
int isEmpty(Stack* stack)
{
	return stack->top == NULL;
}

//入栈
void push(Stack* stack, int data)
{
	stackNode* stacknode = (stackNode*)malloc(sizeof(stackNode));
	stacknode->data = data;
	stacknode->next = stack->top;
	stack->top = stacknode;
}

//出栈
int pop(Stack* stack)
{
	if (isEmpty(stack))
	{
		printf("Stack is empty.\n");
		return -1;
	}
	stackNode*temp= stack->top;
	int data = temp->data;
	stack->top = stack->top->next;
	free(temp);
	return data;
}

//查看栈顶元素
int peek(Stack* stack)
{
	if (isEmpty(stack))
	{
		printf("false");
		return -1;
	}
	return stack->top->data;
}

//释放栈内存
void destoryStack(Stack* stack)
{
	stackNode* current = stack->top;
	while (current != NULL)
	{
		stackNode* next = current->next;
		free(current);
		current = next;
	}
	free(stack);
}