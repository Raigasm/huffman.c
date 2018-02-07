#ifndef MIN_HEAP_H
#define MIN_HEAP_H

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#include "character_frequency.h"

typedef struct node
{
  char data;
  int frequency;
  struct node *lt, *rt; // children
} node;

typedef struct minheap
{
  int size, capacity;     // current/max size
  struct Node **contents; //array of pointers to nodes (minheap node instances)
} minheap;

// creates a minheap of a given capacity
minheap *minHeap_create(int capacity);

// constructs an appropriately-sized minheap
minheap *minHeap_build(minheap *minHeap);

// returns the minimum node
node *minHeap_getMinNode(minheap *minHeap);

// returns true if minheap has only one member
bool minHeap_hasOnlyOne(minheap *minHeap);

// maintains min-heap structure
void minHeap_minHeapify(struct minheap *minHeap, int index);

// creates a huffman tree based off the character frequency table
node *minHeap_build_huffman(charfreq_table *data, int size);

// creates a node instance
node *node_create(char data, int freq);

// returns true if node has no children
bool node_isLeaf(node *input);

// swaps a and b
minheap *node_swap(node **a, node **b);

// adds a node to the minheap in the correct position
void node_add(minheap *heap, node *input);

#endif //MIN_HEAP_H
