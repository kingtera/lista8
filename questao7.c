#include <stdio.h>
#include <stdlib.h>

int ** criaMatriz(int l, int c);

void pares(int **M, int l, int c);

void imprimeMatriz(int **M, int l, int c);

void exibeNumeroDeParesImpares(int **M, int l, int c);

int main(void) {
    int l = 0;
    int c = 0;

    printf("Digite o numero de linhas da matriz: ");
    scanf("%d", &l);

    printf("Digite o numero de colunas da matriz: ");
    scanf("%d", &c);

    int **matriz = criaMatriz(l, c);
    pares(matriz, l, c);
    exibeNumeroDeParesImpares(matriz, l, c);

    for (int i = 0; i < l; i++) {
        free(matriz[i]);
    }

    free(matriz);
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

    imprimeMatriz(matriz, l, c);

    return matriz;
}

void pares(int **M, int l, int c) {
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < c; j++) {
            if((M[i][j] % 2) == 0) printf("\nNumero par encontrado => %d - linha: %d| coluna: %d", M[i][j], i + 1, j + 1);
        }
    }
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

void exibeNumeroDeParesImpares(int **M, int l, int c) {
    int numerosMatriz = 0;
    int quantidadePares = 0;

    for(int i = 0; i < l; i++) {
        for(int j = 0; j < c; j++) {
            numerosMatriz++;
            if((M[i][j] % 2) == 0) quantidadePares++;
        }
    }

    printf("\nA matriz apresenta %d posicoes pares e %d posicoes impares", quantidadePares, numerosMatriz - quantidadePares);
}