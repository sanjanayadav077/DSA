#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
struct Node {
    int data;
    struct Node* next;
};
// Function to detect and remove cycle
bool removeCycle(struct Node* head) {
    if (head == NULL || head->next == NULL)
        return false;
    struct Node *slow = head, *fast = head;
    // Step 1: Detect cycle
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
            break;
    }
    // If no cycle
    if (slow != fast)
        return false;
    // Step 2: Find start of cycle
    slow = head;
    struct Node* prev = NULL;
    while (slow != fast) {
        prev = fast;
        slow = slow->next;
        fast = fast->next;
    }
    // Step 3: Remove cycle
    prev->next = NULL;

    return true;
}