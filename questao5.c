#include <stdio.h>
#include <stdlib.h>

double * criaVetor(int dimensao);

int *uniao(int *v1, int n1, int *v2, int n2);

int main(void) {
    int n = 0;

    printf("Digite o tamanho do vetor: ");
    scanf("%d", &n);

    printf("---Vetor 1---");
    double *vetor1 = criaVetor(n);

    printf("---Vetor2---");
    double *vetor2 = criaVetor(n);

    printf("Vetor 1: ");
    imprimeVetor(vetor1, n);

    // Libera a memória alocada
    free();
    free();


    return EXIT_SUCCESS;
}

int *uniao(int *v1, int n1, int *v2, int n2) {

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