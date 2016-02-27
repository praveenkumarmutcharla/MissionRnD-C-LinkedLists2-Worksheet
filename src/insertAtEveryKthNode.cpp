/*
OVERVIEW: Given a single linked list insert a new node at every Kth node with value K.
E.g.: 1->2->3->4->5, k = 2, 1->2->2->3->4->2->5

INPUTS: A linked list and Value of K.

OUTPUT: Insert a new node at every Kth node with value K.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>
#include <malloc.h>

struct node {
	int num;
	struct node *next;
};
struct node * createNode(int num) {
	struct node *newNode = (struct node *)malloc(sizeof(struct node));
	newNode->num = num;
	newNode->next= NULL;
	return newNode;
}
struct node * insertAtEveryKthNode(struct node *head, int K) {
	int count = 1;
	struct node *travsal_node = head, *new_node = NULL, *current = NULL;
	while (travsal_node != NULL)
	{
		travsal_node = travsal_node->next;
		count += 1;
	}
	if (K > count)
		return head;;
	travsal_node = head;
	count = 1;
	while (travsal_node != NULL)
	{
		if (count == K)
		{
			new_node = createNode(K);
			current = travsal_node;
			new_node->next = current->next;
			current->next = new_node;
			travsal_node = new_node;
			count = 0;
		}
		travsal_node = travsal_node->next;
		count += 1;
	}

	return head;
}

