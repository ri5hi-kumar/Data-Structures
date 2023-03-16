// Adjacency Matrix representaion and Warshall’s Algorithm
#include <stdio.h>
#include <stdlib.h>
#define INF 99999

void warshellAlgorithm(int graph[][4])
{
    for (int k = 0; k < 4; k++)
    {
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                if (graph[i][j] > graph[i][k] + graph[k][j])
                    graph[i][j] = graph[i][k] + graph[k][j];
            }
        }
    }
}

int main()
{
    int graph[][4] = {
        {0, 3, INF, 7},
        {8, 0, 2, INF},
        {5, INF, 0, 1},
        {2, INF, INF, 0}};

    warshellAlgorithm(graph);

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            printf("%d\t", graph[i][j]);
        }
        printf("\n");
    }

    return 0;
}