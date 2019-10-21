// most simplest sorting algorithm
// bubble sort sorts the array by repeatedly swapping the adjacent elements in the array

#include <stdio.h>
#define MAX 20

int main() {

    int arr[MAX] = {3, 5, 3, 1, 6};

    // i => outer loop index
    // j => inner loop index
    // temp => to act as a temporary variable when swapping elements in the array
    // length => to hold the no of elements in the array
    int i, j, temp, length;

    // intialize the array length as the no of elements in the array
    length = 5;

    // outer loop runs from i = 0 to i less than (length - 1)
    for (i = 0; i < length - 1; i++) {

        // inner loop runs from j = 0 to j less than (length - i - 1)
        for (j = 0; j < length - i - 1; j++) {

            // check whether the current element is greater than the next element in the inner loop
            if (arr[j] > arr[j + 1]) {

                // swaps the current element with the next element
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    // print out the sorted array
    for (i = 0; i < 5; i++) {
        printf("%d\n", arr[i]);
    }

    return 0;
}