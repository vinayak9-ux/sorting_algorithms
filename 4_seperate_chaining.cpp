/*
Topic	: Hashing: Seperate chaining
Date	: 20/9/2021
Time	: 11.00am
*/

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

#define LEN 5

struct node
{
	int data;
	struct node *next;
};
typedef struct node node;

node *chains[LEN];

void init(); // initialize chains to null

void traverse(int i);
int search(int val);

void insert(node **head, int v); // insert a node at start 
void seperateChaining(int val);

int main()
{
	int flag = 1, i, e, opt, pos, key;
	init();
	while(flag)
	{
		printf("\n\nMenu : \n");
		printf("1. display\t");
		printf("2. insert\t");
		printf("3. search \t");
		printf("4. exit\n");
		printf("Option : ");
		scanf("%d", &opt);
		
		switch(opt)
		{
			case 1:
				for(i = 0 ; i < LEN ; i++)
					traverse(i);
				break;
				
			case 2:
				printf("enter element :: ");
				scanf("%d", &e);
				seperateChaining(e);
				break;
				
			case 3:
				printf("enter key element :: ");
				scanf("%d", &key);
				pos = search(key);
				
				if( pos == -1)
					printf("key not found!\n");
				else
					printf("key found at list %d\n", pos+1);				
				break;				
			case 4:
				flag = 0;
				break;
				
			default:
				printf("invalid option!\n");
		}		
	}

	getch();
	return 0;
}

void init()
{
	for(int i = 0 ; i < LEN ; i++)
		chains[i] = NULL;
}

void insert(node **head, int v)
{
	node *newNode = (node *)malloc(sizeof(node));
	newNode->data = v;
	newNode->next = *head;
	*head = newNode;
}

void traverse(int i)
{
	node *ptr = chains[i];
	
	printf("%d | ", i);
	while(ptr != NULL)
	{
		printf("%d ", ptr->data);
		ptr = ptr->next;
	}
	printf("\n");
}

int search(int val)
{
	int i = val % LEN;
	node *ptr = chains[i];
	while(ptr != NULL)
	{
		if( ptr->data == val)
			return i;
		ptr = ptr->next;
	}
	return -1;
}

void seperateChaining(int val)
{
	int key = val % LEN;
	insert(&chains[key], val);
}
