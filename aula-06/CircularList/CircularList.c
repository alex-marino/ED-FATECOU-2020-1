//
// Created by alexmarino on 13/04/2020.
//

#include <stdio.h>
#include <stdlib.h>
#include "CircularList.h"

int CircularListSize(struct CLLNode *head){
    struct CLLNode *current=head;
    int count=0;
    if(head==NULL){
        return 0;
    }
    do {
        current=current->next;
        count++;
    } while(current!=head);
    return count;
}

void InsertAtEndCircularList(struct CLLNode **head, int data){
    struct CLLNode *current = *head;
    struct CLLNode *newNode = (struct CLLNode*) malloc(sizeof(struct CLLNode));
    if (!newNode){
        printf("Erro de memoria!\n");
        return;
    }
    newNode->value=data;
    while(current->next!=*head){
        current=current->next;
    }
    newNode->next=newNode;
    if(*head==NULL){
        *head=newNode;
    }else{
        newNode->next=*head;
        current->next=newNode;
    }
}

void InsertAtBeginCLL(struct CLL **head, int data){
    struct CLLNode *current = *head;
    struct CLLNode *newNode = (struct CLLNode*) malloc(sizeof(struct CLLNode));
    if (!newNode){
        printf("Erro de memoria!\n");
        return;
    }
    newNode->value=data;
    while(current->next!=*head){
        current=current->next;
    }
    newNode->next=newNode;
    if(*head==NULL){
        *head=newNode;
    }else{
        newNode->next=*head;
        current->next=newNode;
        *head=newNode;
    }
    return;
}

void DeleteFrontNodeCLL(struct CLLNode **head){
    struct CLLNode *temp = *head;
    struct CLLNode *current=*head;
    if (*head==NULL){
        printf("Lista Vazia!\n");
        return;
    }
    while(current->next!=*head){
        current=current->next;
    }
    current->next=(*head)->next;
    *head=(*head)->next;
    free(temp);
    return;
}