//
// Created by MSI-NB on 2022/3/6.
//

#include "BTopts.h"

// Previous Order Travel of Binary Tree
void PreOrderTravel(BinTree BT) {
    if (BT) {
        Visit(BT->Data);
        PreOrderTravel(BT->Left);
        PreOrderTravel(BT->Right);
    }
}

// In Order Travel of binary tree
void InOrderTravel(BinTree BT) {
    if (BT) {
        InOrderTravel(BT->Left);
        Visit(BT->Data);
        InOrderTravel(BT->Right);
    }
}

// In Order Travel of binary tree with non-recursion method
//void NonRecursionIOT(BinTree BT) {
//    BinTree BTree;
//    Stack S;
//    S = CreateStack();
//    Push(S, BT);
//    while (!IsEmptyStk(S)) {
//        if (BT->Left) {
//
//        }
//    }
//}

// Post Order travel of binary tree
void PostOrderTravel(BinTree BT) {
    if (BT) {
        PostOrderTravel(BT->Left);
        PostOrderTravel(BT->Right);
        Visit(BT->Data);
    }
}

// Level Order travel of binary tree
void LevelOrderTravel(BinTree BT) {
    Queue Q;
    BinTree T;
    if (!BT) {
        return;
    }
    Q = CreateQueue();
    AddQ(Q, BT);
    while (!IsEmptyQue(Q)) {
        T = DeleteQ(Q);
        Visit(T->Data);
        if (T->Left) {
            AddQ(Q, T->Left);
        }
        if (T->Right) {
            AddQ(Q, T->Right);
        }
    }
}

int *inorderTra_ite(struct TreeNode *root, int *returnSize) {
    int *arr = (int *) malloc(sizeof(int) * 101);
    *returnSize = 0;
    int top = 0;
    struct TreeNode **stk = (struct TreeNode **) malloc(sizeof(struct TreeNode *) * 101);
    while (root != NULL || top > 0) {
        while (root != NULL) {
            stk[top++] = root;
            root = root->Left;
        }
        root = stk[--top];
        arr[(*returnSize)++] = root->Data;
        root = root->Right;
    }
    return arr;
}

void inorder(struct TreeNode *root, int *arr, int *arrSize) {
    if (!root) {
        return;
    }
    inorder(root->Left, arr, arrSize);
    arr[(*arrSize)++] = root->Data;
    inorder(root->Right, arr, arrSize);
}

int *inorderTra_rec(struct TreeNode *root, int *returnSize) {
    int *arr = (int *) malloc(sizeof(int) * 101);
    *returnSize = 0;
    inorder(root, arr, returnSize);
    return arr;
}

void Visit(int num) {
    printf("%d", num);
}
