/*
OVERVIEW: You are given a bank statement where transactions are ordered by date. Write a function that finds the number of transactions in that statement after a given date.
-- find the count of numbers greater than a given number in a sorted array.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
date = "19-10-2004"
Output: 1 (as there is only one transaction { 30, "03-03-2005", "Third" })

INPUTS: One bank statement (array of transactions) and date.

OUTPUT: Return the number of transactions in that statement after a given date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include<stdio.h>
int compareDate(struct transaction a, char *date);
struct transaction {
	int amount;
	char date[11];
	char description[20];
};

int countGreaterNumbers(struct transaction *Arr, int len, char *date) {
	int low = 0, high = len - 1, dupl = 0, index;
	if (compareDate(Arr[low], date) == 0 && compareDate(Arr[high], date) == 0)
		return NULL;
	else
	{
		while (low <= high)
		{
			int mid = (low + high) / 2;
			if (compareDate(Arr[mid], date) == 0) {
				dupl++;
				index = len - 1 - mid;
				return index;
			}
			else if (compareDate(Arr[mid], date) == -1)
				low = mid + 1;
			else
				high = mid - 1;
		}
		return NULL;
	}
}

int compareDate(struct transaction a, char *date)
{
	int dcount = 0;
	for (int j = 6; j < 10; j++)
	{
		if (a.date[j] - '0' < date[j] - '0')
			return -1;
		else if (a.date[j] - '0' > date[j] - '0')
			return 1;
		else
			dcount++;
	}
	if (dcount == 4)
	{
		dcount = 0;
		for (int j = 3; j < 5; j++)
		{
			if (a.date[j] - '0' < date[j] - '0')
				return -1;
			else if (a.date[j] - '0' > date[j] - '0')
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
			if (a.date[j] - '0' < date[j] - '0')
				return -1;
			else if (a.date[j] - '0' > date[j] - '0')
				return 1;
			else
				dcount++;
		}
	}
	if (dcount == 2)
		return 0;
}