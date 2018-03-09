/*
OVERVIEW: Given an unsorted single linked list, sort the linked list without using extra array or linked list.
E.g.: 4->2->1->5->3, output is 1->2->3->4->5.

INPUTS: An unsorted single linked list.

OUTPUT: Sort the linked list.

ERROR CASES: Return NULL for error cases.

NOTES: Without using extra array or linked list.

*/

#include <stdio.h>
#include <stdlib.h>

struct node {
	int num;
	struct node *next;
};

typedef struct node* lptr;

struct node * sortLinkedList(struct node *head) {
	node *first, *start;
	start = head;
	int count = 0;
	first = head;
	while (first != NULL)
	{
		count++;
		first = first->next;
	}
	for (int i = 0; i < count; i++)
	{
		while (head->next != NULL)
		{
			if (head->num > head->next->num)
			{
				int temp;
				temp = head->num;
				head->num = head->next->num;
				head->next->num = temp;
			}
			head = head->next;
		}
		head = start;
	}
	return head;
}