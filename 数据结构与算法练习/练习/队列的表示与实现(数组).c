#include<stdio.h>
#include <stdbool.h>

#define Max 100
//数组队列结构
typedef struct
{
	int data[Max];
	int front;
	int rear;
}Queue;

//创建一个队列
Queue* createQueue()
{
	Queue* queue = (Queue*)malloc(sizeof(Queue));
	queue->front = queue->rear = -1;
	return queue;
}

//判断是否为空
bool isEmpty(Queue*queue)
{
	return queue->front == -1;
}

//判断是否已满
bool isFull(Queue* queue)
{
	return (queue->rear + 1) % Max == queue->front;
}

//入队
void push(Queue* queue, int data)
{
	if (isFull(queue))
	{
		printf("false,full");
	}
	else
	{
		if (queue->front == -1)
		{
			queue->front = 0;
		}
		queue->rear = (queue->rear + 1) % Max;
		queue->data[queue->rear] = data;
	}
}

//出队
int pop(Queue* queue)
{
	if (isEmpty(queue))
	{
		printf("it is empty");
		return -1;
	}
	int temp = queue->data[queue->front];
	if (queue->front == queue->rear)
	{
		queue->front = queue->rear = -1;
	}
	else
	{
		queue->front = (queue->front + 1) % Max;
	}
	return temp;
}

//释放队
void destoryQueue(Queue* queue)
{
	free(queue);
}
