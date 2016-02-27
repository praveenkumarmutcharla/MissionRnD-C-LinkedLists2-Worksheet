/*
OVERVIEW: Given a single sorted linked list find the median element of the single linked list.
Median is the middle element.
E.g.: 1->2->3->4->5, output is 3.

INPUTS: A sorted linked list.

OUTPUT: Return median of the linked list elements.

ERROR CASES: Return -1 for error cases.

NOTES: If length is even, return average of middle pair of numbers.
*/

#include <stdio.h>

struct node {
	int num;
	struct node *next;
};

int linkedListMedian(struct node *head) {
	if (head == NULL)
		return -1;
	int travsingcount = 1, evenmedian = 0, count = 0;
	struct node *travsalnode = head;
	while (travsalnode != NULL)
	{
		count += 1;
		travsalnode = travsalnode->next;
	}
	//int chk = (no_of_nodes / 2);
	if (count % 2 != 0)
	{
		while (travsalnode != NULL&&travsingcount <= (count))
		{
			++travsingcount;
			travsalnode = travsalnode->next;
		}
		return travsalnode->num;
	}

	else
	{

		while (travsalnode != NULL&&travsingcount <= count - 1)
		{

			travsalnode = travsalnode->next;
			++travsingcount;
		}
		evenmedian = (travsalnode->num + travsalnode->next->num) / 2;
		return evenmedian;
	}
	head = NULL;
}

