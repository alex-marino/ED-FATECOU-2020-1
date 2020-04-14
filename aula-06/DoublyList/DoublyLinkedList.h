//
// Created by alexmarino on 13/04/2020.
//
struct DLLNode{
    int value;
    struct DLLNode* next;
    struct DLLNode* prev;
};

#ifndef DOUBLYLIST_DOUBLYLINKEDLIST_H
#define DOUBLYLIST_DOUBLYLINKEDLIST_H
void DLLInsert(struct DLLNode **head, int data, int position);
void DLLDelete(struct DLLNode **head, int position);
#endif //DOUBLYLIST_DOUBLYLINKEDLIST_H
