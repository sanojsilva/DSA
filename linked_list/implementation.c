#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* link;
};

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->link = NULL;
    return node;
}

int main() {
    struct Node* first = newNode(5);
    struct Node* second = newNode(10);
    second->link = first;
    printf("%d\n", first->data);
    printf("first => %p\n", first);
    printf("second => %p\n", second->link);
    return 0;
}