#include<stdio.h>
#define MAX 100
//定义节点属性
typedef struct
{
	int data;
	int parent;
}treeNode;

//定义树的属性
typedef struct
{
	treeNode nodes[100];
	int n;
}Tree;

//树的初始化
void initTree(Tree* tree)
{
	tree->n = 0;
}

//增添节点
void insertNode(Tree* tree, int parent,int data)
{
	if (tree->n == MAX)
	{
		printf("full");
		return;
	}
	tree->nodes[tree->n].data = data;
	tree->nodes[tree->n].parent = parent;
	tree->n++;
}

//查找节点在树中的位置
int findNode(Tree tree, int data)
{
	for (int i = 0; i < tree.n; i++)
	{
		if (tree.nodes[i].data == data)
		{
			return i;
		}
	}
	return -1;
}

//遍历二叉树
void inorderTraversal(Tree tree)
{
	for (int i = 0; i <= tree.n; i++)
	{
		printf("双亲%d 节点%d\n",tree.nodes[i].parent, tree.nodes[i].data);
	}
}
