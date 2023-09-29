#include <stdio.h>
#include <stdlib.h>

int * criaVetor(int tamanhoVetor);

int main(void) {
    int tamanho = 0;
    int *x, *y;

    printf("Digite o tamanho dos vetores: ");
    scanf("%d", &tamanho);

    printf("\n-----Vetor X-----");
    x = criaVetor(tamanho);

    printf("\n-----Vetor Y-----");
    y = criaVetor(tamanho);

    printf("\nO produto escalar entre X e Y e: ");
    // int resultado[tamanho];

    for (int i = 0; i < tamanho; i++) {
        int resultado = 0;
        resultado = (*x) * y[i];
        printf(" %d ", resultado);

        x++;
    }

    free(x);
    free(y);

    return EXIT_SUCCESS;
}

int * criaVetor(int tamanhoVetor) {
    int *vetor;

    printf("\nCriando vetor\n");

    vetor = (int *) malloc(tamanhoVetor*sizeof(int));
    if(vetor == NULL) exit(EXIT_FAILURE);

    for(int i = 0; i < tamanhoVetor; i++) {
        int n = 0;
        printf("Digite o %d numero do vetor (deve estar entre 1 e 100): ", i+1);
        scanf("%d", &n);

        while (n < 1 || n > 100) {
            printf("\nNumero invalido, digite novamente: ");
            scanf("%d", &n);
        }

        vetor[i] = n;
    }

    return vetor;
}