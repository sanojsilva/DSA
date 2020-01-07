#include <stdio.h>
#define SIZE 6

int queue[SIZE];
int front = -1;
int rear = -1;
int count = 0;

int isEmpty() {
    if (front == -1 || front > rear) {
        return 1;
    } else {
        return 0;
    }
}

int isFull() {
    if (rear == SIZE - 1) {
        return 1;
    } else {
        return 0;
    }
}

void enqueue(int ele) {
    if (isFull()) {
        printf("Queue is Full\n");
    } else {
        if (front == -1)
            front = 0;
        rear++;
        queue[rear] = ele;
        count++;
    }
}

int dequeue() {
    if (isEmpty()) {
        printf("Queue is Empty\n");
        return -1;
    } else {
        int val = queue[front];
        front++;
        if (front > rear) 
            front = rear = -1;
        
        count--;
        return val;
    }
}


void push(int ele) {
    int currentSize = count;
    int i;
    enqueue(ele);
    for (i = 0; i < currentSize; i++) {
        // printf("D: %d\n", val);
        enqueue(dequeue());
    }
}


int pop() {
    return dequeue();
}

void display() {
    int i;
    for (i = front; i <= rear; i++){
        printf("%d\n", queue[i]);
    }
}

int main() {
    push(20);
    push(40);
    push(30);
    display();
    printf("----\n");
    pop();
    display();
    return 0;
}