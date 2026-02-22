#include <stdio.h>
#include <stdbool.h>
bool isToeplitzMatrix(int** matrix, int matrixSize, int* matrixColSize) {
    int rows = matrixSize;
    int cols = matrixColSize[0];
    for (int i = 1; i < rows; i++) {
        for (int j = 1; j < cols; j++) {
            if (matrix[i][j] != matrix[i - 1][j - 1]) {
                return false;
            }
        }
    }
    return true;
}
int main() {
    int r = 3, c = 4;
    int row0[] = {1, 2, 3, 4};
    int row1[] = {5, 1, 2, 3};
    int row2[] = {6, 5, 1, 2};
    int* matrix[] = {row0, row1, row2};
    int colSize[] = {c, c, c};
    if (isToeplitzMatrix(matrix, r, colSize))
        printf("true");
    else
        printf("false");
    return 0;
}