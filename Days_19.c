#include <stdio.h>
int max(int a, int b) {
    return (a > b) ? a : b;
}
int min(int a, int b) {
    return (a < b) ? a : b;
}
int maxSubarraySumCircular(int* nums, int numsSize) {
    int total = nums[0];
    int currMax = nums[0], maxSum = nums[0];
    int currMin = nums[0], minSum = nums[0];
    for (int i = 1; i < numsSize; i++) {
        currMax = max(nums[i], currMax + nums[i]);
        maxSum = max(maxSum, currMax);
        currMin = min(nums[i], currMin + nums[i]);
        minSum = min(minSum, currMin);
        total += nums[i];
    }
    if (maxSum < 0)
        return maxSum;
    return max(maxSum, total - minSum);
}
int main() {
    int nums[] = {5, -3, 5};
    int size = sizeof(nums) / sizeof(nums[0]);
    int result = maxSubarraySumCircular(nums, size);
    printf("%d", result);
    return 0;
}