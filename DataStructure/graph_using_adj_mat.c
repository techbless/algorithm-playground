#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 50
typedef struct GraphType {
    int n; // 정점의 개수
    int adj_mat[MAX_VERTICES][MAX_VERTICES];
} GraphType;

void init(GraphType* g) {
    int r, c;
    g->n = 0;

    for (r = 0; r < MAX_VERTICES; r++) {
        for (c = 0; c < MAX_VERTICES; c++) {
            g->adj_mat[r][c] = 0;
        }
    }
}

void insertVertex(GraphType* g, int v) {
    if (((g->n) + 1) > MAX_VERTICES) {
        printf("그래프: 정점의 개수 초과");
        return;
    }
    g->n++;
}

void insertEdge(GraphType* g, int start, int end) {
    if (start >= g->n || end >= g->n) {
        printf("그래프: 정점 번호 오류");
        return;
    }
    g->adj_mat[start][end] = 1;
    g->adj_mat[end][start] = 1;
}

void printAdjMat(GraphType* g) {
    for (int i = 0; i < g->n; i++) {
        for (int j = 0; j < g->n; j++) {
            printf("%2d ", g->adj_mat[i][j]);
        }
        printf("\n");
    }
}

int main(void) {
    GraphType* g;
    g = (GraphType*)malloc(sizeof(GraphType));
    init(g);

    for (int i = 0; i < 4; i++) {
        insertVertex(g, i);
    }

    insertEdge(g, 0, 1);
    insertEdge(g, 0, 2);
    insertEdge(g, 0, 3);
    insertEdge(g, 1, 2);
    insertEdge(g, 2, 3);

    printAdjMat(g);

    free(g);
    return 0;
}
