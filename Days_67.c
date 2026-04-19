#include <stdio.h>
#include <stdlib.h>
#define MAX 2000
int graph[MAX][MAX];
int graphSize[MAX];
int* findOrder(int numCourses, int prerequisites[][2], int prereqSize, int* returnSize) {
    int indegree[MAX] = {0};
    for (int i = 0; i < numCourses; i++)
        graphSize[i] = 0;
    for (int i = 0; i < prereqSize; i++) {
        int a = prerequisites[i][0];
        int b = prerequisites[i][1];
        graph[b][graphSize[b]++] = a;
        indegree[a]++;
    }
    int queue[MAX];
    int front = 0, rear = 0;
    for (int i = 0; i < numCourses; i++) {
        if (indegree[i] == 0)
            queue[rear++] = i;
    }
    int* result = (int*)malloc(numCourses * sizeof(int));
    int count = 0;
    while (front < rear) {
        int node = queue[front++];
        result[count++] = node;
        for (int i = 0; i < graphSize[node]; i++) {
            int neighbor = graph[node][i];
            indegree[neighbor]--;
            if (indegree[neighbor] == 0)
                queue[rear++] = neighbor;
        }
    }
    if (count != numCourses) {
        *returnSize = 0;
        return (int*)malloc(0);
    }
    *returnSize = count;
    return result;
}
int main() {
    int prerequisites[][2] = {{1,0}};
    int returnSize;
    int* order = findOrder(2, prerequisites, 1, &returnSize);
    for (int i = 0; i < returnSize; i++)
        printf("%d ", order[i]);
    return 0;
}