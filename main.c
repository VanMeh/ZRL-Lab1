#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>
#include "lab1.h"



int main(int argc, char** argv) {
    long k = -1;
    char* end;
    //Checks
    if(argc%3) {
        printf("Incorrect number of arguments\n");
        return 1;
    }
    for(int i = 1; i < argc; i++) {
        if(strstr(argv[i], "-k") != 0) {
            k = strtol(argv[i+1], &end, 10);
            if(end == argv[i+1] || *end != '\0') {
                printf("Incorrect value of k");
                return 1;
            }
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
        a1 = strtol(argv[i], &end, 10);
        if(end == argv[i] || *end != '\0') {
            printf("Incorrect operand");
            return 1;
        }
        a2 = strtol(argv[i+2], &end, 10);
        if(end == argv[i+2] || *end != '\0') {
            printf("Incorrect operand");
            return 1;
        }
        operator = *argv[i+1];


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

    printRes(results, (argc/3-1));
    decrypt(results, (argc/3-1), k);
    return 0;
}