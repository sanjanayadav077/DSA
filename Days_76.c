#include <stdio.h>
#include <stdlib.h>

#define MAX 101

struct Node {
    int val;
    int numNeighbors;
    struct Node** neighbors;
};

/* Helper DFS function */
struct Node* dfs(struct Node* node, struct Node* map[]) {
    if (map[node->val] != NULL) {
        return map[node->val];
    }

    // Create clone node
    struct Node* clone = (struct Node*)malloc(sizeof(struct Node));
    clone->val = node->val;
    clone->numNeighbors = node->numNeighbors;
    clone->neighbors = (struct Node**)malloc(sizeof(struct Node*) * node->numNeighbors);

    // Store in map
    map[node->val] = clone;

    // Clone neighbors
    for (int i = 0; i < node->numNeighbors; i++) {
        clone->neighbors[i] = dfs(node->neighbors[i], map);
    }

    return clone;
}

/* Main function */
struct Node* cloneGraph(struct Node* node) {
    if (node == NULL) return NULL;

    struct Node* map[MAX] = {NULL};  // visited + cloned nodes
    return dfs(node, map);
}