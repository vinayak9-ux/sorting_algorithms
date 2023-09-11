

#include<stdio.h>

void tower(char src, char aux, char dest, int n);

int main()
{
	int n;
	printf("enter the number of disks :: ");
	scanf("%d", &n);
	
	tower('A', 'B', 'C', n);
	return 0;
}
void tower(char src, char aux, char dest, int n)
{
	if(n == 1)
	{
		printf("%d move from : %c tower to %c tower\n", n, src, dest);
	}
	else
	{
		tower(src, dest, aux, n-1);
		printf("%d move from : %c tower to %c tower \n", n, src, dest);
		tower(aux, src, dest ,n - 1);
	}
}
