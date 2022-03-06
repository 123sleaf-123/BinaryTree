//
// Created by MSI-NB on 2022/2/26.
//

#ifndef TREE_AVLTREENODE_H
#define TREE_AVLTREENODE_H

#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct AVLNode *Position;
typedef Position AVLTree;
struct AVLNode {
    ElementType data;
    AVLTree left;
    AVLTree right;
    int height;
};

int max(int a, int b);

int GetHeight(AVLTree T);

AVLTree LeftRotation(AVLTree AVLT);

AVLTree RightRotation(AVLTree AVLT);

AVLTree LeftRightRotation(AVLTree AVLT);

AVLTree RightLeftRotation(AVLTree AVLT);

AVLTree Insert(ElementType val, AVLTree AVLT);

AVLTree Delete(ElementType val, AVLTree AVLT);

#endif //TREE_AVLTREENODE_H
