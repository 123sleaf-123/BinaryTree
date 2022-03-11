#include <stdio.h>
//#include "BinaryTree/BTopts.h"
#include "AVLTree/AVLTreeNode.h"
#include "Heap/MaxHeap.h"
#include "print.h"

int main() {
    printf("Hello, World!\n");
    int i = 1;
    switch (i) {

        case 0:
        {
            AVLTree T;
            for (int i = 0; i < 10; ++i) {
                T = AVLInsert((9 - i), T);
            }
            break;
        }

        case 1:
        {
            MaxHeap H = CreateHeap(10);
            for (int j = 0; j < H->capacity; ++j) {
                HeapInsert(j, H);
            }
            for (int j = 0; j < H->size; ++j) {
                printI(H->elements, H->size, 1);
                DeleteMax(H);
            }
            break;
        }
    }
    return 0;
}
