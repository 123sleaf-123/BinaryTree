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

AVLTree LeftRotation(AVLTree AVLT);

AVLTree RightRotation(AVLTree AVLT);

AVLTree LeftRightRotation(AVLTree AVLT);

AVLTree RightLeftRotation(AVLTree AVLT);

AVLTree Insert(ElementType val, AVLTree AVLT);

int max(int a, int b) {
    return a > b ? a : b;
}

AVLTree LeftRotation(AVLTree AVLT) {
    AVLTree temp = AVLT->right;
    AVLT->right = NULL;
    temp->left = AVLT;
    AVLT->height = AVLT->left->height + 1;
    temp->height = max(temp->left->height, temp->right->height) + 1;
    return temp;
}

AVLTree RightRotation(AVLTree AVLT) {
    AVLTree temp = AVLT->left;
    AVLT->left = NULL;
    temp->right = AVLT;
    AVLT->height = AVLT->right->height + 1;
    temp->height = max(temp->left->height, temp->right->height) + 1;
    return temp;
}

AVLTree LeftRightRotation(AVLTree AVLT) {
    AVLT->left = LeftRotation(AVLT->left);
    return RightRotation(AVLT);
}

AVLTree RightLeftRotation(AVLTree AVLT) {
    AVLT->right = RightRotation(AVLT->right);
    return LeftRotation(AVLT);
}

AVLTree Insert(ElementType val, AVLTree AVLT) {
    if (!AVLT) {
        AVLT = (AVLTree) malloc(sizeof(struct AVLNode *));
        AVLT->data = val;
        AVLT->left = AVLT->right = NULL;
        AVLT->height = 0;
    }

    // Insert val to the left son trees
    if (val < AVLT->data) {
        AVLT->left = Insert(val, AVLT->left);

        // Judge whether the tree should rotate or not
        if (abs(AVLT->left->height - AVLT->right->height) > 1) {
            if(val < AVLT->left->data) AVLT = RightRotation(AVLT);
            else AVLT = LeftRightRotation(AVLT);
        }
    }

    // Insert val to the right son tree
    if (val > AVLT->data) {
        AVLT->right = Insert(val, AVLT->right);

        // Judge whether the tree should rotate or not
        if(abs(AVLT->left->height - AVLT->right->height) > 1) {
            if (val > AVLT->right->data) AVLT = LeftRotation(AVLT);
            else AVLT = RightLeftRotation(AVLT);
        }
    }
}

#endif //TREE_AVLTREENODE_H
