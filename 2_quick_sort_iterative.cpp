/*
Topic	: Quick Sort - Iterative approach
Date	: 6/9/2021
Time	: 11.00am
*/

#include<stdio.h>
#include<conio.h>

void quick_sort_iterative(int arr[], int len);
int partition(int arr[], int left, int right);

int main()
{
	int arr[] = {54, 26, 93, 17, 77, 31, 44, 55, 20};
	int len = sizeof(arr)/sizeof(int);
	
	printf("original = ");
	for(int i = 0 ; i < len ; i++)
		printf("%d ", arr[i]);	
	quick_sort_iterative(arr, len);
	
	printf("\nsorted   = ");
	for(int i = 0 ; i < len ; i++)
		printf("%d ", arr[i]);
	
	getch();
	return 0;
}

void quick_sort_iterative(int arr[], int len)
{
	int left, right, top = -1, pi, rp, lp;
	int stack[len]; // worst case for stack = skew tree, so took size of ori array
	
	left = 0;
	right = len - 1;
	
	stack[++top] = left;
	stack[++top] = right;
	
	while(top >= 0)
	{
		rp = stack[top--];
		lp = stack[top--];
		
		pi = partition(arr, lp, rp);
		
		if(pi - 1 > lp)
		{
			stack[++top] = lp;
			stack[++top] = pi - 1;
		}
		if(pi + 1 < rp)
		{
			stack[++top] = pi + 1;
			stack[++top] = rp;
		}
	}	
}

int partition(int arr[], int left, int right)
{
	int lp = left, rp = right, tmp;
	int pivot = arr[left];
	
	while(lp < rp)
	{
		while(arr[lp] <= pivot && lp < right)
			lp++;
			
		while(arr[rp] > pivot && rp > 0)
			rp--;
		
		if(lp < rp)
		{
			tmp = arr[rp];
			arr[rp] = arr[lp];
			arr[lp] = tmp;
		}
	}
	tmp = arr[left];
	arr[left] = arr[rp];
	arr[rp] = tmp;
	
	return rp;
}

