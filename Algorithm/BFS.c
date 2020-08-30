#include <stdio.h>
#include <stdbool.h>

#define MAX_QUEUE_SIZE 10

typedef int element;

typedef struct {
    element queue[MAX_QUEUE_SIZE];
    int front, rear;
} Queue;

void error(char* msg) {
    fprintf(stderr, "%s\n", msg);
}

void initQueue(Queue* q) {
    q->front = q->rear = 0;
}

bool isEmpty(Queue* q) {
    return (q->front == q->rear);
}

bool isFull(Queue* q) {
    return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}

void enqueue(Queue* q, element item) {
    if (isFull(q)) {
        error("큐가 포화상태 입니다.");
    }

    q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
    q->queue[q->rear] = item;
}

element dequeue(Queue* q) {
    if (isEmpty(q)) {
        error("큐가 공백상태입니다");
    }

    q->front = (q->front + 1) % MAX_QUEUE_SIZE;
    return q->queue[q->front];
}

#define MAX_VERTICES 50

typedef struct Graph {
    int n;
    int adj_mat[MAX_VERTICES][MAX_VERTICES];
} Graph;

bool visited[MAX_VERTICES];

void initGraph(Graph* g) {
    int r, c;
    g->n = 0;

    for (r = 0; r < MAX_VERTICES; r++) {
        for (c = 0; c < MAX_VERTICES; c++) {
            g->adj_mat[r][c] = 0;
        }
    }
}

void insertVertex(Graph* g, int v) {
    if (((g->n) + 1) > MAX_VERTICES) {
        error("그래프: 정점의 개수 초과");
        return;
    }
    g->n++;
}

void insertEdge(Graph* g, int start, int end) {
    if (start >= g->n || end >= g->n) {
        error("그래프: 정점 번호 오류");
    }

    g->adj_mat[start][end] = 1;
    g->adj_mat[end][start] = 1;
}

void bfs(Graph* g, int v) {
    int w;
    Queue q;

    initQueue(&q);
    visited[v] = true;
    
    printf("%d 방문 -> ", v);
    enqueue(&q, v);
    while (!isEmpty(&q)) {
        v = dequeue(&q);
        for (w = 0; w < g->n; w++) {
            if (g->adj_mat[v][w] && !visited[w]) {
                visited[w] = true;
                printf("%d 방문 -> ", w);
                enqueue(&q, w);
            }
        }
    }

    printf("\n");
}

int main(void) {
    Graph* g = (Graph*)malloc(sizeof(Graph));
    initGraph(g);

    for (int i = 0; i < 6; i++) {
        insertVertex(g, i);
    }

    insertEdge(g, 0, 2);
    insertEdge(g, 2, 1);
    insertEdge(g, 2, 3);
    insertEdge(g, 0, 4);
    insertEdge(g, 4, 5);
    insertEdge(g, 1, 5);

    printf("너비 우선 탐색\n");
    bfs(g, 0);

    free(g);
    return 0;
}
