#include <stdio.h>
#define SIZE 6

int queue[SIZE];
int front = 0;
int rear = 0;
int count = 0;

void insert(int ele) {
    if (count == SIZE) {
        printf("Queue is Full\n");
    } else {
        queue[rear] = ele;
        rear = (rear + 1) % SIZE;
        count++;
    }
}

void delete() {
    if (count == 0) {
        printf("Queue is Empty\n");
    } else {
        queue[front];
        front = (front + 1) % SIZE;
        count--;
    }
}

void display() {
    if (count == 0) {
        printf("Queue is Empty\n");
    } else {
        int i;
        int j = count;
        for (i = front; j != 0; j--) {
            printf("%d\n", queue[i]);
            i = (i + 1) % SIZE;
        }
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
    delete();
    insert(11);
    display();
    return 0;
}