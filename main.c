#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>
#include "lab1.h"



int main(int argc, char** argv) {
    int k = -1;
    char *locale = setlocale(LC_ALL, "Rus");
    //Checks
    if(argc%3) {
        printf("Incorrect number of arguments\n");
        return 1;
    }
    for(int i = 1; i < argc; i++) {
        if(strstr(argv[i], "-k") != 0) {
            k = atoi(argv[i+1]);
        }
    }
    if(k == -1) {
        printf("Incorrect flag or no flag found");
        return 1;
    }
    //Result
    int* results = (int*)malloc(sizeof(int) * (argc/3-1));

    int r = 0, temp = 0;
    for(int i = 1; i < argc-2; i = i+3) {
        int a1, a2;
        char operator;
        a1 = atoi(argv[i]);
        a2 = atoi(argv[i+2]);
        operator = *argv[i+1];

        if(a1==0 || a2 == 0) {
            printf("Incorrect operand\n");
            return 1;
        }

        switch (operator) {
        case '+':
            results[r] = a1+a2;
            break;
        case '-':
            results[r] = a1-a2;
            break;
        case '*':
            results[r] = a1*a2;
            break;
        case '%':
            results[r] = a1%a2;
            break;
        default:
            printf("Incorrect operator\n");
            return 1;
            break;
        }
        r++;
    }

    return 0;
}