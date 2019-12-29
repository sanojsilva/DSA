#ifndef CHAR_STACK_H
#define CHAR_STACK_H

struct Stack {
    int size;
    int top;
    char* items;
};

struct Stack* newStack(int size); 
int currentSize(struct Stack* stack);
int isEmpty(struct Stack* stack);
int isFull(struct Stack* stack);
int peek(struct Stack* stack);
void push(struct Stack* stack, char value);
char pop(struct Stack* stack);
void traverse(struct Stack* stack);

#endif
