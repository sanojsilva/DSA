#include <stdio.h>
#include <stdlib.h>

struct Stack {
    int size;
    int top;
    int* items;
};

struct Stack* newStack(int size) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->size = size;
    stack->top = -1;
    stack->items = (int *)malloc(size * sizeof(int));
    return stack;
}

int currentSize(struct Stack* stack) {
    return stack->top + 1;
}

int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

int isFull(struct Stack* stack) {
    return stack->top == stack->size - 1;
}

int peek(struct Stack* stack) {
    return stack->items[stack->top];
}

void push(struct Stack* stack, int value) {
    if (!isFull(stack)) {
        stack->items[++stack->top] = value;
        printf("Pushed %d\n", value);
    } else {
        printf("Stack is Full\n");
    }
}

int pop(struct Stack* stack) {
    if (!isEmpty(stack)) {
        printf("Popped %d\n", stack->top);
        return stack->items[stack->top--];
    } else {
        printf("Stack is Empty\n");
    }
}

void traverse(struct Stack* stack) {
    int i;
    for (i = stack->top; i >= 0; i--) {
        printf("%d\n", stack->items[i]);
    }
}

int main() {
    struct Stack* myStack = newStack(5);
    push(myStack, 3);
    push(myStack, 2);
    push(myStack, 1);
    push(myStack, 8);
    traverse(myStack);
    return 0;
}