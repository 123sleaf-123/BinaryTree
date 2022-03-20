cmake_minimum_required(VERSION 3.21)
project(Tree C)

set(CMAKE_C_STANDARD 99)

add_executable(Tree main.c BinaryTree/TreeNode.h BinaryTree/Stack.h BinaryTree/Queue.h BinaryTree/BTopts.h BinaryTree/BSTopts.h AVLTree/AVLTreeNode.h AVLTree/AVLTreeNode.c BinaryTree/Queue.c BinaryTree/Stack.c BinaryTree/BSTopts.c BinaryTree/BTopts.c Heap/Heap.c Heap/Heap.h print.c print.h HuffmanTree/HuffmanTree.c HuffmanTree/HuffmanTree.h HuffmanTree/HeapForHuffmanTree.c HuffmanTree/HeapForHuffmanTree.h Set/Set.c Set/Set.h SetBset/FileTransfer.c SetBset/FileTransfer.h)
