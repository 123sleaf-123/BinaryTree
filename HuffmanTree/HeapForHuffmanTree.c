//
// Created by MSI-NB on 2022/3/16.
//

#include "HeapForHuffmanTree.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int IsFullH(Heap MH) {
    if (MH) {
        if (MH->capacity == MH->size) return 1;
    }
    return 0;
}

int IsEmptyH(Heap MH) {
    if (MH != NULL)
        if (MH->size != 0) return 0;
    return 1;
}

MinHeap CreateMinHeapH(int maxSize) {
    MinHeap MH = (MinHeap) malloc(sizeof(struct HeapStruct *));

//  Since the heap will store its elements since the subscript 1, therefore we need one more space
    MH->elements = (ElementType *) malloc((maxSize + 1) * sizeof(ElementType *));
    MH->size = 0;
    MH->capacity = maxSize;

//    A sentry stores a value which can be larger than any possible value appearing in the heap
    HuffmanTree HT = (HuffmanTree) malloc(sizeof(struct HTreeNode*));
    HT->weight = 0;
    HT->left = HT->right = NULL; // NULL == (void *)0
    MH->elements[0] = HT;

    return MH;
}

void MinHeapInsertH(ElementType HT, MinHeap MH) {
    if (IsFullH(MH)) {
        printf("Minimum heap has been full. Insertion failed.");
        return;
    }

    int i = ++MH->size;

//    此处实际有一玄妙：
//    i /= 2，总有一天会把i给除成0，然后永无休止
//    可惜我们的哨兵——MH->elements[0]的值极大
//    所以插入值最终会满足 MH->elements[i / 2] < val 这一条件
//    于是，插入值就插入了 1 位置
    for (; MH->elements[i / 2]->weight > HT->weight; i /= 2) MH->elements[i] = MH->elements[i / 2];
    MH->elements[i] = HT;
//    Author comment: 这数组二叉树浓眉大眼的，没想到还挺tm方便
}

ElementType DeleteMinH(MinHeap MH) {
    if (IsEmptyH(MH)) {
        printf("Minumum heap has been empty. Deletion failed.");
        return NULL;
    }

    ElementType min;
    min = MH->elements[1];
    int i = 1;
    int j = 1;

    while (j <= MH->size) {
//        If node doesn't have children, the interchange will over
        if (i * 2 > MH->size) break;

//        If node only have right child, we will choose its right child
        else if ((i * 2 + 1) > MH->size) j = i * 2;

//        If node have both left and right children, we will compare which one is larger and choose the larger one
        else j = (MH->elements[i * 2]->weight < MH->elements[i * 2 + 1]->weight) ? (i * 2) : (i * 2 + 1);
        if (j != 0) MH->elements[i] = MH->elements[j];
        i = j;
    }

    MH->size--;

    return min;
}

HuffmanTree Huffman(MinHeap MH) {
    HuffmanTree HT;
    for (int i = 0; i < MH->size; ++i) {
        HT = (HuffmanTree) malloc(sizeof(struct HTreeNode*));

//        Delete and take out the two Huffman Tree node whose weight is the smallest two
//        from the given minimum heap.
//        Then the two nodes become the lef and right child of the targeted Huffman Tree node
        HT->left = DeleteMinH(MH);
        HT->right = DeleteMinH(MH);

//        Calculate the sum of children's weights, stores and add the node back to the minimum heap
        HT->weight = HT->left->weight + HT->right->weight;
        MinHeapInsertH(HT, MH);
    }

//    Return the root node as the result
    return MH->elements[1];
}
