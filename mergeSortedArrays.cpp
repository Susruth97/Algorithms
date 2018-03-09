/*
OVERVIEW: You are given 2 bank statements that are ordered by date - 
Write a function that produces a single merged statement ordered by dates.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[2] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" } };
Output: { { 10, "09-10-2003", "First" }, { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" },  30, "03-03-2005", "Third" }, { 220, "18-01-2010", "Sixth" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Combined statement ordered by transaction date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <stdio.h>
#include <stdlib.h>
int compare(struct transaction a, struct transaction b);

struct transaction {
	int amount;
	char date[11];
	char description[20];
};

struct transaction * mergeSortedArrays(struct transaction *A, int ALen, struct transaction *B, int BLen) {
	if (A != NULL && B != NULL && (ALen > 0 || BLen > 0))
	{
		struct transaction *output;
		int CLen, i, j, k;
		CLen = ALen + BLen;
		output = (struct transaction *)malloc(CLen * sizeof(struct transaction));
		i = ALen - 1;
		j = BLen - 1;
		k = CLen - 1;
		while (i >= 0 && j >= 0)
		{
			if (compare(A[i], B[j]) == 1)
				output[k--] = A[i--];
			else if (compare(A[i], B[j]) == -1)
				output[k--] = B[j--];
			else if (compare(A[i], B[j]) == 0)
			{
				output[k--] = A[i--];
				output[k--] = B[j--];
			}
		}
		while (i >= 0)
			output[k--] = A[i--];
		while (j >= 0)
			output[k--] = B[j--];

		return output;
	}
	else
		return NULL;
}

int compare(struct transaction a, struct transaction b)
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