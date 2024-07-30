#include <limits.h>
#include <stdbool.h>
#include <stdio.h>

#define MAX_VERTICES 30

int minDistance(int dist[], bool sptSet[], int V)
{
    int min = INT_MAX, min_index;
    int v;
    for (v = 0; v < V; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;

    return min_index;
}

void printSolution(int dist[], int V)
{
    int i;
    printf("Vertex \t\t Distance from Source\n");
    for (i = 0; i < V; i++)
        printf("%d \t\t\t\t %d\n", i, dist[i]);
}

void dijkstra(int graph[MAX_VERTICES][MAX_VERTICES], int V, int src)
{
    int i, v, count;
    int dist[MAX_VERTICES];

    bool sptSet[MAX_VERTICES];

    for (i = 0; i < V; i++)
        dist[i] = INT_MAX, sptSet[i] = false;

    dist[src] = 0;

    for (count = 0; count < V - 1; count++)
    {

        int u = minDistance(dist, sptSet, V);

        sptSet[u] = true;

        for (v = 0; v < V; v++)
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }

    printSolution(dist, V);
}

int main()
{
    int V, i, j;
    printf("Enter the number of vertices in the graph (maximum %d): ", MAX_VERTICES);
    scanf("%d", &V);

    int graph[MAX_VERTICES][MAX_VERTICES];

    printf("Enter the adjacency matrix representing the graph:\n");
    for (i = 0; i < V; i++)
    {
        for (j = 0; j < V; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }

    int src;
    printf("Enter the source vertex: ");
    scanf("%d", &src);

    dijkstra(graph, V, src);

    return 0;
}
