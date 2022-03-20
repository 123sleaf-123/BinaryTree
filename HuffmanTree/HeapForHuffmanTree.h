//
// Created by MSI-NB on 2022/3/16.
//

#ifndef TREE_HEAPFORHUFFMANTREE_H
#define TREE_HEAPFORHUFFMANTREE_H
#include "HuffmanTree.h"

#define ElementType HuffmanTree
typedef struct HeapStruct *Heap;
typedef struct HeapStruct *MinHeap;
struct HeapStruct {
    ElementType *elements;  // The array to store the elements
    int size;  // The number of elements stored in the heap
    int capacity;  // The maximum capacity of the heap
};

int IsFullH(Heap MH);

int IsEmptyH(Heap MH);

// Create a new minimum heap
MinHeap CreateMinHeapH(int maxSize);

// Insert a new Huffman Tree node into the minimum heap
void MinHeapInsertH(ElementType val, MinHeap MH);

// Delete the maximum Huffman Tree node from the max heap in recurrent way
ElementType DeleteMinH(MinHeap MH);

HuffmanTree Huffman(MinHeap MH);

#endif //TREE_HEAPFORHUFFMANTREE_H
