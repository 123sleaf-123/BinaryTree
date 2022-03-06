//
// Created by MSI-NB on 2022/2/15.
//

#ifndef BINARYTREE_TREENODE_H
#define BINARYTREE_TREENODE_H

#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 1000
#define ElementType int

#define TRUE 1
#define FALSE 0

#define NONVOID 0
#define OVERFLOW 1
#define NONDEFINE 2
#define INVALID 3
#define NOTFOUND 404
typedef struct TreeNode *BinTree;
typedef BinTree Position;
struct TreeNode {
    ElementType Data;
    BinTree Left;
    BinTree Right;
};
#endif //BINARYTREE_TREENODE_H
