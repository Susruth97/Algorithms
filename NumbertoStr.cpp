/*
OVERVIEW: Given a float number ,Convert it into a string 

INPUTS: A Float,Final string ,How many digits after decimal has to be displayed .
Its zero for integers.


OUTPUT: No need to output anything ,Modify the str in function parameter such that it
now holds the string format of the float number specified

Example : number_to_str(345,str,0);
Should copy "345\0" in the str;
number_to_str(345.342,str,2);
Should copy "345.34" in the str;

NOTES: Don't create new string.

*/

#include <stdio.h>


void number_to_str(float number, char *str,int afterdecimal){
	int n, temp, count = 0, j = 0, k;
	float decimal, num;

	num = number;
	if (num < 0)
		number = -1 * number;

	n = number;
	decimal = number - n;

	for (int i = 0; i < afterdecimal; i++)
		decimal = decimal * 10;

	int d = decimal;
	temp = n;
	while (temp != 0)
	{
		temp = temp / 10;
		count ++;
	}

	temp = d;
	if (d != 0)
	{
		j = count + afterdecimal;
		k = j;
		while (j >= count + 1)
		{
			str[j] = temp % 10 + '0';
			temp = temp / 10;
			j--;
		}
		str[j] = '.';
		j--;
	}
	else
	{
		j = count;
		k = j;
		str[j] = '\0';
		j --;
	}

	while (j >= 0)
	{
		str[j] = n % 10 + '0';
		n = n / 10;
		j --;
	}

	if (num < 0)
	{
		for (int i = k + 1; i > 0; i--)
			str[i] = str[i - 1];
		str[0] = '-';
	}
}