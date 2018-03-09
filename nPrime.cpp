
/*
OVERVIEW: Given a number N return all the prime numbers upto the integer N.
Ex: input: 10 output: [2,3,5,7] 

INPUTS: An Integer N

OUTPUT: Return an Array of Prime numbers until the number N(N inclusive)

ERROR CASES: Return NULL for invalid inputs

Sample Input : 10
Sample Output : An Array consisting elements {2,3,5,7}
NOTES:

Try to think of a optimized way , and avoid unnecessary comparisons.
*/

#include <stdio.h>
#include <stdlib.h>
int* nPrime(int N)
{
	if (N > 1)
	{
		int *prime, j = 0;
		prime = (int*)malloc(N * sizeof(int));
		int count = 0;
		for (int i = 2; i <= N ; i++)
		{
			count = 0;
			for (int k = 2; k <= i / 2; k++)
			{
				if (i % k == 0)
					count++;
			}
			if (count == 0)
			{
				prime[j] = i;
				j++;
			}
		}
		return prime;
	}
	else
		return NULL;
}