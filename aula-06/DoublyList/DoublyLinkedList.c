//
// Created by alexmarino on 13/04/2020.
//
#include <stdio.h>
#include <stdlib.h>
#include "DoublyLinkedList.h"

void DLLInsert(struct DLLNode **head, int data, int position) {
    int k=1;
    struct DLLNode *temp, *newNode;
    newNode = (struct DLLNode*) malloc(sizeof(struct DLLNode));
    if (!newNode){
        printf("Erro de memoria\n");
        return;
    }
    newNode->value=data;
    if(position==1){
        newNode->next=*head;
        newNode->prev=NULL;
        if (*head){
            (*head)->prev=newNode;
        }
        *head=newNode;
        return;
    }
    temp=*head;
    while((k<position-1)&&(temp->next!=NULL)){
        temp=temp->next;
        k++;
    }
    if (k!=position){
        printf("Posiçao informada nao existe\n");
    }
    newNode->next=temp->next;
    newNode->prev=temp;
    if(temp->next){
        temp->next->prev=newNode;
    }
    temp->next=newNode;
    return;

}




void DLLDelete(struct DLLNode **head, int position) {
    struct DLLNode *temp, *temp2;
    temp=*head;
    int k=1;
    if(*head==NULL){
        printf("Lista esta vazia\n");
        return;
    }
    if (position==1){
        *head=(*head)->next;
    }
    if ((*head)->prev==NULL){
        free(temp);
        return;
    }
    while((k<position)&&(temp->next!=NULL)){
        temp=temp->next;
        k++;
    }
    if (k!=position-1){
        printf("Posiçao informada nao existe!\n");
    }
    temp2=temp->prev;
    temp2->next=temp->next;
    if(temp->next){
        temp->next->prev=temp2;
    }
    free(temp);
    return;
}

