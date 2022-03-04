#include <stdio.h>
//#include "BinaryTree/BTopts.h"
#include "AVLTree/AVLTreeNode.h"

int main() {
    printf("Hello, World!\n");
    int i = 0;
    switch (i) {
        case 0: {
            AVLTree T;
            for (int i = 0; i < 10; ++i) {
                T = Insert((9 - i), T);
            }
            break;
        }
        case 1: break;
    }
    return 0;
}
