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
void rightView(struct node* root) {
    if (root == NULL) return;
    struct node* queue[100];
    int front = 0, rear = 0;
    queue[rear++] = root;
    while (front < rear) {
        int size = rear - front;

        for (int i = 0; i < size; i++) {
            struct node* temp = queue[front++];
            if (i == size - 1) {
                printf("%d ", temp->data);
            }
            if (temp->left)
                queue[rear++] = temp->left;
            if (temp->right)
                queue[rear++] = temp->right;
        }
    }
}
int main() {
    struct node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->right = newNode(5);
    root->right->right = newNode(4);
    rightView(root);  
    return 0;
}