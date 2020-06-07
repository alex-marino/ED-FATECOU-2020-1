//
// Created by alexm on 07/06/2020.
//
#include <stdio.h>
#include <stdlib.h>
#include "List.h"

/* inserção no início: retorna a lista atualizada */
Lista2 *lst2_insere(Lista2 *l, int v) {
    Lista2 *novo = (Lista2 *) malloc(sizeof(Lista2));
    novo->info = v;
    novo->prox = l;
    novo->ant = NULL;
    /* verifica se lista não estava vazia */
    if (l != NULL)
        l->ant = novo;
    return novo;
}

/* função imprime: imprime valores dos elementos */
void lcirc_imprime(Lista *l) {
    Lista *p = l;
    /* faz p apontar para o nó inicial */
    /* testa se lista não é vazia e então percorre com do-while */
    if (p)
        do {
            printf("%d\n", p->info); /* imprime informação do nó */
            p = p->prox;
            /* avança para o próximo nó */
        } while (p != l);
}

/* função busca: busca um elemento na lista */
Lista *busca(Lista *l, int v) {
    Lista *p;
    for (p = l; p != NULL; p = p->prox) {
        if (p->info == v)
            return p;
    }
    /* não achou o elemento */
    return NULL;
}

/* função de criação: retorna uma lista vazia */
Lista *lst_cria(void) {
    return NULL;
}

void lst_libera(Lista *l) {
    Lista *p = l;
    while (p != NULL) {
        Lista *t = p->prox;
        free(p);
        p = t;
    }
}


/* inserção no início: retorna a lista atualizada */
Lista *lst_insere(Lista *l, int i) {
    Lista *novo = (Lista *) malloc(sizeof(Lista));
    novo->info = i;
    novo->prox = l;
    return novo;
}

/* função insere_ordenado: insere elemento em ordem */
Lista *lst_insere_ordenado(Lista *l, int v) {
    Lista *novo;
    /* ponteiro para elemento anterior */
    Lista *ant = NULL;
    Lista *p = l;
    /* ponteiro para percorrer a lista */
    /* procura posição de inserção */
    while (p != NULL && p->info < v) {
        ant = p;
        p = p->prox;
    }
    /* cria novo elemento */
    novo = (Lista *) malloc(sizeof(Lista));
    novo->info = v;
    /* encadeia elemento */
    if (ant == NULL) { /* insere elemento no início */
        novo->prox = l;
        l = novo;
    } else { /* insere elemento no meio da lista */
        novo->prox = ant->prox;
        ant->prox = novo;
    }
    return l;
}

/* função imprime: imprime valores dos elementos */
void lst_imprime(Lista *l) {
    Lista *p;
    for (p = l; p != NULL; p = p->prox)
        printf("info = %d\n", p->info);
}

/* função retira: retira elemento da lista */
Lista *lst_retira(Lista *l, int v) {
    /* ponteiro para elemento anterior*/
    Lista *ant = NULL;
    Lista *p = l;
    /* ponteiro para percorrer a lista */
    /* procura elemento na lista, guardando anterior */
    while (p != NULL && p->info != v) {
        ant = p;
        p = p->prox;
    }
    /* verifica se achou elemento */
    if (p == NULL)
        /* não achou: retorna lista original */
        return l;
    /* retira elemento */
    if (ant == NULL) {
        /* retira elemento do inicio */
        l = p->prox;
    } else {
        /* retira elemento do meio da lista */
        ant->prox = p->prox;
    }
    free(p);
    return l;
}

/* função vazia: retorna 1 se vazia ou 0 se não vazia */
int lst_vazia(Lista *l) {
    return (l == NULL);
}




