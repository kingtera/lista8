#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i;

    printf("Digite o tamanho do vetor: ");
    scanf("%d", &n);

    int v[n]; // Vetor alocado com tamanho n não pré-estabelecido

    for (i = 0; i < n; i++)
        v[i] = i;

    for (i = 0; i < n; i++)
        printf("%d\n", v[i]);

    return EXIT_SUCCESS;
}

// Quando n = 4000000, ocorre um erro na hora da alocação de memória para o vetor.
// Um vetor de tamanho 4000000 excede a memória disponível para armazenamento.