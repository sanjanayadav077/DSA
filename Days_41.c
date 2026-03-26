#include <stdio.h>
int leastInterval(char tasks[], int size, int n) {
    int freq[26] = {0};
    // Count frequency
    for (int i = 0; i < size; i++) {
        freq[tasks[i] - 'A']++;
    }
    // Find max frequency
    int maxFreq = 0;
    for (int i = 0; i < 26; i++) {
        if (freq[i] > maxFreq)
            maxFreq = freq[i];
    }
    // Count how many have max frequency
    int countMax = 0;
    for (int i = 0; i < 26; i++) {
        if (freq[i] == maxFreq)
            countMax++;
    }
    int partCount = maxFreq - 1;
    int partLength = n + 1;
    int emptySlots = partCount * partLength + countMax;

    return (size > emptySlots) ? size : emptySlots;
}
int main() {
    char tasks[] = {'A','A','A','B','B','B'};
    int n = 2;
    int size = sizeof(tasks) / sizeof(tasks[0]);

    printf("Minimum intervals: %d\n", leastInterval(tasks, size, n));
    return 0;
}