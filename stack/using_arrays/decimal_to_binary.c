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

int peek() {
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

void decToBin(int num) {

    while(!isFull() && num != 0) {
        push(num % 2);
        num = num / 2;
    }

    while(!isEmpty()) {
        printf("%d", pop());
    }

}


int main() {
    int num;
    printf("Enter a number > ");
    scanf("%d", &num);
    decToBin(num);

    return 0;
}
