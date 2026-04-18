#include <stdio.h>
#include <stdbool.h>
#define MAX 100
int adj[MAX][MAX];   
bool visited[MAX];
bool dfs(int node, int parent, int V) {
    visited[node] = true;
    for (int i = 0; i < V; i++) {
        if (adj[node][i]) { // if edge exists
            if (!visited[i]) {
                if (dfs(i, node, V))
                    return true;
            }
            else if (i != parent) {
                return true; // cycle detected
            }
        }
    }
    return false;
}
bool hasCycle(int V) {
    for (int i = 0; i < V; i++) {
        visited[i] = false;
    }
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (dfs(i, -1, V))
                return true;
        }
    }
    return false;
}
int main() {
    int V, E;
    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &V, &E);
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            adj[i][j] = 0;
    printf("Enter edges (u v):\n");
    for (int i = 0; i < E; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        adj[v][u] = 1; // undirected graph
    }
    if (hasCycle(V))
        printf("Cycle Detected\n");
    else
        printf("No Cycle\n");
    return 0;
}