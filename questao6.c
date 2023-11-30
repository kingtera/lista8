#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int valor;
    struct no *prox;
} No;

No* extrai_pares(No *p) {
    No *novaLista = NULL;
    No *ultimoPar = NULL;

    while (p != NULL) {
        if (p->valor % 2 == 0) {
            No *novoNo = (No *)malloc(sizeof(No));
            if (novoNo == NULL) {
                // Tratamento de erro na alocação de memória
                printf("Erro ao alocar memoria para o novo no.\n");
                return NULL;
            }

            novoNo->valor = p->valor;
            novoNo->prox = NULL;

            if (novaLista == NULL) {
                novaLista = novoNo;
                ultimoPar = novoNo;
            } else {
                ultimoPar->prox = novoNo;
                ultimoPar = novoNo;
            }
        }

        p = p->prox;
    }

    return novaLista;
}

int main() {
    No *lista = (No *)malloc(sizeof(No));
    lista->valor = 1;

    lista->prox = (No *)malloc(sizeof(No));
    lista->prox->valor = 2;

    lista->prox->prox = (No *)malloc(sizeof(No));
    lista->prox->prox->valor = 3;

    lista->prox->prox->prox = NULL;

    No *listaPares = extrai_pares(lista);

    printf("Lista original:\n");
    while (lista != NULL) {
        printf("%d ", lista->valor);
        No *temp = lista;
        lista = lista->prox;
        free(temp);
    }
    printf("\n");

    printf("Lista de pares:\n");
    while (listaPares != NULL) {
        printf("%d ", listaPares->valor);
        No *temp = listaPares;
        listaPares = listaPares->prox;
        free(temp);
    }
    printf("\n");

    return 0;
}
