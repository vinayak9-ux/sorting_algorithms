/*
Topic	: Recursion: Series
Date	: 27/9/2021
Time	: 11.00am
*/

#include<stdio.h>

int series1(int n);
int series2(int n);

int main()
{
	int s1, s2, n;
	
	printf("enter the number :: ");
	scanf("%d", &n);
	
	s1 = series1(n);
	printf("\n");
	s2 = series2(n);
	
	
	printf("\n\ns1 = %d  s2 = %d ", s1, s2);
	return 0;
}
int series1(int n)
{
	int sum;
	if(n == 1)
	{
		printf("Series1 = %d", n);
		return 1;
	}
	else
	{
		sum = n * series1(n-1);
		printf(" * %d", n);
		return sum;
	}
}
int series2(int n)
{
	int sum;
	if(n == 1)
	{
		printf("Series2 = %d", n);
		return 1;
	}
	else
	{
		sum = n + series2(n-1);
		printf(" + %d", n);
		return sum;
	}
}
