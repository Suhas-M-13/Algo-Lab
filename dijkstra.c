#include <stdio.h>
#include <stdbool.h>

#define MAX_VERTICES 10
#define INF 9999

int graph[MAX_VERTICES][MAX_VERTICES];

void dijkstra(int vertices, int source) {
    int distance[MAX_VERTICES];
    bool visited[MAX_VERTICES] = { false };

    // Initialize distances to infinity and visited array
    for (int i = 0; i < vertices; i++) {
        distance[i] = INF;
        visited[i] = false;
    }

    // Distance from source to itself is 0
    distance[source] = 0;

    for (int count = 0; count < vertices - 1; count++) {
        // Find the vertex with the minimum distance value among unvisited vertices
        int minDistance = INF;
        int u;

        for (int v = 0; v < vertices; v++) {
            if (!visited[v] && distance[v] <= minDistance) {
                minDistance = distance[v];
                u = v;
            }
        }

        visited[u] = true;

        // Update the distance value of the adjacent vertices of the picked vertex.
        for (int v = 0; v < vertices; v++) {
            if (!visited[v] && graph[u][v] && distance[u] != INF &&
                distance[u] + graph[u][v] < distance[v]) {
                distance[v] = distance[u] + graph[u][v];
            }
        }
    }

    // Print the shortest paths from the source vertex
    printf("Vertex \tDistance from Source\n");
    for (int i = 0; i < vertices; i++) {
        printf("%d \t%d\n", i, distance[i]);
    }
}

int main() {
    int vertices, source;

    printf("Enter the number of vertices (max 10): ");
    scanf("%d", &vertices);

    printf("Enter the adjacency matrix (Enter '9999' for no edge):\n");
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Enter the source vertex: ");
    scanf("%d", &source);

    if (source < 0 || source >= vertices) {
        printf("Invalid source vertex.\n");
        return 1;
    }

    dijkstra(vertices, source);

    return 0;
}