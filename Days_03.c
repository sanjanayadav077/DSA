#include <stdio.h>
int findMissing(int arr[], int n) {
    int total = n * (n + 1) / 2;
    int sum = 0;
    for (int i = 0; i < n - 1; i++) {
        sum += arr[i];
    }
    return total - sum;
}
int main() {
    int arr[] = {1, 2, 4, 5};  
    int n = 5;

    int missing = findMissing(arr, n);
    printf("Missing number is: %d\n", missing);

    return 0;
}
int findMissingXOR(int arr[], int n) {
    int xor1 = 0, xor2 = 0;

    for (int i = 1; i <= n; i++) {
        xor1 ^= i;
    }

    for (int i = 0; i < n - 1; i++) {
        xor2 ^= arr[i];
    }

    return xor1 ^ xor2;
}


