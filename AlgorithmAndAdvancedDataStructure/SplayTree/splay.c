/*
Splay tree is self-balancing BST. Main idea of splay tree is to bring recently accessed item to root of tree.
All splay tree operation run in O(logn) in average, where n is the number of entries in the tree. Any single tree can take Theta(n) time in the worst case.
*/
#include <stdio.h>
#include <stdlib.h>

// defination of node struct
typedef struct{
	int key;
	struct node *left, *right;	
}node;

// create a new node with key value
node *newNode(int key){
	node *n = (node *)malloc(sizeof(node));
	n->key = key;
	n->left = NULL;
	n->right = NULL;
}	

// preperder traversal
void preOrder(node *root){
	if(root == NULL)	return;
	printf("%d ", root->key);
	preOrder(root->left);
	preOrder(root->right);
}

// splay tree
node *splay(node *root, int key){
	// if key is in root node
	if(root == NULL || root->value == key){
		return root;
	}
	// key may lie in left subtree
	if(root->key > key){

	}else{// otherwise key may in right subtree

	}
}

// search operation


int main(){
	node *root = newNode(100);
	root->right = newNode(200);
	root->left = newNode(50);
	root->left->left = newNode(40);
	root->left->left->left = newNode(30);
	root->left->left->left->left = newNode(20);
}

