/*
OVERVIEW:  Given a single linked list of 0s 1s and 2s ,Sort the SLL such that zeroes
will be followed by ones and then twos.

You should only change the links and shouldnt swap the data. Basically no write operation should be done on data field.

INPUTS:  SLL head pointer
OUTPUT: Sorted SLL ,Head should Finally point to an sll of sorted 0,1,2
ERROR CASES:
NOTES: Only 0,1,2, will be in sll nodes
*/

#include <stdio.h>
#include <malloc.h>

struct node {
	int data;
	struct node *next;
};

typedef struct node* lptr;

/*
Optional : For this function swapping data is allowed.Although this wont be tested on our end.
It is only for learning purpose.
*/
void sll_012_sort_swapData(struct node **head){

}

/*
This is the actual function. You are supposed to change only the links.
*/
void sll_012_sort(struct node **head){
	if (*head == NULL)
		return;
	lptr start, prev, temp, temp1 = NULL;
	int flag = 0;
	start = *head;
	temp = start->next;
	prev = start;

	while (temp != NULL)
	{
		if (temp->data == 0)
		{
			prev->next = temp->next;
			temp->next = start;
			start = temp;
			temp = prev->next;
			flag = 1;
		}
		else
		{
			prev = temp;
			temp = temp->next;
		}
	}
	*head = start;
	while (start->data == 0)
	{
		temp1 = start;
		start = start->next;
		if (start == NULL)
			return;
	}

	temp = start->next;
	prev = start;

	while (temp != NULL)
	{
		if (temp->data == 1)
		{
			prev->next = temp->next;
			temp->next = start;
			start = temp;
			temp = prev->next;
		}
		else
		{
			prev = temp;
			temp = temp->next;
		}
	}

	if (flag == 0)
	{
		*head = start;
	}
	else
	{
		temp1 = *head;
		while (temp1->next->data == 0)
			temp1 = temp1->next;
		temp1->next = start;
	}
}


