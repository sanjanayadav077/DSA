#include <stdio.h>
#include <limits.h>
#define INF INT_MAX
int findCheapestPrice(int n, int flights[][3], int flightsSize, int src, int dst, int k) {
    int dist[n];
    for (int i = 0; i < n; i++) {
        dist[i] = INF;
    }
    dist[src] = 0;
    for (int i = 0; i <= k; i++) {
        int temp[n];
        for (int j = 0; j < n; j++) {
            temp[j] = dist[j];
        }
        for (int j = 0; j < flightsSize; j++) {
            int u = flights[j][0];
            int v = flights[j][1];
            int cost = flights[j][2];

            if (dist[u] != INF && dist[u] + cost < temp[v]) {
                temp[v] = dist[u] + cost;
            }
        }
        for (int j = 0; j < n; j++) {
            dist[j] = temp[j];
        }
    }
    return (dist[dst] == INF) ? -1 : dist[dst];
}
int main() {
    int n = 4;
    int flights[][3] = {
        {0, 1, 100},
        {1, 2, 100},
        {2, 3, 100},
        {0, 2, 500}
    };
    int flightsSize = sizeof(flights) / sizeof(flights[0]);
    int src = 0, dst = 3, k = 1;
    int result = findCheapestPrice(n, flights, flightsSize, src, dst, k);
    printf("Cheapest Price: %d\n", result);
    return 0;
}