/*
OVERVIEW: You are given 2 bank statements that are ordered by date.
Write a function that returns dates common to both statements
(ie both statements have transactions in these dates).
E.g.: Input:
A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[3] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" }, { 320, "27-08-2015", "Seventh" } };
Output: { { 10, "09-10-2003", "First" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Transactions having same dates.


ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <stdio.h>
#include <stdlib.h>
int compareDate(struct transaction a, struct transaction b);

struct transaction {
	int amount;
	char date[11];
	char description[20];
};

struct transaction * sortedArraysCommonElements(struct transaction *A, int ALen, struct transaction *B, int BLen) {
	if (A != NULL && B != NULL && ALen > 0 && BLen > 0)
	{
		int i = 0, j = 0, k = 0, flag = 0;
		struct transaction *output;
		output = (struct transaction *)malloc(ALen * sizeof(struct transaction));
		while (i < ALen && j < BLen)
		{
			if (compareDate(A[i], B[j]) == 0) {
				flag = 1;
				output[k] = A[i];
				i++;
				j++;
				k++;
			}
			else if (compareDate(A[i], B[j]) == -1)
				i++;
			else
				j++;
		}
		if (flag == 1)
			return output;
		else
			return NULL;
	}
	else
		return NULL;
}

int compareDate(struct transaction a, struct transaction b)
{
	int dcount = 0;
	for (int j = 6; j < 10; j++)
	{
		if (a.date[j] - '0' < b.date[j] - '0')
			return -1;
		else if (a.date[j] - '0' > b.date[j] - '0')
			return 1;
		else
			dcount++;
	}
	if (dcount == 4)
	{
		dcount = 0;
		for (int j = 3; j < 5; j++)
		{
			if (a.date[j] - '0' < b.date[j] - '0')
				return -1;
			else if (a.date[j] - '0' > b.date[j] - '0')
				return 1;
			else
				dcount++;
		}
	}
	if (dcount == 2)
	{
		dcount = 0;
		for (int j = 0; j < 2; j++)
		{
			if (a.date[j] - '0' < b.date[j] - '0')
				return -1;
			else if (a.date[j] - '0' > b.date[j] - '0')
				return 1;
			else
				dcount++;
		}
	}
	if (dcount == 2)
		return 0;
}