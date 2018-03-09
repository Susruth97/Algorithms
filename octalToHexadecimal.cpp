/*
OVERVIEW:
1)Write a function which takes a octal number as input and returns the hexadecimal number for 
  octalToHexadecimal().
E.g.: octalToHexadecimal(10) returns 8.

2)Write a function which takes a fractional octal number as input and returns the hexadecimal number for 
octalToHexadecimalFraction() until precision two
E.g.: octalToHexadecimal(6.01) returns 6.04

INPUTS: Single octal number num;

OUTPUT: hexadecimal value of the octal number num.

Discalimer:Return 0 for invalid cases.[Negetive Numbers]

There are no test cases for fraction method but it would be good if you complete that too.
*/
#include<stdlib.h>
#include<math.h>
int octalToHexadecimal(long int num)
{
	if (num > 0){
		int octalDigitToBinary[8] = { 0, 1, 10, 11, 100, 101, 110, 111 };
		int hexDigitToBinary[16] = { 0, 1, 10, 11, 100, 101, 110, 111, 1000,
			1001, 1010, 1011, 1100, 1101, 1110, 1111 };
		char hexDigits[16] = { '0', '1', '2', '3', '4', '5', '6', '7', '8',
			'9', 'A', 'B', 'C', 'D', 'E', 'F' };
		char *hexadecimalNumber;
		long long int binaryNumber = 0, position, temp;
		int digit, fourDigit, i, n = 0;

		temp = num;
		if (temp != 0)
		{
			n++;
			temp = temp / 10;
		}

		hexadecimalNumber = (char*)malloc(n * sizeof(char));

		/* octal number  to binary no. */
		position = 1;
		while (num != 0) {
			digit = num % 10;
			binaryNumber = (octalDigitToBinary[digit] * position) + binaryNumber;
			num /= 10;
			position *= 1000;
		}
		/* binary number to hexadecimal no. */
		position = 0;
		while (binaryNumber != 0){
			fourDigit = binaryNumber % 10000;
			for (i = 0; i < 16; i++){
				if (hexDigitToBinary[i] == fourDigit){
					hexadecimalNumber[position] = hexDigits[i];
					break;
				}
			}

			position++;
			binaryNumber /= 10000;
		}
		hexadecimalNumber[position] = '\0';

		/* reversing the array and storing it in an integer */
		int hexa = 0, t;
		for (int j = position - 1; j >= 0; j--)
		{
			t = hexadecimalNumber[j] - '0';
			hexa = hexa * 10 + t;
		}
		return hexa;
	}
	else
		return 0;
}

float octalToHexadecimalFraction(float num)
{
	return 0.0;
}