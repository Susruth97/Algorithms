/*
Problem Code : ISPRIME

In this lesson you will write 3 ways of how to find a prime number and then note down its performances.

Question : Given a number return 1 if its a prime number ,0 otherwise.

Dont try to over optimize soultion unless asked. Write bad code its okay. The purpose of this lesson is to learn
how bad code effects the time taken for running.

Observations: (Write down what you observed here):

Way 1: (Brute Force)

LoopCount = 5, Number = 232910011, Time Taken = 9.642 sec
LoopCount = 10, Number = 232910011, Time Taken = 20.97 sec
LoopCount = 1000, Number = 1298653, Time Taken = 10.84 sec
Way 2: (Square Root)

LoopCount = 1000, Number = 232910011, Time Taken = 0.124 sec
LoopCount = 10000, Number = 232910011, Time Taken = 1.3 sec
LoopCount = 100000, Number = 1298653, Time Taken = 0.081 sec
Way 3: (Omptmized way)

LoopCount = 1000, Number = 232910011, Time Taken = 0.042 sec
LoopCount = 10000, Number = 232910011, Time Taken = 0.36 sec
LoopCount = 100000, Number = 1298653, Time Taken = 0.028 sec

Conclusion :

1 and 2 are did as instructed, while in optimized way,
I used a property of prime no. that it can be represented in either 6k-1 or 6k+1,
and possible divisors are also in that form
In divisors I excluded even numbers and number divisible by 3
*/

#include <stdio.h>
#include <math.h>

/*
Divide the number with all elements from  1 to number and check whether its prime number or not.
Dont do any optimizations. Just write the brute force code.
*/
int isPrimeBruteForce(int number){
	int count = 0;
	for (int i = 2; i < number; i++)
	{
		if (number % i == 0)
			count++;
	}
	if (count == 0)
		return 1;
	else
		return 0;
}

/*
Is checking division till number neccesary?

You can do it just till half of number or even better just square root of n.

Divide the number with all elements from  1 to sqrt(number) and check whether its prime number or not.
Dont do any more optimizations.

Think why is it sufficient to do it till just square root of number.
*/
int isPrimeSquareRoot(int number){
	int count = 0;
	for (int i = 2; i*i <= number; i++)
	{
		if (number % i == 0)
			count++;
	}
	if (count == 0)
		return 1;
	else
		return 0;
}

/*
Add more optimizations you like,
Like if a number is odd number you need not divide it with even numbers. etc.
*/
int isPrimeOptimized(int number){
	if (number == 2)
		return 1;
	else if (number == 3)
		return 1;
	else if (number % 2 == 0 || number % 3 == 0 || number % 5 == 0)
		return 0;
	else
	{
		int count = 0;
		for (int i = 5; i*i <= number; i = i + 6)
		{
			if (number % i == 0 || number % (i + 2) == 0)
				count++;
		}
		if (count == 0)
			return 1;
		else
			return 0;
	}
}

