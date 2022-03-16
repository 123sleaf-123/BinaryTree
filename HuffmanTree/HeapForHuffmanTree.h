//
// Created by MSI-NB on 2022/3/16.
//

#ifndef TREE_HEAPFORHUFFMANTREE_H
#define TREE_HEAPFORHUFFMANTREE_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "HuffmanTree.h"

#define ElementType HuffmanTree
typedef struct HeapStruct *Heap;
typedef struct HeapStruct *MinHeap;
struct HeapStruct {
    ElementType *elements;  // The array to store the elements
    int size;  // The number of elements stored in the heap
    int capacity;  // The maximum capacity of the heap
    char type;
};

int IsFull(Heap MH);

int IsEmpty(Heap MH);

// Create a new minimum heap
MinHeap CreateMinHeap(int maxSize);

// Insert a new Huffman Tree node into the minimum heap
void MinHeapInsert(ElementType val, MinHeap MH);

// Delete the maximum Huffman Tree node from the max heap in recurrent way
ElementType DeleteMin(MinHeap MH);

#endif //TREE_HEAPFORHUFFMANTREE_H
