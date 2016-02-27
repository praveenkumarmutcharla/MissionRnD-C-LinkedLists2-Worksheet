/*
OVERVIEW: Merge two sorted linked lists.
E.g.: 1->3->5 and 2->4, output is 1->2->3->4->5.

INPUTS: Two sorted linked lists.

OUTPUT: Return merged sorted linked list.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>
#include<malloc.h>
struct node {
	int num;
	struct node *next;
};

struct node *mergeliststart = NULL;
struct node * merge_list_creation(struct node *head1, struct node *head2, int list1no_of_nodes, int list2no_of_nodes)
{
	mergeliststart = NULL;
	int  i;
	struct node *new_node, *current = NULL;
	for (i = 0; i <list1no_of_nodes + list2no_of_nodes; i++)
	{
		new_node = (struct node *)malloc(sizeof(struct node));
		new_node->next = NULL;
		if (mergeliststart == NULL)
		{
			mergeliststart = new_node;
			current = new_node;
		}
		else
		{
			current->next = new_node;
			current = new_node;
		}
	}
	return mergeliststart;
}

struct node * merge2LinkedLists(struct node *head1, struct node *head2) {
	if (head1 == NULL || head2 == NULL)
		return NULL;
	mergeliststart = NULL;
	int  i = 0, j = 0;
	int list1no_of_nodes = 0, list2no_of_nodes = 0;
	struct node  *current = NULL, *travsalnode = head1;
	while (travsalnode != NULL)
	{
		list1no_of_nodes += 1;
		travsalnode = travsalnode->next;
	}
	travsalnode = head2;
	while (travsalnode != NULL)
	{
		list2no_of_nodes += 1;
		travsalnode = travsalnode->next;
	}
	if (head1 == NULL)
		return head2;
	if (head2 == NULL)
		return head1;

	mergeliststart = merge_list_creation(head1, head2, list1no_of_nodes, list1no_of_nodes);
	struct node *list1node = head1, *list2node = head2, *mergenode = mergeliststart;
	while (i < list1no_of_nodes&&j < list2no_of_nodes)
	{
		if (list1node->num < list2node->num)
		{
			mergenode->num = list1node->num;
			i++;
			list1node = list1node->next;
			mergenode = mergenode->next;

		}
		else
		{
			mergenode->num = list2node->num;
			j++;
			list2node = list2node->next;
			mergenode = mergenode->next;
		}

	}
	while (i < list1no_of_nodes)
	{
		mergenode->num = list1node->num;
		i++;
		list1node = list1node->next;
		mergenode = mergenode->next;
	}
	while (j < list2no_of_nodes)
	{
		mergenode->num = list2node->num;
		j++;
		list2node = list2node->next;
		mergenode = mergenode->next;
	}
	return mergeliststart;
}