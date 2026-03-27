#include <stdio.h>
#include <stdlib.h>
#define MAX 50000
int maxHeap[MAX], maxSize = 0;
int minHeap[MAX], minSize = 0;
void maxHeapifyUp(int i) {
    while (i > 0 && maxHeap[(i - 1) / 2] < maxHeap[i]) {
        int temp = maxHeap[i];
        maxHeap[i] = maxHeap[(i - 1) / 2];
        maxHeap[(i - 1) / 2] = temp;
        i = (i - 1) / 2;
    }
}
void maxHeapifyDown(int i) {
    int largest = i;
    int left = 2 * i + 1, right = 2 * i + 2;
    if (left < maxSize && maxHeap[left] > maxHeap[largest])
        largest = left;
    if (right < maxSize && maxHeap[right] > maxHeap[largest])
        largest = right;
    if (largest != i) {
        int temp = maxHeap[i];
        maxHeap[i] = maxHeap[largest];
        maxHeap[largest] = temp;
        maxHeapifyDown(largest);
    }
}
void insertMax(int val) {
    maxHeap[maxSize++] = val;
    maxHeapifyUp(maxSize - 1);
}
int extractMax() {
    int root = maxHeap[0];
    maxHeap[0] = maxHeap[--maxSize];
    maxHeapifyDown(0);
    return root;
}
void minHeapifyUp(int i) {
    while (i > 0 && minHeap[(i - 1) / 2] > minHeap[i]) {
        int temp = minHeap[i];
        minHeap[i] = minHeap[(i - 1) / 2];
        minHeap[(i - 1) / 2] = temp;
        i = (i - 1) / 2;
    }
}
void minHeapifyDown(int i) {
    int smallest = i;
    int left = 2 * i + 1, right = 2 * i + 2;
    if (left < minSize && minHeap[left] < minHeap[smallest])
        smallest = left;
    if (right < minSize && minHeap[right] < minHeap[smallest])
        smallest = right;
    if (smallest != i) {
        int temp = minHeap[i];
        minHeap[i] = minHeap[smallest];
        minHeap[smallest] = temp;
        minHeapifyDown(smallest);
    }
}
void insertMin(int val) {
    minHeap[minSize++] = val;
    minHeapifyUp(minSize - 1);
}
int extractMin() {
    int root = minHeap[0];
    minHeap[0] = minHeap[--minSize];
    minHeapifyDown(0);
    return root;
}
void addNum(int num) {
    if (maxSize == 0 || num <= maxHeap[0]) {
        insertMax(num);
    } else {
        insertMin(num);
    }
    if (maxSize > minSize + 1) {
        insertMin(extractMax());
    } else if (minSize > maxSize) {
        insertMax(extractMin());
    }
}
double findMedian() {
    if (maxSize > minSize) {
        return maxHeap[0];
    } else {
        return (maxHeap[0] + minHeap[0]) / 2.0;
    }
}
int main() {
    addNum(1);
    addNum(2);
    printf("%.1f\n", findMedian()); // 1.5

    addNum(3);
    printf("%.1f\n", findMedian()); // 2.0

    return 0;
}