/*
OVERVIEW: Given a string, remove all spaces in it.
E.g.: Input: "abd scd". Output: "abdscd"

INPUTS: A string.

OUTPUT: Return string after removing spaces.

ERROR CASES: Return '\0' for invalid inputs.

NOTES: Don't create new string.
*/
char removeSpaces(char *str) {
	int j = 0, i = 0;
	if (str)
	{
		while (str[j] != '\0')
		{
			if (str[j] != ' ')
				str[i++] = str[j];
			j++;
		}
		str[i] = '\0';
		return *str;
	}
	else
		return '\0';
}