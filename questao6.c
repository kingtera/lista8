#include <stdio.h>
#include <stdlib.h>

int triangular(int *M, int l, int c);

int main() {
    int l, c;

    printf("Digite o numero de linhas da matriz: ");
    scanf("%d", &l);

    printf("Digite o numero de colunas da matriz: ");
    scanf("%d", &c);

    int matriz[l][c];

    printf("Digite os elementos da matriz:\n");
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < c; j++) {
            scanf("%d", &matriz[i][j]);
        }
    }

    int resultado = triangular(&matriz[l][c], l, c);

    if (resultado) {
        printf("A matriz e triangular inferior.\n");
    } else {
        printf("A matriz nao e triangular inferior.\n");
    }

    return EXIT_SUCCESS;
}

int triangular(int *M, int l, int c) {
    if (l != c) {
        return 0;
    }

    for (int i = 0; i < l; i++) {
        for (int j = i + 1; j < c; j++) {
            //ERRO ESTA AQUI
            if (*(M + i * c + j) != 0) {
                return 0;
            }
        }
    }

    return 1;
}