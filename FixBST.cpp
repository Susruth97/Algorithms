/*

Given a Binary Search Tree ,with two misplaced Node .Find those nodes and fix them .

Do not create a new tree ,Modify the original tree
Ex : In the below tree 3 and 30 is misplaced .

  5
 / \
2   3
 \
  30
When fixed 30 will be right node of 5 , and 3 will be right node of 2 .

Ex :In the below tree 1 and 20 are misplaced

         9
        / \
       4   1
      /     \
    20      30
Nodes 1 and 20 need to be fixed here .

*/
#include <stdio.h>
#include <stdlib.h>


struct node{
	struct node * left;
	int data;
	struct node *right;
};

void bst_fixing(struct node *root, struct node **first, struct node **mid, struct node **last, struct node **prev) {
	if (root) {
		bst_fixing(root->left, first, mid, last, prev);

		if (*prev && root->data < (*prev)->data) {
			if (!*first) {
				*first = *prev;
				*mid = root;
			}
			else *last = root;
		}

		*prev = root;

		bst_fixing(root->right, first, mid, last, prev);
	}
}

void fix_bst(struct node *root){
	int t;
	struct node *first = NULL, *mid = NULL, *last = NULL, *prev = NULL;
	if (root == NULL) return;

	bst_fixing(root, &first, &mid, &last, &prev);

	if (first && last) {
		t = first->data;
		first->data = last->data;
		last->data = t;
	}
	else if (first && mid) {
		t = first->data;
		first->data = mid->data;
		mid->data = t;
	}
}