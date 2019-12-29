#ifndef INT_STACK_H
#define INT_STACK_H

struct Stack {
    int size;
    int top;
    int* items;
};

struct Stack* newStack(int size); 
int currentSize(struct Stack* stack);
int isEmpty(struct Stack* stack);
int isFull(struct Stack* stack);
int peek(struct Stack* stack);
void push(struct Stack* stack, int value);
int pop(struct Stack* stack);
void traverse(struct Stack* stack);

#endif
