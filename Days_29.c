#include <stdio.h>
#include <stdlib.h>
/* Definition for singly-linked list */
struct ListNode {
    int val;
    struct ListNode *next;
};
/* Function to create a new node */
struct ListNode* createNode(int value) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = value;
    newNode->next = NULL;
    return newNode;
}
/* Function to add two numbers */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode dummy;
    struct ListNode* temp = &dummy;
    dummy.next = NULL;
    int carry = 0;
    while (l1 != NULL || l2 != NULL || carry != 0) {
        int sum = carry;

        if (l1 != NULL) {
            sum += l1->val;
            l1 = l1->next;
        }
        if (l2 != NULL) {
            sum += l2->val;
            l2 = l2->next;
        }
        carry = sum / 10;

        temp->next = createNode(sum % 10);
        temp = temp->next;
    }
    return dummy.next;
}
/* Function to print linked list */
void printList(struct ListNode* head) {
    while (head != NULL) {
        printf("%d ", head->val);
        head = head->next;
    }
}
/* Example usage */
int main() {
    // First number: 342 (stored as 2->4->3)
    struct ListNode* l1 = createNode(2);
    l1->next = createNode(4);
    l1->next->next = createNode(3);
    // Second number: 465 (stored as 5->6->4)
    struct ListNode* l2 = createNode(5);
    l2->next = createNode(6);
    l2->next->next = createNode(4);

    struct ListNode* result = addTwoNumbers(l1, l2);
    printf("Result: ");
    printList(result);

    return 0;
}