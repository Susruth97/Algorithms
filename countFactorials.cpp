/*Problem - To find the number of factorials in a given range.

Description - You will be given an input array[l, h] which gives the range.Your job is to return the count of the number of factorials between 'l' and 'h' both included.

Example: input = [2, 10]
		 The factorails between 2 and 10 is '2' alone.Hence 1 must be returned.


Constraints :
1) The range should not be negative, i.e neither of l and h should be negative.If so, return -1.
2) l, h are both long integers.
3) The range should be non decreasing, i.e l <= h.It is not, return -1.

DONT CHANGE THE FUNCTION HEADERS.



*/

#include <stdio.h>


int countFactorials(long l, long h)
{
	long fact = 1, x = 2;
	if (l >= 0 && h >= 0 && h >= l)
	{
		while (fact < l)
		{
			fact = fact * x;
			x ++;
		}

		long count = 0;
		while (fact <= h)
		{
			count ++;
			fact = fact * x;
			x ++;
		}
		return count;
	}
	else
		return -1;
}