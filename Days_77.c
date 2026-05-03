#include <stdio.h>
#include <stdlib.h>
#define MAX 1000
int graph[MAX][MAX];
int size[MAX];
int disc[MAX], low[MAX];
int visited[MAX];
int timeCounter = 0;
int result[MAX][2];
int resultSize = 0;
void dfs(int u, int parent, int n) {
    visited[u] = 1;
    disc[u] = low[u] = ++timeCounter;
    for (int i = 0; i < size[u]; i++) {
        int v = graph[u][i];
        if (v == parent) continue;
        if (!visited[v]) {
            dfs(v, u, n);
            if (low[v] < low[u])
                low[u] = low[v];
            if (low[v] > disc[u]) {
                result[resultSize][0] = u;
                result[resultSize][1] = v;
                resultSize++;
            }
        }
        else {
            if (disc[v] < low[u])
                low[u] = disc[v];
        }
    }
}
int main() {
    int n, m;
    printf("Enter number of servers (nodes): ");
    scanf("%d", &n);
    printf("Enter number of connections: ");
    scanf("%d", &m);
    for (int i = 0; i < n; i++) {
        size[i] = 0;
        visited[i] = 0;
    }
    printf("Enter connections (u v):\n");
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);

        graph[u][size[u]++] = v;
        graph[v][size[v]++] = u;
    }
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i, -1, n);
        }
    }
    printf("\nCritical Connections:\n");
    for (int i = 0; i < resultSize; i++) {
        printf("%d - %d\n", result[i][0], result[i][1]);
    }
    return 0;
}