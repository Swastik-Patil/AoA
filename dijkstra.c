#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define V 9

int minDistance(int dist[], bool setShort[])
{
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++)
    {
        if (setShort[v] == false && dist[v] <= min)
        {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

void display(int dist[])
{
    printf("Vertext \t\t Distance from source\n");
    for (int i = 0; i < V; i++)
    {
        printf("%d \t\t\t\t %d\n", i, dist[i]);
    }
}

void dijkstra(int graph[V][V], int source)
{
    int dist[V];
    bool setShort[V];

    for (int i = 0; i < V; i++)
    {
        dist[i] = INT_MAX;
        setShort[i] = false;
    }

    dist[source] = 0;

    for (int j = 0; j < V - 1; j++)
    {
        int u = minDistance(dist, setShort);
        setShort[u] = true;

        for (int v = 0; v < V; v++)
        {
            if (!setShort[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
            {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }
    display(dist);
}

int main()
{
    int graph[V][V] = {{0, 4, 0, 0, 0, 0, 0, 8, 0},
                       {4, 0, 8, 0, 0, 0, 0, 11, 0},
                       {0, 8, 0, 7, 0, 4, 0, 0, 2},
                       {0, 0, 7, 0, 9, 14, 0, 0, 0},
                       {0, 0, 0, 9, 0, 10, 0, 0, 0},
                       {0, 0, 4, 14, 10, 0, 2, 0, 0},
                       {0, 0, 0, 0, 0, 2, 0, 1, 6},
                       {8, 11, 0, 0, 0, 0, 1, 0, 7},
                       {0, 0, 2, 0, 0, 0, 6, 7, 0}};

    dijkstra(graph, 0);

    return 0;
}