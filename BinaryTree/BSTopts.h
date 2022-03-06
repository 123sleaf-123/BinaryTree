//
// Created by MSI-NB on 2022/2/17.
//

#ifndef BINARYTREE_BSTOPTS_H
#define BINARYTREE_BSTOPTS_H

#include "TreeNode.h"

// Find ElementType element X in binary search tree BST
Position Find(ElementType X, BinTree BST);

// Iteration way of Find function
Position IterFind(ElementType X, BinTree BST);

// Find the maximum element in BST
Position FindMax(BinTree BST);

// Find the pos of minimum element in BST
Position FindMin(BinTree BST);

// Insert a new element to a BST
BinTree Insert(ElementType X, BinTree BST);

// Delete an existing element from a BST
BinTree Delete(ElementType X, BinTree BST);

#endif //BINARYTREE_BSTOPTS_H
