#include <stdio.h>
#define MAX 1001
int parent[MAX];
// Find with path compression
int find(int x) {
    if (parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
}
// Union function
int unionSet(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);
    if (rootX == rootY)
        return 0; // cycle detected
    parent[rootY] = rootX;
    return 1;
}
int* findRedundantConnection(int edges[][2], int n) {
    static int result[2];
    // Initialize parent
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }
    for (int i = 0; i < n; i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        if (!unionSet(u, v)) {
            result[0] = u;
            result[1] = v;
        }
    }
    return result;
}
int main() {
    int edges[3][2] = {{1,2}, {1,3}, {2,3}};
    int n = 3;

    int* ans = findRedundantConnection(edges, n);

    printf("Redundant edge: [%d, %d]\n", ans[0], ans[1]);

    return 0;
}