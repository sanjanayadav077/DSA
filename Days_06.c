#include <stdio.h>
void moveZeroes(int nums[], int size) {
    int j = 0;  

    for (int i = 0; i < size; i++) {
        if (nums[i] != 0) {
            nums[j] = nums[i];
            j++;
        }
    }
    while (j < size) {
        nums[j] = 0;
        j++;
    }
}

int main() {
    int nums[] = {0, 1, 0, 3, 12};
    int size = sizeof(nums) / sizeof(nums[0]);

    moveZeroes(nums, size);

    printf("Updated array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", nums[i]);
    }

    return 0;
}
