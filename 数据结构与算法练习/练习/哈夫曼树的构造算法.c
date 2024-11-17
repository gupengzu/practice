#include<stdio.h>
#include<stdlib.h>

//节点属性
typedef struct
{
	int weight;
	huffmanNode* left;
	huffmanNode* right;
}huffmanNode;

//比较函数，用于最小堆（优先级队列），使得权重小的节点排在前面
void compare(const void* a, const void* b)
{
	return ((huffmanNode*)a)->weight - ((huffmanNode*)b)->weight;
}

//构建哈夫曼树
huffmanNode* buildHuffmanTree(int*weight,int n)
{
	huffmanNode** nodes = (huffmanNode**)malloc(sizeof(huffmanNode*));
	for (int i = 0; i < n; i++)
	{
		nodes[i] = (huffmanNode*)malloc(sizeof(huffmanNode));
		nodes[i]->weight = weight[i];
		nodes[i]->left = NULL;
		nodes[i]->right = NULL;
	}
	//使用qsort函数对节点数组进行排序，实现最小堆功能
	qsort(nodes, n, sizeof(huffmanNode*), compare);
	while (n > 1)
	{
		huffmanNode* left = nodes[0];
		huffmanNode* right = nodes[1];
		huffmanNode* newNode = (huffmanNode*)malloc(sizeof(huffmanNode));
		newNode->weight = left->weight + right->weight;
		newNode->left = left;
		newNode->right = right;
		nodes[0] = newNode;
		nodes[1] = nodes[n - 1];
		n--;
		qsort(nodes, n, sizeof(huffmanNode*), compare);
	}
	return nodes[0];
}
