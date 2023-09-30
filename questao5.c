#include <stdio.h>
#include <stdlib.h>

int *criaVetor(int dimensao);

int *uniao(int *v1, int n1, int *v2, int n2);

int main(void) {
    int tamanho1 = 0;
    int tamanho2 = 0;

    printf("Digite o tamanho do vetor 1: ");
    scanf("%d", &tamanho1);
    printf("---Vetor 1---");
    int *vetor1 = criaVetor(tamanho1);

    printf("Digite o tamanho do vetor 2: ");
    scanf("%d", &tamanho2);
    printf("---Vetor2---");
    int *vetor2 = criaVetor(tamanho2);

    int *vetorResultante = uniao(vetor1, tamanho1, vetor2, tamanho2);
    
    for(int i = 0; i < tamanho1 + tamanho2; i++) {
        printf(" %d ", vetorResultante[i]);
    }

    free(vetor1);
    free(vetor2);
    free(vetorResultante);


    return EXIT_SUCCESS;
}

int *uniao(int *v1, int n1, int *v2, int n2) {
    int *vetor;
    vetor = (int *) malloc((n1 + n2) * sizeof(int));
    if(vetor == NULL) exit(EXIT_FAILURE);

    int i = 0;
    int j = 0;
    while(i < (n1 + n2)) {
        if(j < n1) {
            vetor[j] = v1[j];
        } else {
            vetor[j] = v2[j - n1];
        }

        i++;
        j++;
    }

    return vetor;
}

int * criaVetor(int dimensao) {
    int *vetor;

    printf("\nCriando vetor\n");

    vetor = (int *) malloc(dimensao * sizeof(int));
    if(vetor == NULL) exit(EXIT_FAILURE);

    for(int i = 0; i < dimensao; i++) {
        int n = 0;
        printf("Digite o %d numero do vetor: ", i+1);
        scanf("%d", &n);
        vetor[i] = n;
    }

    return vetor;
}