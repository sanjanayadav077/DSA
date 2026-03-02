#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
// Definition of node
struct Node {
    int data;
    struct Node* next;
};
// Function to reverse a linked list
struct Node* reverse(struct Node* head) {
    struct Node* prev = NULL;
    struct Node* next = NULL;
    while (head != NULL) {
        next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }
    return prev;
}
// Function to check palindrome
bool isPalindrome(struct Node* head) {
    if (head == NULL || head->next == NULL)
        return true;
    struct Node *slow = head, *fast = head;
    // Step 1: find middle
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    // Step 2: reverse second half
    struct Node* secondHalf = reverse(slow);
    // Step 3: compare both halves
    struct Node* firstHalf = head;
    while (secondHalf != NULL) {
        if (firstHalf->data != secondHalf->data)
            return false;

        firstHalf = firstHalf->next;
        secondHalf = secondHalf->next;
    }
    return true;
}