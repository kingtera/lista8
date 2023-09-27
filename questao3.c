#include <stdio.h>
#include <stdlib.h>

int *misterio(int n) {
    int i, *vet = malloc(n * sizeof(int));
    vet[0] = 1;
    for (i = 1; i < n; i++)
        vet[i] = i * vet[i - 1];
    return vet;
}

int main() {
    int i, n, *v;
    printf("Digite n:");
    scanf("%d", &n);
    v = misterio(n);
    for (i = 0; i < n; i++)
        printf("%d\n", v[i]);
    free(v);
    return 0;
}

//para n = 3, o retorno é 1, 1 e 2
//o codigo não apresenta nenhum erro. Um único ponto é que seria recomendável adicionar uma verificação logo após o malloc com o
// objetivo de assegurar que a alocação dinâmica foi realizada e concluída com sucesso.