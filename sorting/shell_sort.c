//🔥 An improved insertion sorting algorithm
//🔥 compares distinct elements in the array rather than the adjacent elements
//🔥 gap is calculated by array length / 2 and getting the floor value 

#include <stdio.h>

void printArray(int arr[]);

int main() {
    int arr[9] = { 2, 7, 9, 5, 23, 29, 15, 19, 31 };
    int i, j, length, gap, temp;
    length = 9;

    for (gap = length / 2; gap >= 1; gap = gap / 2) {
        for (j = gap; j < length; j++) {
            for (i = j - gap; i >= 0; i = i - gap) {
                if (arr[i + gap] > arr[i]) {
                    break;
                } else {
                    temp = arr[i + gap];
                    arr[i + gap] = arr[i];
                    arr[i] = temp;
                }
            }
        }
    }

    printArray(arr);
    

    return 0;
}


void printArray(int arr[]) {
    // print out the sorted array
    for (int i = 0; i < 9; i++) {
        if (i == 8) {
            printf("%d\n", arr[i]);
        } else {
            printf("%d, ", arr[i]);
        }
    }
}