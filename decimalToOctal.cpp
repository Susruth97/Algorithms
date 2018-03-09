/*
OVERVIEW: 
1)Write a function which takes a decimal number as input and returns the octal number for decimalToOctal().
E.g.: decimalToOctal(10) returns 12.

2)Write a function which takes a fractional decimal number as input and returns the octal number for decimalToOctalFraction()
until precision two
E.g.: decimalToOctal(6.06) returns 6.03

INPUTS: Single decimal number num;

OUTPUT: Octal value of the Decimal Number num.

Discalimer:Return 0 for invalid cases.[Negetive Numbers]

There are no test cases for fraction method but it would be good if you complete that too.
*/
#include<stdlib.h>

int decimalToOctal(int num)
{
	int *octalNumber, octal = 0, quotient, i = 0, n = 0;
	quotient = num;

	/* to get the max. size n for dynamic initialization */
	while (quotient != 0)
	{
		n++;
		quotient = quotient / 10;
	}

	octalNumber = (int *)malloc((n+1) * sizeof(int));

	if (num > 0)
	{
		/* converting decimal number into octal no. */
		quotient = num;
		while (quotient != 0)
		{
			octalNumber[i++] = quotient % 8;
			quotient = quotient / 8;
		}
		for (int j = i - 1; j >= 0; j--)
		{
			octal = octal * 10 + octalNumber[j];
		}
		return octal;
	}
	else
	return 0;
}

float decimalToOctalFraction(float num)
{
	return 0.0;
}

