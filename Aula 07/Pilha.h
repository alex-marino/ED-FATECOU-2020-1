//
// Created by alexm on 07/06/2020.
//
#include "List.h"

#ifndef PILHA_PILHA_H
#define PILHA_PILHA_H
struct pilha {
    Lista* prim;
};
typedef struct pilha Pilha;

Pilha* pilha_cria (void);

void pilha_push (Pilha*, float);

float pilha_pop (Pilha*);

int pilha_vazia (Pilha*);

void pilha_libera (Pilha*);

void pilha_imprime(Pilha*);

float pilha_top (Pilha* P);

#endif //PILHA_PILHA_H
