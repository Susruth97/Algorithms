
/*
Given a value n

1. return nth Fibonacci number for the function nthFibonacci(int)
	EX: 0 for n=1 and 1 for n=2


2. return nth prime number for the function nthPrime(int)
	EX: 2 for n=1 and 3 for n=2

INPUTS: single integer n

OUTPUTS: nth Fibonacci number for nthFibonacci() 
		 nth prime number for nthPrime()

ERROR CASES: return -1 for the error cases
*/

int nthFibonacci(int n)
{
	if (n > 0)
	{
		int n1 = 0, n2 = 1, n3;
		if (n == 1)
			return 0;
		else if (n == 2)
			return 1;
		else
		{
			for (int i = 3;i <= n;i++)
			{
				n3 = n1 + n2;
				n1 = n2;
				n2 = n3;
			}
			return n3;
		}
	}
	else
		return -1;
}

int nthPrime(int num)
{
	int i = 2, c = 0, n = 0, primen;
	if (num > 0)
	{
		for (int i = 2; ;i ++)
		{
			c = 0;
			for (int k = 2;k <= i/2;k++)
			{
				if (i % k == 0)
					c++;
			}
			if (c == 0)
			{
				primen = i;
				n++;
			}
			if (num == n)
				return primen;
		}
	}
	else
		return -1;

}