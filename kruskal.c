#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100
#define MAX_EDGES 1000

// Edge struct to store edges in the graph
typedef struct
{
    int u, v, weight;
} Edge;

// Disjoint set struct to track connected components
typedef struct
{
    int parent[MAX_VERTICES];
    int rank[MAX_VERTICES];
} DisjointSet;

// Function to initialize a disjoint set with n vertices
void makeSet(DisjointSet *set, int n)
{
    for (int i = 0; i < n; i++)
    {
        set->parent[i] = i;
        set->rank[i] = 0;
    }
}

// Function to find the parent of a vertex in the disjoint set
int find(DisjointSet *set, int vertex)
{
    if (set->parent[vertex] != vertex)
    {
        set->parent[vertex] = find(set, set->parent[vertex]);
    }
    return set->parent[vertex];
}

// Function to join two sets together based on their rank
void unionSet(DisjointSet *set, int u, int v)
{
    int parentU = find(set, u);
    int parentV = find(set, v);
    if (set->rank[parentU] > set->rank[parentV])
    {
        set->parent[parentV] = parentU;
    }
    else if (set->rank[parentU] < set->rank[parentV])
    {
        set->parent[parentU] = parentV;
    }
    else
    {
        set->parent[parentV] = parentU;
        set->rank[parentU]++;
    }
}

// Comparator function for sorting edges by weight
int compare(const void *a, const void *b)
{
    Edge *edgeA = (Edge *)a;
    Edge *edgeB = (Edge *)b;
    return edgeA->weight - edgeB->weight;
}

// Function to perform Kruskal's algorithm on a graph
void kruskal(int n, int m, Edge edges[], Edge result[])
{
    DisjointSet set;
    makeSet(&set, n);
    int resultIndex = 0;
    qsort(edges, m, sizeof(Edge), compare);
    for (int i = 0; i < m && resultIndex < n - 1; i++)
    {
        Edge edge = edges[i];
        if (find(&set, edge.u) != find(&set, edge.v))
        {
            unionSet(&set, edge.u, edge.v);
            result[resultIndex++] = edge;
        }
    }
}

int main()
{
    int n = 7;  // number of vertices
    int m = 11; // number of edges
    Edge edges[MAX_EDGES] = {
                              {0, 1, 7}, {0, 3, 5}, 
                              {1, 2, 8}, {1, 3, 9}, 
                              {1, 4, 7}, {2, 4, 5}, 
                              {3, 4, 15}, {3, 5, 6}, 
                              {4, 5, 8}, {4, 6, 9}, {5, 6, 11}
                              };
    Edge result[MAX_VERTICES];
    kruskal(n, m, edges, result);
    for (int i = 0; i < n - 1; i++)
    {
        printf("(%d, %d) -> %d\n", result[i].u, result[i].v, result[i].weight);
    }
    return 0;
}
