#include <stdio.h>
#include <string.h>
#include "char_stack.h"

int isDuplicate(char* str) {
    int i, len = strlen(str);
    struct Stack* stack = newStack(len);
    for (i = 0; i < len; i++) {
        if (str[i] != ')') {
            push(stack, str[i]);
        } else {
            if (peek(stack) == '(') {
                return 1;
            }

            while(peek(stack) != '(') {
                pop(stack);
            }

            pop(stack);
        }
    }

    return 0;
}

int main() {
    char* str = "(exp)";
    if (isDuplicate(str)) 
        printf("Duplicate parantheses\n");
    else
        printf("No Duplicate parantheses\n");
    return 0;
}
