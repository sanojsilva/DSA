#include <stdio.h>
#define N 8

int arr[N] = {3, 5, 1, 20, 12, 6, 8, 7};

void printArray() {
    int i;
    for (i = 0; i < N; i++) {
        if (i != N - 1) {
            printf("%d, ", arr[i]);
        } else {
            printf("%d\n", arr[i]);
        }
    }
}

int main() {
    int i;

    for (i = 1; i < N; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }

    printArray();
    return 0;
}