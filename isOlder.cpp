/*
OVERVIEW: 	Given date of births of two persons as inputs, return 1 if person one is elder,
2 if person two is elder, 0 if both are of same age.
Example: isOlder("24-07-2000", "25-07-2000") should return 1 as person one
is elder than person two.

INPUTS: 	DOBs of two persons as parameters in the format "DD-MM-YYYY".

OUTPUT: 	1 if person one is elder, 2 if person two is elder, 0 if both are of same age.

ERROR CASES: Return -1 if any DOB is invalid.

NOTES: 		Don't use any built-in C functions for comparisions. You are free to write any helper functions.
*/
struct date
{
	int year;
	int month;
	int day;
};
struct date numerize(char *dob);
int compare(struct date d1, struct date d2);
int valid(struct date d);

int isOlder(char *dob1, char *dob2) {
	date d1, d2;
	d1 = numerize(dob1);
	d2 = numerize(dob2);

	/* checking for alphabets in input */
	int temp1, temp2, alph = 0;
	for (int i = 0; i < 10; i++)
	{
		if (dob1[i] != 2 && dob1[i] != 5 && dob2[i] != 2 && dob2[i] != 5)
		{
			temp1 = dob1[i] - '0';
			temp2 = dob2[i] - '0';
			if (temp1 < 0 || temp1 > 9 || temp2 < 0 || temp2 > 9)
				alph ++;
		}
	}

	/* checking whether the dates are valid or not */
	int v_date1, v_date2;
	if (alph != 0)
	{
		v_date1 = valid(d1);
		v_date2 = valid(d2);
	}
	else
		return -1;

	/* comparing the two dates if they are valid */
	if (v_date1 == 1 && v_date2 == 1)
		compare(d1, d2);
	else
		return -1;
}

date numerize(char *dob) {
	date d;
	d.year = 0;
	d.month = 0;
	d.day = 0;

	int temp;
	for (int i = 0; i < 2; i  ++)
	{
		d.day = d.day * 10 + (dob[i] - '0');
	}
	for (int i = 3; i < 5; i++)
	{
		d.month = d.month * 10 + (dob[i] - '0');
	}
	for (int i = 6; i < 10; i++)
	{
		d.year = d.year * 10 + (dob[i] - '0');
	}
	return d;
}

int compare(struct date d1, struct date d2)
{
	if (d1.year < d2.year)
		return 1;

	else if (d1.year > d2.year)
		return 2;

	if (d1.year == d2.year)
	{
		if (d1.month < d2.month)
			return 1;
		else if (d1.month > d2.month)
			return 2;
		if (d1.month == d2.month)
		{
			if (d1.day < d2.day)
				return 1;
			else if (d1.day > d2.day)
				return 2;
			else
				return 0;
		}
	}
}

int valid(struct date d) {
	if (d.year > 0 && d.month > 0 && d.month <= 12 && d.day > 0)
	{
		if (d.month == 4 || d.month == 6 || d.month == 9 || d.month == 11)
		{
			if (d.day >= 1 && d.day <= 30)
				return 1;
			else
				return -1;
		}
		else if (d.month == 2)
		{
			if (d.year % 4 == 0)
			{
				if (d.day >= 1 && d.day <= 29)
					return 1;
				else
					return -1;
			}
			else
			{
				if (d.day >= 1 && d.day <= 28)
					return 1;
				else
					return -1;
			}
		}
		else
		{
			if (d.day >= 1 && d.day <= 30)
				return 1;
			else
				return -1;
		}
	}
	else
		return -1;
}










