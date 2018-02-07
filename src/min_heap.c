#include "min_heap.h"
#include "log.h"
#include <stdbool.h>

// creates a minheap of a given capacity
minheap *minHeap_create(int capacity)
{
  return (minheap *)0;
}

// constructs an appropriately-sized minheap
minheap *minHeap_build(minheap *minHeap)
{
  return (minheap *)0;
}

// returns the minimum node
node *minHeap_getMinNode(minheap *minHeap)
{
  return (node *)0;
}

// returns true if minheap has only one member
bool minHeap_hasOnlyOne(minheap *minHeap)
{
  return (bool)0;
}

// maintains min-heap structure
void minHeap_minHeapify(struct minheap *minHeap, int index)
{
  return;
}

// creates a huffman tree based off the character frequency table
node *minHeap_build_huffman(charfreq_table *data, int size)
{
  return (node *)0;
}

// creates a node instance
node *node_create(char data, int freq)
{
  node *output = (node *)malloc(sizeof(node));
  output->lt = NULL;
  output->rt = NULL;
  output->data = data;
  output->frequency = freq;
  return output;
}

// returns true if node has no children
bool node_isLeaf(node *input)
{
  return (input->lt == input->rt) && (input->lt == NULL);
}

// swaps a and b
minheap *node_swap(node **a, node **b)
{
  return (minheap *)0;
}

// adds a node to the minheap in the correct position
void node_add(minheap *heap, node *input)
{
  return;
}
