/*

ProblemCODE : BINARYSTROP
Difficulty : Medium
Marks : 15

Given two binary numbers in form of strings and
a string representing "AND", "OR", "NOR" or "XOR". Return the output string which forms by doing the specified operation on those 2 strings .


Ex:	Input: "101", "111", op =  "OR"
Output: "111"


Ex:	Input: "10101", "1111", op =  "AND"
Output: "00101"

Ex:	Input: "0111", "1010", op =  "XOR"
Output: "0010"

Ex:	Input: "0011", "1010", op =  "NOR"
Output: "0100"

Note :
In the above representations ,Write those strings on a paper ,you will understand them better . [Align them to the Right]
If 1 string length is less than other ,you need to consider missing letters as 0's ie "1111" AND "1" is same as "1111" AND "0001".
Ie if a String is "" ,you should consider it as All 0's .This dosent not apply if String is NULL.

Reference : http://www.bristolwatch.com/pport/pics/logic_table.gif [For AND,OR,XOR]
For NOR : http://www.circuitstoday.com/wp-content/uploads/2010/04/2-Input-NOR-Gate-Truth-Table.jpg

Contraints :
String length < 50.
For 50% of TestCases ,only AND/OR operations will be given .

Difficulty : Medium

*/

#include <stdio.h>
#include <stdlib.h>

int find_length(char *str);

char *performOperation(char *str1, char *str2, char *operation){
	int len1, len2, len;
	char *output;

	len1 = find_length(str1);
	len2 = find_length(str2);

	if (len1 >= len2)
		len = len1;
	else
		len = len2;

	output = (char*)calloc(len + 1 , sizeof(char));
	output[len] = '\0';
	if (*operation == 'A')
	{
		// AND Operation.
		int i = len1 - 1, j = len2 - 1, k = len - 1;
		while (i >= 0 && j >= 0)
		{
			if (str1[i] == '1' && str2[j] == '1')
				output[k--] = '1';
			else
				output[k--] = '0';
			i--;
			j--;
		}
		while (i >= 0)
		{
			output[k--] = '0';
			i--;
		}
		while (j >= 0)
		{
			output[k--] = '0';
			j--;
		}
		return output;
	}
	else if (*operation == 'O')
	{
		// OR Operation.
		int i = len1 - 1, j = len2 - 1, k = len - 1;
		while (i >= 0 && j >= 0)
		{
			if (str1[i] == '0' && str2[j] == '0')
				output[k--] = '0';
			else
				output[k--] = '1';
			i--;
			j--;
		}
		while (i >= 0)
		{
			if (str1[i] == '1')
				output[k--] = '1';
			else
				output[k--] = '0';
			i--;
		}
		while (j >= 0)
		{
			if (str2[j] == '1')
				output[k--] = '1';
			else
				output[k--] = '0';
			j--;
		}
		return output;
	}
	else if (*operation == 'X')
	{
		// XOR Operation.
		int i = len1 - 1, j = len2 - 1, k = len - 1;
		while (i >= 0 && j >= 0)
		{
			if (str1[i] == str2[j])
				output[k--] = '0';
			else
				output[k--] = '1';
			i--;
			j--;
		}
		while (i >= 0)
		{
			if (str1[i] == '1')
				output[k--] = '1';
			else
				output[k--] = '0';
			i--;
		}
		while (j >= 0)
		{
			if (str2[j] == '1')
				output[k--] = '1';
			else
				output[k--] = '0';
			j--;
		}
		return output;
	}
	else if (*operation == 'N')
	{
		// NOR Operation.
		int i = len1 - 1, j = len2 - 1, k = len - 1;
		while (i >= 0 && j >= 0)
		{
			if (str1[i] == '0' && str2[j] == '0')
				output[k--] = '1';
			else
				output[k--] = '0';
			i--;
			j--;
		}
		while (i >= 0)
		{
			if (str1[i] == '0')
				output[k--] = '1';
			else
				output[k--] = '0';
			i--;
		}
		while (j >= 0)
		{
			if (str2[j] == '0')
				output[k--] = '1';
			else
				output[k--] = '0';
			j--;
		}
		return output;
	}
}

int find_length(char *str)
{
	int i = 0;
	while (*(str + i) != '\0')
		i++;
	return i;
}






