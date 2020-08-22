#include <stdio.h>
#define MAX_ELEMENT 200

typedef struct {
    int key;
} element;


typedef struct {
    element heap[MAX_ELEMENT];
    int heapSize;
} HeapType;


void insertMaxHeap(HeapType* h, element item) {
    int i;
    i = ++(h->heapSize);

    while ((i != 1) && (item.key > h->heap[i / 2].key)) {
        h->heap[i] = h->heap[i / 2];
        i /= 2;
    }
    h->heap[i] = item;

}

element deleteMaxHeap(HeapType* h) {
    int parent, child;
    element item, temp;

    item = h->heap[1];
    temp = h->heap[(h->heapSize)--];

    parent = 1;
    child = 2;

    while (child <= h->heapSize) {
        if ((child < h->heapSize) && (h->heap[child].key < h->heap[child + 1].key)) {
            child++;
        }

        if (temp.key >= h->heap[child].key) {
            break;
        }

        h->heap[parent] = h->heap[child];
        parent = child;
        child *= 2;
    }

    h->heap[parent] = temp;
    return item;
}


void printHeap(HeapType* h) {
    printf("HEAP : [ ");

    for (int i = 1; i <= h->heapSize; i++) {
        printf("%d ", h->heap[i].key);
    }

    printf("] \n");
}


int main(void) {
    HeapType heap;
    heap.heapSize = 0;

    element e1 = { 10 }, e2 = { 5 }, e3 = { 30 };
    element e4, e5, e6;

    insertMaxHeap(&heap, e1);
    insertMaxHeap(&heap, e2);
    insertMaxHeap(&heap, e3);

    e4 = deleteMaxHeap(&heap);
    e5 = deleteMaxHeap(&heap);
    e6 = deleteMaxHeap(&heap);

    printf("< %d > ", e4.key);
    printf("< %d > ", e5.key);
    printf("< %d > ", e6.key);

    return 0;
}
