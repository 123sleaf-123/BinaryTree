//
// Created by MSI-NB on 2022/3/20.
//

#include "Set.h"
#include <stdio.h>

rootName FindR(SetType S, ElementType x) {
    for (; S[x] >= 0; x = S[x]);
    return x;
}

void Union(SetType S, ElementType x1, ElementType x2) {
    rootName root1 = FindR(S, x1);
    rootName root2 = FindR(S, x2);
    if (S[root1] < S[root2]) {
        S[root1] += S[root2];
        S[root2] = root1;
    } else {
        S[root2] += S[root1];
        S[root1] = root2;
    }
}
