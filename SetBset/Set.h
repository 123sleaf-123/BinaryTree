//
// Created by MSI-NB on 2022/3/20.
//

#ifndef TREE_SET_H
#define TREE_SET_H

#define MaxSize 1000

typedef int ElementType;
typedef int rootName;
typedef ElementType SetType[MaxSize];

rootName FindR(SetType S, ElementType x);

void Union(SetType S, ElementType x1, ElementType x2);

#endif //TREE_SET_H
