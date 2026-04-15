#include <stdio.h>
#define MAX 200
int visited[MAX];
void dfs(int isConnected[MAX][MAX], int n, int city) {
    visited[city] = 1;
    for (int i = 0; i < n; i++) {
        if (isConnected[city][i] == 1 && !visited[i]) {
            dfs(isConnected, n, i);
        }
    }
}
int findCircleNum(int isConnected[MAX][MAX], int n) {
    int provinces = 0;
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(isConnected, n, i);
            provinces++;
        }
    }
    return provinces;
}
int main() {
    int n;
    printf("Enter number of cities: ");
    scanf("%d", &n);
    int isConnected[MAX][MAX];
    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &isConnected[i][j]);
        }
    }
    int result = findCircleNum(isConnected, n);
    printf("Number of Provinces: %d\n", result);
    return 0;
}