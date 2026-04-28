#include <stdio.h>
#define MAX 100
int isConnected[MAX][MAX];
int visited[MAX];
// DFS function
void dfs(int city, int n) {
    visited[city] = 1;
    for (int i = 0; i < n; i++) {
        if (isConnected[city][i] == 1 && !visited[i]) {
            dfs(i, n);
        }
    }
}
// Function to find number of provinces
int findCircleNum(int n) {
    int provinces = 0;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i, n);
            provinces++;
        }
    }
    return provinces;
}
int main() {
    int n;
    printf("Enter number of cities: ");
    scanf("%d", &n);
    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        visited[i] = 0;  // initialize visited
        for (int j = 0; j < n; j++) {
            scanf("%d", &isConnected[i][j]);
        }
    }
    int result = findCircleNum(n);
    printf("Number of provinces: %d\n", result);
    return 0;
}
