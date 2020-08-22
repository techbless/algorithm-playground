#include <stdio.h>
#include <stdlib.h>
#define MAX_ELEMENT 200

typedef struct TreeNode {
    int weight;
    char ch;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

typedef struct {
    TreeNode* ptree;
    char ch;
    int key;
} element;

typedef struct {
    element heap[MAX_ELEMENT];
    int heapSize;
} HeapType;

HeapType* create() {
    return (HeapType*)malloc(sizeof(HeapType));
}

void init(HeapType* h) {
    h->heapSize = 0;
}

void insertMinHeap(HeapType* h, element item) {
    int i;
    i = ++(h->heapSize);

    while ((i != 1) && (item.key) < h->heap[i / 2].key) {
        h->heap[i] = h->heap[i / 2];
        i /= 2;
    }
    
    h->heap[i] = item;
}

element deleteMinHeap(HeapType* h) {
    int parent, child;
    element item, temp;

    item = h->heap[1];
    temp = h->heap[(h->heapSize)--];

    parent = 1;
    child = 2;

    while (child <= h->heapSize) {
        if ((child < h->heapSize) && (h->heap[child].key > h->heap[child + 1].key)) {
            child++;
        }

        if (temp.key < h->heap[child].key) {
            break;
        }
        h->heap[parent] = h->heap[child];
        parent = child;
        child *= 2;
    }

    h->heap[parent] = temp;

    return item;
}

TreeNode* makeTree(TreeNode* left, TreeNode* right) {
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->left = left;
    node->right = right;

    return node;
}

void destroyTree(TreeNode* root) {
    if (root == NULL) return;

    destroyTree(root->left);
    destroyTree(root->right);

    free(root);
}

int isLeaf(TreeNode* root) {
    return !(root->left) && !(root->right);
}

void printArray(int codes[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d", codes[i]);
    }
    printf("\n");
}

void printCodes(TreeNode* root, int codes[], int top) {
    if (root->left) {
        codes[top] = 1;
        printCodes(root->left, codes, top + 1);
    }
    if (root->right) {
        codes[top] = 0;
        printCodes(root->right, codes, top + 1);
    }
    if (isLeaf(root)) {
        printf("%c ", root->ch);
        printArray(codes, top);
    }
}

void huffmanTree(int freq[], char chList[], int n) {
    int i;
    TreeNode* node, * x;
    HeapType* heap;
    element e, e1, e2;
    int codes[100];
    int top = 0;

    heap = create();
    init(heap);
    
    for (i = 0; i < n; i++) {
        node = makeTree(NULL, NULL);
        e.ch = node->ch = chList[i];
        e.key = node->weight = freq[i];
        e.ptree = node;
        insertMinHeap(heap, e);
    }

    for (i = 1; i < n; i++) {
        e1 = deleteMinHeap(heap);
        e2 = deleteMinHeap(heap);

        x = makeTree(e1.ptree, e2.ptree);
        e.key = x->weight = e1.key + e2.key;
        e.ptree = x;
        printf("%d+%d->%d \n", e1.key, e2.key, e.key);
        insertMinHeap(heap, e);
    }

    e = deleteMinHeap(heap);
    printCodes(e.ptree, codes, top);
    destroyTree(e.ptree);
    free(heap);
}

int main(void) {
    char chList[] = { 's', 'i', 'n', 't', 'e' };
    int freq[] = { 4, 6, 8, 12, 15 };

    huffmanTree(freq, chList, 5);
    return 0;
}
