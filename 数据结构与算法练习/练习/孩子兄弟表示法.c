#include<stdio.h>

typedef struct
{
	int data;
	CSNode* firstchild;
	CSNode*nextsibling ;
}CSNode;

//创建新节点
CSNode* createNode(int data)
{
	CSNode* newNode = (CSNode*)malloc(sizeof(CSNode));
	newNode->data = data;
	newNode->firstchild = NULL;
	newNode->nextsibling = NULL;
	return newNode;
}

//插入新节点
void insertNode(CSNode* parent,CSNode* child)
{
	if (parent->firstchild == NULL)
	{
		parent->firstchild = child;
	}
	else
	{
		CSNode* temp=parent;
		while (parent->firstchild != NULL)
		{
			temp = temp->firstchild;
		}
		temp->nextsibling = child;
	}
}

//遍历并打印树
void printTree(CSNode* root)
{
	if (root == NULL)
	{
		return;
	}
	printf(root->data);
	printTree(root->firstchild);
	printTree(root->nextsibling);
}