/*
👉 Before Main Loop:
    3, 12, 1, 5, 6
👉 Before Inner Loop:
    3, 12, 1, 5, 6
👉 After Main Loop:
    3, 12, 1, 5, 6

👉 Before Main Loop:
    3, 12, 1, 5, 6
👉 Before Inner Loop:
    3, 12, 1, 5, 6
👉 After Inner Loop:
    3, 1, 12, 5, 6
👉 Before Inner Loop:
    3, 1, 12, 5, 6
👉 After Inner Loop:
    1, 3, 12, 5, 6
👉 After Main Loop:
    1, 3, 12, 5, 6

👉 Before Main Loop:
    1, 3, 12, 5, 6
👉 Before Inner Loop:
    1, 3, 12, 5, 6
👉 After Inner Loop:
    1, 3, 5, 12, 6
👉 Before Inner Loop:
    1, 3, 5, 12, 6
👉 After Main Loop:
    1, 3, 5, 12, 6

👉 Before Main Loop:
    1, 3, 5, 12, 6
👉 Before Inner Loop:
    1, 3, 5, 12, 6
👉 After Inner Loop:
    1, 3, 5, 6, 12
👉 Before Inner Loop:
    1, 3, 5, 6, 12
👉 After Main Loop:
    1, 3, 5, 6, 12
*/

#include <stdio.h>

void printArray(int arr[]) {
    // print out the sorted array
    for (int i = 0; i < 5; i++) {
        if (i == 4) {
            printf("%d\n", arr[i]);
        } else {
            printf("%d, ", arr[i]);
        }
    }
}

int main() {
    int arr[5] = {3, 12, 1, 5, 6};
    int i, j, temp;

    for ( i = 1; i < 5; i++) {
        // printf("Before Main Loop: \n");
        // printArray(arr);

        for (j = i; j > 0; j--) {
            // printf("Before Inner Loop: \n");
            // printArray(arr);
            if (arr[j] < arr[j-1]) {
                temp = arr[j-1];
                arr[j-1] = arr[j];
                arr[j] = temp;
            } else {
                break;
            }
            // printf("After Inner Loop: \n");
            // printArray(arr);
        }
        // printf("After Main Loop: \n");
        // printArray(arr);
        printf("\n");
        // break;
    }
    
        // printArray(arr);
    

    
    return 0;
}