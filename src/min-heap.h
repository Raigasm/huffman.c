#ifdef MIN_HEAP_H
#define MIN_HEAP_H

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct MinHeap MinHeap;

MinHeap *minHeap_create();
MinHeap *minHeap_build();
Node *minHeap_getMinNode();
bool minHeap_hasOnlyOne();
MinHeap *minHeap_minHeapify();

typedef struct Node Node;

Node *node_create();
bool node_isLeaf();
MinHeap *node_swap();
Node *node_add();

#endif //MIN_HEAP_H
