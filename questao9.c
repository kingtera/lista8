#include <stdio.h>
#include <stdlib.h>

int **multiplicaM(int *A, int l1, int c1, int *B, int l2, int c2) {
    if (c1 != l2) {
        printf("As matrizes não podem ser multiplicadas. O número de colunas de A deve ser igual ao número de linhas de B.\n");
        return NULL;
    }

    int **C = (int **)malloc(l1 * sizeof(int *));
    if (C == NULL) {
        perror("Erro ao alocar memoria para C");
        return NULL;
    }

    for (int i = 0; i < l1; i++) {
        C[i] = (int *)malloc(c2 * sizeof(int));
        if (C[i] == NULL) {
            perror("Erro ao alocar memoria para C");
            for (int j = 0; j < i; j++) {
                free(C[j]);
            }
            free(C);
            return NULL;
        }
    }

    for (int i = 0; i < l1; i++) {
        for (int j = 0; j < c2; j++) {
            C[i][j] = 0;
            for (int k = 0; k < c1; k++) {
                C[i][j] += A[i * c1 + k] * B[k * c2 + j];
            }
        }
    }

    return C;
}

int main() {
    int l1, c1, l2, c2;

    printf("Digite o numero de linhas da matriz A: ");
    scanf("%d", &l1);

    printf("Digite o numero de colunas da matriz A: ");
    scanf("%d", &c1);

    printf("Digite o numero de linhas da matriz B: ");
    scanf("%d", &l2);

    printf("Digite o numero de colunas da matriz B: ");
    scanf("%d", &c2);

    if (c1 != l2) {
        printf("As matrizes não podem ser multiplicadas. O numero de colunas de A deve ser igual ao numero de linhas de B.\n");
        return EXIT_FAILURE;
    }

    int *A = (int *)malloc(l1 * c1 * sizeof(int));
    int *B = (int *)malloc(l2 * c2 * sizeof(int));

    printf("Digite os elementos da matriz A:\n");
    for (int i = 0; i < l1; i++) {
        for (int j = 0; j < c1; j++) {
            scanf("%d", &A[i * c1 + j]);
        }
    }

    printf("Digite os elementos da matriz B:\n");
    for (int i = 0; i < l2; i++) {
        for (int j = 0; j < c2; j++) {
            scanf("%d", &B[i * c2 + j]);
        }
    }

    int **C = multiplicaM(A, l1, c1, B, l2, c2);

    if (C == NULL) {
        return EXIT_FAILURE;
    }

    printf("Resultado da multiplicacao C = A x B:\n");
    for (int i = 0; i < l1; i++) {
        for (int j = 0; j < c2; j++) {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }

    // Libera a memória alocada
    for (int i = 0; i < l1; i++) {
        free(C[i]);
    }
    
    free(C);
    free(A);
    free(B);
    return EXIT_SUCCESS;
}