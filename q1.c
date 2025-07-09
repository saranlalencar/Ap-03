#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int x;
    int y;
} Ponto;

void gerarPonto(Ponto *p, int limite) {
    p->x = rand() % limite;
    p->y = rand() % limite;
}

void imprimirPontos(Ponto *vetor, int quantidade) {
    printf("\nPontos gerados:\n");
    for (int i = 0; i < quantidade; i++) {
        printf("Ponto %d: (%d, %d)\n", i + 1, (vetor + i)->x, (vetor + i)->y);
    }
}

int main() {
    int n, limite = 100;
    printf("Informe a quantidade de pontos: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        fprintf(stderr, "Quantidade inválida.\n");
        return 1;
    }

    Ponto *conjunto = malloc(n * sizeof(Ponto));
    if (!conjunto) {
        fprintf(stderr, "Falha na alocação de memória.\n");
        return 1;
    }

    srand((unsigned)time(NULL));

    for (int i = 0; i < n; i++) {
        gerarPonto(conjunto + i, limite);
    }

    imprimirPontos(conjunto, n);

    free(conjunto);
    return 0;
}