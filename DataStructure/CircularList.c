#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct Node {
    element data;
    struct Node* link;
} Node;

Node* insertFirst(Node* head, element data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;

    if (head == NULL) {
        head = node;
        node->link = head;
    }
    else {
        node->link = head->link;
        head->link = node;
    }

    return head;
}

Node* insertLast(Node* head, element data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;

    if (head == NULL) {
        head = node;
        node->link = head;
    }
    else {
        node->link = head->link;
        head->link = node;
        head = node;
    }

    return head;
}

void print(Node* head) {
    if (head == NULL) {
        return printf("[ 리스트가 비었습니다. ]\n");
    }

    Node* p = head->link;
    do {
        printf("| %d | -> ", p->data);
        p = p->link;
    } while (p != head->link);
    
    printf("\n");
}

int main(void) {
    Node* head = NULL;

    for (int i = 5; i >= 1; i--) {
        head = insertFirst(head, i);
        print(head);
    }

    for (int i = 6; i <= 10; i++) {
        head = insertLast(head, i);
        print(head);
    }
}
