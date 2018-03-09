/*
OVERVIEW: Given an array where every element occurs three times, except one element which occurs only
once. Find the element that occurs once.
E.g.: Input: arr = 12, 1, 12, 3, 12, 1, 1, 2, 3, 3
ouput: 2

INPUTS: Integer array and length of the array.

OUTPUT: Element that occurs only once.

ERROR CASES: Return -1 for invalid inputs.

NOTES:
There are better ways of solving the problem than a brute-force solution which is of O(n^2)
complexity .
*/

#include <stdio.h>
#include <stdlib.h>

void mergesort(int *A, int low, int high);
void merge(int *A, int i1, int j1, int i2, int j2);

int findSingleOccurenceNumber(int *A, int len) {
	if (A != NULL && len > 0)
	{
		mergesort(A, 0, len - 1);

		int i = 0, j = len - 1;
		while (i <= j)
		{
			if (A[i] != A[i + 1])
				return A[i];
			else if (A[j] != A[j - 1])
				return A[j];
			else
			{
				i = i + 3;
				j = j - 3;
			}
		}
	}
	return -1;
}

void mergesort(int *A, int low, int high) {

	int mid;
	if (low < high)
	{
		mid = (low + high) / 2;
		mergesort(A, low, mid);
		mergesort(A, mid + 1, high);
		merge(A, low, mid, mid + 1, high);
	}
}

void merge(int *A, int i1, int j1, int i2, int j2)
{
	int temp[100], i, j, k = 0;
	i = i1;
	j = i2;
	while (i <= j1 && j <= j2)
	{
		if (A[i] < A[j])
			temp[k++] = A[i++];
		else
			temp[k++] = A[j++];
	}

	while (i <= j1)
		temp[k++] = A[i++];
	while (j <= j2)
		temp[k++] = A[j++];
	for (i = i1, j = 0; i <= j2; i++, j++)
		A[i] = temp[j];
}
