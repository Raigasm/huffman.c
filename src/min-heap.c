#include "min-heap.h"
#include "log.h"
#include <stdbool.h>

typedef struct Node
{
  char data;
  unsigned frequency;
  struct Node *lt, *rt; // children
} Node;

typedef struct MinHeap
{
  int size, capacity;     // current/max size
  struct Node **contents; //array of pointers to nodes (minheap node instances)
} MinHeap;

MinHeap *minHeap_create()
{
  log_info(">> minHeap_create");
  return (MinHeap *)0;
}

MinHeap *minHeap_build()
{
  log_info(">> minHeap_build");
  return (MinHeap *)0;
}

Node *minHeap_getMinNode()
{
  log_info(">> minHeap_getMinNode");
  return (Node *)0;
}

bool minHeap_hasOnlyOne()
{
  log_info(">> minHeap_hasOnlyOne");
  return false;
}

MinHeap *minHeap_minHeapify()
{
  log_info(">> minHeap_minHeapify");
  return (MinHeap *)0;
}

Node *node_create()
{
  log_info(">> node_create");
  return (Node *)0;
}

bool node_isLeaf()
{
  log_debug(">> node_isLeaf");
  return false;
}

MinHeap *node_swap()
{
  log_debug(">> node_swap");
  return (MinHeap *)0;
}

Node *node_add()
{
  log_debug(">> node_add");
  return (Node *)0;
}
