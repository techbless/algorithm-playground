#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 100
#define INF 10000000

typedef struct GraphType {
    int n;
    int weight[MAX_VERTICES][MAX_VERTICES];
} GraphType;

int A[MAX_VERTICES][MAX_VERTICES];

void printA(GraphType* g) {
    int i, j;
    printf("==========================\n");
    for (int i = 0; i < g->n; i++) {
        for (int j = 0; j < g->n; j++) {
            if (A[i][j] == INF) {
                printf(" * ");
            }
            else {
                printf("%3d", A[i][j]);
            }
        }
        printf("\n");
    }

    printf("==========================\n");
}

void floyd(GraphType* g) {
    for (int i = 0; i < g->n; i++) {
        for (int j = 0; j < g->n; j++) {
            A[i][j] = g->weight[i][j];
        }
    }

    printA(g);

    for (int k = 0; k < g->n; k++) {
        for (int i = 0; i < g->n; i++) {
            for (int j = 0; j < g->n; j++) {
                if (A[i][k] + A[k][j] < A[i][j]) {
                    A[i][j] = A[i][k] + A[k][j];
                }
            }
        }

        printA(g);
    }
}

int main(void) {
    GraphType g = { 7,
    {
        { 0, 7, INF , INF , 3, 10, INF },
        { 7, 0, 4, 10, 2, 6, INF },
        { INF , 4, 0, 2 , INF , INF , INF },
        { INF , 10, 2, 0, 11, 9, 4 },
        { 3, 2, INF , 11, 0, INF , 5 },
        { 10, 6, INF , 9, INF , 0, INF },
        { INF , INF , INF , 4, 5, INF , 0 }
    }};
    floyd(&g);

    return 0;
}
