#include <stdio.h>
#define MAX 20


int main() {
    int arr[MAX] = {5, 2, 6, 4, 2};
    int i, j, length;
    int min = 0, minIndex = 0;
    length = 5;

    for (i = 0; i < length - 1; i++) {
        min = arr[i];
        minIndex = i;
        // printf("outer loop before: %d\nmin = %d\nminIndex = %d\n", i, min, minIndex);

        for (j = i+1; j < length; j++) {
            if (arr[j] < min) {
                min = arr[j];
                minIndex = j;
            }
        }

        // printf("outer loop after: %d\nmin = %d\nminIndex = %d\n", i, min, minIndex);
        if (minIndex != i) {
            arr[minIndex] = arr[i];
            arr[i] = min;
            // printf("swapping\n");
        }
        // printf("========\n");
    }

    for (i = 0; i < 5; i++) {
        printf("%d\n", arr[i]);
    }
    
    return 0;
}