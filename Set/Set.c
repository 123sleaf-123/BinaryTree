//
// Created by MSI-NB on 2022/3/20.
//

#include "Set.h"
#include <stdio.h>

root FindR(SetType *S, ElementType x) {
    int i;
    for (i = 0; i < MaxSize && S[i].data != x; ++i);
    if ((i >= MaxSize)) return -1;
    for (; i >= 0; i = S[i].parent);
    return i;
}

void Union(SetType *S, ElementType x1, ElementType x2) {
    int root1 = FindR(S, x1);
    int root2 = FindR(S, x2);
    int size = S[root1].parent + S[root2].parent;
    if (S[root1].parent < S[root2].parent) {
        S[root1].parent = size;
        S[root2].parent = root1;
    } else {
        S[root2].parent = size;
        S[root1].parent = root2;
    }
}
