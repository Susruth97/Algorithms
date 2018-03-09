/*
Write a program to generate elements of a matrix in spiral order.
Store the generated elements in single dimensional array and return that array.

Directions for Spiral are : Go Right ,Go Down ,Go Left, Go Up
Ex:

Matrix:
1	2	3
4	5	6
7	8	9

Spiral order:
1	2	3	6	9	8	7	4	5

Given matrix is a two dimensional array(input_array) with dimensions rows, columns.
If rows, columns are invalid then return NULL.
If input_array is NULL then return NULL.

Example Input :
int board[2][3]={
				 {4,6,7},
				 {1,3,8}
				};
spiral(2,2,(int **)board); // Rows followed by columns followed by board

Example Output : Return an array consisting of {4,6,7,8,3,1};

Note : Check the function Parameters ,Its a double pointer .

*/


#include "stdafx.h"
#include<stdlib.h>

void traverse(int **input, int *arr, int x, int y, int *i, int rows, int cols, int x1, int y1, int x2, int y2, int flag);

int *spiral(int rows, int columns, int **input_array)
{
	int *arr, i = 0;
	if (input_array == NULL || rows < 1 || columns < 1) 
		return NULL;

	arr = (int *)malloc(sizeof(int) * rows * columns);
	
	traverse(input_array, arr, 0, 0, &i, rows, columns, 0, 0, rows-1, columns-1, 0);

	return arr;
}

void traverse(int **input, int *arr, int x, int y, int *i, int rows, int cols, int x1, int y1, int x2, int y2, int flag) {
	if (*i >= (rows*cols)) return;
	if (flag) {
		while (y >= y1)
		{
			arr[*i] = input[x][y];
			*i += 1;
			y--;
		}
		y++;
		x--;
		while (x >= x1)
		{
			arr[*i] = input[x][y];
			*i += 1;
			x--;
		}
		x++;
		traverse(input, arr, x, y + 1, i, rows, cols, x1, y1 + 1, x2 - 1, y2, 0);
	}
	else {
		while (y <= y2) {
			arr[*i] = input[x][y];
			*i += 1;
			y++;
		}
		y--;
		x++;
		while (x <= x2) {
			arr[*i] = input[x][y];
			*i += 1;
			x++;
		}
		x--;
		traverse(input, arr, x, y - 1, i, rows, cols, x1 + 1, y1, x2, y2 - 1, 1);
	}
}
