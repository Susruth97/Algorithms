/*
Here you will compare 2 searching algorithms.

LinearSearch and BinarySearch

Question :
Given an Array and its length and a key element, return the index (Where key is found) if key is found in array
or -1 if key is not found.

Sample Input : 
[1,2,3,4,5] Key : 4, Returns 3
[0,49,22] Key : 212, Returns -1

Observations: (Write down what you observed here, Run for various variations):

Linear Search:

array  of length 10000 and loop count=  10000 time taken=0.076s (key at start)
array  of length 10000 and loop count=  10000 time taken=0.306s (key at middle)
array  of length 10000 and loop count=  10000 time taken=0.595s (key at end).

Binary Search :

array  of length 10000 and loop count=  1000 time taken=0.00001s
array  of length 10000 and loop count= 10000 time taken=0.003s
array  of length 100000 and loop count=  100000 time taken=0.023s
array  of length 100000 and loop count=  1000000 time taken=0.176s

Conclusion :

Linear search O(n) as name suggests depend linearly on length, loop count, and key position,
Binary search is more efficient O(logn) as it eliminates umwanted data, and not depend on key pos.
But Complexity of binary search for unsorted array is O(nlogn) where linear search is more efficient,
so for unsorted array linear search using hash maps is more efficient than normal linear search
*/

int linearSearch(int *arr, int len, int key) {
	int i, match = 0;
	for (i = 0; i < len; i++)
	{
		if (arr[i] == key)
		{
			match = 1;
			break;
		}
	}
	if (match == 0)
		return -1;
	else
		return i;
}



int binarySearch(int *arr, int len, int key) {
	//Use this function as wrapper function,if you are implementing bs recursively.
	int low = 0, high = len - 1;
	while (low <= high)
	{
		int mid = (low + high) / 2;
		if (arr[mid] == key)
		{
			return mid;
			break;
		}
		else if (arr[mid] < key)
			low = mid + 1;
		else
			high = mid - 1;
	}
	return -1;
}