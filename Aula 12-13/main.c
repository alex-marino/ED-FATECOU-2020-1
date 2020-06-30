#include <stdio.h>

#include "Sort.h"

int main() {
    printf("Hello, World!\n");
    int size, i;
    scanf("%d", &size);
    int arr[size];
    for (i=0; i<size; i++){
        scanf("%d", &arr[i]);
    }
    printArray(arr, size);
//    insertionSort(arr, size);
    selectionSort(arr, size);
    printArray(arr, size);
    return 0;
}
