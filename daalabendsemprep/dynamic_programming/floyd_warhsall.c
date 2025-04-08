#include <stdio.h>

#define V 4 // Number of vertices in the graph

// Function to compute transitive closure using Warshall's Algorithm
void warshall(int graph[V][V]) {
    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                graph[i][j] = graph[i][j] || (graph[i][k] && graph[k][j]);
            }
        }
    }
}

// Function to print the adjacency matrix
void printGraph(int graph[V][V]) {
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int graph[V][V] = {
        {1, 1, 0, 1},
        {0, 1, 1, 0},
        {0, 0, 1, 1},
        {0, 0, 0, 1}
    };

    printf("Original Graph:\n");
    printGraph(graph);

    warshall(graph);

    printf("\nTransitive Closure:\n");
    printGraph(graph);

    return 0;
}
