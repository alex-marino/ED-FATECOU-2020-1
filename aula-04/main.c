#include <stdio.h>
#include "MyRecFunctions.h"

int main() {
    //int n;
    //scanf("%d", &n);
    //printf("Fatorial de n = %lld", fatorialRec(n));

    //int n, l;
    //scanf("%d %d", &n, &l);
    //drawRuller(n, 3);

    int n;
    scanf("%d", &n);
    int data[10] = {0, 1, 3, 4, 7, 9, 13, 21, 72, 102};
    if (binarySearch(data, n, 0, 9)){
        printf("O numero n = %d encontra-se no array!!\n");
    } else{
        printf("O numero n = %d nao encontra-se no array!!\n");
    }


    return 0;
}
