#include <stdio.h>
#include <stdlib.h>
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
struct TreeNode* searchBST(struct TreeNode* root, int val) {
    // Base case: root is NULL or value found
    if (root == NULL || root->val == val) {
        return root;
    }
    if (val < root->val) {
        return searchBST(root->left, val);
    }
    return searchBST(root->right, val);
}