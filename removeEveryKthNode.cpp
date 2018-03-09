/*
OVERVIEW: Given a single linked list, remove every Kth node in the linked list.
E.g.: 1->2->3->4->5 and K 2, output is 1->3->5.

INPUTS: A linked list and Value of K.

OUTPUT: Remove every Kth node in the linked list.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>
#include <stdlib.h>

struct node {
	int num;
	struct node *next;
};

typedef struct node* lptr;

struct node * removeEveryKthNode(struct node *head, int K) {
	if (head != NULL && K > 1)
	{
		lptr first = head, prev = NULL;
		int count = 0;
		while (first != NULL)
		{
			count++;
			if (count % K == 0)
			{
				prev->next = first->next;
			}
			else
				prev = first;
			first = prev->next;
		}
		return head;
	}
	else
		return NULL;
}