/*
Given an array of integers, return the two numbers such that they add up to a specific target.

You may assume that each input will have exactly one solution. Return NULL for invalid inputs

Given nums = [1, 20, 2, 4], target = 24,

Because nums[1] + nums[3] = 20 + 4 = 24,
return [4, 20]. (Always the first number should be less in final answer)

If target is 5 ,Return [1,4]
If target is 22 ,return [2,20]

Note :
Return_Array[0] should always be less than/equal to Return_Array[1]

Constraints :
len <100000
-100000< nums[i] <100000

Question Source Link : https://leetcode.com/problems/two-sum/
We Picked this standard problem from Online , as its a very famous one and you will get habituated on solving on
Leetcode .

You need to solve this question in 3 ways.And measure time for each way.

Observations: (Write down what you observed here):
way 1 : (Brute Force)

LoopCount = 100, size = 1000 Time Taken = 0.33 sec
LoopCount = 1000, size = 1000 Time Taken = 1.87 sec
Way 2: (Square Root)

LoopCount = 1000, size = 1000 Time Taken = 0.08 sec
LoopCount = 10000, size = 1000 Time Taken = 0.84 sec
Way 3: (Omptmized way)

LoopCount = 100, size = 1000 Time Taken = 0.00 sec
LoopCount = 1000, size = 1000 Time Taken = 0.03 sec
LoopCount = 10000, size = 1000 Time Taken = 0.072 sec

Conclusion :
Brute force and square root takes a lot of time for searching whereas optimized way has O(1)
complexity for search, so making it's complexity O(n).

*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

static void swap(void *x, void *y, size_t size);
static int cmpInt(const void *i, const void *j);
void qsort3way(void *base, int lo, int hi, size_t size, int(*cmp)(const void *, const void *));

//void mergesort(int *nums, int l, int r);
//void merge(int *nums, int l, int m, int r);

/*
Take each element, Sum with all other elements.
Repeat it with all elements.

What is the complexity of this method ? O(n*n).
*/
int* sumoftwoBF(int *nums, int target, int len){
	if (nums != NULL && len > 0)
	{
		int i, j, *output;
		output = (int*)malloc(2 * sizeof(int));
		for (i = 0; i < len; i++)
		{
			for (j = 0; j < len; j++)
			{
				if (nums[i] + nums[j] == target)
				{
					if (nums[i] < nums[j])
					{
						output[0] = nums[i];
						output[1] = nums[j];
						return output;
					}
					else
					{
						output[0] = nums[j];
						output[1] = nums[i];
						return output;
					}
				}
			}
		}
		return NULL;
	}
	else
		return NULL;
}

/*
Sort the array first. Preferably using quicksort/mergesort. (nlogn)

Now the array is sorted, Can you do improve the above method.

Hint:
Lets say sorted array is [3,4,5,7,10,12] and required sum is 11.

Lets say we added 3+12 first, whats the sum, Its 15 right ? Its greater than 11.So should we next add
so that total sum will become less.

What is the complexity of this method ? O(n*logn)
*/
int* sumoftwoSortAndSearch(int *nums, int target, int len){
	int i = 0, j = len - 1;
	qsort3way(nums, 0, len - 1, sizeof(int), cmpInt);
	int *output, flag = 0;
	output = (int*)calloc(2, sizeof(int));

	while (i < j)
	{
		int sum = nums[i] + nums[j];
		if (sum == target)
		{
			flag = 1;
			output[0] = nums[i];
			output[1] = nums[j];
			return output;
		}
		else if (sum < target)
			i++;
		else
			j--;
	}
	if (flag == 0)
		return NULL;

}

static void swap(void *x, void *y, size_t size) {
	void *tmp = malloc(size);
	memcpy(tmp, x, size);
	memcpy(x, y, size);
	memcpy(y, tmp, size);

	free(tmp);
}

static int cmpInt(const void *i, const void *j) {
	if (*(int *)i < *(int *)j)
		return 1;
	else if (*(int *)i == *(int *)j)
		return 0;
	else
		return -1;
}

void qsort3way(void *base, int lo, int hi, size_t size, int(*cmp)(const void *, const void *)) {
	if (hi <= lo)
		return;
	else {
		char *ptr = (char*)base;
		char *v = ptr + lo * size;

		int lt = lo, gt = hi;
		int i = lo;
		while (i <= gt) {
			int c = cmp(v, ptr + i * size);
			if (c < 0)
				swap(ptr + (lt++) * size, ptr + (i++) * size, size);
			else if (c > 0)
				swap(ptr + i * size, ptr + (gt--) * size, size);
			else
				i++;
		}

		qsort3way(base, lo, lt - 1, size, cmp);
		qsort3way(base, gt + 1, hi, size, cmp);
	}
}


/*

Array contains only integers from 1-100; Can you use this range restriction and an extra array to
find 2Sum even more faster

Hint:
Lets say sorted array is [3,4,5,7,10,12] and required sum is 11.

If we are at 3, What number we need to tell that 3 is in final answer? 8 right (11-3 = 8). So some how we need to find a way
to know whether 8 is already in the array or not.As of now we dont know that, we will store 3 somewhere
(Which can be accesible in O(1)) and move to next element. 4 is there, we need to know whether array has 7 or not.(11-4 =7)
We dont know that yet, we move on ...we will store 4 somewhere now.

We go on till 7(4th element). We reach here we require 4 (11-7 = 4) .We already know 4 is present in array. (With O(1)).
We immediately return the answer. Think and discuss with your friends.

You are expected to solve this method in O(n)
*/

int* sumoftwoExtraArray(int *nums, int target, int len) {
	static int hash[101], *output, diff, flag;
	output = (int*)malloc(2 * sizeof(int));
	for (int j = 0; j < len; j++)
	{
		int temp = nums[j];
		if (hash[target - temp] == 1)
		{
			flag = 1;
			if (temp > target - temp)
			{
				output[0] = target - temp;
				output[1] = temp;
				break;
			}
			else
			{
				output[0] = temp;
				output[1] = target - temp;
				break;
			}
		}
		else
			hash[nums[j]] = 1;
	}
	if (flag == 1)
		return output;
	else
		return NULL;
}

