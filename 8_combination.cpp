/*
Topic	: Combination of strings
Date	: 4/10/2021
Time	: 11.00am
*/

#include<stdio.h>
#include<string.h>

int combination(char *str, int ptr);

int main()
{
	char ch[] = "abc";
	combination(ch, 0);
	return 0;
}
int combination(char *str, int ptr)
{
	char ch;
	if(ptr != strlen(str) - 1 )
	{
		
		for(int i = ptr ; i < strlen(str) ; i++)
		{
			ch = str[i];
			str[i] = str[ptr];
			str[ptr] = ch;
			
			combination(str, ptr+1);
			
			ch = str[i];
			str[i] = str[ptr];
			str[ptr] = ch;			
		}
	}
	else
		printf(" [  %s  ]\n", str);
}
