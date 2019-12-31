#include <stdio.h>
#include <string.h>
#include "int_stack.h"

float evaluate(char* str) {
    int i, len = strlen(str);
    struct Stack* stack = newStack(len);
    float num1 = 0, num2 = 0;
    for (i = 0; i < len; i++) {

        if (str[i] >= '0' && str[i] <= '9')
            push(stack, str[i] - 48);
        else {
            num2 = pop(stack);
            num1 = pop(stack);
            switch(str[i]) {
                case '+':
                    push(stack, num1 + num2);
                    break;
                case '-':
                    push(stack, num1 - num2);
                    break;
                case '*':
                    push(stack, num1 * num2);
                    break;
                case '/':
                    push(stack, num1 / num2);
                    break;
            }
        }
    }

    return pop(stack);
}

int main() {
    char expr[100];
    printf("Enter a postfix expression => ");
    scanf("%s", expr);
    printf("Value = %.2f\n", evaluate(expr));
    return 0;
}
