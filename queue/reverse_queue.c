#include <stdio.h>
#define SIZE 6

int stack[SIZE];
int top = -1;

int queue[SIZE];
int front = -1;
int rear = -1;

int isStackEmpty() {
    return top == -1;
}

int isStackFull() {
    return top == SIZE - 1;
}

void push(int ele) {
    if (isStackFull()) {
        printf("Stack is Empty\n");
    } else {
        stack[++top] = ele;
    }
}

int pop() {
    if (isStackEmpty()) {
        printf("Stack is Empty\n");
        return -1;
    } else {
        return stack[top--];
    }
}

int isQueueEmpty() {
    if (front == -1 || front > rear) {
        return 1;
    } else {
        return 0;
    }
}

int isQueueFull() {
    if (rear == SIZE - 1) {
        return 1;
    } else {
        return 0;
    }
}

void enqueue(int ele) {
    if (isQueueFull()) {
        printf("Queue is Full\n");
    } else {
        if (front == -1) 
            front = 0;
        rear++;
        queue[rear] = ele;
    }
}

int dequeue() {
    if (isQueueEmpty()) {
        printf("Queue is Empty\n");
        return -1;
    } else {
        int val = queue[front];
        front++;
        if (front > rear)
            front = rear = -1;
        return val;
    }
}

void displayQueue() {
    int i;
    for (i = front; i <= rear; i++) {
        printf("%d\n", queue[i]);
    }
}

void reverseQueue() {
    // dequeue and push to stack until the queue gets empty
    while(!isQueueEmpty()) {
        push(dequeue());
    }

    // pop from the stack and enqueue it back to the queue
    while(!isStackEmpty()) {
        enqueue(pop());
    }
}

int main() {
    // add elements to queue
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    printf("Original\n==========\n");
    displayQueue();
    reverseQueue();
    printf("Reversed\n==========\n");
    displayQueue();
    return 0;
}