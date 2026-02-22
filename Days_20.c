#include <stdio.h>
#include <stdlib.h>
int cmp(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}
int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    qsort(nums, numsSize, sizeof(int), cmp);
    int capacity = 1000;
    int** result = (int**)malloc(sizeof(int*) * capacity);
    *returnColumnSizes = (int*)malloc(sizeof(int) * capacity);
    int count = 0;
    for (int i = 0; i < numsSize - 2; i++) {
        if (i > 0 && nums[i] == nums[i - 1]) continue;
        int left = i + 1;
        int right = numsSize - 1;
        while (left < right) {
            int sum = nums[i] + nums[left] + nums[right];
            if (sum == 0) {
                if (count >= capacity) {
                    capacity *= 2;
                    result = (int**)realloc(result, sizeof(int*) * capacity);
                    *returnColumnSizes = (int*)realloc(*returnColumnSizes, sizeof(int) * capacity);
                }
                result[count] = (int*)malloc(sizeof(int) * 3);
                result[count][0] = nums[i];
                result[count][1] = nums[left];
                result[count][2] = nums[right];
                (*returnColumnSizes)[count] = 3;
                count++;
                while (left < right && nums[left] == nums[left + 1]) left++;
                while (left < right && nums[right] == nums[right - 1]) right--;

                left++;
                right--;
            }
            else if (sum < 0) {
                left++;
            }
            else {
                right--;
            }
        }
    }
    *returnSize = count;
    return result;
}
int main() {
    int nums[] = {5, -3, 5};
    int size = sizeof(nums) / sizeof(nums[0]);
    int result = maxSubarraySumCircular(nums, size);
    printf("%d", result);
    return 0;
}