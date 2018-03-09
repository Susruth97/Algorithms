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

typedef struct node* lptr;

int linkedListMedian(struct node *head) {
	if (head != NULL)
	{
		lptr walk, jump;
		walk = head;
		jump = head;
		int flag = 0;

		while (jump != NULL && jump->next != NULL)
		{
			jump = jump->next->next;
			if (jump == NULL) {
				flag = 1;
				break;
			}
			walk = walk->next;
		}
		if (flag == 0)
			return walk->num;
		else
			return (walk->num + walk->next->num) / 2;
	}
	else
		return -1;
}
