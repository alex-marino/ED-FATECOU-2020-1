//
// Created by alexm on 07/06/2020.
//

#ifndef PILHA_LIST_H
#define PILHA_LIST_H
struct lista2 {
    int info;
    struct lista2 *ant;
    struct lista2 *prox;
};
typedef struct lista2 Lista2;

struct lista {
    int info;
    struct lista *prox;
};

typedef struct lista Lista;

typedef struct lista Lista;

Lista *lst_cria(void);

void lst_libera(Lista *l);

Lista *lst_insere(Lista *l, int i);

Lista *lst_retira(Lista *l, int v);

int lst_vazia(Lista *l);

Lista *lst_busca(Lista *l, int v);

void lst_imprime(Lista *l);


#endif //PILHA_LIST_H
