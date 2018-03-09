/*
OVERVIEW: Given two strings, find the words that are common to both the strings.
E.g.: Input: "one two three", "two three five".  Output: "two", "three".

INPUTS: Two strings.

OUTPUT: common words in two given strings, return 2D array of strings.

ERROR CASES: Return NULL for invalid inputs.

NOTES: If there are no common words return NULL.
*/

#include <stdio.h>
#include <malloc.h>

#define SIZE 31

char ** commonWords(char *str1, char *str2) {
	if (str1 && str2)
	{
		char **output;
		int m = 0, n, count, common = 0;
		output = (char **)malloc(SIZE * sizeof(char *));

		for (int i = 0; *(str1 + i) != '\0'; i++)
		{
			for (int j = 0; *(str2 + j) != '\0'; j++)
			{
				if (*(str1 + i) == *(str2 + j) && *(str1 + i) != ' ' && *(str1 + (i + 1)) == *(str2 + (j + 1)))
				{
					count = 0;
					while (*(str1 + i) == *(str2 + j) && *(str1 + i) != ' ' && *(str1 + i) != '\0' && *(str2 + j) != '\0')
					{
						i++;
						j++;
						count++;
						common++;
					}
					n = 0;
					output[m] = (char *)malloc(count * sizeof(char));
					for (int k = i - count; k < i; k++)
					{
						output[m][n] = str1[k];
						n++;
					}
					output[m][n] = '\0';
					m++;
				}
			}
		}
		if (common != 0)
			return output;
		else
			return NULL;
	}
	else
		return NULL;
}