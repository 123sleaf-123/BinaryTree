//
// Created by MSI-NB on 2022/2/15.
//

#ifndef BINARYTREE_STACK_H
#define BINARYTREE_STACK_H

#include "TreeNode.h"

struct SNode{
    BinTree BT;
    struct SNode *Next;
};

typedef struct SNode* Stack;

// Create an empty stack the largest length of which is MAXSIZE.
Stack CreateStack();

// Judge whether stack S is full or not.
int IsFullStk(Stack PtrS);

// void Push(Stack S, ElementType item);
// Push element item into the stack.
void Push(Stack S, BinTree BT);

// Judge whether Stack S is empty or not.
int IsEmptyStk(Stack S);

// ElementType Pop(Stack S);
// Delete and return the top element of stack.
BinTree Pop(Stack S);

// void ShowList(Stack S);
#endif //BINARYTREE_STACK_H


#include <stdio.h>
#include <stdlib.h>
Stack CreateStack() {
    Stack PtrS = (Stack) malloc(sizeof(struct SNode));
    PtrS->Next = NULL;
    return PtrS;
}

int IsFullStk(Stack PtrS) {
    Stack p = PtrS;
    int i = 0;
    for (; p != NULL; p = p->Next, i++);
    if (i == MAXSIZE)
        return TRUE;
    else
        return FALSE;
}

void Push(Stack PtrS, BinTree BT) {
    if (IsFullStk(PtrS) == TRUE) {
        printf("Operation Failed!\nError Code %02x!\n", OVERFLOW);
        return;
    } else {
        Stack p = (Stack) malloc(sizeof(struct SNode));
        p->BT = BT;
        p->Next = PtrS;
        PtrS = p;
    }
}

int IsEmptyStk(Stack S) {
    if (S->Next == NULL)
        return TRUE;
    else
        return FALSE;
}

BinTree Pop(Stack PtrS) {
    if (IsEmptyStk(PtrS) == TRUE) {
        printf("Operation Failed!\nError Code %02x!\n", INVALID);
        return NULL;
    } else {
        Stack p = PtrS;
        BinTree BTree = p->BT;
        PtrS = p->Next;
        free(p);
        return BTree;
    }
}

