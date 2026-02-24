#include <stdio.h>
#include <stdlib.h>
// Definition of linked list node
struct Node {
    int data;
    struct Node* next;
};
// Function to create a new node
struct Node* createNode(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}
// Function to remove all nodes with given value
struct Node* removeElements(struct Node* head, int val) {
    // Remove nodes from the beginning if they match val
    while (head != NULL && head->data == val) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
    }
    struct Node* current = head;
    // Traverse the remaining list
    while (current != NULL && current->next != NULL) {
        if (current->next->data == val) {
            struct Node* temp = current->next;
            current->next = current->next->next;
            free(temp);
        } else {
            current = current->next;
        }
    }
    return head;
}
// Function to print list
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}
// Main function to test
int main() {
    // Creating linked list: 1 -> 2 -> 6 -> 3 -> 4 -> 5 -> 6
    struct Node* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(6);
    head->next->next->next = createNode(3);
    head->next->next->next->next = createNode(4);
    head->next->next->next->next->next = createNode(5);
    head->next->next->next->next->next->next = createNode(6);
    printf("Original List:\n");
    printList(head);
    int val = 6;
    head = removeElements(head, val);
    printf("List after removing %d:\n", val);
    printList(head);
    return 0;
}