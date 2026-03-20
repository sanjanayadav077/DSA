#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct {
    int *arr;
    int front;
    int rear;
    int size;
    int capacity;
} MyCircularDeque;
MyCircularDeque* createDeque(int k) {
    MyCircularDeque* obj = (MyCircularDeque*)malloc(sizeof(MyCircularDeque));
    obj->capacity = k;
    obj->arr = (int*)malloc(k * sizeof(int));
    obj->front = -1;
    obj->rear = -1;
    obj->size = 0;
    return obj;
}
bool isEmpty(MyCircularDeque* obj) {
    return obj->size == 0;
}
bool isFull(MyCircularDeque* obj) {
    return obj->size == obj->capacity;
}
bool insertFront(MyCircularDeque* obj, int value) {
    if (isFull(obj)) return false;
    if (isEmpty(obj)) {
        obj->front = obj->rear = 0;
    } else {
        obj->front = (obj->front - 1 + obj->capacity) % obj->capacity;
    }
    obj->arr[obj->front] = value;
    obj->size++;
    return true;
}
bool insertLast(MyCircularDeque* obj, int value) {
    if (isFull(obj)) return false;

    if (isEmpty(obj)) {
        obj->front = obj->rear = 0;
    } else {
        obj->rear = (obj->rear + 1) % obj->capacity;
    }
    obj->arr[obj->rear] = value;
    obj->size++;
    return true;
}
bool deleteFront(MyCircularDeque* obj) {
    if (isEmpty(obj)) return false;
    if (obj->front == obj->rear) {
        obj->front = obj->rear = -1;
    } else {
        obj->front = (obj->front + 1) % obj->capacity;
    }
    obj->size--;
    return true;
}
bool deleteLast(MyCircularDeque* obj) {
    if (isEmpty(obj)) return false;

    if (obj->front == obj->rear) {
        obj->front = obj->rear = -1;
    } else {
        obj->rear = (obj->rear - 1 + obj->capacity) % obj->capacity;
    }
    obj->size--;
    return true;
}
int getFront(MyCircularDeque* obj) {
    if (isEmpty(obj)) return -1;
    return obj->arr[obj->front];
}
int getRear(MyCircularDeque* obj) {
    if (isEmpty(obj)) return -1;
    return obj->arr[obj->rear];
}
int main() {
    MyCircularDeque* dq = createDeque(3);
    printf("%d\n", insertLast(dq, 1));   // 1
    printf("%d\n", insertLast(dq, 2));   // 1
    printf("%d\n", insertFront(dq, 3));  // 1
    printf("%d\n", insertFront(dq, 4));  // 0
    printf("%d\n", getRear(dq));         // 2
    printf("%d\n", isFull(dq));          // 1
    printf("%d\n", deleteLast(dq));      // 1
    printf("%d\n", insertFront(dq, 4));  // 1
    printf("%d\n", getFront(dq));        // 4
    return 0;
}