#include <stdio.h>
#include <stdlib.h>

int ** criaMatriz(int l, int c);

void imprimeMatriz(int **M, int l, int c);

int **somaMatriz(int **A, int l1, int c1, int **B, int l2, int c2);

int main(void) {
    int n = 0;

    printf("Digite o numero n para a matriz (n x n): ");
    scanf("%d", &n);
    
    int l1 = n;
    int c1 = n;
    int l2= n;
    int c2 = n;

    int **matrizA = criaMatriz(l1, c1);
    int **matrizB = criaMatriz(l2, c2);

    printf("\n-----A-----\n");
    imprimeMatriz(matrizA, l1, c1);

        printf("\n-----B-----\n");
    imprimeMatriz(matrizB, l2, c2);
    
    int **resultado = somaMatriz(matrizA, l1, c1, matrizB, l2, c2);
    printf("\nA soma das matrizes A e B gera a seguinte matriz resultante: \n");
    imprimeMatriz(resultado, l1, c1);

    for (int i = 0; i < n; i++) {
        free(matrizA[i]);
    }

    for (int i = 0; i < n; i++) {
        free(matrizB[i]);
    }


    free(matrizA);
    free(matrizB);
    return EXIT_SUCCESS;
}

int ** criaMatriz(int l, int c) {
    int **matriz = (int **)malloc(l * sizeof(int *));
    if (matriz == NULL) exit(EXIT_FAILURE);

    for (int i = 0; i < l; i++) {
        matriz[i] = (int *)malloc(c * sizeof(int));
        if (matriz[i] == NULL) exit(EXIT_FAILURE);
    }

    printf("Digite os elementos da matriz:\n");
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < c; j++) {
            scanf("%d", &matriz[i][j]);
        }
    }

    return matriz;
}

void imprimeMatriz(int **M, int l, int c) {
    printf("\nSua matriz\n");
    for(int i = 0; i < l; i++) {
        for(int j = 0; j < c; j++) {
            printf("%d ", M[i][j]);
        }
        printf("\n");
    }
}

int **somaMatriz(int **A, int l1, int c1, int **B, int l2, int c2) {
    int **matrizResultante = (int **)malloc(l1 * sizeof(int *));
    if (matrizResultante == NULL) exit(EXIT_FAILURE);

    for (int i = 0; i < l1; i++) {
        matrizResultante[i] = (int *)malloc(c1 * sizeof(int));
        if (matrizResultante[i] == NULL) exit(EXIT_FAILURE);
    }

    for(int i = 0; i < l1; i++) {
        for(int j = 0; j < c1; j++) {
            matrizResultante[i][j] = A[i][j] + B[i][j];
        }
    }

    return matrizResultante;
}