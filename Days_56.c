#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node *left, *right;
};
struct node* newNode(int data) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}
int isMirror(struct node* left, struct node* right) {
    if (left == NULL && right == NULL)
        return 1;
    if (left == NULL || right == NULL)
        return 0;
    return (left->data == right->data) &&
           isMirror(left->left, right->right) &&
           isMirror(left->right, right->left);
}
int isSymmetric(struct node* root) {
    if (root == NULL)
        return 1;
    return isMirror(root->left, root->right);
}
int main() {
    struct node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(2);
    root->left->left = newNode(3);
    root->left->right = newNode(4);
    root->right->left = newNode(4);
    root->right->right = newNode(3);
    if (isSymmetric(root))
        printf("Symmetric");
    else
        printf("Not Symmetric");
    return 0;
}