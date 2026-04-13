#include <stdio.h>
#include <stdlib.h>
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}
int search(int inorder[], int start, int end, int value) {
    for (int i = start; i <= end; i++) {
        if (inorder[i] == value)
            return i;
    }
    return -1;
}
struct TreeNode* buildTree(int preorder[], int inorder[], int start, int end, int* preIndex) {
    if (start > end)
        return NULL;
    struct TreeNode* root = newNode(preorder[*preIndex]);
    (*preIndex)++;
    if (start == end)
        return root;
    int inIndex = search(inorder, start, end, root->val);
    root->left = buildTree(preorder, inorder, start, inIndex - 1, preIndex);
    root->right = buildTree(preorder, inorder, inIndex + 1, end, preIndex);
    return root;
}
void printInorder(struct TreeNode* root) {
    if (root == NULL) return;
    printInorder(root->left);
    printf("%d ", root->val);
    printInorder(root->right);
}
int main() {
    int preorder[] = {1, 2, 4, 5, 3};
    int inorder[]  = {4, 2, 5, 1, 3};
    int n = 5;
    int preIndex = 0;
    struct TreeNode* root = buildTree(preorder, inorder, 0, n - 1, &preIndex);
    printf("Inorder of constructed tree: ");
    printInorder(root);
    return 0;
}