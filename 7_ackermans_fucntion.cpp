/*
Topic	: Ackermann's Theorom
Date	: 4/10/2021
Time	: 11.00am
*/
#include<stdio.h>

int ackerman(int m, int n);
int main()
{
	printf("%d ", ackerman(3, 2));
	return 0;
}
int ackerman(int m, int n)
{
	if(m == 0)
		return n+1;
	else if(m > 0 && n == 0)
		return ackerman(m-1, 1);
	else if(m > 0 && n > 0)
		return ackerman(m-1, ackerman(m, n-1));
}
