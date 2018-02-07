#include "min_heap.h"
#include "log.h"
#include <stdbool.h>

// creates a minheap of a given capacity
minheap *minHeap_create(int capacity)
{
  // allocate memory
  minheap *output = (minheap *)malloc(sizeof(minheap));
  // initialize data
  output->contents = (node **)malloc(output->capacity * sizeof(node *));
  // initialize size
  output->size = 0;
  // initialize capacity
  output->capacity = capacity;
  log_info("created minheap with capacity %i", capacity);
  return output;
}

// constructs an appropriately-sized minheap
minheap *minHeap_build(minheap *input)
{
  int max, index; // max = total number of nodes, index = tracking variable for loop
  max = input->size - 1;
  index = (max - 1) / 2;

  while (index >= 0)
  {
    minHeap_minHeapify(input, index);
    --index;
  }
  log_info("built minHeap");
  return input;
}

// returns the minimum node
node *minHeap_getMinNode(minheap *input)
{
  node *output = input->contents[0];
  input->contents[0] = input->contents[input->size - 1];
  --input->size;
  minHeap_minHeapify(input, 0);

  return output;
}

// returns true if minheap has only one member
bool minHeap_hasOnlyOne(minheap *input)
{
  return (input->size == 1);
}

// traverses the minheap->contents memory pool,
// swapping all nodes appropriate in order to maintain a minheap structure (smallest node at top)
void minHeap_minHeapify(struct minheap *input, int index)
{
  int smallest = index;
  int left = (2 * index) + 1;
  int right = (2 * index) + 2;

  // compare to left child
  if (left < input->size && (input->contents[left]->frequency < input->contents[smallest]->frequency))
  {
    smallest = left;
  }

  // compare to right child
  if (right < input->size && (input->contents[right]->frequency < input->contents[smallest]->frequency))
  {
    smallest = right;
  }

  // swap the current with the smallest
  if (index != smallest)
  {
    node_swap(&input->contents[smallest], &input->contents[index]);
    minHeap_minHeapify(input, smallest);
  }
  return;
}

// creates a node instance
node *node_create(char data, int freq)
{
  node *output = (node *)malloc(sizeof(node));
  output->lt = (node *)0;
  output->rt = (node *)0;
  output->data = data;
  output->frequency = freq;
  return output;
}

// returns true if node has no children
bool node_isLeaf(node *input)
{
  log_info("isLeaf: ['%c',%i]\nchildren: %i %i", input->data, input->frequency, input->lt, input->rt);
  if (input->lt == (node *)0)
  {
    log_info("no left child");
  }
  if (input->rt == (node *)0)
  {
    log_info("no right child");
  }

  if (input->lt == (node *)0 && input->rt == (node *)0)
  {
    log_info("leaf found");
    return true;
  }
  else
  {
    log_info("not a leaf");
    return false;
  }
}

// swaps a and b
void node_swap(node **a, node **b)
{
  node *temp = *a;
  *a = *b;
  *b = temp;
}

// adds a node to the minheap memory pool
void node_add(minheap *heap, node *input)
{
  int index = heap->size; // where we will insert the new node

  // find where to insert in memory, swapping as appropriate
  while (index && input->frequency < heap->contents[((index - 1) / 2)]->frequency)
  {
    heap->contents[index] = heap->contents[(index - 1) / 2];
    index = (index - 1) / 2;
  }

  // insert node
  heap->contents[index] = input;

  // update size
  heap->size = heap->size + 1;
}
