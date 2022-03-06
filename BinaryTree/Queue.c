//
// Created by MSI-NB on 2022/3/6.
//

#include "Queue.h"

Queue CreateQueue() {
    Queue PtrQ = (Queue) malloc(sizeof(struct QNode));
    PtrQ->front = NULL;
    PtrQ->rear = NULL;
    PtrQ->length = 0;
    return PtrQ;
}

int IsFullQue(Queue Q) {
    if (Q->length == MAXSIZE)
        return TRUE;
    else
        return FALSE;
}

void AddQ(Queue PtrQ, BinTree BT) {
    if (IsFullQue(PtrQ) == TRUE) {
        printf("Operation Error!\nError Code %02x!\n", OVERFLOW);
        return;
    }
    if (IsEmptyQue(PtrQ) == TRUE) {
        struct Node *q = (struct Node *) malloc(sizeof(struct Node));
        q->TNode = BT;
        q->Next = NULL;
        PtrQ->front = q;
        PtrQ->rear = q;
        PtrQ->length++;
    } else {
        struct Node *q = (struct Node *) malloc(sizeof(struct Node));
        q->TNode = BT;
        q->Next = NULL;
        PtrQ->rear->Next = q;
        PtrQ->rear = q;
        PtrQ->length++;
    }
}

int IsEmptyQue(Queue Q) {
    if (Q->length == 0)
        return TRUE;
    else
        return FALSE;
}

BinTree DeleteQ(Queue PtrQ) {
    if (IsEmptyQue(PtrQ) == TRUE) {
        printf("Operation Error!\nError Code %02x!\n", INVALID);
        return NULL;
    } else {
        struct Node *q = PtrQ->front;

        // ElementType Data;
        struct TreeNode *PtrT = q->TNode;

        PtrQ->front = PtrQ->front->Next;
        PtrQ->length--;
        free(q);
        return PtrT;
    }
}
