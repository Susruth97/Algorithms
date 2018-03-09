/*

Problem : Return the Last word in a string

Input : I will do this without using String Library
Output : Library

Note:Dont modify original string Neglect Spaces at the right end and at left end if required .
->Create a new string and return it , Use dynamic memory allocation .
*/
#include <stdlib.h>

char * get_last_word(char * str) {
	if (*str == '\0')
	{
		int i = 0, pos = 0;
		char *last;
		while (str[i] != '\0')
		{
			if (str[i] == ' ' && str[i + 1] != ' ' && str[i + 1] != '\0')
				pos = i + 1;
			i++;
		}
		int len = i - pos;
		int j = 0;
		last = (char*)malloc(len * sizeof(char));
		while (pos <= i)
		{
			if (str[pos] != ' ')
				last[j++] = str[pos++];
			else
				pos++;
		}
		return last;
	}
	else
		return "";
}
