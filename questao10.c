#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int valor;
    struct no *prox;
} No;

No* uniao(No *p, No *q) {
    No *resultado = NULL;
    No *atual = NULL;

    while (p != NULL || q != NULL) {
        No *novoNo = (No *)malloc(sizeof(No));
        novoNo->prox = NULL;

        if (p != NULL && (q == NULL || p->valor < q->valor)) {
            novoNo->valor = p->valor;
            p = p->prox;
        } else if (q != NULL && (p == NULL || q->valor < p->valor)) {
            novoNo->valor = q->valor;
            q = q->prox;
        } else {
            novoNo->valor = p->valor;
            p = p->prox;
            q = q->prox;
        }

        if (resultado == NULL) {
            resultado = novoNo;
            atual = novoNo;
        } else {
            atual->prox = novoNo;
            atual = novoNo;
        }
    }

    return resultado;
}

int main() {
    No *lista1 = (No *)malloc(sizeof(No));
    lista1->valor = 1;

    lista1->prox = (No *)malloc(sizeof(No));
    lista1->prox->valor = 3;

    lista1->prox->prox = (No *)malloc(sizeof(No));
    lista1->prox->prox->valor = 5;

    lista1->prox->prox->prox = NULL;

    No *lista2 = (No *)malloc(sizeof(No));
    lista2->valor = 2;

    lista2->prox = (No *)malloc(sizeof(No));
    lista2->prox->valor = 4;

    lista2->prox->prox = (No *)malloc(sizeof(No));
    lista2->prox->prox->valor = 5;

    lista2->prox->prox->prox = NULL;

    No *resultado = uniao(lista1, lista2);

    printf("Lista resultante:\n");
    while (resultado != NULL) {
        printf("%d ", resultado->valor);
        No *temp = resultado;
        resultado = resultado->prox;
        free(temp);
    }
    printf("\n");

    return 0;
}
