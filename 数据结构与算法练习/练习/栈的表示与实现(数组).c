//用数组实现
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define stack_size 100
typedef struct
{
	int data[stack_size];
	int top;
	int bottom;
}Stack;

//创建数组栈
Stack* createStack()
{
	Stack* stack = (Stack*)malloc( sizeof(Stack));
	stack->top = -1;
	stack->bottom = 0;
	return stack;
}

//判断是否为空
bool isEmpty(Stack*stack)
{
	return stack->top == -1;
}

//判断是否为满
bool isFull(Stack* stack)
{
	return stack->top == stack_size - 1;
}

//入栈
void push(Stack* stack, int p)
{
	if (isFull(stack))
	{
		printf("栈满了");
	}
	stack->top++;
	stack->data[stack->top] = p;
}

//出栈
int pop(Stack* stack)
{
	if (isEmpty(stack))
	{
		printf("栈已空");
		return -1;
	}
	return stack->data[stack->top--];
}

//查看栈顶元素
int peek(Stack* stack)
{
	if (isEmpty(stack))
	{
		printf("栈为空");
		return -1;
	}
	return stack->data[stack->top];
}

//清空栈
void destoryStack(Stack* stack)
{
	free(stack);
}

//int main()
//{
//	Stack* stack1 = createStack();
//	push(stack1, 3);
//	printf("%d", peek(stack1));
//	return 0;
//}