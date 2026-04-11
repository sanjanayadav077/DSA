#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}
struct Node* findLCA(struct Node* root, int p, int q) {
    if (root == NULL)
        return NULL;
    if (root->data == p || root->data == q)
        return root;
    struct Node* leftLCA = findLCA(root->left, p, q);
    struct Node* rightLCA = findLCA(root->right, p, q);
    if (leftLCA != NULL && rightLCA != NULL)
        return root;
    return (leftLCA != NULL) ? leftLCA : rightLCA;
}
int main() {
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    int p = 4, q = 5;
    struct Node* lca = findLCA(root, p, q);
    if (lca != NULL)
        printf("LCA of %d and %d is %d\n", p, q, lca->data);
    else
        printf("LCA not found\n");

    return 0;
}
