//
// Created by MSI-NB on 2022/3/6.
//

#include "Stack.h"

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

