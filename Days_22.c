#include <stdio.h>
#include <stdlib.h>
struct ListNode {
    int val;
    struct ListNode* next;
};
struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode *prev = NULL, *curr = head, *next = NULL;
    while (curr != NULL) {
        next = curr->next;   // store next
        curr->next = prev;   // reverse link
        prev = curr;         // move prev forward
        curr = next;         
    }
    return prev;
}
int main() {
    struct ListNode* head = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->val = 1;
    struct ListNode* n2 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* n3 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* n4 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* n5 = (struct ListNode*)malloc(sizeof(struct ListNode));
    n2->val = 2; n3->val = 3; n4->val = 4; n5->val = 5;
    head->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = NULL;
    struct ListNode* newHead = reverseList(head);
    while (newHead != NULL) {
        printf("%d ", newHead->val);
        newHead = newHead->next;
    }
    return 0;
}