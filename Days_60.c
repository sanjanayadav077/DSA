#include <stdio.h>
#include <stdlib.h>
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};
struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}
int cameras = 0;
int dfs(struct TreeNode* root) {
    if (root == NULL)
        return 2; // null nodes are covered
    int left = dfs(root->left);
    int right = dfs(root->right);
    if (left == 0 || right == 0) {
        cameras++;
        return 1; // place camera here
    }
    if (left == 1 || right == 1) {
        return 2; // covered
    }
    return 0;
}
int minCameraCover(struct TreeNode* root) {
    if (dfs(root) == 0)
        cameras++; // root not covered
    return cameras;
}
int main() {
    struct TreeNode* root = newNode(0);
    root->left = newNode(0);
    root->left->left = newNode(0);
    root->left->right = newNode(0);

    printf("Minimum Cameras: %d", minCameraCover(root));
    return 0;
}