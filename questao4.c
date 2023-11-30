#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int valor;
    struct no *prox;
} No;

No* busca_lista(No **p, int x) {
    No *atual = *p;

    while (atual != NULL) {
        if (atual->valor == x) {
            return atual;
        }
        atual = atual->prox;
    }

    return NULL;
}

int main() {
    No *lista = (No *)malloc(sizeof(No));
    lista->valor = 1;

    lista->prox = (No *)malloc(sizeof(No));
    lista->prox->valor = 2;

    lista->prox->prox = (No *)malloc(sizeof(No));
    lista->prox->prox->valor = 3;

    lista->prox->prox->prox = NULL;

    int elemento = 2;
    No *resultado = busca_lista(&lista, elemento);

    if (resultado != NULL) {
        printf("Elemento %d encontrado na lista.\n", elemento);
    } else {
        printf("Elemento %d nao encontrado na lista.\n", elemento);
    }

    while (lista != NULL) {
        No *temp = lista;
        lista = lista->prox;
        free(temp);
    }

    return 0;
}
