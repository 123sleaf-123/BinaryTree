//
// Created by MSI-NB on 2022/3/6.
//

#include "MaxHeap.h"

int IsFull(MaxHeap MH) {
    if (MH) {
        if (MH->capacity == MH->size) return 1;
    }
    return 0;
}

MaxHeap CreateHeap(int maxSize) {
    MaxHeap MH = (MaxHeap) malloc(sizeof(struct HeapStruct *));

//  Since the heap will store its elements since the subscript 1, therefore we need one more space
    MH->elements = (ElementType *) malloc((maxSize + 1) * sizeof(ElementType *));
    MH->size = 0;
    MH->capacity = maxSize;

//    A sentry stores a value which can be larger than any possible value appearing in the heap
    MH->elements[0] = INT_MAX;

    return MH;
}

void HeapInsert(ElementType val, MaxHeap MH) {
    if (IsFull(MH)) {
        printf("Max heap has been full. Insertion failed.");
        return;
    }

    int i = ++MH->size;

//    此处实际有一玄妙：
//    i /= 2，总有一天会把i给除成0，然后永无休止
//    可惜我们的哨兵——MH->elements[0]的值极大
//    所以插入值最终会满足 MH->elements[i / 2] < val 这一条件
//    于是，插入值就插入了 1 位置
    for (; MH->elements[i / 2] < val; i /= 2) MH->elements[i] = MH->elements[i / 2];
    MH->elements[i] = val;
//    Author comment: 这数组二叉树浓眉大眼的，没想到还挺tm方便
}

ElementType HeapDelete(ElementType val, MaxHeap MH) {
//    Find the element to be deleted
    int i = MH->size;
    for (; MH->elements[i] != val; i--) {
        if (i == 0) {
            printf("Element doesn't exist.");
            return 0;
        }
    }

//    Change the structure to encounter the features of max heap
    for (int j = 0; j <= MH->size; ++j) {
        j = (MH->elements[i / 2] > MH->elements[i / 2 + 1]) ? (i / 2) : (i / 2 + 1);
        if (j != 0) MH->elements[i] = MH->elements[j];
    }
}
