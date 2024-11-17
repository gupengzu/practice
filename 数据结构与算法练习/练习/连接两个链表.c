/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
//#include <cstddef>
//typedef struct ListNode
//{
//	int val;
//	struct ListNode* next;
//};
//struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) 
//{
//
//	struct ListNode* current = (struct ListNode*)malloc(sizeof(struct ListNode));
//	current->val = list1->val;
//	current->next =NULL;
//	struct ListNode* current1= (struct ListNode*)malloc(sizeof(struct ListNode));
//	current1->next = list1->next;
//	struct ListNode* current2=(struct ListNode*)malloc(sizeof(struct ListNode));
//	current2->next = list2;
//	struct ListNode* current3= (struct ListNode*)malloc(sizeof(struct ListNode));
//	current3->next = current;
//	while (current1->next != NULL && current2->next != NULL)
//	{
//		if (current1->next != NULL && current2->next != NULL&&current1->next >= current2->next)
//		{
//			current3->next->next = current2->next;
//			current3 = current3->next;
//			current2=current2->next;
//		}		
//		if (current1->next != NULL && current2->next != NULL&&current1->next < current2->next)
//		{
//			current3->next->next = current1->next;
//			current3=current3->next;
//			current1=current1->next;
//		}
//		if (current1->next == NULL && current2->next != NULL)
//		{
//			current3->next->next = current2->next;
//			current3=current3->next;
//			current2=current2->next;
//		}		
//		if (current1->next != NULL && current2->next == NULL)
//		{
//			current3->next->next = current1->next;
//			current3=current3->next;
//			current1=current1->next;
//		}
//	}
//	free(current1);
//	free(current2);
//	free(current3);
//	return current;
//}