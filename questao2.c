#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int valor;
    struct no *prox;
} No;

int conta_lista(No *p) {
    int contador = 0;

    while (p != NULL) {
        contador++;
        p = p->prox;
    }

    return contador;
}

int main() {
    No *lista = (No *)malloc(sizeof(No));
    lista->valor = 1;

    lista->prox = (No *)malloc(sizeof(No));
    lista->prox->valor = 2;

    lista->prox->prox = (No *)malloc(sizeof(No));
    lista->prox->prox->valor = 3;

    lista->prox->prox->prox = NULL;

    int resultado = conta_lista(lista);

    printf("O numero de celulas na lista ligada e: %d\n", resultado);

    No *temp;
    while (lista != NULL) {
        temp = lista;
        lista = lista->prox;
        free(temp);
    }

    return 0;
}
