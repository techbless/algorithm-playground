#include <stdio.h>
#define SIZE 4

typedef struct {
    int container[SIZE];
    int front;
    int rear;
} queue;

queue getNewQueue() {
    queue newQ;
    newQ.front = -1;
    newQ.rear = -1;

    return newQ;
}

int isEmpty(queue* Q) {
    if (Q->front == -1) {
        return 1;
    }
    else {
        return 0;
    }
}

int isFull(queue* Q) {
    return (Q->rear + 1) % SIZE == Q->front;
}

void enqueue(queue* Q, int value) {
    if (isFull(Q)) {
        printf("[This Queue is full] ");
        return;
    }
    else if (Q->front == -1) {
        Q->front = 0;
        Q->rear = 0;
        Q->container[Q->rear] = value;
    }
    else {
        Q->rear = (Q->rear + 1) % SIZE;
        Q->container[Q->rear] = value;
    }
}

int dequeue(queue* Q) {
    if (isEmpty(Q)) {
        printf("[This Queue is empty, Return value should be ignored] ");
        return -1;
    }
    // Only one element left
    else if (Q->front == Q->rear) {
        int temp = Q->container[Q->front];
        Q->front = -1;
        Q->rear = -1;
        return temp;
    }
    int temp = Q->container[Q->front];
    Q->front = (Q->front + 1) % SIZE;
    return temp;
}

int main(void) {
    queue q1 = getNewQueue();

    for (int i = 0; i < 4; i++) {
        enqueue(&q1, i);
        printf("Enqueue : %d\n", i);
    }

    for (int i = 0; i < 3; i++) {
        printf("Dequeue : %d\n", dequeue(&q1));
    }

    for (int i = 0; i < 4; i++) {
        enqueue(&q1, i);
        printf("Enqueue : %d\n", i);
    }

    for (int i = 0; i < 5; i++) {
        printf("Dequeue : %d\n", dequeue(&q1));
    }

    return 0;
}
