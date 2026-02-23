#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
// Function to detect cycle
int hasCycle(struct Node* head) {
    struct Node *slow = head, *fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;          // move 1 step
        fast = fast->next->next;    // move 2 steps

        if (slow == fast) {
            return 1;  // cycle found
        }
    }
    return 0;  // no cycle
}
int main() {
    // Creating linked list: 1 -> 2 -> 3 -> 4 -> 5
    struct Node* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);
    // Creating a cycle: last node points to node with value 2
    head->next->next->next->next->next = head->next;
    if (hasCycle(head)) {
        printf("Cycle detected in the linked list\n");
    } else {
        printf("No cycle in the linked list\n");
    }
    return 0;
}