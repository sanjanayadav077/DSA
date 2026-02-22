#include <stdio.h>
void setZeroes(int** matrix, int matrixSize, int* matrixColSize) {
    int rows = matrixSize;
    int cols = matrixColSize[0];
    int firstRowZero = 0, firstColZero = 0;
    for (int i = 0; i < rows; i++) {
        if (matrix[i][0] == 0) {
            firstColZero = 1;
            break;
        }
    }
    for (int j = 0; j < cols; j++) {
        if (matrix[0][j] == 0) {
            firstRowZero = 1;
            break;
        }
    }
    for (int i = 1; i < rows; i++) {
        for (int j = 1; j < cols; j++) {
            if (matrix[i][j] == 0) {
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }
    for (int i = 1; i < rows; i++) {
        for (int j = 1; j < cols; j++) {
            if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                matrix[i][j] = 0;
            }
        }
    }
    if (firstRowZero) {
        for (int j = 0; j < cols; j++) {
            matrix[0][j] = 0;
        }
    }
    if (firstColZero) {
        for (int i = 0; i < rows; i++) {
            matrix[i][0] = 0;
        }
    }
}
int main() {
    int r = 3, c = 3;
    int row0[] = {1, 1, 1};
    int row1[] = {1, 0, 1};
    int row2[] = {1, 1, 1};
    int* matrix[] = {row0, row1, row2};
    int colSize[] = {c, c, c};
    setZeroes(matrix, r, colSize);
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    return 0;
}