#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

int main() {
    printf("Hello, World!\n");
    struct Node **myList = NULL;

    InsertInLisnkedList(&myList, 7, 1);
    InsertInLisnkedList(&myList, 2, 1);
    InsertInLisnkedList(&myList, 5, 1);
    InsertInLisnkedList(&myList, 9, 1);
    InsertInLisnkedList(&myList, 6, 1);
    ListSize(&myList);
    DeleteFromLisnkedList(&myList, 3);
    ListSize(&myList);
    InsertInLisnkedList(&myList, 43, 1);
    InsertInLisnkedList(&myList, 62, 4);
    InsertInLisnkedList(&myList, 77, 1);
    InsertInLisnkedList(&myList, 24, 6);
    ListSize(&myList);
    return 0;
}
