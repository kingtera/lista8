#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int valor;
    struct no *prox;
} No;

void remove_lista(No **p, int x) {
    No *atual = *p;
    No *anterior = NULL;

    while (atual != NULL) {
        if (atual->valor == x) {
            if (anterior == NULL) {
                *p = atual->prox;
            } else {
                anterior->prox = atual->prox;
            }

            free(atual);
            return;
        }

        anterior = atual;
        atual = atual->prox;
    }
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
    remove_lista(&lista, elemento);

    printf("Elementos da lista ligada:\n");
    while (lista != NULL) {
        printf("%d ", lista->valor);
        No *temp = lista;
        lista = lista->prox;
        free(temp);
    }
    printf("\n");

    return 0;
}
