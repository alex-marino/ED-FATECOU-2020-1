#include <stdio.h>
#include <stdlib.h>
//
// Created by alexmarino on 13/04/2020.
//


struct Node{
    int data;
    struct Node *next;
};

int ListSize(struct Node *head){
    struct Node *curr = head;
    int count = 0;

    while(curr!=NULL){
        count++;
        curr=curr->next;
    }
}

void InsertInLisnkedList(struct Node **head, int val, int position){
    int k=1;
    struct Node *p, *q, *newNode;
    newNode = (struct Node*) malloc(sizeof(struct Node));
    if (!newNode){
        printf("Erro de Memoria\n");
        return;
    }
    newNode->data = val;
    p=*head;
    if(position==1){//inserir no inicio
        newNode->next=p;
        *head=newNode;
    } else {
        while((p!=NULL)&&(k<position)){//percorre a lista ate achar p
            k++;
            q=p;
            p=p->next;
        }
        q->next=newNode;
        newNode->next=p;
    }
}

void DeleteFromLisnkedList(struct Node **head, int position){
    int k=1;
    struct Node *p, *q;
    if(*head==NULL){
        printf("Lista vazia\n");
        return;
    }
    p=*head;
    if (position=1){ //exclui primeiro no
        *head=(*head)->next;
        free(p);
        return;
    } else { //Percorre lista ate encontrar noh
        while ((p!=NULL) && (k<position)) {
            k++;
            q=p;
            p=p->next;
        }
        if (p==NULL){ //chegou ao ultimo noh
            printf("Posiçao nao existe!!");
        } else { //chegou ao noh
            q->next=p->next;
            free(p);
        }
    }
}

void DropLinkedList (struct Node **head){
    struct Node *aux, *iterator;
    iterator = *head;
    while(iterator){
        aux=iterator->next;
        free(iterator);
        iterator=aux;
    }
    *head=NULL;
}