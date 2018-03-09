/*
OVERVIEW: Given a string, Count the number of consonants and vowels and copy them to 'consonants' and 'vowels' respectively
Notes : Neglect Space and Other Symbols .Consider Capital Letters too

E.g.: Input: "aB c" , Output: consonants should contain 2 and vowels 1

INPUTS: A string and two int pointers

OUTPUT: Modify the consonants and vowels pointers accordingly with their counts (*consonants=?? ;*vowels=??)

INPUT2: Dont Forget they are pointers ;consonants and vowels are addresses of two variables .

Output: consonants should be ??,vowels should be ??

??:Count them :)

NOTES: Don't create new string , Dont return anything ,you have been given two pointers ,copy values into those .
*/

#include <stddef.h>

void count_vowels_and_consonants(char *str, int *consonants, int *vowels){
	int i = 0, v = 0, c = 0;
	if (str)
	{
		while (*(str + i) != '\0')
		{
			if (*(str + i) >= 97 && *(str + i) <= 121)
				*(str + i) = *(str + i) - 'a' + 'A';
			if (*(str + i) >= 65 && *(str + i) <= 90)
			{
				if (*(str + i) == 65 || *(str + i) == 69 || *(str + i) == 73 || *(str + i) == 79 || *(str + i) == 85)
					v++;
				else
					c++;
			}
			i++;
		}
	}
	*vowels = v;
	*consonants = c;
}
