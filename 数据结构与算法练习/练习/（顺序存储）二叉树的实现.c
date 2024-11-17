#include<stdio.h>
#define Max 100
//定义二叉树的基本元素
typedef struct
{
	int data[Max];//一个整数数组，用于储存二叉树中结点的数据（此处假定最多有Max个节点）
	int size;//定义节点数量
}BinaryTreeArray;

//初始化顺序存储的二叉树
void initBinaryTreeArray(BinaryTreeArray* tree)
{
	tree->size = 0;//将二叉树的节点数量设置为零，表示当前二叉树为空
	for (int i = 0; i < Max; i++)//将每一个节点数据初始化为-1，这里-1作为特殊值，表示该节点位置没有实际数据。
	{
		tree->data[i] = -1;
	}
}

//插入元素到顺序二叉树中
void push(BinaryTreeArray* tree, int data)
{
	if (tree->size < Max)
	{
		tree->data[tree->size++] = data;
	}
	else
	{
		printf("full");
	}
}

//遍历顺序存储的二叉树
