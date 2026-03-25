#include <stdio.h>
void dailyTemperatures(int temp[], int n, int ans[]) {
    int stack[n];   // stack to store indices
    int top = -1;
    for (int i = 0; i < n; i++) {
        while (top != -1 && temp[i] > temp[stack[top]]) {
            int prev = stack[top--];
            ans[prev] = i - prev;
        }
        stack[++top] = i;
    }
}
int main() {
    int temp[] = {73,74,75,71,69,72,76,73};
    int n = sizeof(temp)/sizeof(temp[0]);
    int ans[n];
    // initialize answer array with 0
    for (int i = 0; i < n; i++) {
        ans[i] = 0;
    }
    dailyTemperatures(temp, n, ans);
    for (int i = 0; i < n; i++) {
        printf("%d ", ans[i]);
    }
    return 0;
}