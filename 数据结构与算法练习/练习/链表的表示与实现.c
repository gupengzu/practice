//#include <cstddef>
//typedef struct
//{
//	int data;
//	ListNode* next;
//}ListNode;
//ListNode* createnode(int value)
//{
//	ListNode* newnode = (ListNode*)malloc(sizeof(ListNode));
//	if (newnode == NULL)
//	{
//		return NULL;
//	}
//	newnode->data = value;
//	newnode->next = NULL;
//	return newnode;
//}
//ListNode* insertathead(ListNode* head, int value)
//{
//	ListNode* newnode = createnode(value);
//	newnode->next = head;
//	return newnode;
//}
//ListNode* insertatail(ListNode*head, int value)
//{
//	ListNode* newnode = createnode(value);
//	if (head == NULL)
//	{
//		return newnode;
//	}
//	ListNode* current = head;
//	while (current->next != NULL)
//	{
//		current = current->next;
//	}
//
//	ListNode* newnode = createnode(value);
//	current->next=newnode;
//	return head;
//}
//ListNode* index(ListNode* head, int value, int index)
//{
//	if (index == 0)
//	{
//		return insertathead(head, value);
//	}
//	ListNode* current = head;
//	for (int i = 0; i < index-1&&current!=NULL; i++)
//	{
//		current = current->next;
//		
//	}
//	if (current == NULL)
//	{
//		printf("插入无效\n");
//		return head;
//	}
//	ListNode* newnode = createnode(value);
//	newnode->next = current->next;
//	current->next = newnode;
//	return head;
//}
//ListNode* deleteathead(ListNode* head)
//{
//	if (head == NULL)
//	{
//		printf("无效\n");
//		return head;
//	}
//	ListNode* temp = head;
//	head = head->next;
//	free(temp);
//	return head;
//}
//ListNode* deleteattail(ListNode* head)
//{
//	if (head == NULL||head->next==NULL)
//	{
//		printf("无效\n");
//		return head;
//	}
//	ListNode* current = head;
//	while (current->next->next != NULL)
//	{
//		current = current->next;
//	}
//	free(current->next);
//	current->next = NULL;
//	return head;
//}
//ListNode* deleteAtIndex(ListNode* head, int index)
//{
//	ListNode* current = head;
//	for (int i = 0; i < index - 1 && current != NULL; i++)
//	{
//		current = current->next;
//	}
//	if (current == NULL || current->next == NULL)
//	{
//		printf("无效\n");
//		return head;
//	}
//	ListNode* temp = current->next;
//	current->next = current->next->next;
//	free(temp);
//	return head;
//}
//void printList(ListNode* head)
//{
//	ListNode* current = head;
//	while (current != NULL)
//	{
//		printf("%d ", current->data);
//		current = current->next;
//	}
//	printf("\n");
//}
//int ListNodeChart(ListNode* head, int index, int position)
//{
//	ListNode* current = head;
//	index = 0;
//	while (current->data != position && current!= NULL)
//	{
//		index++;
//		current = current->next;
//	}
//	if (current == NULL)
//	{
//		printf("无效\n");
//		return -1;
//	}
//	return index;
//}