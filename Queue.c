#include <stdio.h>
#define MAX 10

typedef struct {
	int container[MAX];
	int front;
	int rear;
} queue;

queue getNewQueue() {
	queue newQ;
	newQ.front = -1;
	newQ.rear = -1;
	
	return newQ;
}

void enqueue(queue* Q, int value) {
	Q->container[++Q->rear] = value;
}

int dequeue(queue* Q) {
	if (Q->front == Q->rear) {
		printf("This Queue is empty, return value should be ignored.");
		return -1;
	}

	return Q->container[++Q->front];
}

int main(void) {
	queue q1 = getNewQueue();

	for (int i = 0; i < 10; i++) {
		enqueue(&q1, i);
		printf("Enqueue : %d\n", i);
	}

	for (int i = 0; i < 10; i++) {
		printf("Dequeue : %d\n", dequeue(&q1));
	}

	return 0;
}
