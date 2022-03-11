//
// Created by MSI-NB on 2022/3/11.
//

#include "print.h"

char *printI(int *arr, int arrSize, int head) {
    char str[100] = {'['};
    for (int k = head; k < arrSize; ++k) {
        char temp[12];
        itoa(arr[k], temp, 10);
        strcat(str, temp);
        if (k + 1 != arrSize) strcat(str, ", ");
    }
    strcat(str, "]");
    printf("%s\n", str);

    return str;
}

//char *printF(float *arr, int arrSize, int head) {
//    char str[100] = {'['};
//    for (int k = head; k < arrSize; ++k) {
//        char temp[12];
//        itoa(arr[k], temp, 10);
//        strcat(str, temp);
//        if (k + 1 != arrSize) strcat(str, ", ");
//    }
//    strcat(str, "]");
//    printf("%s\n", str);
//
//    return 0;
//}
