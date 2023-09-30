#include <stdio.h>
#include <stdlib.h>

double * criaVetor(int dimensao);

void imprimeVetor(double *vetor, int dimensao);

int main(void) {
    int dimensao = 0;

    printf("Digite a dimensao do vetor: ");
    scanf("%d", &dimensao);

    printf("---Vetor 1---");
    double *vetor1 = criaVetor(dimensao);

    printf("---Vetor2---");
    double *vetor2 = criaVetor(dimensao);

    printf("Vetor 1: ");
    imprimeVetor(vetor1, dimensao);

    printf("\nVetor 2: ");
    imprimeVetor(vetor2, dimensao);

    printf("\nResultado da soma dos vetores:\n");
    for (int i = 0; i < dimensao; i++) {
        printf("%.2lf ", (*vetor1) + (*vetor2));
        vetor1++;
        vetor2++;
    }


    free(vetor1);
    free(vetor2);

    return EXIT_SUCCESS;
}

double * criaVetor(int dimensao) {
    double *vetor;

    printf("\nCriando vetor\n");

    vetor = (double *) malloc(dimensao * sizeof(double));
    if(vetor == NULL) exit(EXIT_FAILURE);

    for(int i = 0; i < dimensao; i++) {
        int n = 0;
        printf("Digite o %d numero do vetor: ", i+1);
        scanf("%d", &n);
        vetor[i] = n;
    }

    return vetor;
}

void imprimeVetor(double *vetor, int dimensao) {
    for(int i = 0; i < dimensao; i++) {
        printf(" %lf ", vetor[i]);
    }
}