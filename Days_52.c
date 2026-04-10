#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};
struct Node* newNode(int val) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = val;
    temp->left = temp->right = NULL;
    return temp;
}
struct Node* findLCA(struct Node* root, int p, int q) {
    if (root == NULL)
        return NULL;
    if (root->data == p || root->data == q)
        return root;
    struct Node* left = findLCA(root->left, p, q);
    struct Node* right = findLCA(root->right, p, q);
    if (left != NULL && right != NULL)
        return root;
    return (left != NULL) ? left : right;
}
int main() {
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    int p = 4, q = 5;
    struct Node* lca = findLCA(root, p, q);
    if (lca != NULL)
        printf("LCA: %d", lca->data);

    return 0;
}