#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};
struct Node* newNode(int value) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = value;
    node->left = node->right = NULL;
    return node;
}
int sumOfLeftLeaves(struct Node* root) {
    if (root == NULL)
        return 0;
    int sum = 0;
    if (root->left != NULL) {
        // If left child is leaf
        if (root->left->left == NULL && root->left->right == NULL) {
            sum += root->left->data;
        } else {
            sum += sumOfLeftLeaves(root->left);
        }
    }
    sum += sumOfLeftLeaves(root->right);
    return sum;
}
int main() {
    struct Node* root = newNode(3);
    root->left = newNode(9);
    root->right = newNode(20);
    root->right->left = newNode(15);
    root->right->right = newNode(7);
    printf("Sum of left leaves = %d", sumOfLeftLeaves(root));
    return 0;
}