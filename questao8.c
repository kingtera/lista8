#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int valor;
    struct no *prox;
} No;

void concatena(No **p, No **q) {
    if (*p == NULL) {
        *p = *q;
    } else {
        No *temp = *p;
        while (temp->prox != NULL) {
            temp = temp->prox;
        }
        temp->prox = *q;
    }

    *q = NULL;
}

int main() {
    No *lista1 = (No *)malloc(sizeof(No));
    lista1->valor = 1;

    lista1->prox = (No *)malloc(sizeof(No));
    lista1->prox->valor = 2;

    lista1->prox->prox = (No *)malloc(sizeof(No));
    lista1->prox->prox->valor = 3;

    lista1->prox->prox->prox = NULL;

    No *lista2 = (No *)malloc(sizeof(No));
    lista2->valor = 4;

    lista2->prox = (No *)malloc(sizeof(No));
    lista2->prox->valor = 5;

    lista2->prox->prox = (No *)malloc(sizeof(No));
    lista2->prox->prox->valor = 6;

    lista2->prox->prox->prox = NULL;

    concatena(&lista1, &lista2);

    printf("Lista concatenada:\n");
    while (lista1 != NULL) {
        printf("%d ", lista1->valor);
        No *temp = lista1;
        lista1 = lista1->prox;
        free(temp);
    }
    printf("\n");

    return 0;
}
