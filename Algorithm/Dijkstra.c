#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#define INF 100000000
#define MAX_VERTICES 100

typedef struct GraphType {
    int n;
    int weight[MAX_VERTICES][MAX_VERTICES];
} GraphType;

int distance[MAX_VERTICES];
int found[MAX_VERTICES];

int choose(int distance[], int n, int found[]) {
    int min, minpos;
    min = INT_MAX;
    minpos = -1;

    for (int i = 0; i < n; i++) {
        if (distance[i] < min && !found[i]) {
            min = distance[i];
            minpos = i;
        }
    }

    return minpos;
}

void printStatus(GraphType* g) {
    static int step = 1;
    printf("STEP %d: ", step++);
    printf("distance: ");
    for (int i = 0; i < g->n; i++) {
        if (distance[i] == INF) {
            printf(" * ");
        }
        else {
            printf("%2d ", distance[i]);
        }
    }

    printf("\n");
    printf("found: ");
    for (int i = 0; i < g->n; i++) {
        printf("%2d ", found[i]);
    }

    printf("\n\n");
}

void dijkstra(GraphType* g, int start) {
    for (int i = 0; i < g->n; i++) {
        distance[i] = g->weight[start][i];
        found[i] = false;
    }

    found[start] = true;
    distance[start] = 0;

    int u;
    for (int i = 0; i < (g->n - 1); i++) {
        printStatus(g);
        u = choose(distance, g->n, found);
        found[u] = true;

        for (int w = 0; w < g->n; w++) {
            if (!found[w]) {
                if (distance[u] + g->weight[u][w] < distance[w]) {
                    distance[w] = distance[u] + g->weight[u][w];
                }
            }
        }
    }
}

int main(void) {
    GraphType g = { 7,
        {
            { 0, 7, INF, INF, 3, 10, INF},
            { 7, 0, 4, 10, 2, 6, INF},
            { INF, 4, 0, 2, INF, INF, INF},
            { INF, 10, 2, 0, 11, 9, 4 },
            { 3, 2, INF, 11, 0, INF, 5},
            { 10, 6, INF, 9, INF, 0, INF},
            { INF, INF, INF, 4, 5, INF, 0}
        }
    };
    
    dijkstra(&g, 0);
    return 0;
}
