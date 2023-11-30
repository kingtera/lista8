#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int valor;
    struct no *prox;
} No;

No *inserirNo(No *lista, int valor) {
    No *novoNo = (No *)malloc(sizeof(No));
    novoNo->valor = valor;
    novoNo->prox = NULL;

    if (lista == NULL) {
        lista = novoNo;
    } else {
        No *temp = lista;
        while (temp->prox != NULL) {
            temp = temp->prox;
        }
        temp->prox = novoNo;
    }

    return lista;
}

void imprimirLista(No *lista) {
    printf("Elementos da lista ligada:\n");
    while (lista != NULL) {
        printf("%d ", lista->valor);
        lista = lista->prox;
    }
    printf("\n");
}

int main() {
    No *lista = NULL; 

    int valor;

    printf("Digite os inteiros (digite -1 para encerrar):\n");
    while (1) {
        scanf("%d", &valor);
        if (valor == -1) {
            break; 
        }
        lista = inserirNo(lista, valor);
    }

    imprimirLista(lista);

    No *temp;
    while (lista != NULL) {
        temp = lista;
        lista = lista->prox;
        free(temp);
    }

    return 0;
}