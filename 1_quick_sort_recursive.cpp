/*
Topic	: Quick Sort - Recursive approach
Date	: 6/9/2021
Time	: 11.00am
*/

#include<stdio.h>
#include<conio.h>

void quick_sort(int arr[], int left, int right);
int partition(int arr[], int left, int right);

int main()
{
	int arr[] = {54, 26, 93, 17, 77, 31, 44, 55, 20};
	int len = sizeof(arr)/sizeof(int);
	
	printf("original = ");
	for(int i = 0 ; i < len ; i++)
		printf("%d ", arr[i]);
	printf("\n");	
	
	quick_sort(arr, 0, len-1);
	
	printf("sorted = ");
	for(int i = 0 ; i < len ; i++)
		printf("%d ", arr[i]);
	
	getch();
	return 0;
}

void quick_sort(int arr[], int left, int right)
{
	if(left < right)
	{
		int pi = partition(arr, left, right);
		printf("%d %d %d\n", left, right, pi);
		
		quick_sort(arr, left, pi-1);
		quick_sort(arr, pi+1, right);
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
