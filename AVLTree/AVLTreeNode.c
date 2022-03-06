//
// Created by MSI-NB on 2022/3/6.
//

#include "AVLTreeNode.h"

int max(int a, int b) {
    return a > b ? a : b;
}

int GetHeight(AVLTree T) {
//    if (!T) return -1;
//    else {
//        int a = GetHeight(T->left);
//        int b = GetHeight(T->right);
//        T->height = (a > b ? a : b) + 1;
//        return T->height;
//        return (a > b ? a : b) + 1;
//    }
    if (!T) return 0;
    else return T->height;
}

AVLTree LeftRotation(AVLTree AVLT) {
    AVLTree temp = AVLT->right;
    AVLT->right = NULL;
    temp->left = AVLT;
    AVLT->height = max(GetHeight(AVLT->left), GetHeight(AVLT->right)) + 1;
    temp->height = max(GetHeight(temp->left), GetHeight(temp->right)) + 1;
    return temp;
}

AVLTree RightRotation(AVLTree AVLT) {
    AVLTree temp = AVLT->left;
    AVLT->left = NULL;
    temp->right = AVLT;
    AVLT->height = max(GetHeight(AVLT->left), GetHeight(AVLT->right)) + 1;
    temp->height = max(GetHeight(temp->left), GetHeight(temp->right)) + 1;
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

AVLTree AVLInsert(ElementType val, AVLTree AVLT) {
    if (!AVLT) {
        AVLT = (AVLTree) malloc(sizeof(struct AVLNode *));
        AVLT->data = val;
        AVLT->left = AVLT->right = NULL;
        AVLT->height = 0;
    }

        // AVLInsert val to the left son trees
    else if (val < AVLT->data) {
        AVLT->left = AVLInsert(val, AVLT->left);
        AVLT->height = max(GetHeight(AVLT->left), GetHeight(AVLT->right)) + 1;

        // Judge whether the tree should rotate or not
        if (abs(GetHeight(AVLT->left) - GetHeight(AVLT->right)) > 1) {
            if(val < AVLT->left->data) AVLT = RightRotation(AVLT);
            else AVLT = LeftRightRotation(AVLT);
        }
    }

        // AVLInsert val to the right son tree
    else if (val > AVLT->data) {
        AVLT->right = AVLInsert(val, AVLT->right);
        AVLT->height = max(GetHeight(AVLT->left), GetHeight(AVLT->right)) + 1;

        // Judge whether the tree should rotate or not
        if(abs(GetHeight(AVLT->left) - GetHeight(AVLT->right)) > 1) {
            if (val > AVLT->right->data) AVLT = LeftRotation(AVLT);
            else AVLT = RightLeftRotation(AVLT);
        }
    }

    return AVLT;
}

//AVLTree Delete(ElementType val, AVLTree AVLT) {
//    if (val != AVLT->data)
//}


