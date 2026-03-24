#include <stdio.h>
#include <stdlib.h>
typedef struct {
    int num;
    int freq;
} Pair;
int compare(const void* a, const void* b) {
    return ((Pair*)b)->freq - ((Pair*)a)->freq;
}
int* topKFrequent(int* nums, int numsSize, int k, int* returnSize) {
    Pair freq[numsSize];
    int unique = 0;
    // Count frequency
    for (int i = 0; i < numsSize; i++) {
        int found = 0;
        for (int j = 0; j < unique; j++) {
            if (freq[j].num == nums[i]) {
                freq[j].freq++;
                found = 1;
                break;
            }
        }
        if (!found) {
            freq[unique].num = nums[i];
            freq[unique].freq = 1;
            unique++;
        }
    }
    // Sort by frequency descending
    qsort(freq, unique, sizeof(Pair), compare);
    // Take top k
    int* result = (int*)malloc(k * sizeof(int));
    for (int i = 0; i < k; i++) {
        result[i] = freq[i].num;
    }
    *returnSize = k;
    return result;
}