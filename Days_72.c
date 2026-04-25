#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int min(int a, int b) {
    return a < b ? a : b;
}

int minCostConnectPoints(int** points, int pointsSize) {
    int* visited = (int*)calloc(pointsSize, sizeof(int));
    int* minDist = (int*)malloc(pointsSize * sizeof(int));

    // Initialize distances
    for (int i = 0; i < pointsSize; i++) {
        minDist[i] = INT_MAX;
    }

    minDist[0] = 0; // Start from first point
    int result = 0;

    for (int i = 0; i < pointsSize; i++) {
        int u = -1;

        // Find unvisited node with minimum distance
        for (int j = 0; j < pointsSize; j++) {
            if (!visited[j] && (u == -1 || minDist[j] < minDist[u])) {
                u = j;
            }
        }

        visited[u] = 1;
        result += minDist[u];

        // Update distances
        for (int v = 0; v < pointsSize; v++) {
            if (!visited[v]) {
                int cost = abs(points[u][0] - points[v][0]) + 
                           abs(points[u][1] - points[v][1]);

                if (cost < minDist[v]) {
                    minDist[v] = cost;
                }
            }
        }
    }

    free(visited);
    free(minDist);

    return result;
}

// ----------- DRIVER CODE -----------
int main() {
    int n = 5;

    int arr[5][2] = {
        {0, 0},
        {2, 2},
        {3, 10},
        {5, 2},
        {7, 0}
    };

    int** points = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        points[i] = arr[i];
    }

    int result = minCostConnectPoints(points, n);
    printf("Minimum Cost = %d\n", result);

    free(points);
    return 0;
}