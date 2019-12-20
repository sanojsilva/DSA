#include <stdio.h>
#define N 8

int arr[N] = {3, 5, 1, 20, 12, 6, 8, 7};

void swap (int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

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

int partition(int low, int high) {
    int pivot = arr[low];
    int i = low, j = high;

    while (i < j) {
        while(arr[i] <= pivot && i < high) {
            i++;
        }
        while(arr[j] > pivot) {
            j--;
        }

        if (i < j) {
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[low], &arr[j]);
    return j;

}

void quickSort(int low, int high) {
    // check if the array has at least 2 elements
    if (low < high) {
        int j = partition(low, high);
        quickSort(low, j - 1);
        quickSort(j + 1, high);
    }
}

int main() {
    quickSort(0, N - 1);
    printArray();
    return 0;
}