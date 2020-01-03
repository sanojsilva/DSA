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

char pop() {
    if (!isEmpty()) {
        return stack[top--];
    } else {
        printf("Stack is Full\n");
        return '\0';
    }
}

void push(char ele) {
    if (!isFull()) {
        stack[++top] = ele;
    } else {
        printf("Stack is Full\n");
    }
}

int isBalanced(char str[]) {
    int i, len = strlen(str);
    char curValue, topValue;
    for (i = 0; i < len; i++) {
        curValue = str[i];
        if (curValue == '(' || curValue == '{' || curValue == '[') {
            push(curValue);
        }

        if (curValue == ')' || curValue == '}' || curValue == ']') {
             if (isEmpty()) {
                 return 0;
             }

             topValue = pop();

             if ((curValue == ')' && topValue != '(') || (curValue == '}' && topValue != '{') || (curValue == ']' && topValue != '[')) {
                 return 0;
             }
        }

    }
    return isEmpty();
}


int main() {
    char str[100];
    printf("Enter a string > ");
    scanf("%100[^\n]s", str);
    if (isBalanced(str)) {
        printf("Balanced\n");
    } else {
        printf("Not Balanced\n");
    }
    return 0;
}
