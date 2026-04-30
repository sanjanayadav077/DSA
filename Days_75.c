#include <stdio.h>
#include <stdlib.h>
#define MAX 100
int isBipartite(int graph[MAX][MAX], int n) {
    int color[MAX];
    for (int i = 0; i < n; i++) {
        color[i] = -1;
    }
    for (int start = 0; start < n; start++) {
        if (color[start] == -1) {
            int queue[MAX], front = 0, rear = 0;
            queue[rear++] = start;
            color[start] = 0;
            while (front < rear) {
                int u = queue[front++];
                for (int v = 0; v < n; v++) {
                    if (graph[u][v]) { // edge exists
                        // If not colored, assign opposite color
                        if (color[v] == -1) {
                            color[v] = 1 - color[u];
                            queue[rear++] = v;
                        }
                        // If same color, not bipartite
                        else if (color[v] == color[u]) {
                            return 0;
                        }
                    }
                }
            }
        }
    }
    return 1;
}
int main() {
    int n;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    int graph[MAX][MAX];
    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }
    if (isBipartite(graph, n))
        printf("Graph is Bipartite\n");
    else
        printf("Graph is NOT Bipartite\n");

    return 0;
}