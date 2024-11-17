#include<stdio.h>
#define Max 100

//定义链表
typedef struct
{
	int child;
	int* next;
}*childPtr;

//节点属性
typedef struct
{
	int data;
	childPtr* firstchild;
}treeNode;

//定义二叉树数组
typedef struct
{
	treeNode nodes[Max];
	int n;
}Tree;

//初始化
void createTree(Tree*tree)
{
	tree->n = 0;
}

//查找节点
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

//插入节点
void insertNode(Tree* tree, int data, int childData)
{
	if (tree->n == Max)
	{
		printf("full");
		return;
	}
	int parentIndex = findNode(*tree, data);
	if (parentIndex == -1)
	{
		printf("查找不到父节点");
		return;
	}
	childPtr newchild = (childPtr)malloc(sizeof(childPtr));
	newchild->child = childData;
	newchild->next = tree->nodes[parentIndex].firstchild;
	tree->nodes[parentIndex].firstchild = newchild;
	if (findNode(*tree,childData) == -1)
	{
		tree->nodes[tree->n].data = childData;
		tree->nodes[tree->n].firstchild=NULL;
		tree->n++;
	}
}

//遍历二叉树
void printTree(Tree tree)
{
	for (int i = 0; i < tree.n; i++)
	{
		printf("节点%d", tree.nodes[tree.n].data);
		childPtr temp = tree.nodes[tree.n].firstchild;
		while (temp!=NULL)
		{
			printf("%d",temp);
			temp = temp->next;
		}
		printf("\n");
	}
}
