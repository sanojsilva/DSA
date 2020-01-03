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

void reverseString(char str[]) {
    int i, len = strlen(str);
    for (i = 0; i < len; i++) {
        push(str[i]);
    }

    while(!isEmpty()) {
        printf("%c", pop());
    }
}


int main() {
    char str[100];
    printf("Enter a string > ");
    scanf("%100[^\n]s", str);
    reverseString(str);
    return 0;
}
