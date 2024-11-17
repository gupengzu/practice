#include<stdio.h>

//定义结点属性
typedef struct 
{
	int data;
	treeNode* left;
	treeNode* right;
}treeNode;

//二叉树即为节点衍生出的东西，所以定义完节点后即可开始生成二叉树
treeNode* createTree(int data)
{
	//初始的二叉树的属性包括：占用的内存，data，left，right。
	treeNode* tree = (treeNode*)malloc(sizeof(treeNode));
	tree->data = data;
	tree->left = NULL;
	tree->right = NULL;
	return tree;
}

//二叉树应该具有的行为有：增添节点，遍历，释放。

//增添节点:增添的节点
void insertTreeNode(treeNode** root, int data)
{
	if (*root == NULL)
	{
		treeNode* tree = createTree(data);
		return;
	}
	treeNode* current = *root;
	if (data < current->data)
	{
		insertTreeNode(&current->left, data);
	}
	else
	{
		insertTreeNode(&current->right, data);
	}
}

//遍历二叉树
//中序遍历
void inorderTraversal(treeNode* root)
{
	if (root == NULL)
	{
		printf("empty");
		return;
	}
	inorderTraversal(root->left);
	printf("%d", root->data);
	inorderTraversal(root->right);
}

//释放二叉树
void freeTree(treeNode* root)
{
	if (root == NULL)
	{
		return;
	}
	freeTree(root->left);
	freeTree(root->right);
	freeTree(root);
}

//中序非递归算法遍历二叉树
void inorderTraversal(treeNode* root)
{
	if (root == NULL) return;
	treeNode* stack[100];//假设栈足够大
	int top = -1;
	treeNode* current = root;
	while (current != NULL || top != -1)
	{
		while (current != NULL)
		{
			stack[++top] = current;
			current = current->left;
		}
		current = stack[top--];
		printf("%d", current->data);
		current = current->right;
	}
}