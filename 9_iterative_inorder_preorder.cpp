/*
Topic	: Iterative traversals in a binary tree
			- in order
			- pre order
Date	: 25/10/2021
Time	: 11.00am
*/

#include<stdio.h>
#include<stdlib.h>

#define MAX 100

struct node
{
	char label;
	struct node *left;
	struct node *right;
};
typedef struct node node;

struct stack{
	node *arr[MAX];
	int top;
};
typedef stack stack;

void init(stack *st);
void push(stack *st, node *n);
node* pop(stack *st);
int isEmpty(stack *st);

node* insertNode(node *root, char label);
void inOrderTraversal(node *root);
void preOrderTraversal(node *root);

int main()
{
	node *tree = NULL;
	tree = insertNode(tree, 'D');
	
	insertNode(tree, 'A');
	insertNode(tree, 'F');
	insertNode(tree, 'E');
	insertNode(tree, 'G');
	
	printf("pre order: ");
	preOrderTraversal(tree);

	printf("\nin order: ");
	inOrderTraversal(tree);
		
	return 0;
}

node* insertNode(node *root, char label)
{
	if(root == NULL) // empty tree
	{
		root = (node *)malloc(sizeof(node));
		root->left = root->right = NULL;
		root->label = label;
		
	}
	else if(root->label > label)
		root->left = insertNode(root->left, label);
	else
		root->right = insertNode(root->right, label);

	return root;	
}

//iterative in order traversal
void inOrderTraversal(node *root)
{
	stack s;
	node *n;
	init(&s);
	
	n = root;
	do
	{
		while(n != NULL)// moving left till possible
		{
			push(&s, n);
			n = n->left;
		}
		n = pop(&s);// popping and printing root
		printf("%c ", n->label);
		
		n = n->right;// start to move right now
	}while(!isEmpty(&s)|| n != NULL);	
}

//iterative pre order traversal
void preOrderTraversal(node *root)
{
	node *n;
	stack s;
	
	init(&s);
	
	n = root;
	do
	{
		while(n != NULL)// moving left till possible
		{
			push(&s, n);
			printf("%c ", n->label);
			n = n->left;
		}
		n = pop(&s);// popping root
		
		n = n->right;// start to move right now
	}while(!isEmpty(&s) || n != NULL);	
}

// Stack function starts here 
void init(stack *st)
{
	st->top = -1;
}
void push(stack *st, node *n)
{
	if(st->top == MAX - 1)
		printf("Stack overflow");
	else
	{
		st->top++;
		st->arr[st->top] = n;
	}
}
node* pop(stack *st)
{
	node* t;
	if(st->top == -1)
		printf("Stack underflow");
	else
	{
		t = st->arr[st->top];
		st->top--;
		return t;
	}
}
int isEmpty(stack *st)
{
	if(st->top == -1)
		return 1;
	else
		return 0;
}
