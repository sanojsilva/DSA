#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "char_stack.h"

int isBalanced(char *str) {
    struct Stack* stack = newStack(strlen(str));
    int i;

    for (i = 0; i < strlen(str); i++) {
        if(str[i] == '(' || str[i] == '{' || str[i] == '[') {
            push(stack, str[i]);
        }

        if(str[i] == ')' || str[i] == '}' || str[i] == ']') {
            if (isEmpty(stack)) {
                return 0;
            }

            char top = pop(stack);

            if ((top == '(' && str[i] != ')') || (top == '{' && str[i] != '}') || (top == '[' && str[i] != ']'))  {
                return 0;
            }

        }
    }

    return isEmpty(stack);

}

int main() {
    char* str = (char* )malloc(100);
    printf("Enter the expression string: \n");
    scanf("%s", str);
    printf("str = %s\n", str);
    printf("%s is %s\n", str, isBalanced(str) ? "Balanced" : "Not Balanced");


    return 0;
}
