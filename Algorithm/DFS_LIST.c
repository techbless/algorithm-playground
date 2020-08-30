#include <stdio.h>
#include <stdbool.h>

#define MAX_VERTICES 50

typedef struct GraphNode {
    int vertex;
    struct GraphNode* link;
} GraphNode;

typedef struct GraphType {
    int n; // 정점의 개수
    GraphNode* adj_list[MAX_VERTICES];
} GraphType;

bool visited[MAX_VERTICES];

void init(GraphType* g) {
    int v;
    g->n = 0;
    for (v = 0; v < MAX_VERTICES; v++) {
        g->adj_list[v] = NULL;
    }
}

void insert_vertex(GraphType* g, int v) {
    if (((g->n + 1) > MAX_VERTICES)) {
        printf("그래프: 정점의 개수 초과");
        return;
    }

    g->n++;
}

void insert_edge(GraphType* g, int u, int v) {
    if (u >= g->n || v >= g->n) {
        printf("그래프: 정점 번호 오류");
        return;
    }

    GraphNode* node = (GraphNode*)malloc(sizeof(GraphNode));
    node->vertex = v;
    node->link = g->adj_list[u];
    g->adj_list[u] = node;
}


void dfs(GraphType* g, int v) {
    GraphNode* w;
    visited[v] = true;

    printf("정점 %d -> ", v);
    for (w = g->adj_list[v]; w; w = w->link) {
        if (!visited[w->vertex]) {
            dfs(g, w->vertex);
        }
    }
}

int main(void) {
    GraphType* g;
    g = (GraphType*)malloc(sizeof(GraphType));
    init(g);

    for (int i = 0; i < 4; i++) {
        insert_vertex(g, i);
    }

    insert_edge(g, 0, 3);
    insert_edge(g, 0, 2);
    insert_edge(g, 0, 1);
    insert_edge(g, 2, 3);
    insert_edge(g, 1, 2);

    printf("깊이 우선 탐색\n");
    dfs(g, 0);
    free(g);

    return 0;
}
