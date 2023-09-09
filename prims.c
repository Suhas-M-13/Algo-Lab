#include <stdio.h>
#include <stdbool.h>

#define MAX_VERTICES 10
#define INF 9999

int graph[MAX_VERTICES][MAX_VERTICES];

void primMST(int vertices) {
    int parent[MAX_VERTICES]; // To store the parent of each vertex in the MST
    int key[MAX_VERTICES]; // To store the key (weight) of each vertex
    bool mstSet[MAX_VERTICES] = { false }; // To track if the vertex is included in the MST

    // Initialize keys and parent arrays
    for (int i = 0; i < vertices; i++) {
        key[i] = INF;
        parent[i] = -1;
    }

    // The first vertex is always picked as the starting vertex
    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < vertices - 1; count++) {
        int minKey = INF;
        int u;

        // Pick the vertex with the minimum key value from the set of vertices not yet included in MST
        for (int v = 0; v < vertices; v++) {
            if (mstSet[v] == false && key[v] < minKey) {
                minKey = key[v];
                u = v;
            }
        }

        mstSet[u] = true; // Include the picked vertex in the MST

        // Update the key value and parent index of the adjacent vertices of the picked vertex.
        for (int v = 0; v < vertices; v++) {
            if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    // Print the MST edges
    printf("Edge \tWeight\n");
    for (int i = 1; i < vertices; i++) {
        printf("%d - %d \t%d \n", parent[i], i, graph[i][parent[i]]);
    }
}

int main() {
    int vertices;

    printf("Enter the number of vertices (max 10): ");
    scanf("%d", &vertices);

    printf("Enter the adjacency matrix (Enter '9999' for no edge):\n");
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    primMST(vertices);

    return 0;
}