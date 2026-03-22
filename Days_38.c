#include <stdio.h>
#define MAX 100000
int deque[MAX];
int front = 0, rear = -1;
void push_back(int i) {
    deque[++rear] = i;
}
void pop_back() {
    rear--;
}
void pop_front() {
    front++;
}
int front_element() {
    return deque[front];
}
int empty() {
    return front > rear;
}
int main() {
    int nums[] = {1,3,-1,-3,5,3,6,7};
    int n = 8;
    int k = 3;
    int result[MAX];
    int idx = 0;
    front = 0;
    rear = -1;
    for (int i = 0; i < n; i++) { 
        if (!empty() && front_element() <= i - k) {
            pop_front();
        }
        while (!empty() && nums[deque[rear]] < nums[i]) {
            pop_back();
        }
        push_back(i);
        if (i >= k - 1) {
            result[idx++] = nums[front_element()];
        }
    }
    for (int i = 0; i < idx; i++) {
        printf("%d ", result[i]);
    }
    return 0;
}