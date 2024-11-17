#include<stdio.h>
#include <stdbool.h>
//定义队列节点结构
typedef struct queueNode
{
	int data;
	struct queueNode* next;
}queueNode;

//定义队列结构
typedef struct Queue
{
	queueNode* front;
	queueNode* rear;
}Queue;

//创建一个队列
Queue* createqueue()
{
	Queue* queue = (Queue*)malloc(sizeof(Queue));
	queue->front = NULL;
	queue->rear = NULL;
	return queue;
}

//检查队列是否为空
bool isEmpty(Queue*queue)
{
	return queue->front == NULL;
}

//入队
void push(Queue* queue, int data)
{
	queueNode* newNode = (queueNode*)malloc(sizeof(queueNode));
	newNode->data = data;
	newNode->next = NULL;
	if (queue->rear == NULL)
	{
		queue->front = queue->rear = newNode;
		return;
	}
	queue->rear->next = newNode;
	queue->rear = newNode;
}

//出队
int pop(Queue* queue)
{
	if (isEmpty(queue))
	{
		printf("false");
		return -1;
	}

	queueNode* current = queue->front;
	int temp = current->data;
	queue->front = queue->front->next;

	if (queue->front == NULL)
	{
		queue->rear = NULL;
	}

	free(current);
	return temp;
}

//检查队首元素
int peek(Queue* queue)
{
	return queue->front->data;
}

//释放队列
void destoryQueue(Queue* queue)
{
	while (!isEmpty(queue))
	{
		pop(queue);
	}
	free(queue);
}