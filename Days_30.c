#include <stdio.h>
#include <stdlib.h>
struct ListNode {
    int val;
    struct ListNode* next;
};
struct ListNode* newNode(int val) {
    struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
    node->val = val;
    node->next = NULL;
    return node;
}
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    int s1[100], s2[100];
    int top1 = -1, top2 = -1;
    while (l1) {
        s1[++top1] = l1->val;
        l1 = l1->next;
    }
    while (l2) {
        s2[++top2] = l2->val;
        l2 = l2->next;
    }
    int carry = 0;
    struct ListNode* head = NULL;

    while (top1 >= 0 || top2 >= 0 || carry) {
        int sum = carry;
        if (top1 >= 0)
            sum += s1[top1--];
        if (top2 >= 0)
            sum += s2[top2--];
        carry = sum / 10;
        struct ListNode* node = newNode(sum % 10);
        node->next = head;
        head = node;
    }
    return head;
}
void printList(struct ListNode* head) {
    while (head) {
        printf("%d ", head->val);
        head = head->next;
    }
}
int main() {
    struct ListNode* l1 = newNode(7);
    l1->next = newNode(2);
    l1->next->next = newNode(4);
    l1->next->next->next = newNode(3);
    struct ListNode* l2 = newNode(5);
    l2->next = newNode(6);
    l2->next->next = newNode(4);
    struct ListNode* result = addTwoNumbers(l1, l2);
    printList(result);
}