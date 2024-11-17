#include<stdio.h>

//定义二叉树节点的属性
typedef struct
{
	int data;
	treeNode* left;
	treeNode* right;
}treeNode;

//创建二叉树
treeNode* createTree(int data)
{
	treeNode* root = (treeNode*)malloc(sizeof(treeNode));
	root->data = data;
	root->left = NULL;
	root->right = NULL;
}

//增加节点
void push(treeNode* root, int data)
{
	if (root == NULL)
	{
		createTree(data);
		return;
	}
	if (data < root->data)
	{
		push(root->left,data);
	}
	else
	{
		push(root->right, data);
	}
}

//重点！
//重点！
//重点！
//实现层次遍历算法
void levelOrderTraversal(treeNode* root)
{
	if (root == NULL) return;
	treeNode* queue[100];//假设队列足够大
	int front = 0;
	int rear = 0;
	queue[rear++] = root;
	while (front < rear)
	{
		treeNode* current = queue[front++];
		printf("%d", current);
		if (current->left)queue[rear++] = current->left;
		if (current->right)queue[rear++] = current->right;
	}
}

//释放二叉树
void freeTree(treeNode* root)
{
	if (root == NULL)return;
	freeTree(root->left);
	free(root->right);
	free(root);
}