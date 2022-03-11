//
// Created by MSI-NB on 2022/3/6.
//

/*
 * 堆的特性：
 * 结构性：用数组表示的完全二叉树
 * 有序性：任意结点的关键字是其子树所有节点的最大值（或者最小值）
 * */

#ifndef TREE_MAXHEAP_H
#define TREE_MAXHEAP_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
//#include "../AVLTree/AVLTreeNode.h"
#define ElementType int
typedef struct HeapStruct *MaxHeap;
struct HeapStruct {
    ElementType *elements;  // The array to store the elements
    int size;  // The number of elements stored in the heap
    int capacity;  // The maximum capacity of the heap
};

int IsFull(MaxHeap MH);

int IsEmpty(MaxHeap MH);

// Create a new max heap
MaxHeap CreateHeap(int maxSize);

// Insert a new element into the max heap
void HeapInsert(ElementType val, MaxHeap MH);

// Delete the maximum element from the max heap in recurrent way
ElementType DeleteMax(MaxHeap MH);

#endif //TREE_MAXHEAP_H
