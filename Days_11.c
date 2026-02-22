#include <stdio.h>
#include <stdlib.h>
int** transpose(int** matrix, int matrixSize, int* matrixColSize, int* returnSize, int** returnColumnSizes) {
    int rows = matrixSize;
    int cols = matrixColSize[0];
    int** result = (int**)malloc(sizeof(int*) * cols);
    *returnColumnSizes = (int*)malloc(sizeof(int) * cols);
    for (int i = 0; i < cols; i++) {
        result[i] = (int*)malloc(sizeof(int) * rows);
        (*returnColumnSizes)[i] = rows;
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[j][i] = matrix[i][j];
        }
    }
    *returnSize = cols;
    return result;
}
int main() {
    int r = 2, c = 3;
    int** matrix = (int**)malloc(sizeof(int*) * r);
    for (int i = 0; i < r; i++)
        matrix[i] = (int*)malloc(sizeof(int) * c);
    matrix[0][0] = 1; matrix[0][1] = 2; matrix[0][2] = 3;
    matrix[1][0] = 4; matrix[1][1] = 5; matrix[1][2] = 6;
    int* colSize = (int*)malloc(sizeof(int) * r);
    for (int i = 0; i < r; i++) colSize[i] = c;
    int returnSize;
    int* returnColSizes;
    int** t = transpose(matrix, r, colSize, &returnSize, &returnColSizes);
    for (int i = 0; i < returnSize; i++) {
        for (int j = 0; j < returnColSizes[i]; j++) {
            printf("%d ", t[i][j]);
        }
        printf("\n");
    }
    return 0;
}