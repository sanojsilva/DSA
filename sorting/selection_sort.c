// Selection sort sorts an array by repeatedly finding the minimum element.

#include <stdio.h>

// defining the maximum storing capacity of the array
#define MAX 20


int main() {
    // unsorted array
    int arr[MAX] = {5, 2, 6, 4, 2};

    // i => outer loop index
    // j => inner loop index
    // length => no of elements in the array
    int i, j, length;

    // min => to find and hold the minimum element of the array
    // minIndex => to hold the index of the minimum element of the array
    int min = 0, minIndex = 0;
    length = 5;

    // outer loop runs from index 0 to length - 1
    for (i = 0; i < length - 1; i++) {

        // initialize min value with the first element of the array
        min = arr[i];

        // initialize the minIndex with the index of the first iteration
        minIndex = i;

        // FOR_DEBUGGING => printf("outer loop before: %d\nmin = %d\nminIndex = %d\n", i, min, minIndex);

        // inner loop runs from j = (outer loop index) + 1 to legth
        for (j = i + 1; j < length; j++) {

            // check whether the inner loop current element is less than the min element
            if (arr[j] < min) {

                // assign min value as the current element of the inner loop
                min = arr[j];

                // assign the minIndex value as the current index of the inner loop
                minIndex = j;
            }
        }

        // FOR_DEBUGGING => printf("outer loop after: %d\nmin = %d\nminIndex = %d\n", i, min, minIndex);

        // check whether the min index not equals to the current index of the outer loop
        if (minIndex != i) {

            // swap the element corrasponds to minimum index with the element corrasponds to index of the outer loop
            arr[minIndex] = arr[i];
            arr[i] = min;

            // FOR_DEBUGGING =>  printf("swapping\n");
        }
        // FOR_DEBUGGING printf("========\n");
    }

    // print out the sorted array
    for (i = 0; i < 5; i++) {
        printf("%d\n", arr[i]);
    }
    
    return 0;
}


/*
REAL LIFE EXAMPLES FOR SELECTION SORT
=====================================

👉 Consider you have 8 shoes pairs with sizes 6 to 13. You find them not in order. Their arrangement from smallest to largest will be an example of selection sort


👉 Now consider another example if you have 200 glasses of different volume 100 ml, 110 ml, 120 ml, 130 ml, …. , 2080 ml and 2090 ml. You find them spread on a room floor and want to place them such that the 2090 glass, then 2080 glass inside it, then 2070 glass inside it and so on. This sort method is inefficient on large lists because searching for the exact size will take a lot of time but this is the way selection sort works.

*/