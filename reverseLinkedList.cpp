/*
OVERVIEW: Given a single linked list, reverse the linked list.
E.g.: 1->2->3->4->5, output is 5->4->3->2->1.

INPUTS: A linked list.

OUTPUT: Reverse the linked list.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>
#include <stdlib.h>

struct node {
	int num;
	struct node *next;
};

typedef struct node *lptr;
lptr insert_first(lptr first, int n);

struct node * reverseLinkedList(struct node *head) {
	lptr first = NULL;

	while (head != NULL)
	{
		first = insert_first(first, head->num);
		head = head->next;
	}
	return first;
}

lptr insert_first(lptr first, int n)
{
	lptr p;
	p = (lptr)malloc(sizeof(struct node));
	p->num = n;
	if (first == NULL)
	{
		first = p;
		first->next = NULL;
	}
	else
	{
		p->next = first;
		first = p;
	}
	return first;
}