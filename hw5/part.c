#include <stdio.h>
#include <stdlib.h>

#define SIZE 9 // number of vertices

int adj[SIZE][SIZE]; // adjacency matrix
int visited[SIZE];   // visited array

// Function to add edge in an undirected graph
void add_edge(int u, int v)
{
    adj[u][v] = 1;
    adj[v][u] = 1;
}

// BFS algorithm
void BFS(int start)
{
    // Queue for BFS
    int queue[SIZE], front = -1, rear = -1;

    // Mark start vertex as visited
    visited[start] = 1;

    // Enqueue start vertex
    queue[++rear] = start;

    printf("Visited vertices in BFS order: ");

    while (front != rear)
    {
        // Dequeue a vertex and print it
        int vertex = queue[++front];
        printf("%d ", vertex);

        // Enqueue all non-visited adjacent vertices of dequeued vertex
        for (int i = 0; i < SIZE; i++)
        {
            if (adj[vertex][i] && !visited[i])
            {
                queue[++rear] = i;
                visited[i] = 1; // mark as visited
            }
        }
    }
}

int main()
{
    // Add edges
    add_edge(0, 1);
    add_edge(0, 3);
    add_edge(1, 2);
    add_edge(1, 4);
    add_edge(2, 5);
    add_edge(3, 4);
    add_edge(3, 6);
    add_edge(4, 7);
    add_edge(5, 8);
    add_edge(6, 7);
    add_edge(7, 8);

    // Perform BFS
    BFS(0);

    return 0;
}
