#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 100
#define INF 1000

int parent[MAX_VERTICES];

void set_init(int n) {
    for (int i = 0; i < n; i++) {
        parent[i] = -1;
    }
}

// curr이 속하는 집합을 반환한다.
int set_find(int curr) {
    if (parent[curr] == -1) {
        return curr;
    }

    while (parent[curr] != -1) {
        curr = parent[curr];
    }

    return curr;
}

// 두개의 원소가 속한 집합을 합친다.
void set_union(int a, int b) {
    int root1 = set_find(a);
    int root2 = set_find(b);
    if (root1 != root2) {
        parent[root1] = root2;
    }
}

struct Edge {
    int start, end, weight;
};

typedef struct GraphType {
    int n;
    struct Edge edges[2 * MAX_VERTICES];
} GraphType;

void graph_init(GraphType* g) {
    g->n = 0;
    for (int i = 0; i < 2 * MAX_VERTICES; i++) {
        g->edges[i].start = 0;
        g->edges[i].end = 0;
        g->edges[i].weight = INF;
    }
}

void insert_edge(GraphType* g, int start, int end, int w) {
    g->edges[g->n].start = start;
    g->edges[g->n].end = end;
    g->edges[g->n].weight = w;
    g->n++;
}

int compare(const void* a, const void* b) {
    struct Edge* x = (struct Edge*)a;
    struct Edge* y = (struct Edge*)b;
    return (x->weight - y->weight);
}

void kruskal(GraphType* g) {
    int edge_accepted = 0; // 현재까지 선택된 간선의 수
    int uset, vset; // 정점 u와 정점 v의 집합 번호
    struct Edge e;

    set_init(g->n);
    qsort(g->edges, g->n, sizeof(struct Edge), compare);

    printf("크루스칼 최소 신장 트리 알고리즘\n");

    int i = 0;
    while (edge_accepted < (g->n - 1)) {
        e = g->edges[i];
        uset = set_find(e.start);
        vset = set_find(e.end);

        // 서로 속한 집합이 다르면
        if (uset != vset) {
            printf("간선 (%d, %d) %d 선택\n", e.start, e.end, e.weight);
            edge_accepted++;
            set_union(uset, vset); // 두개의 집합을 합친다.
        }
        i++;
    }
}

int main(void) {
    GraphType* g;
    g = (GraphType*)malloc(sizeof(GraphType));
    graph_init(g);

    insert_edge(g, 0, 1, 29);
    insert_edge(g, 1, 2, 16);
    insert_edge(g, 2, 3, 12);
    insert_edge(g, 3, 4, 22);
    insert_edge(g, 4, 5, 27);
    insert_edge(g, 5, 0, 10);
    insert_edge(g, 6, 1, 15);
    insert_edge(g, 6, 3, 18);
    insert_edge(g, 6, 4, 25);

    kruskal(g);
    free(g);

    return 0;
}
