//
// Created by MSI-NB on 2022/3/6.
//

#include "BSTopts.h"

Position Find(int X, BinTree BST) {
    if (!BST) { return NULL; }
    if (X == BST->Data) {
        return BST;
    }
    if (X < BST->Data) {
        return Find(X, BST->Left);
    }
    if (X > BST->Data) {
        return Find(X, BST->Right);
    }
}

Position IterFind(int X, BinTree BST) {
    while (BST) {
//        if (!BST) break;
        if (X < BST->Data) {
            BST = BST->Left;
        } else if (X > BST->Data) {
            BST = BST->Right;
        } else return BST;
    }
    return NULL;
}

Position FindMax(BinTree BST) {
    if (!BST) return NULL;
    while (BST->Right) {
        BST = BST->Right;
    }
    return BST;
}

Position FindMin(BinTree BST) {
    if (!BST) return NULL;
    while (BST->Left) {
        BST = BST->Left;
    }
//    Something mistakes here... I will visit and return the NULL pointer eventually
//    while (BST) {
//        BST = BST->Left;
//    }
    return BST;
}

BinTree Insert(int X, BinTree BST) {
    if (!BST) {
        BST = (BinTree) malloc(sizeof(BinTree));
        BST->Data = X;
        BST->Left = BST->Right = NULL;
    } else if (X < BST->Data) {
        BST->Left = Insert(X, BST->Left);
    } else if (X > BST->Data) {
        BST->Right = Insert(X, BST->Right);
    }
//    If X has already existed, we do nothing.
//    else
//        printf("%d has already existed in BST", X);
    return BST;
}

BinTree Delete(int X, BinTree BST) {
    Position temp;
    if (!BST) printf("Element %d not found.", X);
    else if (X < BST->Data) {
        BST->Left = Delete(X, BST->Left);
    } else if (X > BST->Data) {
        BST->Right = Delete(X, BST->Right);
    } else {
        if (BST->Left && BST->Right) {
            temp = FindMax(BST->Left);
            BST->Data = temp->Data;
            BST->Left = Delete(BST->Data, BST->Left);
        } else {
            temp = BST;
            if (!BST->Left) {
                BST = BST->Right;
            } else if (!BST->Right) {
                BST = BST->Left;
            }
            free(temp);
        }
    }
    return BST;
}

