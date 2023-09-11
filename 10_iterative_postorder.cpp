/*
Topic	: Iterative post-order traversal of binary tree
Date	: 01/11/2021
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
void postOrderTraversal(node *root);



int main()
{
	node *tree = NULL;
	tree = insertNode(tree, 'D');
	
	insertNode(tree, 'A');
	insertNode(tree, 'F');
	insertNode(tree, 'E');
	insertNode(tree, 'G');
	
	printf("post order: ");
	postOrderTraversal(tree);
		
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

void postOrderTraversal(node *root)
{
	stack s1, s2;
	node *n;
	
	init(&s1);
	init(&s2);

	push(&s1, root);// push root to s1		
	while(!isEmpty(&s1))//s1 not empty
	{
		n = pop(&s1);// pop s1  and push to s2
		push(&s2, n);
		
		if(n->left != NULL)// if top of s2 has l. child, push to s1
			push(&s1, n->left);
		
		if(n->right != NULL)// if top of s2 has r. child, push to s1
			push(&s1, n->right);
	} 
	
	// final ans is in s2,
	while(!isEmpty(&s2))
		printf("%c ", pop(&s2)->label);
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
