#include <stdio.h>
#include "Pilha.h"
#include "List.h"

int main() {
    Lista *l;
    l = lst_cria();
    l = lst_insere(l, 23);
    l = lst_insere(l, 45);
    lst_imprime(l);
    printf("-------------\n");
    Pilha *P = pilha_cria();
    pilha_push(P, 14.0);
    pilha_push(P, 15.0);
    pilha_push(P, 16.0);
    pilha_push(P, 17.0);
    pilha_pop(P);
    pilha_push(P, 18.0);
    pilha_push(P, 19.0);
    pilha_push(P, 20.0);
    pilha_imprime(P);

    return 0;
}
