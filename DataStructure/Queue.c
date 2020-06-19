#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_SIZE 1000

typedef int element;

typedef struct {
    element* data;
    int maxSize;
    int front;
    int rear;
} Queue;

Queue create(int size) {
    Queue queue;
    queue.data = (element*)malloc(sizeof(element) * size);
    queue.maxSize = size;
    queue.front = 0;
    queue.rear = 0;

    return queue;
}

bool isEmpty(Queue* queue) {
    if (queue->front == queue->rear) {
        return true;
    }
    else {
        return false;
    }
}

bool isFull(Queue* queue) {
    if (queue->rear >= queue->maxSize) {
        return true;
    }
    else {
        return false;
    }
}

bool enqueue(Queue* queue, int data) {
    if (isFull(queue)) {
        return false;
    }
    else {
        queue->data[++(queue->rear)] = data;
        return true;
    }
}

element dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue가 비어있습니다.\n");
        return -999;
    }
    else {
        return queue->data[++(queue->front)];
    }
}

void print(Queue* queue) {
    printf("[ ");
    for (int i = queue->front+1; i <= queue->rear; i++) {
        printf("%d", queue->data[i]);
        if (i < queue->rear) {
            printf(", ");
        }
    }
    printf(" ]\n");
}

int main(void) {
    Queue queue = create(10);

    printf("NEW: ");
    print(&queue);
    printf("\n");
    
    for (int i = 0; i < 5; i++) {
        if (enqueue(&queue, i)) {
            printf("%d -> ", i);
            print(&queue);
        }
        else {
            printf("큐가 가득 찼습니다.\n");
        }
    }

    printf("\n");
    
    int value;
    for (int i = 0; i < 5; i++) {
        value = dequeue(&queue);
        printf("%d <- ", value);
        print(&queue);
    }

    return 0;
}
