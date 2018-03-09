/*

In a college, there is a data centre where all the communications go on.
Like mails about Holidays, Schedules, Notices etc information.
The clerk at data centre used to ask students of every new batch to create new emails and submit through forms.
The clerk must know the name of the student by seeing the email.

But the students are mischevious. Their emails are unidentifiable.
For example: A student Manoj gave his email as iamironman123@gmail.com, Sunil as rockrocky143@gmail.co.in

The clerk is unable to find the name of the student just by seeing the email address.
So, he added a rule that email must contain the student name as prefix or suffix to email address

Example: Manoj has to create his email as "manojsomething@something.com" or "somethingmanoj@something.com"

Note: "abcmanojabc@live.com is invalid email address Since "manoj" is neither a prefix nor a suffix.

Help the clerk to check the following:

(1). Given email is Valid or not
ex: "manoj@gmail" is not a valid email address

(2). Given email satisfies the suffix/prefix condition
ex: student name: abc, email: "ab@c.com" is not valid
because even though it is valid email email address, it is not satisfying the clerk's new rule.


Given input is in the form of "name email" space seperated Name and email.
Return 1 if email condition (1) is only satisfied. Return 2 if both (1) and (2) are satisfied. Return 0 for all other cases
ex: INPUT: "Manoj iammanoj@gmail.com"
OUTPUT: 2

INPUT: "abc abc.com"
OUTPUT: 0


NOTE: (1) Do not use any string.h functions.
(2) Rules of a valid email address
a. should use only alphanumeric characters. That is, use only “a” through “z” and “0 (zero)” through “9”.
b. Use of the following characters: < > ( ) [ ] ; : , @ \ <space> is not allowed
c. As long as they are not the first character in the e-mail address, hyphens ( – ), underscores ( _ ), periods ( . ),
and numeric characters (“0” through “9”) are acceptable characters to use within the address.
d. Do not use null characters (spaces) between characters. However, as mentioned above, underscores are acceptable.
e. Email length must be less than or equal to 254 characters.
(3) MANoJ ,MaNoj all are same and to be treated as manoj in the name field
(4) Delimiter b/w name and email can be single or multiple spaces
(5) Input is in read only mode. you cannot edit it.
*/

#include <stdio.h>
#include <stdlib.h>

int valid_name(char *mail, int p);
int isalpha(char c);

int isValidEmail(char *email)
{
	int i = 0, at = 0, len, pos, flag, result = 0, sp = 0;
	/* 'at' is to count no. of @ and 'sp' is to count no. of time space occur before a non- space*/

	while (email[i] != '\0')
	{
		if (email[i - 1] == ' ' && email[i] != ' ')
		{
			pos = i;
			sp++;
		}
		if (email[i] == '@')
			at++;
		i++;
	}
	len = i;
	i = pos + 1;
	if (at == 1 && sp == 1 && !(email[pos] == '_' || email[pos] == '.' || email[pos] == '-'))
	{
		while (email[i] != '@')
		{
			if (isalpha(email[i]) == 0)
				break;
			i++;
		}
		if (email[i] == '@' && (len - pos + 1) <= 254)
			flag = 1;
		else
			flag = 0;
	}
	else
		flag = 0;

	if (flag == 1)
	{
		result++;
		if (valid_name(email, pos) == 1)
			result++;
	}
	return result;
}

int valid_name(char *mail, int p)
{
	int j, count = 0;
	for (int i = p; mail[i] != '@'; i++)
	{
		for (j = 0; mail[j] != ' '; j++)
		{
			if (mail[j + i] - mail[j] != 32 && mail[j + i] != mail[j])
				break;
		}
		if (mail[j] == ' ' && (mail[i - 1] == ' ' || mail[i + j] == '@'))
			count++;
	}
	if (count == 1)
		return 1;
	else
		return 0;
}

int isalpha(char c)
{
	if (c >= 65 && c <= 90)
		return 1;
	else if (c >= 97 && c <= 122)
		return 1;
	else if (c == '_' || c == '.' || c == '-')
		return 1;
	else if (c >= 48 && c <= 57)
		return 1;
	else
		return 0;
}