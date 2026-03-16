#include<stdio.h>
#include <stdlib.h>
#define MAX 1000
typedef struct {
    int stack[MAX];
    int minStack[MAX];
    int top;
    int minTop;
} MinStack;
void init(MinStack *s) {
    s->top = -1;
    s->minTop = -1;
}
void push(MinStack *s, int val) {
    s->stack[++s->top] = val;
    if (s->minTop == -1 || val <= s->minStack[s->minTop]) {
        s->minStack[++s->minTop] = val;
    }
}
void pop(MinStack *s) {
    if (s->top == -1) {
        printf("Stack Underflow\n");
        return;
    }
    int removed = s->stack[s->top--];

    if (removed == s->minStack[s->minTop]) {
        s->minTop--;
    }
}
int top(MinStack *s) {
    if (s->top == -1) {
        printf("Stack Empty\n");
        return -1;
    }
    return s->stack[s->top];
}
int getMin(MinStack *s) {
    if (s->minTop == -1) {
        printf("Stack Empty\n");
        return -1;
    }
    return s->minStack[s->minTop];
}
int main() {
    MinStack s;
    init(&s);
    push(&s, 5);
    push(&s, 3);
    push(&s, 7);
    push(&s, 2);
    printf("Top: %d\n", top(&s));
    printf("Min: %d\n", getMin(&s));
    pop(&s);
    printf("Min after pop: %d\n", getMin(&s));
    return 0;
}