/*
Q4: Two dates are given in a 8 node single linked list form,where each node
has one digit only, dates 01-31, months 01-12, year 0000-9999.

Find the number of days in between those two dates .[Exclusive]

Ex : Date1:  0->1->0->1->2->0->0->4 .
     Date2 : 0->5->0->1->2->0->0->4 should return 3 .
As there are 3 days between Jan1st 2004 and Jan 5th 2004.

Ex 2 : Date1 : 3->1->1->2->2->0->1->2.
       Date2 : 0->2->0->1->2->0->1->3 should return 1 .
(There is only one day between 31st Dec 2012 and 2nd  Jan 2013 .)

Note : Consecutive Days and Same Days should return 0;
->Return -1 for NULL Inputs .
->Between Days have to be calculated by not including start and end date .
->The SLL will have 8 Nodes in all cases . Year 999 will be represented as 0999.

Difficulty : Hard 
*/
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

struct node{
	int data;
	struct node *next;
};

int jul_days(int days, int months, int years);

int between_days(struct node *date1head, struct node *date2head){

	if (date1head != NULL && date2head != NULL)
	{
		int d1, d2, m1, m2, y1, y2, t1 = 0, t2 = 0;
		struct node *temp1 = date1head, *temp2 = date2head;

		for (int i = 0; i < 2; i++) {
			t1 = t1 * 10 + date1head->data;
			t2 = t2 * 10 + date2head->data;
			date1head = date1head->next;
			date2head = date2head->next;
		}
		d1 = t1;
		d2 = t2;

		t1 = 0;
		t2 = 0;
		for (int i = 0; i < 2; i++) {
			t1 = t1 * 10 + date1head->data;
			t2 = t2 * 10 + date2head->data;
			date1head = date1head->next;
			date2head = date2head->next;
		}
		m1 = t1;
		m2 = t2;

		t1 = 0;
		t2 = 0;
		for (int i = 0; i < 4; i++) {
			t1 = t1 * 10 + date1head->data;
			t2 = t2 * 10 + date2head->data;
			date1head = date1head->next;
			date2head = date2head->next;
		}
		y1 = t1;
		y2 = t2;

		if ((d1 == d2 || d1 == d2 + 1 || d1 + 1 == d2) && m1 == m2 && y1 == y2)
			return 0;
		else
		{
			int days1, days2;

			days1 = jul_days(d1, m1, y1);
			days2 = jul_days(d2, m2, y2);

			return abs(days1 - days2) - 1;
		}
	}
	else
		return -1;
}

int jul_days(int days, int months, int years) {

	int a, y, m, count;

	a = floor((float)(14 - months) / 12);
	y = years + 4800 - a;
	m = months + 12 * a - 3;

	count = days + floor((float)(153 * m + 2) / 5) + 365 * y + floor((float)y / 4) - floor((float)y / 100) + floor((float)y / 400) - 32045;

	return count;
}