// C program for Huffman Coding
#include <stdio.h>
#include <stdlib.h>

// This constant can be avoided by explicitly
// calculating height of Huffman Tree
#define MAX_TREE_HT 100

// A Huffman tree node
struct node
{

  // One of the input characters
  char data;

  // Frequency of the character
  int freq;

  // Left and right child of this node
  struct node *left, *right;
};

// A Min Heap:  Collection of
// min heap (or Hufmman tree) nodes
struct minheap
{

  // Current size of min heap
  int size;

  // capacity of min heap
  int capacity;

  // Attay of minheap node pointers
  struct node **array;
};

// A utility function allocate a new
// min heap node with given character
// and frequency of the character
struct node *node_create(char data, int freq)
{
  struct node *temp = (struct node *)malloc(sizeof(struct node));

  temp->left = temp->right = NULL;
  temp->data = data;
  temp->freq = freq;

  return temp;
}

// A utility function to create
// a min heap of given capacity
struct minheap *minHeap_create(int capacity)

{
  struct minheap *minHeap = (struct minheap *)malloc(sizeof(struct minheap));

  // current size is 0
  minHeap->size = 0;

  minHeap->capacity = capacity;

  minHeap->array = (struct node **)malloc(minHeap->capacity * sizeof(struct node *));
  return minHeap;
}

// A utility function to
// swap two min heap nodes
void node_swap(struct node **a,
               struct node **b)

{

  struct node *t = *a;
  *a = *b;
  *b = t;
}

// The standard minHeap_minHeapify function.
void minHeap_minHeapify(struct minheap *minHeap, int index)

{

  int smallest = index;
  int left = 2 * index + 1;
  int right = 2 * index + 2;

  if (left < minHeap->size && minHeap->array[left]->freq < minHeap->array[smallest]->freq)
    smallest = left;

  if (right < minHeap->size && minHeap->array[right]->freq < minHeap->array[smallest]->freq)
    smallest = right;

  if (smallest != index)
  {
    swa node(&minHeap->array[smallest],
             &minHeap->array[index]);
    minHeap_minHeapify(minHeap, smallest);
  }
}

// A utility function to check
// if size of heap is 1 or not
int minHeap_hasOnlyOne(struct minheap *minHeap)
{

  return (minHeap->size == 1);
}

// A standard function to extract
// minimum value node from heap
struct node *minHeap_getMinNode(struct minheap *input)

{

  node *output = input->array[0];
  input->array[0] = input->array[input->size - 1];
  --input->size;
  minHeap_minHeapify(input, 0);

  return output;
}

// A utility function to insert
// a new node to Min Heap
void node_add(struct minheap *minHeap,
              struct node node)

{

  ++minHeap->size;
  int i = minHeap->size - 1;

  while (i && node->freq < minHeap->array[(i - 1) / 2]->freq)
  {

    minHeap->array[i] = minHeap->array[(i - 1) / 2];
    i = (i - 1) / 2;
  }

  minHeap->array[i] = node;
}

// A standard funvtion to build min heap
void minHeap_build(struct minheap *minHeap)

{

  int n = minHeap->size - 1;
  int i;

  for (i = (n - 1) / 2; i >= 0; --i)
    minHeap_minHeapify(minHeap, i);
}

// A utility function to print an array of size n
void printArr(int arr[], int n)
{
  int i;
  for (i = 0; i < n; ++i)
    printf("%d", arr[i]);

  printf("\n");
}

// Utility function to check if this node is leaf
int node_isLeaf(struct node *root)

{

  return !(root->left) && !(root->right);
}

// Creates a min heap of capacity
// equal to size and inserts all character of
// data[] in min heap. Initially size of
// min heap is equal to capacity
struct minheap *minHeap_build(charfreq_table *data, int size)
{

  struct minheap *minHeap = minHeap_create(size);

  for (int i = 0; i < size; ++i)
    minHeap->array[i] = node_create(data[i], freq[i]);

  minHeap->size = size;
  minHeap_build(minHeap);

  return minHeap;
}

// The main function that builds Huffman tree
struct node *minHeap_build_huffman(char data[], int freq[], int size)

{
  struct node *left, *right, *top;

  // Step 1: Create a min heap of capacity
  // equal to size.  Initially, there are
  // modes equal to size.
  struct minheap *minHeap = minHeap_build(data, freq, size);

  // Iterate while size of heap doesn't become 1
  while (!minHeap_hasOnlyOne(minHeap))
  {

    // Step 2: Extract the two minimum
    // freq items from min heap
    left = minHeap_getMinNode(minHeap);
    right = minHeap_getMinNode(minHeap);

    // Step 3:  Create a new internal
    // node with frequency equal to the
    // sum of the two nodes frequencies.
    // Make the two extracted node as
    // left and right children of this new node.
    // Add this node to the min heap
    // '$' is a special value for internal nodes, not used
    top = node_create('$', left->freq + right->freq);

    top->left = left;
    top->right = right;

    node_add(minHeap, top);
  }

  // Step 4: The remaining node is the
  // root node and the tree is complete.
  return minHeap_getMinNode(minHeap);
}

// Prints huffman codes from the root of Huffman Tree.
// It uses arr[] to store codes
void printCodes(struct node *root, int arr[], int top)

{

  // Assign 0 to left edge and recur
  if (root->left)
  {

    arr[top] = 0;
    printCodes(root->left, arr, top + 1);
  }

  // Assign 1 to right edge and recur
  if (root->right)
  {

    arr[top] = 1;
    printCodes(root->right, arr, top + 1);
  }

  // If this is a leaf node, then
  // it contains one of the input
  // characters, print the character
  // and its code from arr[]
  if (node_isLeaf(root))
  {

    printf("%c: ", root->data);
    printArr(arr, top);
  }
}

// The main function that builds a
// Huffman Tree and print codes by traversing
// the built Huffman Tree
void HuffmanCodes(char data[], int freq[], int size)

{
  // Construct Huffman Tree
  struct node *root = minHeap_build_huffman(data, freq, size);

  // Print Huffman codes using
  // the Huffman tree built above
  int arr[MAX_TREE_HT], top = 0;

  printCodes(root, arr, top);
}

// Driver program to test above functions
int main()
{

  char arr[] = {'a', 'b', 'c', 'd', 'e', 'f'};
  int freq[] = {5, 9, 12, 13, 16, 45};

  int size = sizeof(arr) / sizeof(arr[0]);

  HuffmanCodes(arr, freq, size);

  return 0;
}
