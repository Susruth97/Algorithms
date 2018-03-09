/*
OVERVIEW: Given a string, return the letter at Kth index from the end of the string.
E.g.: Input: "qwertyui", 3. Output: 't' (index starting from zero).

INPUTS: A string and value of K.

OUTPUT: Return the letter at Kth index from the end of the string (index starting from zero).

ERROR CASES: Return '\0' for invalid inputs.

NOTES:
*/
char KthIndexFromEnd(char *str, int K) {
	int j = 0, len = 0;
	if (str)
	{
		while (str[j] != '\0')
		{
			len++;
			j++;
		}
		if (len > 0 && K >= 0 && K < len)
			return str[len - 1 - K];
		else
			return '\0';
	}
	else
		return '\0';
}