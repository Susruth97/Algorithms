
/*
OVERVIEW: Given an array of integers find the maximum possible sum formed by a positive and the negative
integer in the array.
Ex: input: [1, 9, 8, 2, 3, -1,-10,-5] output: 8 (formed by 9 and -1) 

INPUTS: An Integer array and the length of the array

OUTPUT: Maximum possible sum formed by a positive and the negative integer in the array

ERROR CASES: Return 0 for the invalid inputs

NOTES:
*/

#include <stdio.h>

int maxPosNegSum(int* input,int length)
{
	if (length > 0)
	{
		int pmax, nmax, pcount = 0, ncount = 0, i = 0;
		while (ncount <= 1 || i < length)
		{
			if (input[i] < 0)
			{
				nmax = input[i];
				ncount++;
			}
			i++;
		}

		pmax = 0;
		ncount = 0;
		i = 0;
		for (i = 0; i < length; i++)
		{
			if (input[i] >= 0)
			{
				pcount++;
				if (pmax < input[i])
					pmax = input[i];
			}
			else
			{
				ncount++;
				if (nmax < input[i])
					nmax = input[i];
			}
		}

		if (pcount == 0 || ncount == 0)
			return 0;
		else
			return (pmax + nmax);
	}
	else
		return 0;
}