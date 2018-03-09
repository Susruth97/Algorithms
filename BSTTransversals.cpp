/*

Given a Binary Search Tree ,Calculate its Inorder ,Postorder and PreOrder

Input : A BST
Output : Copy Inorder/Postorder/Preorder into the array specified .

Note : Memory for the Array is already allocated ,Dont allocate it again using malloc
->Take help of helper functions which are actually solving the problem .
->Dont Process Invalid Inputs

Bonus Task :
->Go to the BSTTransversals Spec File ,We have left a custom test case for you ,Try to fill
it and understand how testing works .
*/

#include <stdio.h>
int i = 0;

struct node{
	struct node * left;
	int data;
	struct node *right;
};

void inorder_traversal(struct node *r, int p[]) {
	if (r == NULL) return;
	inorder_traversal(r->left, p);

	p[i] = r->data;
	i++;

	inorder_traversal(r->right, p);
}

void inorder(struct node *root, int *arr){
	int p[100], k;
	if (root == NULL || arr == NULL) return;

	inorder_traversal(root, p);

	for (k = 0; k < i; k++)
		arr[k] = p[k];
	i = 0;
}

void preorder_traversal(struct node *r, int p[]) {
	if (r == NULL) return;

	p[i] = r->data;
	i++;

	preorder_traversal(r->left, p);

	preorder_traversal(r->right, p);
}

void preorder(struct node *root, int *arr){
	int p[100], k;
	if (root == NULL || arr == NULL) return;

	preorder_traversal(root, p);

	for (k = 0; k < i; k++)
		arr[k] = p[k];
	i = 0;
}

void postorder_traversal(struct node *r, int p[]) {
	if (r == NULL) return;

	postorder_traversal(r->left, p);

	postorder_traversal(r->right, p);

	p[i] = r->data;
	i++;
}

void postorder(struct node *root, int *arr){
	int p[100], k;
	if (root == NULL || arr == NULL) return;

	postorder_traversal(root, p);

	for (k = 0; k < i; k++)
		arr[k] = p[k];
	i = 0;
}