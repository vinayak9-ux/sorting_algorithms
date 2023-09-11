/*
Topic	: Dijkstra Algorithm
Date	: 11/11/2021
Time	: 11.00am
*/

#include<stdio.h>
#include<stdlib.h>

#define INF 999
#define N 5
int graph[N][N];

void initGraph();
void addEdge(int src, int dest, int weight);
void display();
void dijkstra(int src);

int main()
{
	initGraph();
	addEdge(0, 1, 10);
	addEdge(0, 2, 3);
	addEdge(1, 2, 1);
	addEdge(2, 1, 4);
	addEdge(2, 4, 2);
	addEdge(2, 3, 8);
	addEdge(1, 3, 2);
	addEdge(3, 4, 7);
	addEdge(4, 3, 9);
	
	display();
	dijkstra(0);
	
	return 0;
}

void initGraph()
{
	int i,j;
	for(i = 0 ; i < N ; i++)
		for(j = 0 ; j < N ; j++)
			graph[i][j] = 0;
}

void addEdge(int src, int dest, int weight)//adding directed graph
{
	graph[src][dest] = weight;
	//graph[dest][src] = weight;
}

void display()
{
	int i,j;
	printf("Graph is :: \n");
	for(i = 0 ; i < N ; i++)
	{
		for(j = 0 ; j < N ; j++)
			printf("%d\t", graph[i][j]);	
		printf("\n");
	}
	printf("\n");
}

void dijkstra(int src)
{
	// create spt set - shortest path tree set [set of elements in the shortest path tree]
	int sptSet[N];
	int distance[N];
	
	int i, j, min, pos;
	
	// init all distance as inf
	for(i = 0 ; i < N ; i++)
	{
		sptSet[i] = 0;
		distance[i] = INF;
	}
	distance[src] = 0;
	// while sptSet dont include all vert
	for(i = 0 ; i < N ; i++)
	{
		// pick u vertex not in sptSet, amd has min distance value
		min = INF;
		pos = -1;
		for(j = 0 ; j < N ; j++)
		{
			if(!sptSet[j] && distance[j] < min)
			{
				min = distance[j];
				pos = j;
			}
		}
		// add u to sptSet
		sptSet[pos] = 1;

		// update distance of adj vertex of u
		for(j = 0 ; j < N ; j++)
		{
			if(sptSet[j])
				continue;
				
			if(graph[pos][j] &&  graph[pos][j] + distance[pos] < distance[j] && distance[pos] != INF)
			{
				distance[j] = graph[pos][j] + distance[pos];
				//printf("\tupdated %d %d %d\n", j, graph[pos][j] + distance[pos] , distance[pos]);
			}
			//printf("\tupdated %d %d %d\n", j, graph[pos][j] + distance[pos] , distance[j]);
		}
	}
	for(i = 0 ; i < N ; i++)
		printf("dist of %d from src = %d \n", i, distance[i]);
}
