/*
OVERVIEW: Given a single linked list, reverse the linked list.
E.g.: 1->2->3->4->5, output is 5->4->3->2->1.

INPUTS: A linked list.

OUTPUT: Reverse the linked list.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>

struct node {
	int num;
	struct node *next;
};

struct node * reverseLinkedList(struct node *head) {
	if (head == NULL)
		return NULL;
	struct node *first;
	struct node *rest;
	if (head == NULL)
		return NULL;
	first = head;
	rest = first->next;
	if (rest == NULL)
		return head;
	reverseLinkedList(rest);
	first->next->next = first;
	first->next = NULL;
	head = rest;
	return head;
}

