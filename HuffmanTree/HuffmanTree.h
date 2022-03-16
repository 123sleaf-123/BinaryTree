//
// Created by MSI-NB on 2022/3/16.
//

#ifndef TREE_HUFFMANTREE_H
#define TREE_HUFFMANTREE_H

#include "HeapForHuffmanTree.h"

typedef struct HTreeNode* HuffmanTree;
struct HTreeNode {
    int weight;
    HuffmanTree left, right;
};

HuffmanTree Huffman(MinHeap MH);

#endif //TREE_HUFFMANTREE_H
