cmake_minimum_required(VERSION 3.21)
project(BinaryTree C)

set(CMAKE_C_STANDARD 99)

add_executable(BinaryTree main.c BinaryTree/TreeNode.h BinaryTree/Stack.h BinaryTree/Queue.h BinaryTree/BTopts.h BinaryTree/BSTopts.h)
