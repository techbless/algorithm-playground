#include <stdio.h>

#include <stdbool.h>

#define MAX_QUEUE_SIZE 10
#define MAX_VERTICES 50

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

bool visited[MAX_VERTICES];

typedef struct GraphNode {
    int vertex;
    struct GraphNode* link;
} GraphNode;

typedef struct GraphType {
    int n; // 정점의 개수
    GraphNode* adj_list[MAX_VERTICES];
} GraphType;

void initGraph(GraphType* g) {
    int v;
    g->n = 0;
    for (v = 0; v < MAX_VERTICES; v++) {
        g->adj_list[v] = NULL;
    }
}

void insertVertex(GraphType* g, int v) {
    if (((g->n + 1) > MAX_VERTICES)) {
        printf("그래프: 정점의 개수 초과");
        return;
    }

    g->n++;
}

void insertEdge(GraphType* g, int u, int v) {
    if (u >= g->n || v >= g->n) {
        printf("그래프: 정점 번호 오류");
        return;
    }

    GraphNode* node = (GraphNode*)malloc(sizeof(GraphNode));
    node->vertex = v;
    node->link = g->adj_list[u];
    g->adj_list[u] = node;
}

void bfs(GraphType* g, int v) {
    GraphNode* w;
    Queue q;

    initQueue(&q);
    visited[v] = true;

    printf("%d 방문 -> ", v);
    enqueue(&q, v);
    while (!isEmpty(&q)) {
        v = dequeue(&q);
        for (w = g->adj_list[v]; w; w = w->link) {
            if (!visited[w->vertex]) {
                visited[w->vertex] = true;
                printf("%d 방문 -> ", w->vertex);
                enqueue(&q, w->vertex);
            }
        }
    }

    printf("\n");
}

int main(void) {
    GraphType* g = (GraphType*)malloc(sizeof(GraphType));
    initGraph(g);

    for (int i = 0; i < 6; i++) {
        insertVertex(g, i);
    }

    insertEdge(g, 0, 4);
    insertEdge(g, 0, 2);
    insertEdge(g, 1, 5);
    insertEdge(g, 2, 3);
    insertEdge(g, 2, 1);
    insertEdge(g, 4, 5);

    printf("너비 우선 탐색\n");
    bfs(g, 0);

    free(g);
    return 0;
}
