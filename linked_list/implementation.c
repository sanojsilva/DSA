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

int main() {
    int i;

    for (i = 0; i < 6; i++) {
        prepend(createNode(i));
    }

    // for (i = 1; i < 6; i++) {
    //     append(createNode(i));
    // }

    deleteGiveNode(4);
    printList();
    return 0;
}