#include <stdio.h>
#include <stdlib.h>
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};
void preorder(struct TreeNode* root) {
    if (root == NULL) return;
    printf("%d ", root->val);   
    preorder(root->left);       
    preorder(root->right);      
}