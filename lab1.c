#include "lab1.h"
#include <stdio.h>
#include <math.h>

void printRes(int* a, int c) {
    for(int i = 0; i < c; i++) {
        printf("Answer #%d: %d\n", i, a[i]);
    }
    return;
}

void decrypt(int* a, int c, int k) {
    printf("Result string: ");
    for(int i = 0; i < c; i++) {
        printf("%c", a[i]-k);
    }
    printf("\n");
    return;
}