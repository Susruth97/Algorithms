/*
OVERVIEW:  Given a number convert that to single linked list (each digit as a node).
E.g.: Input: 234, Output: 2->3->4.

INPUTS:  A number.

OUTPUT: Create linked list from given number, each digit as a node.

ERROR CASES:

NOTES: For negative numbers ignore negative sign.
*/

#include <stdio.h>
#include <malloc.h>

struct node {
	int num;
	struct node *next;
};

typedef struct node* lptr;

lptr insert_first(lptr first, int n);

struct node * numberToLinkedList(int N) {
	lptr first;
	first = NULL;
	if (N != 0)
	{
		int rem, temp = N;

		if (temp < 0)
			temp = -1 * temp;

		while (temp != 0)
		{
			rem = temp % 10;
			first = insert_first(first, rem);
			temp = temp / 10;
		}
		return first;
	}
	else
	{
		first = insert_first(first, N);
		return first;
	}
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