#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int valor;
    struct no *prox;
} No;

void inverte_lista(No **p) {
    No *anterior = NULL;
    No *atual = *p;
    No *proximo = NULL;

    while (atual != NULL) {
        proximo = atual->prox;
        atual->prox = anterior;
        anterior = atual;
        atual = proximo;
    }

    *p = anterior;
}

int main() {
    No *lista = (No *)malloc(sizeof(No));
    lista->valor = 1;

    lista->prox = (No *)malloc(sizeof(No));
    lista->prox->valor = 2;

    lista->prox->prox = (No *)malloc(sizeof(No));
    lista->prox->prox->valor = 3;

    lista->prox->prox->prox = NULL;

    inverte_lista(&lista);

    printf("Lista invertida:\n");
    while (lista != NULL) {
        printf("%d ", lista->valor);
        No *temp = lista;
        lista = lista->prox;
        free(temp);
    }
    printf("\n");

    return 0;
}
