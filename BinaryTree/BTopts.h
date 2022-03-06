//
// Created by MSI-NB on 2022/2/15.
//

#ifndef BINARYTREE_BTOPTS_H
#define BINARYTREE_BTOPTS_H

#include "TreeNode.h"
#include "Stack.h"
#include "Queue.h"

// Previous Order Travel of Binary Tree
void PreOrderTravel(BinTree BT);

// In Order Travel of binary tree
void InOrderTravel(BinTree BT);

// In Order Travel of binary tree with non-recursion method
//void NonRecursionIOT(BinTree BT);

// Post Order travel of binary tree
void PostOrderTravel(BinTree BT);

// Level Order travel of binary tree
void LevelOrderTravel(BinTree BT);

// In Order Travel of binary tree (iteration)
int *inorderTra_ite(struct TreeNode *root, int *returnSize);


void inorder(struct TreeNode *root, int *arr, int *arrSize);

// In Order Travel of binary tree (recursion)
int *inorderTra_rec(struct TreeNode *root, int *returnSize);

// Visit elementtype data
void Visit(int num);

#endif //BINARYTREE_BTOPTS_H
