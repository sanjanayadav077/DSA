#include <stdio.h>
#include <stdlib.h>
#define MAX 100
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};
void inorderTraversal(struct TreeNode* root) {
    struct TreeNode* stack[MAX];
    int top = -1;
    struct TreeNode* curr = root;
    while (curr != NULL || top != -1) {
        while (curr != NULL) {
            stack[++top] = curr;
            curr = curr->left;
        }
        curr = stack[top--];
        printf("%d ", curr->val);
        curr = curr->right;
    }
}