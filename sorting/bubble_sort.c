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

/* 

REAL LIFE SCENARIOS FOR BUBBLE SORT
===================================

👉 Lined up in a random order in front of the teacher, who’s put to the task of lining you all up in an ascending order of height. The bubble sort algorithm comes in handy here. In this case every person’s height is an element of the list. With every pass that the teacher goes over the students, they slowly start standing in a more orderly fashion till all of them stand according to height.

👉 One example of a kind of “concurrent bubble sort” might be represented in the behavior of cars on a long two-lane road; for example California Highway 138 across the Mojave desert. Each time one car passes another, the positions are swapped. The decision to pass is local; it is considered only in the context of the relative speeds of the two cars involved. No car is ever picked up and transported to the front of the pack. Eventually, the cars tend to be sorted by speed, using local swaps of car positions.

*/