#include <stdio.h>
#define MAX 100
typedef struct {
    int x, y;
} Node;
int orangesRotting(int grid[MAX][MAX], int m, int n) {
    Node queue[MAX * MAX];
    int front = 0, rear = 0;
    int fresh = 0, minutes = 0;
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 2) {
                queue[rear++] = (Node){i, j};
            } else if (grid[i][j] == 1) {
                fresh++;
            }
        }
    }
    while (front < rear && fresh > 0) {
        int size = rear - front;
        minutes++;
        for (int i = 0; i < size; i++) {
            Node curr = queue[front++];
            for (int d = 0; d < 4; d++) {
                int nx = curr.x + dx[d];
                int ny = curr.y + dy[d];
                if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == 1) {
                    grid[nx][ny] = 2;
                    fresh--;
                    queue[rear++] = (Node){nx, ny};
                }
            }
        }
    }
    if (fresh > 0)
        return -1;
    return minutes;
}
int main() {
    int m, n;
    int grid[MAX][MAX];
    printf("Enter rows and columns: ");
    scanf("%d %d", &m, &n);
    printf("Enter grid:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &grid[i][j]);
        }
    }
    int result = orangesRotting(grid, m, n);
    printf("Minimum minutes: %d\n", result);
    return 0;
}