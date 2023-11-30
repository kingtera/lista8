#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int valor;
    struct no *prox;
} No;

void insere_comeco(No **p, int x) {
    No *novoNo = (No *)malloc(sizeof(No));
    if (novoNo == NULL) {
        printf("Erro ao alocar memoria para o novo no.\n");
        return;
    }

    novoNo->valor = x;
    novoNo->prox = *p;

    *p = novoNo;
}

int main() {
    No *lista = (No *)malloc(sizeof(No));
    lista->valor = 2;
    lista->prox = NULL;

    int elemento = 1;
    insere_comeco(&lista, elemento);

    printf("Elementos da lista ligada:\n");
    while (lista != NULL) {
        printf("%d ", lista->valor);
        lista = lista->prox;
    }
    printf("\n");

    No *temp;
    while (lista != NULL) {
        temp = lista;
        lista = lista->prox;
        free(temp);
    }

    return 0;
}
