/*
Topic	: Hashing: linear probing
Date	: 13/9/2021
Time	: 11.00am
*/

#include<stdio.h>
#include<conio.h>

#define LEN 5

void initialize();
void disp_table();
int insert_element(int key);
int search_element(int key);

int hash_table[LEN];

int main()
{
	int flag = 1, pos, key, opt;
	initialize();
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
				disp_table();
				break;
				
			case 2:
				printf("enter key element :: ");
				scanf("%d", &key);
				if( insert_element(key) == 0)
					printf("key inserted successfully!\n");
				else
					printf("hash table full\n");
				break;
				
			case 3:
				printf("enter key element :: ");
				scanf("%d", &key);
				
				pos = search_element(key);
				
				if( pos == -1)
					printf("key not found!\n");
				else
					printf("key found at location %d\n", pos);
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
void initialize()
{
	for(int i = 0 ; i < LEN ; i++)
		hash_table[i] = -1;
}
void disp_table()
{
	int i;
	printf("Table :: ");
	for(i = 0 ; i < LEN ; i++)
		printf("%d ",hash_table[i]);
	printf("\n");
}
int insert_element(int key)
{
	int base_loc, offset;
	base_loc = key % LEN;
	offset = 0;
	
	while(hash_table[(base_loc + offset)%LEN] != -1)
	{
		if(offset == LEN)
			return -1;
		offset++;
	}
	hash_table[(base_loc + offset)%LEN] = key;
	
	return 0;
}
int search_element(int key)
{
	int base_loc, offset;
	base_loc = key % LEN;
	offset = 0;
	
	while(hash_table[(base_loc + offset)%LEN] != key)
	{
		if(offset == LEN)
			return -1;
		offset++;
	}
	return (base_loc + offset)%LEN;
}
