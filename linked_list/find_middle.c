#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* start = NULL;

struct Node* createNode(int value) {
    struct Node* tmp = (struct Node*)malloc(sizeof(struct Node));
    tmp->data = value;
    tmp->next = NULL;
    return tmp;
}

void prepend(struct Node* newNode) {
    if (start == NULL) {
        start = newNode;
    } else {
        struct Node* tmp = start;
        start = newNode;
        newNode->next = tmp;
    }
}

void append(struct Node* newNode) {
    if (start == NULL) {
        start = newNode;
    } else {
        struct Node* tmp = start;
        while(tmp->next != NULL) {
            tmp = tmp->next;
        }
        tmp->next = newNode;
    }
}

void deleteGiveNode(int value) {
    if (start == NULL) {
        printf("Linked list is Empty\n");
    } else {
        struct Node* ptr = start;
        struct Node* prePtr = start;

        if (ptr->data == value) {
            start = ptr->next;
            free(ptr);
            return;
        };

        while(ptr != NULL) {
            if (ptr->data == value) {
                prePtr->next = ptr->next;
                free(ptr);
            }
            prePtr = ptr;
            ptr = ptr->next;
        }
    }

}

void printList() {
    struct Node* tmp = start;
    while(tmp != NULL) {
        printf("%d->", tmp->data);
        tmp = tmp->next;
    }
    printf("NULL\n");
}

int findLength() {
    struct Node* tmp = start;
    int count = 0;
    while(tmp != NULL) {
        tmp = tmp->next;
        count++;
    }

    return count;
}

void printMiddle() {
    int i;
    struct Node* tmp = start;
    for (i = 0; i < findLength() / 2; i++) {
        tmp = tmp->next;
    }
    printf("Middle data = %d\n", tmp->data);
    
}

int main() {
    int i;

    for (i = 2; i < 6; i++) {
        append(createNode(i));
    }
    printList();

    printMiddle();
    return 0;
}