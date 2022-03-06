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
