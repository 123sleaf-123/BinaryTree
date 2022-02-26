//
// Created by MSI-NB on 2022/2/15.
//

#ifndef BINARYTREE_QUEUE_H
#define BINARYTREE_QUEUE_H
#include "TreeNode.h"

typedef struct QNode* Queue;
struct Node{
    // ElementType Data
    struct TreeNode* TNode;
    struct Node *Next;
};

// Linked queue structure
struct QNode {
    // Point to the head node of queue
    struct Node *front;

    // point to the tail node of queue
    struct Node *rear;
    int length;
};
// Struct QNode Q;
// Queue PtrQ;

// Create an empty queue, the largest length of which is MAXSIZE.
Queue CreateQueue();

// Judge whether Queue Q is full or not.
int IsFullQue(Queue Q);

// void AddQ(Queue Q, ElementType item);
// Insert element data item into the Queue.
void AddQ(Queue Q, BinTree BT);

// Judge whether Queue Q is empty or not.
int IsEmptyQue(Queue Q);

// ElementType DeleteQ(Queue Q);
// Delete and return the front element of queue.
BinTree DeleteQ(Queue Q);

// void ShowList(Queue Q);
#endif //BINARYTREE_QUEUE_H


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