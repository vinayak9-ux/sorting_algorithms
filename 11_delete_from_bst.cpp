/*
Topic	: Deleting node of a BST
Date	: 08/11/2021
Time	: 11.00am
*/

#include<stdio.h>
#include<stdlib.h>


struct node
{
	int key;
	struct node *left;
	struct node *right;
};
typedef struct node node;

node* insertNode(node *root, int d);
node* deleteNode(node *root, int d);
void inorderTraversal(node *root);

int main()
{
	node *tree = NULL;
	
	tree = insertNode(tree, 7);
	tree = insertNode(tree, 16);
	tree = insertNode(tree, 5);
	tree = insertNode(tree, 3);
	tree = insertNode(tree, 6);
	tree = insertNode(tree, 15);
	tree = insertNode(tree, 19);
	tree = insertNode(tree, 18);
	tree = insertNode(tree, 17);
	
  	inorderTraversal(tree);
	tree = deleteNode(tree, 6);
	printf("\n");
	inorderTraversal(tree);
	
	return 0;
}

node* insertNode(node *root, int d)
{
	if(root == NULL) // empty tree
	{
		root = (node *)malloc(sizeof(node));
		root->left = root->right = NULL;
		root->key = d;
		
	}
	else if(root->key > d)
		root->left = insertNode(root->left, d);
	else
		root->right = insertNode(root->right, d);

	return root;	
}

node *deleteNode(node * root, int d)
{
	if(root == NULL)
		return root;
	
	if(root->key == d) // found! so lets delete
	{
		// lets see if root is full node or not
		if(root->right != NULL && root->left != NULL)
		{
			// first find the left most sub tree on right
			node *ptr = root->right;
			while(ptr->left != NULL)
				ptr = ptr->left;
			int tmp = ptr->key;
			printf("\nleft most node of r sub tree = %d", tmp);
			deleteNode(root, tmp);// delete it from that position
			root->key = tmp;// replace root with it
			
		}
		else if(root->right == NULL && root->left != NULL) // half node with a node on the left
		{
			node *t = root->left;
			free(root);
			return t;
		}
		else if(root->left == NULL && root->right != NULL ) // half node with a node on right
		{
			node *t = root->right;
			free(root);
			return t;
		}
		else // leaf node
		{
			free(root);
			return NULL; // null will get back to the parent of the current node
		}
	}
	else if(d > root->key) // searching for the node in right sub tree
		root->right = deleteNode(root->right, d);
	else // searching for node in left sub tree
		root->left = deleteNode(root->left, d);
	return root;
}

void inorderTraversal(node *root)
{
	if(root != NULL)
	{
		inorderTraversal(root->left);
		printf("%d ", root->key);
		inorderTraversal(root->right);
	}
}

