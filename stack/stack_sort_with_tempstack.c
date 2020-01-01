#include <stdio.h>
#include "int_stack.h"

int main() {
    int temp;
    struct Stack* stack = newStack(5);
    struct Stack* tempStack = newStack(5);
    push(stack, 3);
    push(stack, 2);
    push(stack, 10);
    push(stack, 23);
    push(stack, 11);
    printf("InputStack\n-----------\n");
    traverse(stack);
    while(!isEmpty(stack)) {
        temp = pop(stack);
        while(!isEmpty(tempStack) && peek(tempStack) > temp) {
                push(stack, pop(tempStack));
        }

        push(tempStack, temp);

    }
    printf("TempStack\n-----------\n");
    traverse(tempStack);
    return 0;
}