/*

Here you will be doing the same ArraysQuestion you did before, but now in multiple ways.

OVERVIEW: Given a number N return all the prime numbers upto the integer N.
Ex: input: 10 output: [2,3,5,7]
INPUTS: An Integer N
OUTPUT: Return an Array of Prime numbers until the number N(N inclusive)
ERROR CASES: Return NULL for invalid inputs
Sample Input : 10
Sample Output : An Array consisting elements {2,3,5,7}

Observations: (Write down what you observed here):

Way 1 :

Way 2 :

Way 3:

Conclusion :
*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

/*

Manually loop over every element, Find if its prime or not. Store it in an array.
Write the worst complexity code you can write :D.
*/
int* nPrimeBruteForce(int N)
{
	if (N > 2)
	{
		int *prime, k = 0, count;
		prime = (int*)malloc(N * sizeof(int));
		for (int i = 2; i < N; i++)
		{
			count = 0;
			for (int j = 2; j <= i / 2; j++)
			{
				if (i % j == 0)
					count++;
			}
			if (count == 0)
				prime[k++] = i;
		}
		return prime;
	}
	else
		return NULL;
}


/*
Remove even numbers, Run it again.
Just remove even numbers. So it should essentially take half of time for function 1, Did it really happened?

*/
int* nPrimeEvenRemoved(int N)
{
	if (N > 2)
	{
		int *prime, k = 0, count;
		prime = (int*)malloc(N * sizeof(int));
		prime[k] = 2;
		k++;
		for (int i = 3; i < N; i = i + 2)
		{
			count = 0;
			for (int j = 3; j*j <= i; j = j + 2)
			{
				if (i % j == 0)
					count++;
			}
			if (count == 0)
				prime[k++] = i;
		}
		return prime;
	}
	else
		return NULL;
}

/*
Do all optimizations you can think of.

Hint :
A number can be considered a prime, if its not divisible by any of the primes which are less than it.
ie 100 can be considered as a prime, if no prime number which is less than 100 divides 100 (With remainder as 0).
7 is prime as no prime less than it (2,3,5) can divide it. Think proof for this too.

This heavily reduces the number of divisions you do. If you did correctly you should see some heavy difference in timings.

*/

int* nPrimeOptimized(int N)
{
	if (N > 2)
	{
		int *prime, *output, k, i = 2, count = 0;
		prime = (int*)calloc(N + 1, sizeof(int));
		while (i * i < N)
		{
			if (prime[i] == 0)
			{
				k = i * i;
				while (k < N)
				{
					prime[k] = 1;
					k = k + i;
				}
			}
			i++;
		}

		output = (int*)calloc(N / 2 , sizeof(int));
		k = 0;
		for (i = 2; i < N; i++)
		{
			if (prime[i] == 0)
				output[k++] = i;
		}
		return output;
	}
	else
		return NULL;
}