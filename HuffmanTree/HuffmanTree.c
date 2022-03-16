//
// Created by MSI-NB on 2022/3/16.
//

#include "HuffmanTree.h"

HuffmanTree Huffman(MinHeap MH) {
    HuffmanTree HT;
    for (int i = 0; i < MH->size; ++i) {
        HT = (HuffmanTree) malloc(sizeof(struct HTreeNode*));

//        Delete and take out the two Huffman Tree node whose weight is the smallest two
//        from the given minimum heap.
//        Then the two nodes become the lef and right child of the targeted Huffman Tree node
        HT->left = DeleteMin(MH);
        HT->right = DeleteMin(MH);

//        Calculate the sum of children's weights, stores and add the node back to the minimum heap
        HT->weight = HT->left->weight + HT->right->weight;
        MinHeapInsert(HT, MH);
    }

//    Return the root node as the result
    return MH->elements[1];
}
