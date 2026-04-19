#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 2000
int graph[MAX][MAX];
int graphSize[MAX];
bool dfs(int node, bool visited[], bool recStack[]) {
    visited[node] = true;
    recStack[node] = true;
    for (int i = 0; i < graphSize[node]; i++) {
        int neighbor = graph[node][i];
        if (!visited[neighbor]) {
            if (dfs(neighbor, visited, recStack))
                return true;
        } else if (recStack[neighbor]) {
            return true; // cycle found
        }
    }
    recStack[node] = false;
    return false;
}
bool canFinish(int numCourses, int prerequisites[][2], int prereqSize) {
    bool visited[MAX] = {false};
    bool recStack[MAX] = {false};
    for (int i = 0; i < numCourses; i++)
        graphSize[i] = 0;
    for (int i = 0; i < prereqSize; i++) {
        int a = prerequisites[i][0];
        int b = prerequisites[i][1];
        graph[b][graphSize[b]++] = a;
    }
    for (int i = 0; i < numCourses; i++) {
        if (!visited[i]) {
            if (dfs(i, visited, recStack))
                return false;
        }
    }
    return true;
}
int main() {
    int prerequisites1[][2] = {{1,0}};
    printf("%d\n", canFinish(2, prerequisites1, 1)); // 1 (true)

    int prerequisites2[][2] = {{1,0},{0,1}};
    printf("%d\n", canFinish(2, prerequisites2, 2)); // 0 (false)

    return 0;
}