#include <stdio.h>
#include <stdlib.h>
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};
struct TreeNode* createNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}
int findIndex(int inorder[], int start, int end, int value) {
    for (int i = start; i <= end; i++) {
        if (inorder[i] == value)
            return i;
    }
    return -1;
}
struct TreeNode* buildTreeHelper(int inorder[], int postorder[], 
                                int inStart, int inEnd, int* postIndex) {
    if (inStart > inEnd)
        return NULL;
    int rootVal = postorder[*postIndex];
    (*postIndex)--;
    struct TreeNode* root = createNode(rootVal);
    if (inStart == inEnd)
        return root;
    int inIndex = findIndex(inorder, inStart, inEnd, rootVal);
    root->right = buildTreeHelper(inorder, postorder, inIndex + 1, inEnd, postIndex);
    root->left  = buildTreeHelper(inorder, postorder, inStart, inIndex - 1, postIndex);
    return root;
}
struct TreeNode* buildTree(int inorder[], int postorder[], int size) {
    int postIndex = size - 1;
    return buildTreeHelper(inorder, postorder, 0, size - 1, &postIndex);
}
void preorder(struct TreeNode* root) {
    if (root == NULL)
        return;
    printf("%d ", root->val);
    preorder(root->left);
    preorder(root->right);
}
int main() {
    int inorder[] = {9, 3, 15, 20, 7};
    int postorder[] = {9, 15, 7, 20, 3};
    int n = 5;
    struct TreeNode* root = buildTree(inorder, postorder, n);
    printf("Preorder of constructed tree: ");
    preorder(root);
    return 0;
}