#include <stdio.h>
#include <string.h>
#define STACK_SIZE 10

char stack[STACK_SIZE];
int top = -1;

int isEmpty() {
    return top == -1;
}

int isFull() {
    return top == STACK_SIZE - 1;
}

char peek() {
    return stack[top];
}

int pop() {
    if (!isEmpty()) {
        return stack[top--];
    } else {
        printf("Stack is Full\n");
        return '\0';
    }
}

void push(int ele) {
    if (!isFull()) {
        stack[++top] = ele;
    } else {
        printf("Stack is Full\n");
    }
}

void traverse() {
    int i;
    for (i = 0; i <= top; i++) {
        printf("%d ", stack[i]);
    }
}

float evaluatePostfix(char str[]) {
    int i, len = strlen(str);
    char curValue;
    for (i = 0; i < len; i++) {
        curValue = str[i];
        if (curValue >= '0' && curValue <= '9') {
            push(curValue - 48);
        } else {
            float num2 = pop();
            float num1 = pop();
            if (curValue == '+') {
                push(num1 + num2);
            } else if (curValue == '-') {
                push(num1 - num2);
            } else if (curValue == '*') {
                push(num1 * num2);
            } else if (curValue == '/') {
                push(num1 / num2);
            }
        }
    }
    return pop();
}


int main() {
    char str[100];
    printf("Enter a string > ");
    scanf("%100[^\n]s", str);
    printf("Evaluation = %.2f\n", evaluatePostfix(str));

    return 0;
}
