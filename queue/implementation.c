#include <stdio.h>
#define SIZE 6

int queue[SIZE];
int front = -1;
int rear = -1;

void insert(int ele) {
    if (rear == SIZE - 1) {
        printf("Queue is Full\n");
    } else {
        if (front == -1) 
        front = 0;

        rear++;
        queue[rear] = ele;
    }

}

int delete() {
    int val = 0;
    if (front == -1 || front > rear) {
        printf("Queue is Empty\n");
    } else {
        val = queue[front];
        front++;
        if (front > rear) {
            front = rear = -1;
        }
        return val;
    }
}

int peek() {
    if (front == -1 || front > rear) {
        printf("Queue is Empty\n");
    } else {
        return queue[front];
    }
}

void display() {
    int i;
    for (i = front; i <= rear; i++) {
        printf("%d\n", queue[i]);
    }

}

int main() {
    insert(3);
    insert(6);
    insert(10);
    insert(10);
    insert(11);
    insert(45);
    display();
    return 0;
}