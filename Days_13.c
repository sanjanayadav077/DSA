#include <stdio.h>
#include <stdlib.h>
int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize) {
    if (matrixSize == 0 || matrixColSize[0] == 0) {
        *returnSize = 0;
        return NULL;
    }
    int rows = matrixSize;
    int cols = matrixColSize[0];
    int total = rows * cols;
    int *result = (int*)malloc(sizeof(int) * total);
    int top = 0, bottom = rows - 1;
    int left = 0, right = cols - 1;
    int index = 0;
    while (top <= bottom && left <= right) {
        for (int j = left; j <= right; j++)
            result[index++] = matrix[top][j];
        top++;
        for (int i = top; i <= bottom; i++)
            result[index++] = matrix[i][right];
        right--;
        if (top <= bottom) {
            for (int j = right; j >= left; j--)
                result[index++] = matrix[bottom][j];
            bottom--;
        }
        if (left <= right) {
            for (int i = bottom; i >= top; i--)
                result[index++] = matrix[i][left];
            left++;
        }
    }
    *returnSize = index;
    return result;
}
int main() {
    int r = 3, c = 3;
    int row0[] = {1, 2, 3};
    int row1[] = {4, 5, 6};
    int row2[] = {7, 8, 9};
    int* matrix[] = {row0, row1, row2};
    int colSize[] = {c, c, c};
    int returnSize;
    int* res = spiralOrder(matrix, r, colSize, &returnSize);
    for (int i = 0; i < returnSize; i++) {
        printf("%d ", res[i]);
    }
    free(res);
    return 0;
}