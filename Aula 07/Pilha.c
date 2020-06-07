//
// Created by alexm on 07/06/2020.
//
#include <stdlib.h>
#include <stdio.h>
#include "Pilha.h"

Pilha *pilha_cria(void) {
    Pilha *p = (Pilha *) malloc(sizeof(Pilha));
    p->prim = NULL;
    return p;
}

float pilha_pop(Pilha *p) {
    Lista *t;
    float v;
    if (pilha_vazia(p)) {
        printf("Pilha vazia.\n");
        /* aborta programa */
        exit(1);
    }
    t = p->prim;
    v = t->info;
    p->prim = t->prox;
    free(t);
    return v;
}

void pilha_libera(Pilha *p) {
    Lista *q = p->prim;
    while (q != NULL) {
        Lista *t = q->prox;
        free(q);
        q = t;
    }
    free(p);
}

void pilha_push(Pilha *p, float v) {
    p->prim = lst_insere(p->prim, v);
}

int pilha_vazia(Pilha *P) {
    return (P == NULL);
}

void pilha_imprime(Pilha *P) {
    lst_imprime(P->prim);
}

float pilha_top(Pilha *P) {
    if (!pilha_vazia(P)) {
        return P->prim->info;
    } else {
        exit(1);
    }

}


