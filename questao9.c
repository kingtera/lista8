#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int valor;
    struct no *prox;
} No;

void insere_ordenado(No **p, int x) {
    No *novoNo = (No *)malloc(sizeof(No));
    novoNo->valor = x;
    novoNo->prox = NULL;

    if (*p == NULL || x <= (*p)->valor) {
        novoNo->prox = *p;
        *p = novoNo;
        return;
    }

    No *atual = *p;
    while (atual->prox != NULL && atual->prox->valor < x) {
        atual = atual->prox;
    }

    novoNo->prox = atual->prox;
    atual->prox = novoNo;
}

int main() {
    No *lista = (No *)malloc(sizeof(No));
    lista->valor = 1;

    lista->prox = (No *)malloc(sizeof(No));
    lista->prox->valor = 3;

    lista->prox->prox = (No *)malloc(sizeof(No));
    lista->prox->prox->valor = 5;

    lista->prox->prox->prox = NULL;

    int elemento = 4;
    insere_ordenado(&lista, elemento);

    printf("Lista ordenada:\n");
    while (lista != NULL) {
        printf("%d ", lista->valor);
        No *temp = lista;
        lista = lista->prox;
        free(temp);
    }
    printf("\n");

    return 0;
}
