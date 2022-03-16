//
// Created by MSI-NB on 2022/3/6.
//

/*
 * 堆的特性：
 * 结构性：用数组表示的完全二叉树
 * 有序性：任意结点的关键字是其子树所有节点的最大值（或者最小值）
 * */

#ifndef TREE_HEAP_H
#define TREE_HEAP_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define ElementType int
typedef struct HeapStruct *Heap;
typedef struct HeapStruct *MaxHeap;
typedef struct HeapStruct *MinHeap;
struct HeapStruct {
    ElementType *elements;  // The array to store the elements
    int size;  // The number of elements stored in the heap
    int capacity;  // The maximum capacity of the heap
    char type;
};

int IsFull(Heap MH);

int IsEmpty(Heap MH);

// Create a new max heap
MaxHeap CreateMaxHeap(int maxSize);

// Insert a new element into the max heap
void MaxHeapInsert(ElementType val, MaxHeap MH);

// Delete the maximum element from the max heap in recurrent way
ElementType DeleteMax(MaxHeap MH);

// Create a new minimum heap
MinHeap CreateMinHeap(int maxSize);

// Insert a new element into the minimum heap
void MinHeapInsert(ElementType val, MinHeap MH);

// Delete the maximum element from the max heap in recurrent way
ElementType DeleteMin(MinHeap MH);

#endif //TREE_HEAP_H
